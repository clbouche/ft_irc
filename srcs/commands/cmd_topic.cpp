/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_topic.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:39:32 by clbouche          #+#    #+#             */
/*   Updated: 2022/06/13 12:10:50 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.hpp"
#include "../includes/commands.hpp"
#include "../includes/channels.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"
#include "../includes/utils.hpp"

/**
 Command: TOPIC
   Parameters: <channel> [ <topic> ]

   The TOPIC command is used to change or view the topic of a channel.
   The topic for channel <channel> is returned if there is no <topic>
   given.  If the <topic> parameter is present, the topic for that
   channel will be changed, if this action is allowed for the user
   requesting it.  If the <topic> parameter is an empty string, the
   topic for that channel will be removed.

   Numeric Replies:

           ERR_NEEDMOREPARAMS   ✅             ERR_NOTONCHANNEL ✅
           RPL_NOTOPIC          ✅             RPL_TOPIC        ✅
           ERR_CHANOPRIVSNEEDED                ERR_NOCHANMODES

   Examples:

   :WiZ!jto@tolsun.oulu.fi TOPIC #test :New topic ; User Wiz setting the
                                   topic.

   TOPIC #test :another topic      ; Command to set the topic on #test
                                   to "another topic".

   TOPIC #test :                   ; Command to clear the topic on
                                   #test.

   TOPIC #test                     ; Command to check the topic for
                                   #test.
 */

static bool     check_args(IrcServer *serv, user *currentUser, std::string args, channels *channel)
{
    std::vector<std::string>	split_args = ft_split(args, " ");
    if (split_args.size() == 0)
    {
        serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
		 					send_replies(461, currentUser, serv, "TOPIC")));
		return false;
    }
	if (channel->UserInChan(currentUser) == false)
	{
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
							send_replies(442, currentUser, serv, channel->getName())));
		return false;
	}
    return true;
}

void    cmd_topic( IrcServer *serv, user *currentUser, std::string & args )
{
	size_t 			pos = args.find_first_of(" :");
	std::string		channel = args.substr(0, pos);
    channels        *channel_topic;
	std::string		topic;
	pos == std::string::npos ? topic = "" : topic = args.substr(pos + 2, args.length());
    serv->currentChannels.find(channel) == serv->currentChannels.end()?
            channel_topic = NULL : channel_topic = serv->currentChannels.find(channel)->second;
    if (check_args(serv, currentUser, args, channel_topic) == true)
    {
        if (args.find_first_of(":") == std::string::npos)
		{
			if (channel_topic->getTopic() == "")
            {
				serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
							send_replies(331, currentUser, serv, channel)));
                return ;
            }
        }
        channel_topic->setTopic(topic);
        serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
                    send_replies(332, currentUser, serv, channel, 
                    channel_topic->getTopic())));
    }
}