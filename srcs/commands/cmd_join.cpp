#include <vector>
#include <string>
#include "../../includes/utils.hpp"
#include "../../includes/commands.hpp"
#include "../../includes/channels.hpp"
#include "../../includes/IrcServer.hpp"
#include "../../includes/user.hpp"

void    cmd_join( IrcServer *serv, user	*currentUser, std::string & args )
{
    (void)serv;
    (void)currentUser;
    (void)args;

    std::cout << "enter in cmd_join" << std::endl;
    std::cout << "args:" << args << ":" << std::endl;
	if (args == "")
	{
		args = "#coco_channel";
    	channels	*newChan = new channels(args, currentUser);
		serv->currentChannels.insert(std::make_pair(args	, *newChan));
    	std::cout << "CHANNEL NAME :" << serv->currentChannels.begin()->second.getName() << std::endl;
	}
	serv->currentChannels.begin()->second.addUser(*currentUser);
    std::cout << "quitting cmd_join" << std::endl;
}