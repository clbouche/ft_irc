/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:15:49 by clbouche          #+#    #+#             */
/*   Updated: 2022/06/16 18:28:19 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"
#include "../includes/commands.hpp"

sig_atomic_t	g_looping = true;
int				g_main_socket;

void    loop(IrcServer *server)
{
	std::pair<int, std::string>		buff;
	std::string						args = "";
	std::string						oldBuff = "";
	
	while(g_looping)
	{ 
		server->_tcpServer.waiting_activity();
		server->_tcpServer.write_data(&(server->usersMap));
		buff = server->_tcpServer.listen_data();
		buff.second = oldBuff.append(buff.second);
		if (buff.second.find('\n') != std::string::npos)
		{
			oldBuff = "";
			if (g_looping && buff.first != 0)
			{
				if (server->getServerPassword() == "")
					server->getUser(buff.first)->setCheckPassword(true);
				parse_cmd(buff.second, server, server->getUser(buff.first));
				if (server->getUser(buff.first) != 0 && server->getUser(buff.first)->getWelcomeMsg() == false)
				{
					server->getUser(buff.first)->setWelcomeMsg(
						check_connexion(server->getUser(buff.first), server));
				}
			}
		}
		if (g_looping)
			server->_tcpServer.send_buff();
	}
}

void sigterm(int signo) {
	(void)signo;
	g_looping = false;
	send(g_main_socket, "\r\n", 2, MSG_NOSIGNAL);
}

int main(int argc, char **argv)
{
	int port;
	std::string pass;
	
	if (argc >= 2 && argc < 4)
	{
		port = (argc >= 2) ? std::atoi(argv[1]) : PORT;
		pass = (argc == 3) ? argv[2] : "";
	}
	else
	{
		std::cout << "Invalid number of arguments" << std::endl;
		return 1;
	}
	IrcServer   server(port, pass);
	
	g_main_socket = server._tcpServer.getMainSocket();
	struct sigaction s;
	s.sa_handler = sigterm;
	sigemptyset(&s.sa_mask);
	s.sa_flags = 0;
	sigaction(SIGINT, &s, NULL);

	loop(&server);

	return 0;
}

