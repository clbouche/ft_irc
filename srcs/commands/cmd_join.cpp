/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_join.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:18:16 by clbouche          #+#    #+#             */
/*   Updated: 2022/06/21 11:31:31 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/headers.hpp"
#include "../../includes/commands.hpp"
#include "../../includes/IrcServer.hpp"
#include "../../includes/user.hpp"
#include "../../includes/utils.hpp"

/**
      Command: JOIN
   Parameters: ( <channel> *( "," <channel> ) [ <key> *( "," <key> ) ] )
               / "0"

   The JOIN command is used by a user to request to start listening to
   the specific channel.  Servers MUST be able to parse arguments in the
   form of a list of target, but SHOULD NOT use lists when sending JOIN
   messages to clients.

   Once a user has joined a channel, he receives information about
   all commands his server receives affecting the channel.  This
   includes JOIN, MODE, KICK, PART, QUIT and of course PRIVMSG/NOTICE.
   This allows channel members to keep track of the other channel
   members, as well as channel modes.

   If a JOIN is successful, the user receives a JOIN message as
   confirmation and is then sent the channel's topic (using RPL_TOPIC) and
   the list of users who are on the channel (using RPL_NAMREPLY), which
   MUST include the user joining.

   Note that this message accepts a special argument ("0"), which is
   a special request to leave all channels the user is currently a member
   of.  The server will process this message as if the user had sent
   a PART command (See Section 3.2.2) for each channel he is a member
   of.

   Numeric Replies:

           ERR_NEEDMOREPARAMS ✅             ERR_BANNEDFROMCHAN
           ERR_INVITEONLYCHAN              ERR_BADCHANNELKEY
           ERR_CHANNELISFULL               ERR_BADCHANMASK
           ERR_NOSUCHCHANNEL               ERR_TOOMANYCHANNELS
           ERR_TOOMANYTARGETS              ERR_UNAVAILRESOURCE
           RPL_TOPIC

   Examples:

   JOIN #foobar                    ; Command to join channel #foobar.

   JOIN &foo fubar                 ; Command to join channel &foo using
                                   key "fubar".

   JOIN #foo,&bar fubar            ; Command to join channel #foo using
                                   key "fubar" and &bar using no key.

   JOIN #foo,#bar fubar,foobar     ; Command to join channel #foo using
                                   key "fubar", and channel #bar using
                                   key "foobar".

   JOIN #foo,#bar                  ; Command to join channels #foo and
                                   #bar.

   JOIN 0                          ; Leave all currently joined
                                   channels.

   :WiZ!jto@tolsun.oulu.fi JOIN #Twilight_zone ; JOIN message from WiZ
                                   on channel #Twilight_zone

 */
static bool		check_args(IrcServer *serv, user *currentUser, std::string & chan_name)
{
	//si le prefix du nom de channel n'est pas valide
	if ((strchr(CHANNEL_PREFIX, chan_name.c_str()[0]) == NULL))
	{
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
							send_replies(476, currentUser, serv)));
		return false;
	}
	//si le nom de channel est compose de mauvais chars
	if (chan_name.find(',') == true || chan_name.find(' ') == true)
	{
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
					send_replies(403, currentUser, serv, chan_name)));
		return false;
	}
	//si le nombre maximum de channels est deja atteint
	if (currentUser->getChannelsJoined() > MAX_CHANNELS)
	{
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
					send_replies(405, currentUser, serv, chan_name)));
		return false;
	}
	return true;
}

bool		check_chan(IrcServer *serv, user *currentUser, channels *channel, std::string password)
{
	//si l'ajout de l'utilisateur fait depasser le nombre maximum de users
	if (channel->getNbUsers() == channel->getUserLimit())
	{
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
					send_replies(471, currentUser, serv, channel->getName())));
		return false;
	}
	//si l'utilisateur qui souhaite entrer dans le channel a ete banni
	if (channel->UserIsBan(currentUser) == true)
	{
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
					send_replies(474, currentUser, serv, channel->getName())));
		return false;
	}
	//si l'utilisateur n'a pas ete invite a entrer dans le channel
	int i = channel->getMode().find('i');
	if (channel->getMode().find('i') != std::string::npos && channel->UserIsInvite(currentUser) == false)
	{
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
			send_replies(473, currentUser, serv, channel->getName())));
		return false;
	}
	// si l'utilisateur n'a pas entre la bonne clef 
	if (channel->getPassSet() == true && channel->getPassword() != password)
	{
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
					send_replies(475, currentUser, serv, channel->getName())));
		return false;
	}
	return true;
}

void    cmd_join( IrcServer *serv, user	*currentUser, std::string & args )
{
	channels		*channel;
	std::string		chan_name;
	std::string		pass_chan;
	size_t 			j = 0;
	size_t			pos = args.find_first_of(" ");
	std::string		chans = args.substr(0, pos);
	
	// la regle "JOIN 0" permet a l'user de quitter tous les chans dans lequel il est
	if (args[args.size() - 1] == '0')
	{
		std::list<channels *>				chansOfUser;
		std::list<channels *>::iterator		chan_it;
		
		chansOfUser = currentUser->getListOfChans();
		for (chan_it = chansOfUser.begin() ; chan_it != chansOfUser.end() ; chan_it++ )
		{
			chan_name = (*chan_it)->getName();
			cmd_part(serv, currentUser, chan_name);
		}
		currentUser->setChannelsJoined(0);
		
	}

	//si JOIN n'a pas de nom de channel a rejoindre
	if (chans == "")
	{
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
		 					send_replies(461, currentUser, serv, "JOIN")));
		return ;
	}

	std::string		passwords;
	std::string		msg_join;
	pos == std::string::npos ? passwords = "" : passwords = args.substr(pos + 1, args.size());
	std::vector<std::string>		split_channels = ft_split(chans, ",");
	std::vector<std::string>		split_passwords = ft_split(passwords, ",");

	std::vector<std::string>::iterator	it;
	for (it = split_channels.begin() ; it != split_channels.end(); it++)
	{
		chan_name = split_channels[j];
		j >= split_passwords.size() ? pass_chan = "" : pass_chan = split_passwords[j];
		
		serv->currentChannels.find(chan_name) == serv->currentChannels.end() ? 
			channel = NULL : channel = serv->currentChannels.find(chan_name)->second;
			
		if(check_args(serv, currentUser, chan_name) == true)
		{
			if(channel == NULL)
			{
				//si le channel n'existe pas encore, creation du chan + ajout du user
				channels	*newChan = new channels(chan_name, currentUser);
				serv->currentChannels.insert(std::make_pair(chan_name, newChan));
				currentUser->setListOfChans(newChan);
				currentUser->IncrementChannelsJoined();
				serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
									send_replies(332, currentUser, serv, chan_name, 
				newChan->getTopic())));
				cmd_names(serv, currentUser, chan_name);

			}
			else if (check_chan(serv, currentUser, channel, pass_chan) == true)
			{
				//si le chan existe : 
				// check si le user n'est pas deja dans le chan 
				// sinon ajout du user 
				if (channel->UserInChan(currentUser) == false)
				{
					channel->addUser(currentUser);
					currentUser->setListOfChans(channel);
					currentUser->IncrementChannelsJoined();
					msg_join = formatMsgsUsers(currentUser->getNickName(), currentUser->getUserName(), 
												currentUser->getHostNameUser());
					channel->sendToAllUsersInChan(&serv->_tcpServer, (msg_join + "JOIN " 
							+ channel->getName() + "\r\n"));
					serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
							send_replies(332, currentUser, serv, channel->getName(), 
							channel->getTopic())));
					cmd_names(serv, currentUser, chan_name);
				}
			}
		}
		j++;
	}

}