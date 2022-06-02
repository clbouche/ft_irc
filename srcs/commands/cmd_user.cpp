#include <vector>
#include <string>
#include "../includes/headers.hpp"
#include "../includes/commands.hpp"
#include "../includes/channels.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"

static bool		check_args(IrcServer *serv, user *currentUser, std::string args)
{
	if (args.size() < 4)
	{
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), send_replies(461, currentUser, serv, "USER")));
		return false;
	}
	return true;
}

//si le user est deja set, ne pas changer le user, juste sortir de la fonction et rapporter une error
void    cmd_user( IrcServer *serv, user	*currentUser, std::string & args )
{
	std::vector<std::string>	split_args;

	if (check_args(serv, currentUser, args) == true)
	{
		split_args = ft_split(args, ":");
		currentUser->setRealName(split_args[1]);
		split_args = ft_split(args, " ");
		currentUser->setUserName(split_args[0]);
		currentUser->setMode(split_args[1]);
	}
}