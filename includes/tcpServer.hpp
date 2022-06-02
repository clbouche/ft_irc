/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcpServer.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:39:52 by elaachac          #+#    #+#             */
/*   Updated: 2022/06/02 11:14:48 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TCPSERVER_HPP
# define TCPSERVER_HPP

# include "config.hpp"
# include "user.hpp"
# include <netdb.h>
# include <unistd.h>
# include <arpa/inet.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <sys/time.h>
# include <algorithm>
# include <string>
# include <cstring>
# include <unistd.h>
# include <cerrno>
# include <map>

class tcpServer
{
	private:

		std::string							_hostname;
		int 								_masterSocket , _clientSocket[MAX_CLIENTS]; //, _addrlen;
		fd_set								_readfds;
		struct sockaddr_in					_address;
		/* usage of a multimap (map where we can have one key in more than one leaf)*/
		/*					to store the client's inputs 							*/
		std::multimap<int, std::string>		_buff_out;
	
	public:
		
		/**
		 * @brief Construct a new tcp Server object
		 * 
		 */
		tcpServer();

		/**
		 * @brief Construct a new tcp Server object with port setter
		 * 
		 * @param port 
		 */
		tcpServer(int port = PORT);

		/**
		 * @brief bzero clients and waiting for new connexions
		 * 
		 */
		void							waiting_activity();

		/**
		 * @brief for new connexions
		 * 
		 */
		void							write_data(std::map<int, user*> *usersMap);

		/**
		 * @brief for disconnexion and send messages
		 * 
		 */
		std::pair<int, std::string>		listen_data(void);

		/**
		 * @brief To send replies or errors
		 * 
		 */
		void							add_to_buffer (std::pair<int, std::string> buff);

		/**
		 * @brief Send and flush everything in the buffer
		 */
		void							send_buff (void);


};

#endif