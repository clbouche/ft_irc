
#include "../includes/headers.hpp"
#include "../includes/commands.hpp"
#include "../includes/channels.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"


static bool		check_args(IrcServer *serv, user *currentUser, std::string & chan_name)
{
	//si le prefix du nom de channel n'est pas valide
	if ((strchr(CHANNEL_PREFIX, chan_name.c_str()[0]) == NULL))
	{
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
							send_replies(476, currentUser, serv)));
		return false;
	}
	return true;
}

void    cmd_kick( IrcServer *serv, user *currentUser, std::string & args )
{

	//ne pas oublier de gerer le commentaire a la fin 
	//avec find_last_of(" ") comme ca on recupere tout le reste dans rpl_msg
	channels		*channel;
    std::string		chan_name;
	std::string		userToKick;
	size_t			j = 0;
	size_t			pos = args.find_first_of(" ");
    std::string		chans = args.substr(0, pos);

    //si KICK n'a pas de nom de channel a quitter pour le user
	if (chans == "")
	{
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
		 					send_replies(461, currentUser, serv, "KICK")));
		return ;
	}

    std::string		            users;
	pos == std::string::npos ? users = "" : users = args.substr(pos + 1, args.size());
	std::vector<std::string>		split_channels = ft_split(chans, ",");
	std::vector<std::string>		split_users = ft_split(users, ",");

	std::vector<std::string>::iterator	it;
	for (it = split_channels.begin() ; it != split_channels.end(); it++)
	{
		chan_name = split_channels[j];
		j >= split_users.size() ? userToKick = split_users[0] : userToKick = split_users[j];
		
		serv->currentChannels.find(chan_name) == serv->currentChannels.end() ? 
			channel = NULL : channel = serv->currentChannels.find(chan_name)->second;
			
		if(check_args(serv, currentUser, chan_name) == true)
		{
			//tu envoie a part ou tu le geres ici ? 
		}
}