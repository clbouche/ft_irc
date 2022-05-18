/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:15:49 by clbouche          #+#    #+#             */
/*   Updated: 2022/05/18 10:19:54 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/config.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"
#include "../includes/commands.hpp"

/**
 * @brief attendre l'implementation de la map Users dans IRC pour pouvoir recuperer le socket
 * 
 */

void    loop(IrcServer *server)
{
    std::pair<int, std::string>    buff;
    
    while(TRUE)
    { 
		server->_tcpServer.waiting_activity(&(server->usersMap));
        server->_tcpServer.write_data();
        buff = server->_tcpServer.listen_data();
        std::cout << "SD :" << server->usersMap.find(buff.first)->second.getSdUser() << ":" << std::endl;
        parse_cmd(buff.second, server, server->usersMap.find(buff.first)->second.getSdUser()); // ici on recupere le sd mais seulement pour des teste, on veut recuperer le user (enlever .sdUser)
    }
}

int main(int argc, char **argv)
{
    int port = (argc >= 2) ? std::atoi(argv[1]) : PORT;
    
    IrcServer   server(port);

    loop(&server);

    return 0;
}