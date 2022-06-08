#include <vector>
#include <string>
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
    // size_t          pos = args.find_first_of(" :");
    // std::string     msg;
    // pos == std::string::npos ? msg = "left" = args.substr(pos + , args.length());

}
