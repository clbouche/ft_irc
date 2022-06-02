/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pass ✅.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:50:43 by clbouche          #+#    #+#             */
/*   Updated: 2022/06/02 11:25:23 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/commands.hpp"
#include "../../includes/channels.hpp"
#include "../../includes/IrcServer.hpp"
#include "../../includes/user.hpp"
#include "../../includes/headers.hpp"

/**
 * @brief 
 *   Parameters: <password>

   The PASS command is used to set a 'connection password'.  The
   password can and must be set before any attempt to register the
   connection is made.  Currently this requires that clients send a PASS
   command before sending the NICK/USER combination and servers *must*
   send a PASS command before any SERVER command.  The password supplied
   must match the one contained in the C/N lines (for servers) or I
   lines (for clients).  It is possible to send multiple PASS commands
   before registering but only the last one sent is used for
   verification and it may not be changed once registered.  Numeric
   Replies:

           ERR_NEEDMOREPARAMS              ERR_ALREADYREGISTRED

   Example:

           PASS secretpasswordhere
*/

bool	check_args(IrcServer *serv, user *currentUser, std::string args)
{
	if (args == "")
	{
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), send_replies(461, currentUser, serv, "PASS")));
		return false;
	}
	else if (currentUser->getConnexion() == true)
	{
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), send_replies(462, currentUser, serv)));
		return false;
	}
	return true;
}

void    cmd_pass( IrcServer *serv, user	*currentUser, std::string & args )
{
	if (check_args(serv, currentUser, args) == true)
	{
		if (args == serv->getServerPassword())
			currentUser->setCheckPassword(true);
	}
}