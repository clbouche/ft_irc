
#include "../includes/headers.hpp"
#include "../includes/commands.hpp"
#include "../includes/channels.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"

void    cmd_quit( IrcServer *serv, user *currentUser, std::string & args )
{
    (void)serv;
    (void)currentUser;
    (void)args;
    std::string     msg;
    if (args == "" || args.find_first_of(":") == std::string::npos)
        msg = "left";
    
    //retirer l'tilisateur de tous les channels 
    //supprimer l'appartenance au socket
    //envoyer le msg aux autres users
}
