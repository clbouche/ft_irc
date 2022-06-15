
#include "../includes/headers.hpp"
#include "../includes/commands.hpp"
#include "../includes/channels.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"


bool		check_args( IrcServer *serv, user *currentUser, channels *channel, std::string chan_name, std::string nameOfUserToKick)
{
	if (channel == NULL)
	{
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
						send_replies(403, currentUser, serv, chan_name)));
		return false;

	}
	else if ((strchr(CHANNEL_PREFIX, chan_name.c_str()[0]) == NULL))
	{
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
						send_replies(476, currentUser, serv)));
		return false;

	}
	else if (channel->UserInChan(currentUser) == false)
	{
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
						send_replies(442, currentUser, serv, chan_name)));
		return false;

	}
	else if (channel->UserInChan(nameOfUserToKick) == false)
	{
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
						send_replies(441, currentUser, serv, nameOfUserToKick, chan_name)));
		return false;
	}
	return true;
}

void    cmd_kick( IrcServer *serv, user *currentUser, std::string & args )
{

	//ne pas oublier de gerer le commentaire a la fin 
	//avec find_last_of(" ") comme ca on recupere tout le reste dans rpl_msg
	std::string		tmp_args;
	size_t			pos = args.find_first_of(" ");
    std::string		chans = args.substr(0, pos);

    //si KICK n'a pas de nom de channel a quitter pour le user
	if (chans == "")
	{
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
		 					send_replies(461, currentUser, serv, "KICK")));
		return ;
	}

	tmp_args = args.substr(pos + 1, args.size());
	size_t						tmpPos = tmp_args.find_first_of(" ");
    std::string		            users;
	std::string					rpl_kickMsg;

	pos == std::string::npos ? users = "" : users = args.substr(pos + 1, tmpPos);
	tmpPos == std::string::npos ? rpl_kickMsg = "left" : rpl_kickMsg = tmp_args.substr(tmpPos + 1, tmp_args.size());
	std::string test = tmp_args.substr(tmpPos + 1, tmp_args.size());
	
	std::vector<std::string>		split_channels = ft_split(chans, ",");
	std::vector<std::string>		split_users = ft_split(users, ",");
 
	std::vector<std::string>::iterator	it;
	size_t			j = 0;
	for (it = split_channels.begin() ; it != split_channels.end(); it++)
	{
    	std::string		chan_name;
		std::string		NameOfUserToKick;
		chan_name = split_channels[j];
		j >= split_users.size() ? NameOfUserToKick = split_users[0] : NameOfUserToKick = split_users[j];
		
		channels		*channel;
		serv->currentChannels.find(chan_name) == serv->currentChannels.end() ? 
			channel = NULL : channel = serv->currentChannels.find(chan_name)->second;
			
		if (check_args(serv, currentUser, channel, chan_name, NameOfUserToKick)
				&& channel->UserInChan(currentUser) 
				&& channel->UserInChan(NameOfUserToKick))
		{
			std::map<int, user *>		mapOfUsers;
			user						*userToKick;
			mapOfUsers = channel->getUsers();

			std::map<int, user *>::iterator		ite;
			for (ite = mapOfUsers.begin(); ite != mapOfUsers.end(); ite++)
			{
				if (ite != mapOfUsers.end() && ite->second->getNickName() == NameOfUserToKick )
				{
					userToKick = ite->second;
					channel->sendToAllUsers(&serv->_tcpServer, (":" + userToKick->getNickName() + " KICK "
							+ chan_name + " :" + rpl_kickMsg + "\r\n"));
					userToKick->removeChan(channel);
					channel->removeUser(userToKick);
					if (channel->getNbUsers() == 0)
					{
						delete serv->currentChannels[chan_name];
						serv->currentChannels.erase(chan_name);
					}
				}
			}
		}
	}
}