#include <vector>
#include <string>
#include "../includes/utils.hpp"
#include "../includes/commands.hpp"
#include "../includes/channels.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"

void    cmd_privmsg( IrcServer *serv, user *currentUser, std::string & args )
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

}