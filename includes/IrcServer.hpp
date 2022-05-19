/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IrcServer.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:28:17 by clbouche          #+#    #+#             */
/*   Updated: 2022/05/19 10:53:42 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IRCSERVER_HPP
# define IRCSERVER_HPP

#include <map>
#include <string>
#include "tcpServer.hpp"
#include "user.hpp"
class   IrcServer {

	public:
	
	/**
	 * @brief A map where we store our users
	 * 
	 */
	std::map<int, user>	usersMap;
	
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
	typedef	void	(*command)(IrcServer *, int, std::string &);


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