
#include "../includes/headers.hpp"
#include "../includes/commands.hpp"
#include "../includes/channels.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"

/**
      Command: PING
   Parameters: <server1> [ <server2> ]

   The PING command is used to test the presence of an active client or
   server at the other end of the connection.  Servers send a PING
   message at regular intervals if no other activity detected coming
   from a connection.  If a connection fails to respond to a PING
   message within a set amount of time, that connection is closed.  A
   PING message MAY be sent even if the connection is active.

   When a PING message is received, the appropriate PONG message MUST be
   sent as reply to <server1> (server which sent the PING message out)
   as soon as possible.  If the <server2> parameter is specified, it
   represents the target of the ping, and the message gets forwarded
   there.

   Numeric Replies:

           ERR_NOORIGIN                  ERR_NOSUCHSERVER

   Examples:

   PING tolsun.oulu.fi             ; Command to send a PING message to
                                   server

   PING WiZ tolsun.oulu.fi         ; Command from WiZ to send a PING
                                   message to server "tolsun.oulu.fi"

   PING :irc.funet.fi              ; Ping message sent by server
                                   "irc.funet.fi"
 */

static bool		check_args(IrcServer *serv, user *currentUser, std::string & args)
{
	if (args == "")
	{
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), 
							send_replies(409, currentUser, serv)));
		return false;
	}
	if (args != serv->_tcpServer.getHostname())
	{
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), 
				send_replies(402, currentUser, serv, args)));
		return false;
	}
	return true;
}

void    cmd_ping( IrcServer *serv, user *currentUser, std::string & args )
{
	if (check_args(serv, currentUser, args) == true)
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), 
					"PONG " + args + "\r\n"));
}
