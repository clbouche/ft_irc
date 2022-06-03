/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_motd.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:04:48 by clbouche          #+#    #+#             */
/*   Updated: 2022/06/03 17:15:20 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.hpp"
#include "../includes/commands.hpp"
#include "../includes/channels.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"

void    cmd_motd( IrcServer *serv, user *currentUser, std::string & args)
{
    (void)args;
    const char      *welcome_msg = WELCOME_MESSAGE;
    
    serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), 
							send_replies(375, currentUser, serv, 
                            serv->_tcpServer.getHostname())));
    serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
                            send_replies(372, currentUser, serv, welcome_msg)));
    serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
                            send_replies(376, currentUser, serv)));
}