/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:15:49 by clbouche          #+#    #+#             */
/*   Updated: 2022/05/17 13:46:18 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/config.hpp"
#include "../includes/IrcServer.hpp"
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
		server->_tcpServer.waiting_activity();
        server->_tcpServer.write_data();
        buff = server->_tcpServer.listen_data();
        // if (buff.first != NULL)
        // {
            // if (buff.second == "Disconnected\n")
                // return ;
            // else
        		parse_cmd(buff.second, server, 0);
        // }
    }

}

int main(int argc, char **argv)
{
    int port = (argc >= 2) ? std::atoi(argv[1]) : PORT;
    
    IrcServer   server(port);

    loop(&server);

    return 0;
}