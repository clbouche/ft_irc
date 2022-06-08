#include <vector>
#include <string>
#include "../includes/headers.hpp"
#include "../includes/commands.hpp"
#include "../includes/channels.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"
#include "../includes/utils.hpp"


static bool check_args(std::string target, std::string mode, std::string modeParams, user *currentUser, IrcServer *serv)
{
	(void)modeParams;
	(void)mode;
	(void)currentUser;
	(void)serv;
	if (target == "")
	{
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), send_replies(461, currentUser, serv, "MODE")));
		return (false);
		// ERR_NEEDMOREPARAMS 461
	}
		return (true);
}

void    cmd_mode( IrcServer *serv, user *currentUser, std::string & args )
{
	(void)serv;
	(void)currentUser;
	(void)args;
   	size_t		pos = args.find_first_of(" ");
	std::string target = args.substr(0, pos);
	std::string tmp = args.substr(pos + 1, args.length());
   	size_t		tmpPos = tmp.find_first_of(" ");
	std::string mode;
	std::string modeParams = "";

	user	*userTarget = serv->getUserByNick(target);
	if (userTarget == NULL)
	{
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), send_replies(502, currentUser, serv)));
		return ;
	}

	pos == std::string::npos ? mode = "" : mode = args.substr(pos + 1 - mode.length(), tmpPos);
	tmpPos == std::string::npos ? modeParams = "" : modeParams = tmp.substr(tmpPos + 1, tmp.length());
	
	// std::cout << "TARGET : {" << target << "}" << std::endl << "MODE : {" << mode << "}" << std::endl << "MODEPARAMS : {" << modeParams << "}" << std::endl;

	if (check_args(target, mode, modeParams, currentUser, serv))
	{
		if (strchr(CHANNEL_PREFIX, target.c_str()[0]) != NULL)
		{
			std::cout << "TARGET IS A CHANNEL" << std::endl;
		}
		else
		{
			if (mode.c_str()[0] == '+')
			{
				userTarget->setMode(mode);
			}
			else
			{
				//FAIRE UN AUTRE BAIL
			}
			serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), send_replies(221, currentUser, serv, currentUser->getMode())));
		}
	}
}