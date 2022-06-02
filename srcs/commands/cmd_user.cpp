#include <vector>
#include <string>
#include "../includes/headers.hpp"
#include "../includes/commands.hpp"
#include "../includes/channels.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"


//si le user est deja set, ne pas changer le user, juste sortir de la fonction et rapporter une error
void    cmd_user( IrcServer *serv, user	*currentUser, std::string & args )
{
	(void)serv;
	std::cout << "enter in cmd_user" << std::endl;
	std::cout << "args are : " << args << std::endl;
	
	std::vector<std::string>	split_args = ft_split(args, " ");
	std::string					username = split_args.front().c_str();

	currentUser->setUserName(username);
}