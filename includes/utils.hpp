/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:20:47 by clbouche          #+#    #+#             */
/*   Updated: 2022/06/13 14:51:58 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include "IrcServer.hpp"
# include "user.hpp"

class IrcServer;

std::vector<std::string>		ft_split(std::string args, std::string delim);
bool							check_connexion( user *currentUser, IrcServer *serv);
std::string						send_replies(const int code, user *user, IrcServer *serv, std::string arg1 = "", std::string arg2 = "", std::string arg3 = "", std::string arg4 = "");
void							ft_strToupper (std::string & str);

void		ltrim(std::string &s);
void		rtrim(std::string &s);
void		trim(std::string &s);
std::string ltrim_copy(std::string s);
std::string rtrim_copy(std::string s);
std::string trim_copy(std::string s);
#endif