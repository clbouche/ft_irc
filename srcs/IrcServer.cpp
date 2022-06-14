/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IrcServer.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:04:27 by clbouche          #+#    #+#             */
/*   Updated: 2022/06/14 14:35:20 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/tcpServer.hpp"
#include "../includes/user.hpp"
#include "../includes/commands.hpp"

	/* ------------------------------------------------------------- */
	/* ------------------------ CONSTRUCTORS ----------------------- */	
	/* ------------------------------------------------------------- */

IrcServer::IrcServer(int port, std::string password) : _tcpServer(port), _server_password(password)
{
	this->create_pointer();
}

	/* ------------------------------------------------------------- */
	/* -------------------------- FUNCTIONS ------------------------ */	
	/* ------------------------------------------------------------- */

user 	*IrcServer::getUser(int fd)
{
	return (this->usersMap[fd]);
}

user	*IrcServer::getUserByNick(std::string nick)
{
	std::map<int, user*>::iterator	it;
	it = this->usersMap.begin();
	while (it != this->usersMap.end())
	{
		if (it->second->getNickName() == nick)
			return (it->second);
		it++;
	}
	return (NULL);
}

std::string		IrcServer::getServerPassword( void )
{
	return (this->_server_password);
}

// channels	*IrcServer::getChannel(std::string name)
// {
// 	std::map<std::string, channels *>::iterator	it;
// 	for(it = currentChannels.begin() ; it != currentChannels.end() ; it++)
// 	{
// 		if (it->first == name)
// 			return it->second;
// 	}
// 	return it->second;
// }



void    IrcServer::create_pointer(void)
{
    this->_pointer_to_valid_cmd.insert(std::make_pair("PASS", &cmd_pass));
    this->_pointer_to_valid_cmd.insert(std::make_pair("NICK", &cmd_nick));
    this->_pointer_to_valid_cmd.insert(std::make_pair("USER", &cmd_user));
    this->_pointer_to_valid_cmd.insert(std::make_pair("JOIN", &cmd_join));    
    // this->_pointer_to_valid_cmd.insert(std::make_pair("INVITE", &cmd_invite));
    // this->_pointer_to_valid_cmd.insert(std::make_pair("KICK", &cmd_kick));
    this->_pointer_to_valid_cmd.insert(std::make_pair("LIST", &cmd_list));
    this->_pointer_to_valid_cmd.insert(std::make_pair("MODE", &cmd_mode));
    this->_pointer_to_valid_cmd.insert(std::make_pair("MOTD", &cmd_motd));
    this->_pointer_to_valid_cmd.insert(std::make_pair("NAMES", &cmd_names));
    // this->_pointer_to_valid_cmd.insert(std::make_pair("NOTICE", &cmd_notice));
    // this->_pointer_to_valid_cmd.insert(std::make_pair("OPER", &cmd_oper));
    this->_pointer_to_valid_cmd.insert(std::make_pair("PART", &cmd_part));
    this->_pointer_to_valid_cmd.insert(std::make_pair("PING", &cmd_ping));
    this->_pointer_to_valid_cmd.insert(std::make_pair("PRIVMSG", &cmd_privmsg));
    this->_pointer_to_valid_cmd.insert(std::make_pair("QUIT", &cmd_quit));
    this->_pointer_to_valid_cmd.insert(std::make_pair("TOPIC", &cmd_topic));
    // this->_pointer_to_valid_cmd.insert(std::make_pair("WHO", &cmd_who));
}

IrcServer::command	IrcServer::recup_cmd ( std::string & command ) const
{
	std::map<std::string, IrcServer::command>::const_iterator	it;
	
	ft_strToupper(command);
	it = this->_pointer_to_valid_cmd.find(command);
	if (it != this->_pointer_to_valid_cmd.end())
		return (it->second);
	else
		return (&cmd_NULL);
}
			
void				IrcServer::deleteUser ( int fd)
{
	usersMap.erase(fd);
	delete usersMap[fd];
}