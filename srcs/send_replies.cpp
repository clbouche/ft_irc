/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_replies.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:49:53 by clbouche          #+#    #+#             */
/*   Updated: 2022/06/17 15:20:08 by clbouche         ###   ########.fr       */
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


std::string	formatMsgsUsers(const std::string & nickname, const std::string & username, const std::string & hostname)
{
	std::string		msg;

	msg.append(":");
	msg.append(nickname);
	msg.append("!");
	msg.append(username);
	msg.append("@");
	msg.append(hostname);
	msg.append(" ");
	return (msg);
}

std::string		send_replies(const int code, user *user, IrcServer *serv, std::string arg1, std::string arg2, std::string arg3, std::string arg4)
{
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
		case 1:
			return reply + RPL_WELCOME(arg1, arg2, arg3);
		case 2:
			return reply + RPL_YOURHOST(arg1, arg2);
		case 3:
			return reply + RPL_CREATED();
		case 4:
			return reply + RPL_MYINFO(arg1, arg2, arg3, arg4);
		case 221:
			return reply + RPL_UMODEIS(arg1);
		case 322:
			return reply + RPL_LIST(arg1, arg2);
		case 323:
			return reply + RPL_LISTEND();
		case 324:
			return reply + RPL_CHANNELMODEIS(arg1, arg2, arg3);
		case 331:
			return reply + RPL_NOTOPIC(arg1);
		case 332:
			return reply + RPL_TOPIC(arg1, arg2);
		case 341:
			return reply + RPL_INVITING(arg1, arg2);
		case 353:
			return reply + RPL_NAMREPLY(arg1);
		case 366:
			return reply + RPL_ENDOFNAMES(arg1);
		case 367:
			return reply + RPL_BANLIST(arg1, arg2);
		case 368:
			return reply + RPL_ENDOFBANLIST(arg1);
		case 372:
			return reply + RPL_MOTD(arg1);
		case 375:
			return reply + RPL_MOTDSTART(arg1);
		case 376:
			return reply + RPL_ENDOFMOTD();
		case 401:
			return reply + ERR_NOSUCHNICK(arg1);
		case 402:
			return reply + ERR_NOSUCHSERVER(arg1);
		case 403:
			return reply + ERR_NOSUCHCHANNEL(arg1);
		case 404:
			return reply + ERR_CANNOTSENDTOCHAN(arg1);
		case 405:
			return reply + ERR_TOOMANYCHANNELS(arg1);
		case 409:
			return reply + ERR_NOORIGIN();
		case 411:
			return reply + ERR_NORECIPIENT(arg1);
		case 412:
			return reply + ERR_NOTEXTTOSEND();
		case 422:
			return reply + ERR_NOMOTD();
		case 421:
			return reply + ERR_UNKNOWNCOMMAND(arg1);
		case 431:
			return reply + ERR_NONICKNAMEGIVEN();
		case 432:
			return reply + ERR_ERRONEUSNICKNAME(arg1);
		case 433:
			return reply + ERR_NICKNAMEINUSE(arg1);
		case 441:
			return reply + ERR_USERNOTINCHANNEL(arg1, arg2);
		case 442:
			return reply + ERR_NOTONCHANNEL(arg1);
		case 443:
			return reply + ERR_USERONCHANNEL(arg1, arg2);
		case 451:
			return reply + ERR_NOTREGISTERED();
		case 461:
			return reply + ERR_NEEDMOREPARAMS(arg1);
		case 462:
			return reply + ERR_ALREADYREGISTRED();
		case 471:
			return reply + ERR_CHANNELISFULL(arg1);
		case 472:
			return reply + ERR_UNKNOWNMODE(arg1, arg2);
		case 473:
			return reply + ERR_INVITEONLYCHAN(arg1);
		case 474:
			return reply + ERR_BANNEDFROMCHAN(arg1);
		case 475:
			return reply + ERR_BADCHANNELKEY(arg1);
		case 476:
			return reply + ERR_BADCHANMASK(arg1);
		case 482:
			return reply + ERR_CHANOPRIVSNEEDED(arg1);
		case 501:
			return reply + ERR_UMODEUNKNOWNFLAG();
		case 502:
			return reply + ERR_USERSDONTMATCH();
		case 667:
			return reply + ": " + arg2 + " ban list already contains " + arg1 + "\r\n";
		case 998:
			return RPL_BANUSER(arg1, arg2);
	
	}
	return (reply);
}
