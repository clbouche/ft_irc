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
	// On determine d'abord si on a un seul user ou un channel
	// si channel, on stock les users devant recevoir le message dans une stack
	// on envoie ensuite le message dans une boucle telle que :
	// tant que stack.size != 0:
	//      send msg a stack.top()   -> send msg a user
	//		stack.pop()    -> supprimer le user a qui on vient de send msg de la stack
	//
	// Si on a qu'un seul user : 
	// send directement msg a user
	
	std::cout << "ENTERING PRIVMSG FCT" << std::endl;
	if (strchr(CHANNEL_PREFIX, args.c_str()[0]) == NULL)
	{
		std::cout << "char :" << args.c_str()[0] << ":" << std::endl;
		std::cout << "char2 :" << args.c_str()[1] << ":" << std::endl;
		std::cout << "TARGET IS A USER" << std::endl;
	}
	
}