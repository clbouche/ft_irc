/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_privmsg.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:03:10 by elaachac          #+#    #+#             */
/*   Updated: 2022/06/16 11:47:35 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.hpp"
#include "../includes/utils.hpp"
#include "../includes/commands.hpp"
#include "../includes/channels.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"

static bool check_args(std::string target, std::string msg_to_check, user *currentUser, IrcServer *serv)
{
	if (target == "")
	{
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), send_replies(411, currentUser, serv, target)));
		return (false);
	}
	if (msg_to_check == "")
	{
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), send_replies(412, currentUser, serv, target)));
		return (false);
	}
	return (true);
}

void cmd_privmsg(IrcServer *serv, user *currentUser, std::string &args)
{
	size_t pos = args.find_first_of(" ");
	std::string target = args.substr(0, pos);
	std::string msg_to_check;
	pos == std::string::npos ? msg_to_check = "" : msg_to_check = args.substr(pos + 1, args.length());
	if (check_args(target, msg_to_check, currentUser, serv))
	{
		std::string msg = "PRIVMSG " + target + " :" + msg_to_check + "\r\n";

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
						serv->_tcpServer.add_to_buffer(std::make_pair(it->second->getSdUser(), msg.c_str()));
					}
				}
			}
			else
				serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), send_replies(404, currentUser, serv, target)));
		}
		else
		{
			std::map<int, user *>::iterator it;
			for (it = serv->usersMap.begin(); it != serv->usersMap.end(); it++)
			{
				if (it->second->getNickName() == target)
				{
					serv->_tcpServer.add_to_buffer(std::make_pair(it->second->getSdUser(), msg.c_str()));
					return;
				}
			}
			serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), send_replies(401, currentUser, serv, target)));
		}
	}
}
