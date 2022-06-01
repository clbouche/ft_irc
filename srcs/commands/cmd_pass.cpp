#include <vector>
#include <string>
#include "../../includes/utils.hpp"
#include "../../includes/commands.hpp"
#include "../../includes/channels.hpp"
#include "../../includes/IrcServer.hpp"
#include "../../includes/user.hpp"

void    cmd_pass( IrcServer *serv, user	*currentUser, std::string & args )
{
	if (args == serv->getServerPassword())
		currentUser->setCheckPassword(true);
}