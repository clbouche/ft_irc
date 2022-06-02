/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_replies.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:49:53 by clbouche          #+#    #+#             */
/*   Updated: 2022/06/02 11:25:12 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.hpp"
#include "../includes/IrcServer.hpp"

std::string		send_replies(const int code, user *user, IrcServer *serv, std::string arg1)
{
	(void)user;
	(void)serv;
	std::string		reply;

	switch(code)
	{
		case 461:
			return reply + ERR_NEEDMOREPARAMS(arg1);
		case 462:
			return reply + ERR_ALREADYREGISTRED();
	
	}
	return (reply);
}
