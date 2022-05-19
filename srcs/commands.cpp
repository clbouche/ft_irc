/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:25:28 by clbouche          #+#    #+#             */
/*   Updated: 2022/05/19 13:48:37 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <string>
#include "../includes/utils.hpp"
#include "../includes/commands.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"

void    cmd_user( IrcServer *serv, int sd, std::string & args )
{
	(void)serv;
	(void)sd;
	std::cout << "enter in cmd_user" << std::endl;
	std::cout << "args are : " << args << std::endl;
}

void    cmd_pass( IrcServer *serv, int sd, std::string & args )
{
	(void)serv;
	(void)sd;
	(void)args;
	std::cout << "enter in cmd_pass" << std::endl;
	std::cout << "args are : "<< args << std::endl;
}
 
void    cmd_nick( IrcServer *serv, int sd, std::string & args )
{
	(void)serv;
	(void)sd;
	(void)args;
	std::cout << "enter in cmd_nick" << std::endl;
	std::cout << "args are : " << args<< std::endl;
}

void    cmd_NULL( IrcServer *serv, int sd, std::string & args )
{
	(void)serv;
	(void)sd;
	(void)args;
	std::cout << "cmd not found" << std::endl;
}

void    parse_cmd(std::string args, IrcServer *IRC, int sd)
{
	std::vector<std::string>	split_args = ft_split(args, " ");
	const std::string			command = split_args.front();

	IRC->recup_cmd(command)(IRC, sd, args);
}