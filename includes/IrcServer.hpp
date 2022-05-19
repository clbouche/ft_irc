/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IrcServer.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:28:17 by clbouche          #+#    #+#             */
/*   Updated: 2022/05/19 13:36:33 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IRCSERVER_HPP
# define IRCSERVER_HPP

#include <map>
#include "tcpServer.hpp"
#include "user.hpp"
#include "channels.hpp"

class channels;

class   IrcServer {

	public:
	
	/**
	 * @brief A map where we store our users
	 * 
	 */
	std::map<int, user>	usersMap;

	/**
	 * @brief A map where we store our channels
	 * 
	 */
	std::map<int, channels>	currentChannels;
	
	/**
	 * @brief Our tcp server where we setup the main sockets
	 * and the class Users
	 * 
	 */
	tcpServer       _tcpServer;

	/**
	 * @brief typedef to call function of IRC commands.
	 * 
	 */
	typedef	void	(*command)(IrcServer *, user, std::string &);


	private:

	/**
	 * @brief map of all the commands and the associated function
	 * 
	 */
	std::map<std::string, command>  _pointer_to_valid_cmd;

	/**
	 * @brief Create the association between function and command
	 * 
	 */
	void    create_pointer(void);


	public:    
	/**
	 * @brief Construct a new Irc Server object
	 * 
	 */
	IrcServer( int port);

	/**
	 * @brief Send to recup args of the command
	 * 
	 * @param cmd the function
	 * @param server IRCserver
	 * @param user User who send the command
	 */
	void    parse_cmd(char *cmd, IrcServer *server);

	/**
	 * @brief send to the right function 
	 * 
	 * @param cmd command send from the user 
	 * @return function_for_cmd function associated to the command
	 */
	command     recup_cmd(const std::string & command ) const;


};

# endif 