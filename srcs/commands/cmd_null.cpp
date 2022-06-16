
#include "../includes/headers.hpp"
#include "../includes/commands.hpp"
#include "../includes/channels.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"

void    cmd_NULL( IrcServer *serv, user	*currentUser, std::string & args )
{
	serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
						send_replies(421, currentUser, serv, args)));
}