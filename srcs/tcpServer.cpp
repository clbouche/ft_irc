#include	"../includes/tcpServer.hpp"

	/********************************/
	/*			CONSTRUCTORS		*/
	/********************************/

tcpServer::tcpServer()
{
}

tcpServer::tcpServer(int port)
{
	int opt = 1;
	char hostname[1024];

	std::memset(&this->_clientSocket, 0, MAX_CLIENTS * sizeof(int));//set the memory for clients socket

	//create the socket for the server
	if((this->_masterSocket = socket(AF_INET , SOCK_STREAM , 0)) == 0)
	{
		perror("master socket failed");
		exit(EXIT_FAILURE);
	}

	//set the server's socker to receive multiple connections
	if(setsockopt(this->_masterSocket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) < 0)
	{
		perror("master setsockopt failed");
		exit(EXIT_FAILURE);
	}
}