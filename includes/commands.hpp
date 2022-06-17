/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:25:00 by clbouche          #+#    #+#             */
/*   Updated: 2022/06/15 16:21:53 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef COMMANDS_HPP
# define COMMANDS_HPP

#include "IrcServer.hpp"
#include "headers.hpp"

void    parse_cmd(std::string cmd, IrcServer *IRC, user	*currentUser);

void	cmd_invite(IrcServer *serv, user *currentUser, std::string &args);
void    cmd_join(IrcServer *serv, user	*currentUser, std::string & args);
void	cmd_kick(IrcServer *serv, user *currentUser, std::string &args);
void	cmd_list(IrcServer *serv, user *currentUser, std::string &args);
void	cmd_mode(IrcServer *serv, user *currentUser, std::string &args);
void	cmd_motd(IrcServer *serv, user *currentUser, std::string &args);
void	cmd_names(IrcServer *serv, user *currentUser, std::string &args);
void    cmd_nick(IrcServer *serv, user	*currentUser, std::string & args);
void	cmd_notice(IrcServer *serv, user *currentUser, std::string &args);
void	cmd_part(IrcServer *serv, user *currentUser, std::string &args);
void    cmd_pass(IrcServer *serv, user	*currentUser, std::string & args);
void	cmd_ping(IrcServer *serv, user *currentUser, std::string &args);
void    cmd_privmsg( IrcServer *serv, user *currentUser, std::string & args);
void	cmd_quit(IrcServer *serv, user *currentUser, std::string &args);
void	cmd_topic(IrcServer *serv, user *currentUser, std::string &args);
void    cmd_user(IrcServer *serv, user	*currentUser, std::string &args);
void    cmd_who( IrcServer *serv, user	*currentUser, std::string &args);

void    cmd_NULL( IrcServer *serv, user	*currentUser, std::string &args);



#endif