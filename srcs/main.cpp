/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:15:49 by clbouche          #+#    #+#             */
/*   Updated: 2022/05/25 18:07:00 by elaachac         ###   ########.fr       */
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
		server->_tcpServer.waiting_activity();
		server->_tcpServer.write_data(server->usersMap);
		buff = server->_tcpServer.listen_data();
		std::cout << buff.second  << "caca" << std::endl;
		if (buff.first != 0)
		{
			parse_cmd(buff.second, server, server->usersMap.find(buff.first)->second);
		}
	}
}

int main(int argc, char **argv)
{
	int port;
	std::string pass;
	
	if (argc >= 2 && argc < 4)
	{
		port = (argc >= 2) ? std::atoi(argv[1]) : PORT;
		// 	if (port <= 0 || port > 0xffff)
		// 	{
		// 		std::cerr << "Invalid port number\n";
		// 		return false;
		// 	}
		pass = (argc == 3) ? argv[2] : "";
	}
	else
	{
		std::cout << "Invalid number of arguments" << std::endl;
		return 1;
	}
	IrcServer   server(port, pass);
	
	loop(&server);

	return 0;
}

