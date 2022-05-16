/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IrcServer.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:28:17 by clbouche          #+#    #+#             */
/*   Updated: 2022/05/16 18:20:25 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IRCSERVER_HPP
# define IRCSERVER_HPP

#include <map>
#include "tcpServer.hpp"
// #include "User.hpp"


class   IrcServer {

    private:

    std::string     _command[3];

    public:
    
    tcpServer   _tcpServer;
    
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