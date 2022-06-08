/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_motd.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:04:48 by clbouche          #+#    #+#             */
/*   Updated: 2022/06/08 18:00:51 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.hpp"
#include "../includes/commands.hpp"
#include "../includes/channels.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"
#include "../includes/utils.hpp"

void    cmd_motd(IrcServer *serv, user *currentUser, std::string & args)
{
    (void)args;
    std::fstream    motd_file;
    std::string     line;
    
    motd_file.open(MOTD_FILE, std::ios::in);
    if (motd_file && motd_file.is_open())
    {
        serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), 
                                send_replies(375, currentUser, serv, 
                                serv->_tcpServer.getHostname())));
        while (getline(motd_file, line))
        {
            serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
                                    send_replies(372, currentUser, serv, line)));
            
        }
        serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
                                send_replies(376, currentUser, serv)));
      motd_file.close();  
    }
    else
        serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
                            send_replies(422, currentUser, serv)));
    
}
