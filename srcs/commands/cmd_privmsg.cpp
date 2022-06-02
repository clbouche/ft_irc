#include <vector>
#include <string>
#include "../includes/headers.hpp"
#include "../includes/commands.hpp"
#include "../includes/channels.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"

void    cmd_privmsg( IrcServer *serv, user *currentUser, std::string & args )
{
    (void)serv;
    (void)currentUser;
	(void)args;
	std::cout << "ENTERING PRIVMSG FCT" << std::endl;
}