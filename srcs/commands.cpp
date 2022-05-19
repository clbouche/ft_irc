/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:25:28 by clbouche          #+#    #+#             */
/*   Updated: 2022/05/19 17:45:09 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <string>
#include "../includes/utils.hpp"
#include "../includes/commands.hpp"
#include "../includes/channels.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"
 
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

