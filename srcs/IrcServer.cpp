/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IrcServer.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:04:27 by clbouche          #+#    #+#             */
/*   Updated: 2022/05/17 14:07:35 by elaachac         ###   ########.fr       */
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

IrcServer::IrcServer(int port) : _tcpServer(port)
{
    std::cout << "constructor of IRC" << std::endl;

    this->create_pointer();
}

void    IrcServer::create_pointer(void)
{
    this->_pointer_to_valid_cmd.insert(std::make_pair("USER", &cmd_user));
    this->_pointer_to_valid_cmd.insert(std::make_pair("PASS", &cmd_pass));
    this->_pointer_to_valid_cmd.insert(std::make_pair("NICK", &cmd_nick));
}


IrcServer::function_for_cmd     IrcServer::recup_cmd(std::string cmd)
{
    std::map<std::string, IrcServer::function_for_cmd>::const_iterator    it;
    it = this->_pointer_to_valid_cmd.find(cmd);
    return (it->second);
}