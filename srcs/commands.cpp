/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:25:28 by clbouche          #+#    #+#             */
/*   Updated: 2022/05/17 14:20:22 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/commands.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"

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

void    parse_cmd(std::string cmd, IrcServer *IRC, const int sd)
{
    IRC->recup_cmd(cmd)(IRC, sd, cmd);
}