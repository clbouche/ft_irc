/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:15:49 by clbouche          #+#    #+#             */
/*   Updated: 2022/05/17 16:34:27 by elaachac         ###   ########.fr       */
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
        // if (buff.first != NULL)
        // {
            // if (buff.second == "Disconnected\n")
                // return ;
            // else
            std::cout << "SD :" << server->usersMap.find(buff.first)->second.getSdUser() << ":" << std::endl;
                parse_cmd(buff.second, server, server->usersMap.find(buff.first)->second.getSdUser()); // ici on recupere le sd mais seulement pour des teste, on veut recuperer le user (enlever .sdUser)
        		// parse_cmd(buff.second, server, 0);
        // }
        // parse_cmd(buff.second, server, buff.first);
    }
}

int main(int argc, char **argv)
{
    int port = (argc >= 2) ? std::atoi(argv[1]) : PORT;
    
    IrcServer   server(port);

    loop(&server);

    return 0;
}