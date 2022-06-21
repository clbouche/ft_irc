
#include "../includes/headers.hpp"
#include "../includes/commands.hpp"
#include "../includes/channels.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"

static bool check_args(std::string target, std::string msg_to_check)
{
	if (target == "")
		return (false);
	if (msg_to_check == "")
		return (false);
	return (true);
}

void cmd_notice(IrcServer *serv, user *currentUser, std::string &args)
{
	size_t pos = args.find_first_of(" ");
	std::string target = args.substr(0, pos);
	std::string msg_to_check;
	pos == std::string::npos ? msg_to_check = "" : msg_to_check = args.substr(pos + 1, args.length());
	if (check_args(target, msg_to_check))
	{
		std::string msg_notice = formatMsgsUsers(currentUser->getNickName(), currentUser->getUserName(), currentUser->getHostNameUser());

		if (strchr(CHANNEL_PREFIX, target.c_str()[0]) != NULL)
		{
			channels *chanToSend = serv->currentChannels.find(target)->second;
			std::map<int, user *>::iterator it;
			if (chanToSend->UserInChan(currentUser) == true)
			{
				for (it = chanToSend->getUsers().begin(); it != chanToSend->getUsers().end(); it++)
				{
					if (it->second->getNickName() != currentUser->getNickName())
					{
					chanToSend->sendToAllUsersInChan(&serv->_tcpServer, (msg_notice + "PRIVMSG "
							+ chanToSend->getName() + " " + target + " :"
							+ msg_to_check + "\r\n"));
					}
				}
			}
		}
		else
		{
			std::map<int, user *>::iterator it;
			for (it = serv->usersMap.begin(); it != serv->usersMap.end(); it++)
			{
				if (it->second->getNickName() == target)
				{
					serv->_tcpServer.add_to_buffer(std::make_pair(it->second->getSdUser(), (msg_notice + "PRIVMSG "
							+ target + " : " + msg_to_check + "\r\n")));
					return;
				}
			}
		}
	}
}
