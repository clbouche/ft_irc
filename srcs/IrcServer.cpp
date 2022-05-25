/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IrcServer.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:04:27 by clbouche          #+#    #+#             */
/*   Updated: 2022/05/25 18:08:12 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/IrcServer.hpp"
#include "../includes/tcpServer.hpp"
#include "../includes/user.hpp"
#include "../includes/commands.hpp"
#include <iostream>


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
    this->_pointer_to_valid_cmd.insert(std::make_pair("USER\n", &cmd_user));
    this->_pointer_to_valid_cmd.insert(std::make_pair("PASS\n", &cmd_pass));
    this->_pointer_to_valid_cmd.insert(std::make_pair("NICK\n", &cmd_nick));
    this->_pointer_to_valid_cmd.insert(std::make_pair("JOIN\n", &cmd_join));
}

/**
 * @todo ERASE : split_args.begin() pour ne garder que les arguments de la commande a la fonction.
 * 
 */
IrcServer::command	IrcServer::recup_cmd ( const std::string & command ) const
{
	std::map<std::string, IrcServer::command>::const_iterator	it;

	it = this->_pointer_to_valid_cmd.find(command);
    if (it != this->_pointer_to_valid_cmd.end())
        return (it->second);
	else
        return (&cmd_NULL);
}
            