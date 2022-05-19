/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:25:28 by clbouche          #+#    #+#             */
/*   Updated: 2022/05/19 14:52:49 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <string>
#include "../includes/utils.hpp"
#include "../includes/commands.hpp"
#include "../includes/channels.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"

void    cmd_user( IrcServer *serv, user	currentUser, std::string & args )
{
	(void)serv;
	(void)currentUser;
	std::cout << "enter in cmd_user" << std::endl;
	std::cout << "args are : " << args << std::endl;
}

void    cmd_pass( IrcServer *serv, user	currentUser, std::string & args )
{
	(void)serv;
	(void)currentUser;
	(void)args;
	std::cout << "enter in cmd_pass" << std::endl;
	std::cout << "args are : "<< args << std::endl;
}
 
void    cmd_nick( IrcServer *serv, user	currentUser, std::string & args )
{
	(void)serv;
	(void)currentUser;
	(void)args;
	std::cout << "enter in cmd_nick" << std::endl;
	std::cout << "args are : " << args<< std::endl;
}

void    cmd_NULL( IrcServer *serv, user	currentUser, std::string & args )
{
	(void)serv;
	(void)currentUser;
	(void)args;
	std::cout << "cmd not found" << std::endl;
}

void    parse_cmd(std::string args, IrcServer *IRC, user currentUser)
{
	std::vector<std::string>	split_args = ft_split(args, " ");
	const std::string			command = split_args.front();

	IRC->recup_cmd(command)(IRC, currentUser , args);
}


void    cmd_join( IrcServer *serv, user	currentUser, std::string & args )
{
    (void)serv;
    (void)currentUser;
    // (void)args;

	args = "coco channel";
    std::cout << "enter in cmd_join" << std::endl;
    channels	*newChan = new channels(args, &currentUser);
	serv->currentChannels.insert(std::make_pair(1, *newChan));
    std::cout << "CHANNEL NAME :" << serv->currentChannels.begin()->second.getName() << std::endl;
    std::cout << "quitting cmd_join" << std::endl;
}