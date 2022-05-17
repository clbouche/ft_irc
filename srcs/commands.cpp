/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:25:28 by clbouche          #+#    #+#             */
/*   Updated: 2022/05/17 13:46:30 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/commands.hpp"
#include "../includes/IrcServer.hpp"

void    cmd_user( IrcServer *serv, int sd, std::string & args )
{
    std::cout << "enter in cmd_user" << std::endl;
}

void    cmd_pass( IrcServer *serv, int sd, std::string & args )
{
    std::cout << "enter in cmd_pass" << std::endl;
}
 
void    cmd_nick( IrcServer *serv, int sd, std::string & args )
{
    std::cout << "enter in cmd_nick" << std::endl;
}

void    parse_cmd(std::string cmd, IrcServer *IRC, int sd)
{
    IRC->recup_cmd(cmd)(IRC, sd, cmd);
}