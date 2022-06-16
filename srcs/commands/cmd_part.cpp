
#include "../includes/headers.hpp"
#include "../includes/commands.hpp"
#include "../includes/channels.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"

void    cmd_part( IrcServer *serv, user *currentUser, std::string & args )
{
	size_t 						pos = args.find_first_of(" ");
	channels					*chan;
	std::string					chan_name;
    std::string					partMsg;
	std::string					rpl_partMsg;
	std::string					chans = args.substr(0, pos);
	size_t						j = 0;

	if (chans == "")
	{
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
					send_replies(461, currentUser, serv, "PART")));
		return ;
	}

    pos == std::string::npos ? partMsg = "" : partMsg = args.substr(pos + 1, args.size());
    std::vector<std::string>	split_chans = ft_split(chans, ",");

	std::vector<std::string>::iterator		it;
	for(it = split_chans.begin(); it != split_chans.end(); it++)
	{
		chan_name = split_chans[j];

		serv->currentChannels.find(chan_name) == serv->currentChannels.end() ? 
			chan = NULL : chan = serv->currentChannels.find(chan_name)->second;

		if (chan == NULL)
		{
			serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
							send_replies(403, currentUser, serv, chan_name)));
		}
		else if (chan->UserInChan(currentUser) == false)
		{
			serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
							send_replies(442, currentUser, serv, chan_name)));
		}
		else if (chan->UserInChan(currentUser) == true)
		{
			chan->sendToAllUsers(&serv->_tcpServer, (":" + currentUser->getNickName() + "!" + 
							currentUser->getUserName() + "@" + currentUser->getHostNameUser() + " PART "
							+ chan_name + " :" + partMsg + "\r\n"));		
			chan->removeUser(currentUser);
			currentUser->removeChan(chan);
			if (chan->getNbUsers() == 0)
			{
				delete serv->currentChannels[chan_name];
				serv->currentChannels.erase(chan_name);
			}
		}
		j++;
	}     
}

