/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_user.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 09:31:55 by clbouche          #+#    #+#             */
/*   Updated: 2022/06/03 10:23:12 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.hpp"
#include "../includes/commands.hpp"
#include "../includes/channels.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"

/**
  Command: USER
   Parameters: <user> <mode> <unused> <realname>

   The USER command is used at the beginning of connection to specify
   the username, hostname and realname of a new user.

   The <mode> parameter should be a numeric, and can be used to
   automatically set user modes when registering with the server.  This
   parameter is a bitmask, with only 2 bits having any signification: if
   the bit 2 is set, the user mode 'w' will be set and if the bit 3 is
   set, the user mode 'i' will be set.  (See Section 3.1.5 "User
   Modes").

   The <realname> may contain space characters.

   Numeric Replies:

           ERR_NEEDMOREPARAMS              ERR_ALREADYREGISTRED

   Example:

   USER guest 0 * :Ronnie Reagan   ; User registering themselves with a
                                   username of "guest" and real name
                                   "Ronnie Reagan".

   USER guest 8 * :Ronnie Reagan   ; User registering themselves with a
                                   username of "guest" and real name
                                   "Ronnie Reagan", and asking to be set
                                   invisible.
 */


//de ce que j'ai vu sur le code d'arthur, on doit send les 3 premieres replies -> a checker.


static bool		check_args(IrcServer *serv, user *currentUser, std::string args)
{
	//check s'il y a bien tous les args necessaire a la cmd USER
	if (args.size() < 4)
	{
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
		 					send_replies(461, currentUser, serv, "USER")));
		return false;
	}
	//check si le realname a été donné ou pas
	if (args.find(":") == std::string::npos)
	{
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
		 					send_replies(461, currentUser, serv, "USER")));
		return false;
	}
	//si la cmd USER a deja ete lance, on ne change pas de nom
	if (currentUser->getUserName() != "" || currentUser->getRealName() != "")
	{
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), 
							send_replies(462, currentUser, serv)));
		return false;
	}
	return true;
}

void    cmd_user( IrcServer *serv, user	*currentUser, std::string & args )
{
	std::vector<std::string>	split_args;

	if (check_args(serv, currentUser, args) == true)
	{
		split_args = ft_split(args, ":");
		currentUser->setRealName(split_args[1]);
		split_args = ft_split(args, " ");
		currentUser->setUserName(split_args[0]);
		currentUser->setMode(split_args[1]);
	}
}