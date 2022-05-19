/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcpServer.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 10:18:32 by claclou           #+#    #+#             */
/*   Updated: 2022/05/19 18:09:20 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/tcpServer.hpp"
#include <iostream>
#include <sys/time.h>

	/* ------------------------------------------------------------- */
	/* ------------------------ CONSTRUCTORS ----------------------- */	
	/* ------------------------------------------------------------- */

tcpServer::tcpServer()
{

}

tcpServer::tcpServer(int port)
{
	int opt = TRUE;
	// char hostname[1024];

	std::memset(&this->_clientSocket, 0, MAX_CLIENTS * sizeof(int));//set the memory for clients socket

	//create the socket for the server (master socket)
	if((this->_masterSocket = socket(AF_INET , SOCK_STREAM , 0)) == 0)
	{
		std::cerr << std::strerror(errno) << std::endl;
		exit(EXIT_FAILURE);
	}

	//set the server's socker to receive multiple connections
	if(setsockopt(this->_masterSocket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) < 0)
	{
		std::cerr << std::strerror(errno) << std::endl;
		exit(EXIT_FAILURE);
	}

	//type of socket created
	_address.sin_family = AF_INET;
	_address.sin_addr.s_addr = INADDR_ANY;
	_address.sin_port = htons( PORT );

	//bind the socket to localhost port 8888
	if (bind(_masterSocket, (struct sockaddr *)&_address, sizeof(_address)) < 0)
	{
		std::cerr << std::strerror(errno) << std::endl;
		exit(EXIT_FAILURE);
	}
	std::cout << "Listener on port " << port << std::endl;

	//try to specify maximum of 3 pending connections for the master socket
	if (listen(_masterSocket, MAX_CLIENTS) < 0)
	{
		std::cerr << std::strerror(errno) << std::endl;
		exit(EXIT_FAILURE);
	}

	//accept the incoming connection
	std::cout << "Waiting for connections ..." << std::endl;
}

		/* ------------------------------------------------------------- */
		/* ------------------------- FUNCTIONS ------------------------- */	
		/* ------------------------------------------------------------- */

void	tcpServer::waiting_activity(std::map<int, user> *usersMap)
{
	int 	max_sd, activity;

	//clear the socket set comme bzero mais pour un fd !
	FD_ZERO(&_readfds);

	//add master socket to set
	FD_SET(_masterSocket, &_readfds);
	max_sd = _masterSocket;

	//add child sockets to set
	for ( int i = 0 ; i < MAX_CLIENTS ; i++)
	{
		//socket descriptor
		user	*newUser = new user(_clientSocket[i]) ;
		usersMap->insert(std::make_pair(_clientSocket[i], *newUser));

		//if valid socket descriptor then add to read list
		if(newUser->getSdUser() > 0)
			FD_SET( newUser->getSdUser() , &_readfds);

		//highest file descriptor number, need it for the select function
		if(newUser->getSdUser() > max_sd)
			max_sd = newUser->getSdUser();
	}

	//wait for an activity on one of the sockets , timeout is NULL ,
	//so wait indefinitely
	activity = select( max_sd + 1 , &_readfds , NULL , NULL , NULL);

	if ((activity < 0) && (errno!=EINTR))
		std::cout << "select error" << std::endl;
}

void	tcpServer::write_data(void)
{
	int 	new_socket;
	const char 	*message = WELCOME_MESSAGE;
	int		_addrlen = sizeof(_address);


	//If something happened on the master socket ,
	//then its an incoming connection
	if (FD_ISSET(_masterSocket, &_readfds))
	{
		if ((new_socket = accept(_masterSocket,
				(struct sockaddr *)&_address, (socklen_t*)&_addrlen))<0)
		{
			std::cerr << std::strerror(errno) << std::endl;
			exit(EXIT_FAILURE);
		}

		//inform user of socket number - used in send and receive commands
		std::cout << "New connection, socket fd is " << new_socket << ", ip is : " << inet_ntoa(_address.sin_addr)
			<< ", port : " << ntohs(_address.sin_port) << std::endl; 

		//send new connection greeting message
		if( send(new_socket, message, strlen(message), 0) != (ssize_t)strlen(message) )
		{
			std::cerr << std::strerror(errno) << std::endl;
		}

		std::cout << "Welcome message sent successfully" << std::endl;

		//add new socket to array of sockets
		for (int i = 0; i < MAX_CLIENTS; i++)
		{
			//if position is empty
			if(_clientSocket[i] == 0 )
			{
				_clientSocket[i] = new_socket;
				std::cout << "Adding to list of sockets as " << i << std::endl;

				break;
			}
		}
	}

}

std::pair<int, std::string>		tcpServer::listen_data(void)
{
	int 	sd, valread;
	char 	buffer[1025];
	int		_addrlen = sizeof(_address);


	//else its some IO operation on some other socket
	for (int i = 0; i < MAX_CLIENTS; i++)
	{
		sd = _clientSocket[i];

		if (FD_ISSET( sd , &_readfds))
		{
			//Check if it was for closing , and also read the
			//incoming message
			if ((valread = read( sd , buffer, 1024)) == 0)
			{
				//Somebody disconnected , get his details and print
				getpeername(sd , (struct sockaddr*)&_address , \
					(socklen_t*)&_addrlen);
				std::cout << "Host disconnected, ip " << inet_ntoa(_address.sin_addr) << " , port " << ntohs(_address.sin_port) << std::endl;

				//Close the socket and mark as 0 in list for reuse
				close( sd );
				_clientSocket[i] = 0;
				return (std::make_pair(sd, std::string("Disconnected\n")));
			}

			//Echo back the message that came in
			else
			{
				//set the string terminating NULL byte on the end of the data read
				buffer[valread] = '\0';
				return (std::make_pair(sd, std::string(buffer)));
			}
		}
	}
	return (std::make_pair(sd, std::string("")));
}

