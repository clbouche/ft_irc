/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:25:00 by clbouche          #+#    #+#             */
/*   Updated: 2022/05/19 14:44:45 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef COMMANDS_HPP
# define COMMANDS_HPP

#include "IrcServer.hpp"
#include <iostream>

void    parse_cmd(std::string cmd, IrcServer *IRC, user	currentUser);

void    cmd_pass(IrcServer *serv, user	currentUser, std::string & args);
void    cmd_nick(IrcServer *serv, user	currentUser, std::string & args);
void    cmd_user(IrcServer *serv, user	currentUser, std::string & args);
void    cmd_join(IrcServer *serv, user	currentUser, std::string & args);

void    cmd_NULL( IrcServer *serv, user	currentUser, std::string & args );



#endif