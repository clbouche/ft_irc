/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:25:00 by clbouche          #+#    #+#             */
/*   Updated: 2022/05/17 13:53:55 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef COMMANDS_HPP
# define COMMANDS_HPP

#include "IrcServer.hpp"
#include <iostream>

void    parse_cmd(std::string cmd, IrcServer *IRC, int sd);

void    cmd_pass(IrcServer *serv, int sd, std::string & args);
void    cmd_nick(IrcServer *serv, int sd, std::string & args);
void    cmd_user(IrcServer *serv, int sd, std::string & args);


#endif