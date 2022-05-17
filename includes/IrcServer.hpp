/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IrcServer.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:28:17 by clbouche          #+#    #+#             */
/*   Updated: 2022/05/17 14:18:53 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IRCSERVER_HPP
# define IRCSERVER_HPP

#include <map>
#include "tcpServer.hpp"
#include "user.hpp"


class   IrcServer {

    public:
    
	std::map<int, user>	usersMap;
    tcpServer       	_tcpServer;
    typedef	void		(*function_for_cmd)(IrcServer *, int, std::string &);


    private:

    // std::string     _command[3];
    std::map<std::string, function_for_cmd>  _pointer_to_valid_cmd;
    void    create_pointer(void);


    public:    
    /**
     * @brief Construct a new Irc Server object
     * 
     */
    IrcServer( int port);

    void    parse_cmd(char *cmd, IrcServer *server);

    function_for_cmd     recup_cmd(std::string cmd);


};

# endif 