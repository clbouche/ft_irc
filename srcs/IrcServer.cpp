/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IrcServer.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:04:27 by clbouche          #+#    #+#             */
/*   Updated: 2022/05/19 13:24:33 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/IrcServer.hpp"
#include "../includes/tcpServer.hpp"
#include "../includes/user.hpp"
#include "../includes/commands.hpp"
#include "../includes/utils.hpp"
#include <iostream>
#include <vector>

	/* ------------------------------------------------------------- */
	/* ------------------------ CONSTRUCTORS ----------------------- */	
	/* ------------------------------------------------------------- */

IrcServer::IrcServer(int port, std::string password) : _tcpServer(port), _server_password(password)
{
    std::cout << "constructor of IRC" << std::endl;

    this->create_pointer();
}

	/* ------------------------------------------------------------- */
	/* -------------------------- FUNCTIONS ------------------------ */	
	/* ------------------------------------------------------------- */

void    IrcServer::create_pointer(void)
{
    this->_pointer_to_valid_cmd.insert(std::make_pair("USER", &cmd_user));
    this->_pointer_to_valid_cmd.insert(std::make_pair("PASS", &cmd_pass));
    this->_pointer_to_valid_cmd.insert(std::make_pair("NICK", &cmd_nick));
}

/**
 * @todo ERASE : split_args.begin() pour ne garder que les arguments de la commande a la fonction.
 * 
 */
IrcServer::command	IrcServer::recup_cmd ( const std::string & args ) const
{
	std::vector<std::string>	split_args = ft_split(args, " ");
	const std::string	command = split_args.front();
	std::map<std::string, IrcServer::command>::const_iterator	it;

	it = this->_pointer_to_valid_cmd.find(command);
    if (it != this->_pointer_to_valid_cmd.end())
        return (it->second);
	else
        return (&cmd_NULL);
}