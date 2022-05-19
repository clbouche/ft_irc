#include <vector>
#include <string>
#include "../includes/utils.hpp"
#include "../includes/commands.hpp"
#include "../includes/channels.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"

void    cmd_user( IrcServer *serv, user	currentUser, std::string & args )
{
	(void)serv;
	(void)currentUser;
	std::cout << "enter in cmd_user" << std::endl;
	std::cout << "args are : " << args << std::endl;
}