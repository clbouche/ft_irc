/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IrcServer.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:04:27 by clbouche          #+#    #+#             */
/*   Updated: 2022/06/01 12:28:26 by elaachac         ###   ########.fr       */
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

void    IrcServer::create_pointer(void)
{
    this->_pointer_to_valid_cmd.insert(std::make_pair("PASS", &cmd_pass));
    this->_pointer_to_valid_cmd.insert(std::make_pair("NICK", &cmd_nick));
    this->_pointer_to_valid_cmd.insert(std::make_pair("USER", &cmd_user));
    this->_pointer_to_valid_cmd.insert(std::make_pair("JOIN", &cmd_join));
    // this->_pointer_to_valid_cmd.insert(std::make_pair("ADMIN", &cmd_admin));
    // this->_pointer_to_valid_cmd.insert(std::make_pair("AWAY", &cmd_away));
    // this->_pointer_to_valid_cmd.insert(std::make_pair("DIE", &cmd_die));
    // this->_pointer_to_valid_cmd.insert(std::make_pair("INVITE", &cmd_invite));
    // this->_pointer_to_valid_cmd.insert(std::make_pair("KICK", &cmd_kick));
    // this->_pointer_to_valid_cmd.insert(std::make_pair("KILL", &cmd_kill));
    // this->_pointer_to_valid_cmd.insert(std::make_pair("LIST", &cmd_list));
    // this->_pointer_to_valid_cmd.insert(std::make_pair("MODE", &cmd_mode));
    // this->_pointer_to_valid_cmd.insert(std::make_pair("MOTD", &cmd_motd));
    // this->_pointer_to_valid_cmd.insert(std::make_pair("NAMES", &cmd_names));
    // this->_pointer_to_valid_cmd.insert(std::make_pair("NICK", &cmd_nick));
    // this->_pointer_to_valid_cmd.insert(std::make_pair("NOTICE", &cmd_notice));
    // this->_pointer_to_valid_cmd.insert(std::make_pair("OPER", &cmd_oper));
    // this->_pointer_to_valid_cmd.insert(std::make_pair("PART", &cmd_part));
    // this->_pointer_to_valid_cmd.insert(std::make_pair("PING", &cmd_ping));
    this->_pointer_to_valid_cmd.insert(std::make_pair("PRIVMSG", &cmd_privmsg));
    // this->_pointer_to_valid_cmd.insert(std::make_pair("QUIT", &cmd_quit));
    // this->_pointer_to_valid_cmd.insert(std::make_pair("TIME", &cmd_time));
    // this->_pointer_to_valid_cmd.insert(std::make_pair("TOPIC", &cmd_topic));
    // this->_pointer_to_valid_cmd.insert(std::make_pair("VERSION", &cmd_version));
    // this->_pointer_to_valid_cmd.insert(std::make_pair("WHO", &cmd_who));
}

IrcServer::command	IrcServer::recup_cmd ( const std::string & command ) const
{
	std::map<std::string, IrcServer::command>::const_iterator	it;

	it = this->_pointer_to_valid_cmd.find(command);
    if (it != this->_pointer_to_valid_cmd.end())
        return (it->second);
	else
        return (&cmd_NULL);
}
            
std::string		IrcServer::getServerPassword( void )
{
    return (this->_server_password);
}
