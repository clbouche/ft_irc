/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IrcServer.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:28:17 by clbouche          #+#    #+#             */
/*   Updated: 2022/06/14 14:33:29 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef IRCSERVER_HPP
# define IRCSERVER_HPP

#include "headers.hpp"
#include "tcpServer.hpp"
#include "user.hpp"
#include "channels.hpp"

class channels;
class user;
class   IrcServer {

	public:
	/**
	 * @brief A map where we store our users
	 * 
	 */
	std::map<int, user*>	usersMap;

	/**
	 * @brief A map where we store our channels
	 * 
	 */
	std::map<std::string, channels*>	currentChannels;
	
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
	typedef	void	(*command)(IrcServer *, user*, std::string &);


	private:

	std::string 	 _server_password;

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
	IrcServer( int port, std::string password);

	/**
	 * @brief Get the User object 
	 * 
	 * @param fd socket of the user 
	 * @return User* pointer to the user
	 */
	user 	 *getUserByNick(std::string nick);
	/**
	 * @brief Get the User object 
	 * 
	 * @param nick nickname of the user 
	 * @return User* pointer to the user
	 */
	user 	*getUser(int fd);

	/**
	 * @brief Get the password of the server
	 * 
	 */
	std::string		getServerPassword( void );

	/**
	 * @brief Get the Channel object
	 * 
	 * @param name recup the channel with name
	 * @return channels* return pointer to the chan
	 */
	// channels	*getChannel(std::string name);

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
	command     recup_cmd( std::string & args ) const;

	void		deleteUser(int fd);

};

# endif 