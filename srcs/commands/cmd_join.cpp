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
    // (void)args;

	args = "coco channel";
    std::cout << "enter in cmd_join" << std::endl;
    channels	*newChan = new channels(args, currentUser);
	serv->currentChannels.insert(std::make_pair(1, *newChan));
    std::cout << "CHANNEL NAME :" << serv->currentChannels.begin()->second.getName() << std::endl;
    std::cout << "quitting cmd_join" << std::endl;
}