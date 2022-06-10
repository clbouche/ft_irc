
#include "../includes/headers.hpp"
#include "../includes/commands.hpp"
#include "../includes/channels.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"

static bool		check_args(IrcServer *serv, user *currentUser, std::string & args)
{
	if (args == "")
	{
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), 
							send_replies(409, currentUser, serv)));
		return false;
	}
	if (args != serv->_tcpServer.getHostname())
	{
		std::cout << "ping servername is : [" << args << "]" << std::endl;
		std::cout << "good servername is : [" << serv->_tcpServer.getHostname() << "]" << std::endl;

		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), 
				send_replies(402, currentUser, serv, args)));
		return false;
	}
	return true;
}

void    cmd_ping( IrcServer *serv, user *currentUser, std::string & args )
{
	if (check_args(serv, currentUser, args) == true)
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), 
					"PONG " + args + "\r\n"));
}
