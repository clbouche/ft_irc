#include "../includes/headers.hpp"
#include "../includes/commands.hpp"
#include "../includes/channels.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"

/**
 Command: INVITE
   Parameters: <nickname> <channel>

   The INVITE command is used to invite a user to a channel.  The
   parameter <nickname> is the nickname of the person to be invited to
   the target channel <channel>.  There is no requirement that the
   channel the target user is being invited to must exist or be a valid
   channel.  However, if the channel exists, only members of the channel
   are allowed to invite other users.  When the channel has invite-only
   flag set, only channel operators may issue INVITE command.

   Only the user inviting and the user being invited will receive
   notification of the invitation.  Other channel members are not
   notified.  (This is unlike the MODE changes, and is occasionally the
   source of trouble for users.)

   Numeric Replies:

           ERR_NEEDMOREPARAMS              ERR_NOSUCHNICK
           ERR_NOTONCHANNEL                ERR_USERONCHANNEL
           ERR_CHANOPRIVSNEEDED
           RPL_INVITING                    RPL_AWAY

   Examples:

   :Angel!wings@irc.org INVITE Wiz #Dust

                                   ; Message to WiZ when he has been
                                   invited by user Angel to channel
                                   #Dust

   INVITE Wiz #Twilight_Zone       ; Command to invite WiZ to
                                   #Twilight_zone
 */
bool        check_args(IrcServer *serv, user *currentUser, channels *chan, std::string nicknameToInvite)
{
    //si le channel est en mode invite-only, le user qui veut invite doit avoir les droits
    if (!chan->checkOperator(currentUser) && chan->getMode().find("i"))
    {
        serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), 
                    send_replies(482, currentUser, serv, chan->getName())));
        return false;
    }
    //si le user qu'on souhaite inviter n'existe pas 
    if (serv->getUserByNick(nicknameToInvite) == NULL)
    {
        serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), 
                    send_replies(401, currentUser, serv, nicknameToInvite)));
		return false;

    }
    //si le user est deja dans le channel 
    if (chan->UserInChan(nicknameToInvite) == true)
    {
        serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), 
                    send_replies(443, currentUser, serv, nicknameToInvite,
                    chan->getName())));
        return false;
    }
    //si le user qui veut ajouter quelqu'un n'est pas dans le channel
    if (chan->UserInChan(currentUser) == false)
    {
        serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), 
                    send_replies(443, currentUser, serv, nicknameToInvite,
                    chan->getName())));
        return false;
	}
    return true;
}


void    cmd_invite( IrcServer *serv, user *currentUser, std::string & args )
{
    std::vector<std::string>    split_args = ft_split(args, " ");

    //si pas precise nickname + channel
    if (split_args.size() < 2)
    {
        serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
		 					send_replies(461, currentUser, serv, "INVITE")));
        return ;
    }
    channels        *chan;
    std::string     nicknameToInvite = split_args[0];
    std::string     channelInvitation = split_args[1];

    serv->currentChannels.find(channelInvitation) == serv->currentChannels.end() ? 
        chan = NULL : chan = serv->currentChannels.find(channelInvitation)->second;
    
    if (chan != NULL && check_args(serv, currentUser, chan, nicknameToInvite) == true)
    {
		//il faut aller chercher le user dans le serveur 
		//pas oublier de changer le bool BAN a false 
		//envoyer le message au mec qui a ete invite 
		//envoyer un accuse de reception au mec qui a invite 
		
	}
}
    