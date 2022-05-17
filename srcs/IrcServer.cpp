/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IrcServer.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:04:27 by clbouche          #+#    #+#             */
/*   Updated: 2022/05/17 12:09:38 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/IrcServer.hpp"
#include "../includes/tcpServer.hpp"
#include <iostream>

	/* ------------------------------------------------------------- */
	/* ------------------------ CONSTRUCTORS ----------------------- */	
	/* ------------------------------------------------------------- */

IrcServer::IrcServer(int port) : _tcpServer(port)
{
    std::cout << "constructor of IRC" << std::endl;

    _command[0] = "PASS\n";
    _command[1] = "NICK\n";
    _command[2] = "USER\n";
}

void    IrcServer::pass(void)
{
    std::cout << "enter in function PASS" << std::endl;
}

void    IrcServer::nick(void)
{
    std::cout << "enter in function NICK" << std::endl;
}

void    IrcServer::user(void)
{
    std::cout << "enter in function USER" << std::endl;
}

void    IrcServer::parse_cmd(char *cmd, IrcServer *server)
{
    // std::cout << "_command[0] : " << _command[0] << std::endl;
    // std::cout << "_command[1] : " << _command[1] << std::endl;
    // std::cout << "_command[2] : " << _command[2] << std::endl;

    // std::cout << "enter in parse cmd with : " << cmd << std::endl;
    void	(IrcServer::*func[3])(void) = {
            &IrcServer::pass,
            &IrcServer::nick,
            &IrcServer::user,
        };

        for (int i = 0; i < 3; i++)
        {
            // std::cout << "cmd = " << "[" << cmd << "]"<< std::endl;
        //     std::cout << "_cmd[i] = " << "[" << _command[i] << "]" << std::endl;
            if (cmd == _command[i])
            {
                (this->*func[i])();
                return ;
            }
        }
        return ;
    
}
