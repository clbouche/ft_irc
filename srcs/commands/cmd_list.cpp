
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

static void		listSelectedChans(IrcServer *serv, user *currentUser, std::vector<std::string> listOfChans)
{
	std::map<int, user *>::iterator		ite;
	std::string							rpl_list;

	for (size_t i = 0; i < listOfChans.size(); i++)
	{
		channels		*chan;
		serv->currentChannels.find(listOfChans[i]) == serv->currentChannels.end() ?
				chan = NULL : chan = serv->currentChannels.find(listOfChans[i])->second;
		if (chan != NULL)
		{
			serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
						send_replies(322, currentUser, serv, chan->getName(),
						chan->getTopic())));
		}
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
							send_replies(323, currentUser, serv)));
	}
}

void    cmd_list( IrcServer *serv, user *currentUser, std::string & args )
{
    //si LIST n'a pas d'argument, on liste toutes les channels + topics
	if (args == "")
        listAllChans(serv, currentUser);
	else
	{
		std::vector<std::string>		split_args = ft_split(args, " ");
		std::vector<std::string>		listOfChans;
		//si le nom donne n'est pas le serveur actuel, ERR
		if (split_args.size() > 1 && serv->_tcpServer.getHostname() != split_args[1])
		{
			serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
				send_replies(402, currentUser, serv, split_args[1])));
			return ;
		}
		listOfChans = ft_split(args, ",");
		listSelectedChans(serv, currentUser, listOfChans);
	}
}