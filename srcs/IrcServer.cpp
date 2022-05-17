/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IrcServer.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:04:27 by clbouche          #+#    #+#             */
/*   Updated: 2022/05/17 14:48:14 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/IrcServer.hpp"
#include "../includes/tcpServer.hpp"
#include "../includes/commands.hpp"
#include <iostream>

	/* ------------------------------------------------------------- */
	/* ------------------------ CONSTRUCTORS ----------------------- */	
	/* ------------------------------------------------------------- */

IrcServer::IrcServer(int port) : _tcpServer(port)
{
    std::cout << "constructor of IRC" << std::endl;

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
}


IrcServer::command	IrcServer::recup_cmd ( const std::string & command ) const
{
	std::map<std::string, IrcServer::command>::const_iterator	it;

    std::cout << "command = " << command << std::endl;
    // std::cout << "my command = " << it->first << std::endl;
    std::cout << "my command = " << this->_pointer_to_valid_cmd.begin()->first << std::endl;
	it = this->_pointer_to_valid_cmd.find(command);
    // std::cout << "it->second = " << it->second << std::endl;
    // std::cout << "it->first : " << it->first << 
    if (it != this->_pointer_to_valid_cmd.end())
        return (it->second);
	else
        return (&cmd_NULL);
}