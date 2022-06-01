#include "../includes/headers.hpp"
#include "../includes/utils.hpp"
#include "../includes/commands.hpp"
#include "../includes/channels.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"

void    cmd_privmsg(IrcServer *serv, user *currentUser, std::string & args)
{
	(void)serv;
	(void)currentUser;
	// On determine d'abord si on a un seul user ou un channel
	// si channel, on stock les users devant recevoir le message dans une stack
	// on envoie ensuite le message dans une boucle telle que :
	// tant que stack.size != 0:
	//      send msg a stack.top()   -> send msg a user
	//		stack.pop()    -> supprimer le user a qui on vient de send msg de la stack
	//
	// Si on a qu'un seul user : 
	// send directement msg a user
	size_t		pos = args.find_first_of(" ");
	std::string	target = args.substr(0, pos);
	std::string	msg = args.substr(pos + 1, args.length());
	
	std::cout << "ENTERING PRIVMSG FCT" << std::endl;
	std::cout << "target :{" << target << "}" << std::endl;
	std::cout << "msg :{" << msg << "}" << std::endl;

	if (strchr(CHANNEL_PREFIX, args.c_str()[0]) != NULL)
	{
		// std::cout << "char :" << args.c_str()[0] << ":" << std::endl;
		std::cout << "TARGET IS A CHANNEL" << std::endl;
		channels 
		std::stack<user> receiving;

	}
	else
	{
		std::cout << "TARGET IS A USER" << std::endl;
	}
	
}