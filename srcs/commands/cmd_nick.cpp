#include "../../includes/headers.hpp"
#include "../../includes/commands.hpp"
#include "../../includes/channels.hpp"
#include "../../includes/IrcServer.hpp"
#include "../../includes/user.hpp"
#include "../includes/utils.hpp"

/**
 Command: NICK
   Parameters: <nickname>

   NICK command is used to give user a nickname or change the existing
   one.

   Numeric Replies:

           ERR_NONICKNAMEGIVEN             ERR_ERRONEUSNICKNAME
           ERR_NICKNAMEINUSE               ERR_NICKCOLLISION
           ERR_UNAVAILRESOURCE             ERR_RESTRICTED

   Examples:

   NICK Wiz                ; Introducing new nick "Wiz" if session is
                           still unregistered, or user changing his
                           nickname to "Wiz"

   :WiZ!jto@tolsun.oulu.fi NICK Kilroy
                           ; Server telling that WiZ changed his
                           nickname to Kilroy.
 */

bool	checkValidNickName(std::string nickname)
{
	if (nickname.length() > 9)
		return false;
	for (size_t i = 0; i < nickname.length(); i++)
	{
		if (!std::strchr(NICKNAME_VALID_CHAR, nickname[i]))
			return false;
	}
	return true;
}

bool	checkNicknameInUse(IrcServer *serv, user *currentUser, std::string args)
{
	std::string		checkNickName;

	for (std::map<int, user *>::iterator it = serv->usersMap.begin() ; it != serv->usersMap.end() ; it++)
	{
		if (&(*it->second) != &(*currentUser))
		{
			checkNickName = it->second->getNickName();
			if (args == checkNickName)
				return false;
		}
	}
	return true;
}

static bool		check_args(IrcServer *serv, user *currentUser, std::string args)
{
	//check si cmd NICK a des args 
	if (args == "")
	{
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), 
					send_replies(431, currentUser, serv)));
		return false;
	}
	//check si le nouveau nickname n'est pas deja pris
	if (checkNicknameInUse(serv, currentUser, args) == false)
	{
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), 
					send_replies(433, currentUser, serv, args)));
		return false;
	}
	//check si les caracteres du nouveau nickname sont OK
	if (checkValidNickName(args) == false)
	{
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), 
					send_replies(432, currentUser, serv, args)));
		return false;
	}
	return true;
}


void    cmd_nick( IrcServer *serv, user	*currentUser, std::string & args )
{
	if (check_args(serv, currentUser, args) == true)
	{
		currentUser->setNickName(args);
	}
}