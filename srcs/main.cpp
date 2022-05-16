/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:15:49 by clbouche          #+#    #+#             */
/*   Updated: 2022/05/16 18:19:56 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/config.hpp"
#include "../includes/IrcServer.hpp"

void    loop(IrcServer *server)
{
    int     max_sd;
    char    *buff;
    
    while(TRUE)
    { 
		server->_tcpServer.waiting_activity();
        server->_tcpServer.write_data();
        buff = server->_tcpServer.listen_data();
        server->parse_cmd(buff, server);
    }

}

int main(int argc, char **argv)
{
    int port = (argc >= 2) ? std::atoi(argv[1]) : PORT;
    
    IrcServer   server(port);

    loop(&server);

    return 0;
}