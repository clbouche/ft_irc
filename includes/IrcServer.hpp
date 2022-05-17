/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IrcServer.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:28:17 by clbouche          #+#    #+#             */
/*   Updated: 2022/05/17 13:33:20 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IRCSERVER_HPP
# define IRCSERVER_HPP

#include <map>
#include "tcpServer.hpp"
#include "user.hpp"


class   IrcServer {

	private:

	std::string     _command[3];

	public:
	
	std::map<int, user>	usersMap;
	tcpServer			_tcpServer;
	
	/**
	 * @brief Construct a new Irc Server object
	 * 
	 */
	IrcServer( int port);

	void    parse_cmd(char *cmd, IrcServer *server);

	void    pass(void);
	void    nick(void);
	void    user(void);

};

# endif 