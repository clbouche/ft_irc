/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:25:00 by clbouche          #+#    #+#             */
/*   Updated: 2022/05/17 14:41:15 by clbouche         ###   ########.fr       */
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

void    cmd_NULL( IrcServer *serv, int sd, std::string & args );



#endif 