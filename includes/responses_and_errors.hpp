/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   responses_and_errors.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:30:30 by clbouche          #+#    #+#             */
/*   Updated: 2022/06/13 16:19:58 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESPONSES_AND_ERRORS_HPP
# define RESPONSES_AND_ERRORS_HPP

	/* ------------------------------------------------------------- */
	/* --------------------- RESPONSES REPLIES --------------------- */	
	/* ------------------------------------------------------------- */

    /**
     * The server sends Replies 001 to 004 to a user upon
        successful registration.
    */
/**
 * @brief RPL 001
 * 
 */
# define RPL_WELCOME(nick, user, host) (":Welcome to the Internet Relay Network " \
               + nick + "!" + user + "@" + host + "\r\n")

/**
 * @brief RPL 002
 * 
 */
# define RPL_YOURHOST(servername, ver) (":Your host is " + servername + ", running version " + ver + "\r\n")

/**
 * @brief RPL 003
 * 
 */
# define RPL_CREATED() (":This server was created 01/06/2022\r\n")

/**
 * @brief RPL 004
 * 
 */
# define RPL_MYINFO(servername, version, userModes, channelModes) (":" + servername + \
                    " " + version + " " + userModes + " " + channelModes + "\r\n")

/**
 * @brief ERR 322
 * 
 */
# define RPL_LIST(channel, topic) (channel + " :" + topic + "\r\n")

/**
 * @brief ERR 323
 * 
 */
# define RPL_LISTEND() (":End of LIST\r\n")
/**
 *      - Replies RPL_LIST, RPL_LISTEND mark the actual replies
           with data and end of the server's response to a LIST
           command.  If there are no channels available to return,
           only the end reply MUST be sent.
 * 
 */


/**
 * @brief RPL 331
 * 
 */
# define RPL_NOTOPIC(channel) (channel + " :No topic is set\r\n")

/**
 * @brief RPL 332
 * 
 */
# define RPL_TOPIC(channel, topic) (channel + " :" + topic + "\r\n")


    /**
     * To reply to a NAMES message, a reply pair consisting
        of RPL_NAMREPLY and RPL_ENDOFNAMES is sent by the
        server back to the client.  If there is no channel
        found as in the query, then only RPL_ENDOFNAMES is

        returned.  The exception to this is when a NAMES
        message is sent with no parameters and all visible
        channels and contents are sent back in a series of
        RPL_NAMEREPLY messages with a RPL_ENDOFNAMES to mark
        the end.
     * 
     */
/**
 * @brief RPL 353
 * 
 */
# define RPL_NAMREPLY(channel) ("= " + channel + " :")																// 353

/**
 * @brief ERR 366
 * 
 */
# define RPL_ENDOFNAMES(channel) (channel + " :End of NAMES list\r\n")

    /**
     *  When responding to the MOTD message and the MOTD file
        is found, the file is displayed line by line, with
        each line no longer than 80 characters, using
        RPL_MOTD format replies.  These MUST be surrounded
        by a RPL_MOTDSTART (before the RPL_MOTDs) and an
        RPL_ENDOFMOTD (after).
 */
    
/**
 * @brief RPL 375 
 * 
 */
# define RPL_MOTDSTART(server) (":- " + server + " Message of the day - \r\n")

/**
 * @brief RPL 372 
 * 
 */
# define RPL_MOTD(text) (":- " + text + "\r\n")

/**
 * @brief RPL 376
 * 
 */
# define RPL_ENDOFMOTD() (":End of MOTD command\r\n")



	/* ------------------------------------------------------------- */
	/* ----------------------- ERROR REPLIES ----------------------- */	
	/* ------------------------------------------------------------- */

/**
 * @brief ERR 401
 * Used to indicate the nickname parameter supplied to a command is 
 * currently unused.
 * 
 */
# define ERR_NOSUCHNICK(nickName) (nickName + " :No such nick/channel\r\n")

/**
 * @brief ERR 402
 * Used to indicate the server name given currently doesn't exist.
 * 
 */
# define ERR_NOSUCHSERVER(serverName) (serverName + " :No such server\r\n")

/**
 * @brief ERR 403
 * Used to indicate the given channel name is invalid.
 * 
 */
# define ERR_NOSUCHCHANNEL(channelName) (channelName + " :No such channel\r\n")

/**
 * @brief ERR 404
 * Sent to a user who is either (a) not on a channel which is mode +n 
 * or (b) not a chanop (or mode +v) on a channel which has mode +m 
 * set and is trying to send a PRIVMSG message to that channel.
 * 
 */
# define ERR_CANNOTSENDTOCHAN(channelName) (channelName + " :Cannot send to channel\r\n")

/**
 * @brief ERR 405
 * Sent to a user when they have joined the maximum number of 
 * allowed channels and they try to join another channel.
 * 
 */
# define ERR_TOOMANYCHANNELS(channelName) (channelName + " :You have joined too many \
											channels\r\n")

/**
 * @brief ERR 406
 * Returned by WHOWAS to indicate there is no history
 * information for that nickname.
 * 
 */
# define ERR_WASNOSUCHNICK(nickName) (nickName + " :There was no such nickname\r\n")

/**
 * @brief ERR 407
 * Returned to a client which is attempting to send a PRIVMSG/NOTICE
 * using the user@host destination format and for a user@host 
 * which has several occurrences.
 * 
 */
# define ERR_TOOMANYTARGETS(target) (target + " :Duplicate recipients. No message \
										delivered\r\n")

/**
 * @brief ERR 409
 * PING or PONG message missing the originator parameter which is 
 * required since these commands must work without valid prefixes.
 * 
 */
# define ERR_NOORIGIN() (":No origin specified\r\n")

/**
 * @brief ERR 411
 * 
 */
# define ERR_NORECIPIENT(command) (":No recipient given " + command + "\r\n")

/**
 * @brief ERR 412 
 * 
 */
# define ERR_NOTEXTTOSEND() (":No text to send\r\n")

/**
 * @brief ERR 413
 * 
 */
# define ERR_NOTOPLEVEL(mask) (mask + " :No toplevel domain specified\r\n")

/**
 * @brief ERR 414
 * 412 - 414 are returned by PRIVMSG to indicate that the message
 * wasn't delivered for some reason.
 * ERR_NOTOPLEVEL and ERR_WILDTOPLEVEL are errors that are returned
 * when an invalid use of "PRIVMSG $<server>" or "PRIVMSG #<host>" is attempted.
 */
# define ERR_WILDTOPLEVEL(mask) (mask + " :No toplevel domain specified\r\n")

/**
 * @brief ERR 421
 * Returned to a registered client to indicate that the command
 * sent is unknown by the server.
 */
# define ERR_UNKNOWNCOMMAND(command) (command + " :Unknown command\r\n")

/**
 * @brief ERR 422
 * Server's MOTD file could not be opened by the server.
 */
# define ERR_NOMOTD() (" :MOTD File is missing\r\n")

/**
 * @brief ERR 423
 * Returned by a server in response to an ADMIN message when 
 * there is an error in finding the appropriate information.
 */
# define ERR_NOADMININFO(server) (server + " :No administrative info available\r\n")

/**
 * @brief ERR 424
 * Generic error message used to report a failed file 
 * operation during the processing of a message.
 */
# define ERR_FILEERROR(fileOp, file) (":File error doing " + fileOp + " on " + file "\r\n")

/**
 * @brief ERR 431
 * Returned when a nickname parameter expected for 
 * a command and isn't found.
 * 
 */
# define ERR_NONICKNAMEGIVEN() (":No nickname given\r\n")

/**
 * @brief ERR 432
 * Returned after receiving a NICK message which contains
 * characters which do not fall in the defined set.
 * See section x.x.x for details on valid nicknames.
 */
# define ERR_ERRONEUSNICKNAME(nickName) (nickName + " :Erroneus nickname\r\n")

/**
 * @brief ERR 433
 * Returned when a NICK message is processed that results
 * in an attempt to change to a currently existing
 * nickname.
 */
# define ERR_NICKNAMEINUSE(nickName) (nickName + " :Nickname is already in use\r\n")

/**
 * @brief ERR 436
 * Returned by a server to a client when it detects a
 * nickname collision (registered of a NICK that
 * already exists by another server).
 */
# define ERR_NICKCOLLISION(nickName) (nickName + " :Nickname collision KILL\r\n")

/**
 * @brief ERR 441
 * Returned by the server to indicate that the target
 * user of the command is not on the given channel.
 */
# define ERR_USERNOTINCHANNEL(nickName, channel) (nickName + " " + channel + " :They aren't on that channel\r\n")

/**
 * @brief ERR 442
 * Returned by the server to indicate that the target
 * user of the command is not on the given channel.
 */
# define ERR_NOTONCHANNEL(channel) (channel + " :You're not on that channel\r\n")

/**
 * @brief ERR 443
 * Returned when a client tries to invite a user to a
 * channel they are already on.
 */
# define ERR_USERONCHANNEL(user, channel) (user + channel + "  :is already on channel\r\n")

/**
 * @brief ERR 444
 * Returned by the summon after a SUMMON command for a
 * user was unable to be performed since they were not
 * logged in.
 */
# define ERR_NOLOGIN(user) (user + "  :User not logged in\r\n")

/**
 * @brief ERR 445
 * Returned as a response to the SUMMON command.  Must be
 * returned by any server which does not implement it.
 */
# define ERR_SUMMONDISABLED() (":SUMMON has been disabled\r\n")

/**
 * @brief ERR 446
 * Returned as a response to the USERS command.  Must be
 * returned by any server which does not implement it.
 */
# define ERR_USERSDISABLED() (":USERS has been disabled\r\n")

/**
 * @brief ERR 451
 * Returned by the server to indicate that the client
 * must be registered before the server will allow it
 * to be parsed in detail.
 */
# define ERR_NOTREGISTERED() (":You have not registered\r\n")

/**
 * @brief ERR 461
 * Returned by the server by numerous commands to
 * indicate to the client that it didn't supply enough
 * parameters.
 */
# define ERR_NEEDMOREPARAMS(command) (command + " :Not enough parameters\r\n")

/**
 * @brief ERR 462
 * Returned by the server to any link which tries to
 * change part of the registered details (such as
 * password or user details from second USER message).
 */
# define ERR_ALREADYREGISTRED() (":Unauthorized command (already registered)\r\n")


/**
 * @brief ERR 471
 * 
 */
# define ERR_CHANNELISFULL(channel) (channel + " :Cannot join channel (+l)\r\n")

/**
 * @brief ERR 473
 * 
 */
# define    ERR_INVITEONLYCHAN(channel) (channel + " :Cannot join channel (+i)\r\n")

/**
 * @brief ERR 474
 * 
 */
# define ERR_BANNEDFROMCHAN(channel) (channel + " :Cannot join channel (+b)\r\n")

/**
 * @brief ERR 475
 * 
 */
# define ERR_BADCHANNELKEY(channel) (channel + " :Cannot join channel (+k)\r\n")

/**
 * @brief ERR 476
 * 
 */
# define ERR_BADCHANMASK(channel) (channel + " :Bad Channel Mask\r\n")



//         463     ERR_NOPERMFORHOST
//                         ":Your host isn't among the privileged"

//                 - Returned to a client which attempts to register with
//                   a server which does not been setup to allow
//                   connections from the host the attempted connection
//                   is tried.

//         464     ERR_PASSWDMISMATCH
//                         ":Password incorrect"

//                 - Returned to indicate a failed attempt at registering
//                   a connection for which a password was required and
//                   was either not given or incorrect.

//         465     ERR_YOUREBANNEDCREEP
//                         ":You are banned from this server"

//                 - Returned after an attempt to connect and register
//                   yourself with a server which has been setup to
//                   explicitly deny connections to you.

//         467     ERR_KEYSET
//                         "<channel> :Channel key already set"

//         472     ERR_UNKNOWNMODE
//                         "<char> :is unknown mode char to me"
/**
 * @brief ERR 472
 * Returned by the server to indicate that a MODE
 * flag does not exist.
 */
# define ERR_UNKNOWNMODE(flag, target) (flag + " :is unknown mode char to me for " + target + "\r\n")
//         473     ERR_INVITEONLYCHAN
//                         "<channel> :Cannot join channel (+i)"
//         474     ERR_BANNEDFROMCHAN
//                         "<channel> :Cannot join channel (+b)"
//         475     ERR_BADCHANNELKEY
//                         "<channel> :Cannot join channel (+k)"
//         481     ERR_NOPRIVILEGES
//                         ":Permission Denied- You're not an IRC operator"

//                 - Any command requiring operator privileges to operate
//                   must return this error to indicate the attempt was
//                   unsuccessful.

//         482     ERR_CHANOPRIVSNEEDED
//                         "<channel> :You're not channel operator"
/**
 * @brief ERR 482
 * Returned by the server to indicate that
 * the user is not operator in channel
 */
# define ERR_CHANOPRIVSNEEDED(channel) (channel + " :You're not channel operator\r\n")
//                 - Any command requiring 'chanop' privileges (such as
//                   MODE messages) must return this error if the client
//                   making the attempt is not a chanop on the specified
//                   channel.

//         483     ERR_CANTKILLSERVER
//                         ":You cant kill a server!"

//                 - Any attempts to use the KILL command on a server
//                   are to be refused and this error returned directly
//                   to the client.

//         491     ERR_NOOPERHOST
//                         ":No O-lines for your host"

//                 - If a client sends an OPER message and the server has
//                   not been configured to allow connections from the
//                   client's host as an operator, this error must be
//                   returned.

//         501     ERR_UMODEUNKNOWNFLAG
//                         ":Unknown MODE flag"

//                 - Returned by the server to indicate that a MODE
//                   message was sent with a nickname parameter and that
//                   the a mode flag sent was not recognized.

/**
 * @brief ERR 501
 * Returned by the server to indicate that a MODE
 * message was sent with a nickname parameter and that
 * the a mode flag sent was not recognized.
 */
# define ERR_UMODEUNKNOWNFLAG() (":Unknown MODE flag\r\n")

/**
 * @brief ERR 502
 * Error sent to any user trying to view or change the
 * user mode for a user other than themselves.
 */
# define ERR_USERSDONTMATCH() (":Cannot change mode for other users\r\n")


	/* ------------------------------------------------------------- */
	/* --------------------- COMMAND RESPONSES --------------------- */	
	/* ------------------------------------------------------------- */

	//  300     RPL_NONE
    //                     Dummy reply number. Not used.

    //     302     RPL_USERHOST
    //                     ":[<reply>{<space><reply>}]"

    //             - Reply format used by USERHOST to list replies to
    //               the query list.  The reply string is composed as
    //               follows:

    //               <reply> ::= <nick>['*'] '=' <'+'|'-'><hostname>

    //               The '*' indicates whether the client has registered
    //               as an Operator.  The '-' or '+' characters represent
    //               whether the client has set an AWAY message or not
    //               respectively.

    //     303     RPL_ISON
    //                     ":[<nick> {<space><nick>}]"

    //             - Reply format used by ISON to list replies to the
    //               query list.

    //     301     RPL_AWAY
    //                     "<nick> :<away message>"

    //     305     RPL_UNAWAY
    //                     ":You are no longer marked as being away"
    //     306     RPL_NOWAWAY
    //                     ":You have been marked as being away"

    //             - These replies are used with the AWAY command (if
    //               allowed).  RPL_AWAY is sent to any client sending a
    //               PRIVMSG to a client which is away.  RPL_AWAY is only
    //               sent by the server to which the client is connected.
    //               Replies RPL_UNAWAY and RPL_NOWAWAY are sent when the
    //               client removes and sets an AWAY message.

    //     311     RPL_WHOISUSER
    //                     "<nick> <user> <host> * :<real name>"
    //     312     RPL_WHOISSERVER
    //                     "<nick> <server> :<server info>"
    //     313     RPL_WHOISOPERATOR
    //                     "<nick> :is an IRC operator"
    //     317     RPL_WHOISIDLE
    //                     "<nick> <integer> :seconds idle"
    //     318     RPL_ENDOFWHOIS
    //                     "<nick> :End of /WHOIS list"
    //     319     RPL_WHOISCHANNELS
    //                     "<nick> :{[@|+]<channel><space>}"

    //             - Replies 311 - 313, 317 - 319 are all replies
    //               generated in response to a WHOIS message.  Given that
    //               there are enough parameters present, the answering
    //               server must either formulate a reply out of the above
    //               numerics (if the query nick is found) or return an
    //               error reply.  The '*' in RPL_WHOISUSER is there as
    //               the literal character and not as a wild card.  For
    //               each reply set, only RPL_WHOISCHANNELS may appear
    //               more than once (for long lists of channel names).
    //               The '@' and '+' characters next to the channel name
    //               indicate whether a client is a channel operator or
    //               has been granted permission to speak on a moderated
    //               channel.  The RPL_ENDOFWHOIS reply is used to mark
    //               the end of processing a WHOIS message.

    //     314     RPL_WHOWASUSER
    //                     "<nick> <user> <host> * :<real name>"
    //     369     RPL_ENDOFWHOWAS
    //                     "<nick> :End of WHOWAS"

    //             - When replying to a WHOWAS message, a server must use
    //               the replies RPL_WHOWASUSER, RPL_WHOISSERVER or
    //               ERR_WASNOSUCHNICK for each nickname in the presented

    //               list.  At the end of all reply batches, there must
    //               be RPL_ENDOFWHOWAS (even if there was only one reply
    //               and it was an error).

    //     321     RPL_LISTSTART
    //                     "Channel :Users  Name"
    //     322     RPL_LIST
    //                     "<channel> <# visible> :<topic>"
    //     323     RPL_LISTEND
    //                     ":End of /LIST"

    //             - Replies RPL_LISTSTART, RPL_LIST, RPL_LISTEND mark
    //               the start, actual replies with data and end of the
    //               server's response to a LIST command.  If there are
    //               no channels available to return, only the start
    //               and end reply must be sent.

    //     324     RPL_CHANNELMODEIS
    //                     "<channel> <mode> <mode params>"
/**
 * @brief ERR 324
 * Error sent to any user trying to view or change the
 * user mode for a user other than themselves.
 */
# define RPL_CHANNELMODEIS(channel, mode, modeParams) (channel + " " + mode + " " + modeParams + "\r\n")
    //     331     RPL_NOTOPIC
    //                     "<channel> :No topic is set"
    //     332     RPL_TOPIC
    //                     "<channel> :<topic>"

    //             - When sending a TOPIC message to determine the
    //               channel topic, one of two replies is sent.  If
    //               the topic is set, RPL_TOPIC is sent back else
    //               RPL_NOTOPIC.

    //     341     RPL_INVITING
    //                     "<channel> <nick>"

    //             - Returned by the server to indicate that the
    //               attempted INVITE message was successful and is
    //               being passed onto the end client.

    //     342     RPL_SUMMONING
    //                     "<user> :Summoning user to IRC"

    //             - Returned by a server answering a SUMMON message to
    //               indicate that it is summoning that user.

    //     351     RPL_VERSION
    //                     "<version>.<debuglevel> <server> :<comments>"

    //             - Reply by the server showing its version details.
    //               The <version> is the version of the software being

    //               used (including any patchlevel revisions) and the
    //               <debuglevel> is used to indicate if the server is
    //               running in "debug mode".

    //               The "comments" field may contain any comments about
    //               the version or further version details.

    //     352     RPL_WHOREPLY
    //                     "<channel> <user> <host> <server> <nick> \
    //                      <H|G>[*][@|+] :<hopcount> <real name>"
    //     315     RPL_ENDOFWHO
    //                     "<name> :End of /WHO list"

    //             - The RPL_WHOREPLY and RPL_ENDOFWHO pair are used
    //               to answer a WHO message.  The RPL_WHOREPLY is only
    //               sent if there is an appropriate match to the WHO
    //               query.  If there is a list of parameters supplied
    //               with a WHO message, a RPL_ENDOFWHO must be sent
    //               after processing each list item with <name> being
    //               the item.


    //     366     RPL_ENDOFNAMES
    //                     "<channel> :End of /NAMES list"

    //             - To reply to a NAMES message, a reply pair consisting
    //               of RPL_NAMREPLY and RPL_ENDOFNAMES is sent by the
    //               server back to the client.  If there is no channel
    //               found as in the query, then only RPL_ENDOFNAMES is
    //               returned.  The exception to this is when a NAMES
    //               message is sent with no parameters and all visible
    //               channels and contents are sent back in a series of
    //               RPL_NAMEREPLY messages with a RPL_ENDOFNAMES to mark
    //               the end.

    //     364     RPL_LINKS
    //                     "<mask> <server> :<hopcount> <server info>"
    //     365     RPL_ENDOFLINKS
    //                     "<mask> :End of /LINKS list"

    //             - In replying to the LINKS message, a server must send
    //               replies back using the RPL_LINKS numeric and mark the
    //               end of the list using an RPL_ENDOFLINKS reply.

    //     367     RPL_BANLIST
    //                     "<channel> <banid>"
    //     368     RPL_ENDOFBANLIST

    //                     "<channel> :End of channel ban list"

    //             - When listing the active 'bans' for a given channel,
    //               a server is required to send the list back using the
    //               RPL_BANLIST and RPL_ENDOFBANLIST messages.  A separate
    //               RPL_BANLIST is sent for each active banid.  After the
    //               banids have been listed (or if none present) a
    //               RPL_ENDOFBANLIST must be sent.

    //     371     RPL_INFO
    //                     ":<string>"
    //     374     RPL_ENDOFINFO
    //                     ":End of /INFO list"

    //             - A server responding to an INFO message is required to
    //               send all its 'info' in a series of RPL_INFO messages
    //               with a RPL_ENDOFINFO reply to indicate the end of the
    //               replies.

    //     375     RPL_MOTDSTART
    //                     ":- <server> Message of the day - "
    //     372     RPL_MOTD
    //                     ":- <text>"
    //     376     RPL_ENDOFMOTD
    //                     ":End of /MOTD command"

    //             - When responding to the MOTD message and the MOTD file
    //               is found, the file is displayed line by line, with
    //               each line no longer than 80 characters, using
    //               RPL_MOTD format replies.  These should be surrounded
    //               by a RPL_MOTDSTART (before the RPL_MOTDs) and an
    //               RPL_ENDOFMOTD (after).

    //     381     RPL_YOUREOPER
    //                     ":You are now an IRC operator"

    //             - RPL_YOUREOPER is sent back to a client which has
    //               just successfully issued an OPER message and gained
    //               operator status.

    //     382     RPL_REHASHING
    //                     "<config file> :Rehashing"

    //             - If the REHASH option is used and an operator sends
    //               a REHASH message, an RPL_REHASHING is sent back to
    //               the operator.

    //     391     RPL_TIME

    //                     "<server> :<string showing server's local time>"

    //             - When replying to the TIME message, a server must send
    //               the reply using the RPL_TIME format above.  The string
    //               showing the time need only contain the correct day and
    //               time there.  There is no further requirement for the
    //               time string.

    //     392     RPL_USERSSTART
    //                     ":UserID   Terminal  Host"
    //     393     RPL_USERS
    //                     ":%-8s %-9s %-8s"
    //     394     RPL_ENDOFUSERS
    //                     ":End of users"
    //     395     RPL_NOUSERS
    //                     ":Nobody logged in"

    //             - If the USERS message is handled by a server, the
    //               replies RPL_USERSTART, RPL_USERS, RPL_ENDOFUSERS and
    //               RPL_NOUSERS are used.  RPL_USERSSTART must be sent
    //               first, following by either a sequence of RPL_USERS
    //               or a single RPL_NOUSER.  Following this is
    //               RPL_ENDOFUSERS.

    //     200     RPL_TRACELINK
    //                     "Link <version & debug level> <destination> \
    //                      <next server>"
    //     201     RPL_TRACECONNECTING
    //                     "Try. <class> <server>"
    //     202     RPL_TRACEHANDSHAKE
    //                     "H.S. <class> <server>"
    //     203     RPL_TRACEUNKNOWN
    //                     "???? <class> [<client IP address in dot form>]"
    //     204     RPL_TRACEOPERATOR
    //                     "Oper <class> <nick>"
    //     205     RPL_TRACEUSER
    //                     "User <class> <nick>"
    //     206     RPL_TRACESERVER
    //                     "Serv <class> <int>S <int>C <server> \
    //                      <nick!user|*!*>@<host|server>"
    //     208     RPL_TRACENEWTYPE
    //                     "<newtype> 0 <client name>"
    //     261     RPL_TRACELOG
    //                     "File <logfile> <debug level>"

    //             - The RPL_TRACE* are all returned by the server in
    //               response to the TRACE message.  How many are
    //               returned is dependent on the the TRACE message and

    //               whether it was sent by an operator or not.  There
    //               is no predefined order for which occurs first.
    //               Replies RPL_TRACEUNKNOWN, RPL_TRACECONNECTING and
    //               RPL_TRACEHANDSHAKE are all used for connections
    //               which have not been fully established and are either
    //               unknown, still attempting to connect or in the
    //               process of completing the 'server handshake'.
    //               RPL_TRACELINK is sent by any server which handles
    //               a TRACE message and has to pass it on to another
    //               server.  The list of RPL_TRACELINKs sent in
    //               response to a TRACE command traversing the IRC
    //               network should reflect the actual connectivity of
    //               the servers themselves along that path.
    //               RPL_TRACENEWTYPE is to be used for any connection
    //               which does not fit in the other categories but is
    //               being displayed anyway.

    //     211     RPL_STATSLINKINFO
    //                     "<linkname> <sendq> <sent messages> \
    //                      <sent bytes> <received messages> \
    //                      <received bytes> <time open>"
    //     212     RPL_STATSCOMMANDS
    //                     "<command> <count>"
    //     213     RPL_STATSCLINE
    //                     "C <host> * <name> <port> <class>"
    //     214     RPL_STATSNLINE
    //                     "N <host> * <name> <port> <class>"
    //     215     RPL_STATSILINE
    //                     "I <host> * <host> <port> <class>"
    //     216     RPL_STATSKLINE
    //                     "K <host> * <username> <port> <class>"
    //     218     RPL_STATSYLINE
    //                     "Y <class> <ping frequency> <connect \
    //                      frequency> <max sendq>"
    //     219     RPL_ENDOFSTATS
    //                     "<stats letter> :End of /STATS report"
    //     241     RPL_STATSLLINE
    //                     "L <hostmask> * <servername> <maxdepth>"
    //     242     RPL_STATSUPTIME
    //                     ":Server Up %d days %d:%02d:%02d"
    //     243     RPL_STATSOLINE
    //                     "O <hostmask> * <name>"
    //     244     RPL_STATSHLINE
    //                     "H <hostmask> * <servername>"

    //     221     RPL_UMODEIS
    //                     "<user mode string>"

    //                     - To answer a query about a client's own mode,
    //                       RPL_UMODEIS is sent back.
/**
 * @brief ERR 221
 *         - To answer a query about a client's own mode,
 *          RPL_UMODEIS is sent back.
 */
# define RPL_UMODEIS(userModes) ("Your user mode is [" + userModes + "]\r\n")
    //     251     RPL_LUSERCLIENT
    //                     ":There are <integer> users and <integer> \
    //                      invisible on <integer> servers"
    //     252     RPL_LUSEROP
    //                     "<integer> :operator(s) online"
    //     253     RPL_LUSERUNKNOWN
    //                     "<integer> :unknown connection(s)"
    //     254     RPL_LUSERCHANNELS
    //                     "<integer> :channels formed"
    //     255     RPL_LUSERME
    //                     ":I have <integer> clients and <integer> \
    //                       servers"

    //                     - In processing an LUSERS message, the server
    //                       sends a set of replies from RPL_LUSERCLIENT,
    //                       RPL_LUSEROP, RPL_USERUNKNOWN,
    //                       RPL_LUSERCHANNELS and RPL_LUSERME.  When
    //                       replying, a server must send back
    //                       RPL_LUSERCLIENT and RPL_LUSERME.  The other
    //                       replies are only sent back if a non-zero count
    //                       is found for them.

    //     256     RPL_ADMINME
    //                     "<server> :Administrative info"
    //     257     RPL_ADMINLOC1
    //                     ":<admin info>"
    //     258     RPL_ADMINLOC2
    //                     ":<admin info>"
    //     259     RPL_ADMINEMAIL
    //                     ":<admin info>"

    //                     - When replying to an ADMIN message, a server
    //                       is expected to use replies RLP_ADMINME
    //                       through to RPL_ADMINEMAIL and provide a text
    //                       message with each.  For RPL_ADMINLOC1 a
    //                       description of what city, state and country
    //                       the server is in is expected, followed by
    //                       details of the university and department
    //                       (RPL_ADMINLOC2) and finally the administrative
    //                       contact for the server (an email address here
    //                       is required) in RPL_ADMINEMAIL.


#endif
