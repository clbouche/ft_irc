#include <vector>
#include <string>
#include "../includes/headers.hpp"
#include "../includes/commands.hpp"
#include "../includes/channels.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"

void    cmd_quit( IrcServer *serv, user *currentUser, std::string & args )
{
    std::cout << "enter in function quit" << std::endl;
    (void)serv;
    (void)currentUser;
	(void)args;
}
