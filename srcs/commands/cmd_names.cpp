
#include "../includes/headers.hpp"
#include "../includes/commands.hpp"
#include "../includes/channels.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"
/**
Command: NAMES
   Parameters: [ <channel> *( "," <channel> ) [ <target> ] ]

   By using the NAMES command, a user can list all nicknames that are
   visible to him. For more details on what is visible and what is not,
   see "Internet Relay Chat: Channel Management" [IRC-CHAN].  The
   <channel> parameter specifies which channel(s) to return information
   about.  There is no error reply for bad channel names.

   If no <channel> parameter is given, a list of all channels and their
   occupants is returned.  At the end of this list, a list of users who
   are visible but either not on any channel or not on a visible channel
   are listed as being on `channel' "*".

   If the <target> parameter is specified, the request is forwarded to
   that server which will generate the reply.

   Wildcards are allowed in the <target> parameter.

   Numerics:

           ERR_TOOMANYMATCHES              ERR_NOSUCHSERVER
           RPL_NAMREPLY                    RPL_ENDOFNAMES 

   Examples:

   NAMES #twilight_zone,#42        ; Command to list visible users on
                                   #twilight_zone and #42

   NAMES                           ; Command to list all visible
                                   channels and users
 */

void	listAllChannels(IrcServer *serv, user *currentUser)
{
	std::map<std::string, channels *>::iterator	it;
    std::map<int, user *>::iterator             ite;
	std::string							rpl_nicknames;

	for(it = serv->currentChannels.begin() ; it != serv->currentChannels.end() ; it++)
	{
        channels                *chan = it->second;
        std::map<int, user *>   usersMap;

		rpl_nicknames = send_replies(353, currentUser, serv, chan->getName());
        usersMap = chan->getUsers();
        for(ite = usersMap.begin() ; ite != usersMap.end() ; ite++)
        {
			user 		*user = ite->second;
			if (user->getMode().find("i") == std::string::npos)
			{
				rpl_nicknames.append("@");
				rpl_nicknames.append(user->getNickName());
				rpl_nicknames.append(" ");
			}
        }
		rpl_nicknames.append("\r\n");
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), rpl_nicknames));
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
		send_replies(366, currentUser, serv, chan->getName())));
		
	}
}

void	listSelectedChans(IrcServer *serv, user *currentUser, std::vector<std::string> listOfChans)
{
    std::map<int, user *>::iterator		ite;
	std::string							rpl_nicknames;		

	for (size_t i = 0; i < listOfChans.size(); i++)
	{
		channels	*chan;
		serv->currentChannels.find(listOfChans[i]) == serv->currentChannels.end() ? 
				chan = NULL : chan = serv->currentChannels.find(listOfChans[i])->second;
		if (chan != NULL)
		{
			rpl_nicknames = send_replies(353, currentUser, serv, chan->getName());
			std::map<int, user *>   usersMap;

			usersMap = chan->getUsers();
			for(ite = usersMap.begin() ; ite != usersMap.end() ; ite++)
			{
				user 		*user = ite->second;
				if (user->getMode().find("i") == std::string::npos)
				{
					rpl_nicknames.append("@");
					rpl_nicknames.append(user->getNickName());
					rpl_nicknames.append(" ");
				}
			}
			rpl_nicknames.append("\r\n");
			serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), rpl_nicknames));
		}
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
						send_replies(366, currentUser, serv, listOfChans[i])));
	}
}

void    cmd_names( IrcServer *serv, user *currentUser, std::string & args )
{
    if (args == "")
        listAllChannels(serv, currentUser);
	else 
	{
		std::vector<std::string>	split_args = ft_split(args, " ");
		std::vector<std::string>	listOfChans;
		if (split_args.size() > 1 && split_args[1] != serv->_tcpServer.getHostname())
		{
			serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), 
						send_replies(402, currentUser, serv, args)));
			return ;
		}
		listOfChans = ft_split(args, ",");
		listSelectedChans(serv, currentUser, listOfChans);
	}
}