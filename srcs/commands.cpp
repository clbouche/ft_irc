/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:25:28 by clbouche          #+#    #+#             */
/*   Updated: 2022/05/19 16:18:53 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/commands.hpp"
#include "../includes/channels.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"
#include <iterator>

void    cmd_user( IrcServer *serv, user	currentUser, std::string & args )
{
	(void)serv;
	(void)currentUser;
	(void)args;
	std::cout << "enter in cmd_user" << std::endl;
}

void    cmd_pass( IrcServer *serv, user	currentUser, std::string & args )
{
	(void)serv;
	(void)currentUser;
	(void)args;
	std::cout << "enter in cmd_pass" << std::endl;
}
 
void    cmd_nick( IrcServer *serv, user	currentUser, std::string & args )
{
	(void)serv;
	(void)currentUser;
	(void)args;
	std::cout << "enter in cmd_nick" << std::endl;
}

void    cmd_NULL( IrcServer *serv, user	currentUser, std::string & args )
{
	(void)serv;
	(void)currentUser;
	(void)args;
	std::cout << "cmd not found" << std::endl;
}

void    parse_cmd(std::string cmd, IrcServer *IRC, user currentUser)
{
	std::string     commands = "";
	
	IRC->recup_cmd(cmd)(IRC, currentUser, commands);
}

void    cmd_join( IrcServer *serv, user	currentUser, std::string & args )
{
	(void)serv;
	(void)currentUser;
	// (void)args;
	args = "coco channel";

	std::cout << "enter in cmd_join" << std::endl;

	if (serv->currentChannels.find(args) == serv->currentChannels.end())
	{
		channels	*newChan = new channels(args, &currentUser);
		serv->currentChannels.insert(std::make_pair(newChan->getName(), *newChan)); // the key is the name of the chan
		std::cout << "channel created" << std::endl; //DEBUG TO KNOW IF THE CHANNEL HAS BEEN CREATED OR NOT
	}
	else
		std::cout << "CHANNEL NOT CREATED" << std::endl;//DEBUG TO KNOW IF THE CHANNEL HAS BEEN CREATED OR NOT

	std::cout << "CHANNEL NAME :" << serv->currentChannels.begin()->second.getName() << std::endl;
	// std::cout << "CHANNEL SIZE :" << serv->currentChannels.size() << std::endl;
	//affichage channel users
	serv->currentChannels.find(args)->second.addUser(currentUser);
	// std::map<int, user*>::iterator it = serv->currentChannels.begin()->second.getUsers().begin();
	// while(it != serv->currentChannels.begin()->second.getUsers().end())
	// {
	// 	std::cout << "user : " << it->getSdUser() << std::endl;
	// }
	//affichage channel users

	std::cout << "quitting cmd_join" << std::endl;
}