/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:25:28 by clbouche          #+#    #+#             */
/*   Updated: 2022/05/19 10:46:38 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/commands.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"

void    cmd_user( IrcServer *serv, int sd, std::string & args )
{
    (void)serv;
    (void)sd;
    (void)args;
}

void    cmd_pass( IrcServer *serv, int sd, std::string & args )
{
    (void)serv;
    (void)sd;
    (void)args;
    std::cout << "enter in cmd_pass" << std::endl;
}
 
void    cmd_nick( IrcServer *serv, int sd, std::string & args )
{
    (void)serv;
    (void)sd;
    (void)args;
    std::cout << "enter in cmd_nick" << std::endl;
}

void    cmd_NULL( IrcServer *serv, int sd, std::string & args )
{
    (void)serv;
    (void)sd;
    (void)args;
    std::cout << "cmd not found" << std::endl;
}

void    parse_cmd(std::string cmd, IrcServer *IRC, int sd)
{
    std::string     commands = "";
    
    IRC->recup_cmd(cmd)(IRC, sd, commands);
}

void    cmd_join( IrcServer *serv, int sd, std::string & args )
{
    (void)serv;
    (void)sd;
    (void)args;
    std::cout << "enter in cmd_user" << std::endl;
    channels    *newChan = channels();
    std::cout << "quitting cmd_user" << std::endl;
}