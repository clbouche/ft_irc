/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IrcServer.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:28:17 by clbouche          #+#    #+#             */
/*   Updated: 2022/05/17 12:02:18 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IRCSERVER_HPP
# define IRCSERVER_HPP

#include <map>
#include "tcpServer.hpp"
// #include "User.hpp"


class   IrcServer {

    public:
    
    tcpServer       _tcpServer;
    typedef	void	(*function_for_cmd)(IrcServer *, int, std::string &);


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