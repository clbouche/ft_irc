/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:25:00 by clbouche          #+#    #+#             */
/*   Updated: 2022/06/03 10:09:42 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef COMMANDS_HPP
# define COMMANDS_HPP

#include "IrcServer.hpp"
#include "headers.hpp"
#include <iostream>

void    parse_cmd(std::string cmd, IrcServer *IRC, user	*currentUser);

void    cmd_pass(IrcServer *serv, user	*currentUser, std::string & args);
void    cmd_nick(IrcServer *serv, user	*currentUser, std::string & args);
void    cmd_user(IrcServer *serv, user	*currentUser, std::string & args);
void    cmd_join(IrcServer *serv, user	*currentUser, std::string & args);
// void	cmd_admin(Ircserver *serv, user *currentUser, std::string &args);
// void	cmd_away(Ircserver *serv, user *currentUser, std::string &args);
// void	cmd_die(Ircserver *serv, user *currentUser, std::string &args);
// void	cmd_invite(Ircserver *serv, user *currentUser, std::string &args);
// void	cmd_kick(Ircserver *serv, user *currentUser, std::string &args);
// void	cmd_kill(Ircserver *serv, user *currentUser, std::string &args);
// void	cmd_list(Ircserver *serv, user *currentUser, std::string &args);
// void	cmd_mode(Ircserver *serv, user *currentUser, std::string &args);
// void	cmd_motd(Ircserver *serv, user *currentUser, std::string &args);
// void	cmd_names(Ircserver *serv, user *currentUser, std::string &args);
// void	cmd_nick(Ircserver *serv, user *currentUser, std::string &args);
// void	cmd_notice(Ircserver *serv, user *currentUser, std::string &args);
// void	cmd_oper(Ircserver *serv, user *currentUser, std::string &args);
// void	cmd_part(Ircserver *serv, user *currentUser, std::string &args);
// void	cmd_ping(Ircserver *serv, user *currentUser, std::string &args);
void    cmd_privmsg(IrcServer *serv, user *currentUser, std::string & args);
void	cmd_quit(Ircserver *serv, user *currentUser, std::string &args);
// void	cmd_time(Ircserver *serv, user *currentUser, std::string &args);
// void	cmd_topic(Ircserver *serv, user *currentUser, std::string &args);
// void	cmd_version(Ircserver *serv, user *currentUser, std::string &args);
// void	cmd_who(Ircserver *serv, user *currentUser, std::string &args);

void    cmd_NULL( IrcServer *serv, user	*currentUser, std::string & args );



#endif