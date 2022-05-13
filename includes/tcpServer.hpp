#ifndef TCPSERVER_HPP
# define TCPSERVER_HPP

# include "config.hpp"
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

		std::string						_hostname;
		int 							_masterSocket , _clientSocket[MAX_CLIENTS];
		fd_set							_readfds;
		struct		sockaddr_in			_address;
		/* usage of a multimap (map where we can have one key in more than one leaf)*/
		/*					to store the client's inputs 							*/
		std::multimap<int, std::string>	_buffer_out;
	
	public:
		
		/*default constructor*/
		tcpServer();
		/*port setter constructor*/
		tcpServer(int	port = PORT);
};

#endif