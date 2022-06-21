
#include "../includes/headers.hpp"
#include "../includes/commands.hpp"
#include "../includes/channels.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"

/**
Command: LIST
   Parameters: [ <channel> *( "," <channel> ) [ <target> ] ]

   The list command is used to list channels and their topics.  If the
   <channel> parameter is used, only the status of that channel is
   displayed.

   If the <target> parameter is specified, the request is forwarded to
   that server which will generate the reply.

   Wildcards are allowed in the <target> parameter.

   Numeric Replies:

           ERR_TOOMANYMATCHES              ERR_NOSUCHSERVER
           RPL_LIST                        RPL_LISTEND

   Examples:

   LIST                            ; Command to list all channels.

   LIST #twilight_zone,#42         ; Command to list channels
                                   #twilight_zone and #42
 */

void	listAllChans(IrcServer *serv, user *currentUser)
{
	std::map<std::string, channels *>::iterator	it;

	for(it = serv->currentChannels.begin() ; it != serv->currentChannels.end() ; it++)
	{
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
					send_replies(322, currentUser, serv, (*it).second->getName(),
					(*it).second->getTopic())));
	}
	serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
			send_replies(323, currentUser, serv)));
}

void    cmd_list( IrcServer *serv, user *currentUser, std::string & args )
{
	std::vector<std::string>		split_args = ft_split(args, " ");
	std::string						chan_name;
	channels						*chan;
	size_t							j = 0;

    //si LIST n'a pas d'argument, on liste toutes les channels + topics
	if (split_args.size() == 0)
    {
        listAllChans(serv, currentUser);
		return ;
    }
	if (split_args.size() == 2)
	{
		//si le nom donne n'est pas le serveur actuel, ERR
		if (serv->_tcpServer.getHostname() != split_args[1])
		{
			serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
				send_replies(402, currentUser, serv, split_args[1])));
			return ;
		}
	}
	//si le serveur est correct ou qu'il n'a pas ete cite :
	std::vector<std::string>						split_chans = ft_split(split_args[0], ",");
	std::vector<std::string>::iterator				it;
	std::map<std::string, channels *>::iterator		ite;

	for(it = split_chans.begin(); it != split_chans.end(); it++)
	{
		chan_name = split_chans[j];
		serv->currentChannels.find(chan_name) == serv->currentChannels.end() ? 
				chan = NULL : chan = serv->currentChannels.find(chan_name)->second;
			if (chan != NULL)
			{
				serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
							send_replies(322, currentUser, serv, chan->getName(),
							chan->getTopic())));
			}
	}
	serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
							send_replies(323, currentUser, serv)));
}