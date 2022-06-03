/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_replies.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:49:53 by clbouche          #+#    #+#             */
/*   Updated: 2022/06/03 17:21:17 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.hpp"
#include "../includes/IrcServer.hpp"

/**
 * @brief Convert a int to string
 * 
 * @param value Number to convert to string
 * @return Strin with int value
 */
std::string					ft_to_string(int value)
{
	std::string output;
	std::string sign;
	char		nb[2];

	if (value < 0)
	{
		sign + "-";
		value = -value;
	}
	nb[1] = '\0';
	while (output.empty() || (value > 0))
	{
		nb[0] = value % 10 + '0';
		output.insert(0, std::string(nb));
		value /= 10;
	}

	return (sign + output);
}

std::string		send_replies(const int code, user *user, IrcServer *serv, std::string arg1)
{
	(void)user;
	(void)serv;
	std::string		reply = ":";

	reply.append(serv->_tcpServer.getHostname());
	reply.append(" ");
	if (code < 10)
		reply.append("00");
	else if (code < 100)
		reply.append("0");
	reply.append(ft_to_string(code));
	reply.append(" ");
	if (user->getNickName() == "")
		reply.append("*");
	else
		reply.append(user->getNickName());
	reply.append(" ");
	switch(code)
	{
		case 401:
			return reply + ERR_NOSUCHNICK(arg1);
		case 431:
			return reply + ERR_NONICKNAMEGIVEN();
		case 432:
			return reply + ERR_ERRONEUSNICKNAME(arg1);
		case 433:
			return reply + ERR_NICKNAMEINUSE(arg1);
		case 461:
			return reply + ERR_NEEDMOREPARAMS(arg1);
		case 462:
			return reply + ERR_ALREADYREGISTRED();
	
	}
	return (reply);
}
