/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_privmsg.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:03:10 by elaachac          #+#    #+#             */
/*   Updated: 2022/06/03 10:03:11 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.hpp"
#include "../includes/utils.hpp"
#include "../includes/commands.hpp"
#include "../includes/channels.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"

void    cmd_privmsg(IrcServer *serv, user *currentUser, std::string & args)
{
	(void)currentUser;
	// On determine d'abord si on a un seul user ou un channel
	// si channel, on stock les users devant recevoir le message dans une stack
	// on envoie ensuite le message dans une boucle telle que :
	// tant que stack.size != 0:
	//      send msg a stack.top()   -> send msg a user
	//		stack.pop()    -> supprimer le user a qui on vient de send msg de la stack
	//
	// Si on a qu'un seul user : 
	// send directement msg a user
	size_t		pos = args.find_first_of(" ");
	std::string	target = args.substr(0, pos);
	std::string	msg = args.substr(pos + 1, args.length());
	
	std::cout << "ENTERING PRIVMSG FCT" << std::endl;
	std::cout << "target :{" << target << "}" << std::endl;
	std::cout << "msg :{" << msg << "}" << std::endl;

	if (strchr(CHANNEL_PREFIX, target.c_str()[0]) != NULL)
	{
		// std::cout << "char :" << args.c_str()[0] << ":" << std::endl;
		std::cout << "TARGET IS A CHANNEL" << std::endl;
		channels *chanToSend = serv->currentChannels.find(target)->second;
		std::map<int, user *>::iterator	it;
		// it = chanToSend.getUsers().begin();
		// while (it != chanToSend.getUsers().end())
        for (it = chanToSend->getUsers().begin(); it != chanToSend->getUsers().end(); it++)
		{
			std::cout << "current pushed :{" << currentUser->getNickName() << "}" << std::endl;
			std::cout << "Channel name :{" << chanToSend->getName() << "}" << std::endl;
			std::cout << "user pushed :{" << it->second->getNickName() << "}" << std::endl;
			if (it->second != currentUser)
			{
				//send message
				std::cout << PURPLE << "SENDING MESSAGE" << END << std::endl;
			}
			// receiving.push(*(it->second)); CONNARD YA DEJA UNE MAP DE USER, UTILISE LA
			// it++;
		}

	}
	else
	{
		std::cout << "TARGET IS A USER" << std::endl;
	}
	
}