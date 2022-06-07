/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_motd.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:04:48 by clbouche          #+#    #+#             */
/*   Updated: 2022/06/07 13:37:58 by clbouche         ###   ########.fr       */
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

// void	motd_command(const std::string &line, std::list<Server>::iterator server_it, const MyServ &serv)
// {
// 	std::vector<std::string>	params = ft_split(line, " ");
// 	std::fstream				file;
// 	std::string					motd_line;
// 	std::list<Client>::iterator	client_it;
// 	std::list<Server>::iterator	serv_cible;

// 	if (params.size() < 3)
// 		return ;
// 	if ((client_it = find_client_by_iterator(&params[0][1])) == g_all.g_aClient.end())
// 		return ;
// 	if (params[2] == serv.get_hostname())
// 	{
// 		file.open(serv.get_motd_path().c_str());
// 		if (!file)
// 		{
// 			server_it->push_to_buffer(create_msg(422, client_it, serv));
// 			return ;
// 		}
// 		server_it->push_to_buffer(create_msg(375, client_it, serv, serv.get_hostname()));
// 		while (file)
// 		{
// 			getline(file, motd_line);
// 			if (motd_line.size() > 0 && motd_line.size() <= 80)
// 				server_it->push_to_buffer(create_msg(372, client_it, serv, std::string(motd_line)));
// 		}
// 		server_it->push_to_buffer(create_msg(376, client_it, serv));
// 		file.close();
// 	}
// 	else
// 	{
// 		if ((serv_cible = find_server_by_iterator(params[2])) == g_all.g_aServer.end())
// 		{
// 			server_it->push_to_buffer(create_msg(402, client_it, serv, params[2]));
// 			return ;
// 		}
// 		if (serv_cible->get_hopcount() > 1)
// 			serv_cible->get_server_uplink()->push_to_buffer(line + "\r\n");
// 		else
// 			serv_cible->push_to_buffer(line + "\r\n");
// 	}
// }
