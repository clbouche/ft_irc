/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   responses_and_errors.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:30:30 by clbouche          #+#    #+#             */
/*   Updated: 2022/06/16 17:18:58 by elaachac         ###   ########.fr       */
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
 * @brief ERR 221
 *         - To answer a query about a client's own mode,
 *          RPL_UMODEIS is sent back.
 */
# define RPL_UMODEIS(userModes) (userModes + "\r\n")

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
 * @brief RPL 324
 * Error sent to any user trying to view or change the
 * user mode for a user other than themselves.
 */
# define RPL_CHANNELMODEIS(channel, mode, modeParams) (channel + " " + mode + " " + modeParams + "\r\n")

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
 *  Returned by the server to indicate that the
    attempted INVITE message was successful and is
    being passed onto the end client.
 */

/**
 * @brief RPL 341
 * 
 */
# define RPL_INVITING(channel, nick) (channel + " " + nick + "\r\n")


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
 * @brief RPL 367
 */
# define RPL_BANLIST(channel, banned) (" :" + channel + " " + banned + "\r\n")


/**
 * @brief RPL 368
 * - When listing the active 'bans' for a given channel,
 *   a server is required to send the list back using the
 *   RPL_BANLIST and RPL_ENDOFBANLIST messages.  A separate
 *   RPL_BANLIST is sent for each active banid.  After the
 *   banids have been listed (or if none present) a
 *   RPL_ENDOFBANLIST must be sent.
 */
# define RPL_ENDOFBANLIST(channel) (" " + channel + "\r\n")

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


/**
 * @brief ERR 472
 * Returned by the server to indicate that a MODE
 * flag does not exist.
 */
# define ERR_UNKNOWNMODE(flag, target) (flag + " :is unknown mode char to me for " + target + "\r\n")

/**
 * @brief ERR 482
 * Returned by the server to indicate that
 * the user is not operator in channel
 */
# define ERR_CHANOPRIVSNEEDED(channel) (channel + " :You're not channel operator\r\n")


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


#endif
