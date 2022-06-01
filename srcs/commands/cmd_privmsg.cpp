#include <vector>
#include <string>
#include "../includes/defines.hpp"
#include "../includes/utils.hpp"
#include "../includes/commands.hpp"
#include "../includes/channels.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"

void    cmd_privmsg(IrcServer *serv, user *currentUser, std::string & args)
{
    (void)serv;
    (void)currentUser;
	(void)args;
	std::cout << "ENTERING PRIVMSG FCT" << std::endl;
	if (strchr(CHANNEL_PREFIX, args.c_str()[0]) == NULL)
	{
		std::cout << "char :" << args.c_str()[0] << ":" << std::endl;
		std::cout << "char2 :" << args.c_str()[1] << ":" << std::endl;
		std::cout << "TARGET IS A USER" << std::endl;
	}
}