/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:29:46 by clbouche          #+#    #+#             */
/*   Updated: 2022/06/13 12:00:47 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.hpp"
#include "../includes/user.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/headers.hpp"
#include "../includes/commands.hpp"

/**
 * @brief Permet de savoir si les 3 commandes necessaires a la connexion ont ete complete
 * par le user avant d'envoyer le message d'accueil
 * 
 * @param currentUser l'utilisateur qui tente de se connecter au serveur
 * @return true si les 3 sonts sets (si le password existe)
 * @return false s'il manque une des 3 conditions
 */

bool		check_connexion( user *currentUser, IrcServer *serv)
{
	std::string						args = "";
	const char						*date = DATE;
	const char						*version = VERSION;
	const char						*usersmodes = USERSMODES;
	const char						*channelsmodes = CHANNELSMODES;

	if (currentUser->getNickName() != "" && currentUser->getUserName() != "" 
			&& currentUser->getCheckPassword() == true) 
	{
		// if(send(sdUser, message, strlen(message), 0) != (ssize_t)strlen(message) )
		// 	std::cerr << std::strerror(errno) << std::endl;
		std::cout << "Welcome message sent successfully" << std::endl;
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), 
							send_replies(1, currentUser, serv, 
								currentUser->getNickName(), currentUser->getUserName(),
								currentUser->getHostNameUser())));
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), 
							send_replies(2, currentUser, serv, 
								serv->_tcpServer.getHostname(),version)));
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), 
							send_replies(3, currentUser, serv, date)));
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), 
							send_replies(4, currentUser, serv, 
								serv->_tcpServer.getHostname(), version, 
								usersmodes, channelsmodes)));
		cmd_motd(serv, currentUser, args);
		currentUser->setConnexion(true);
		return true;
	}
	return false;
}

std::vector<std::string>		ft_split(std::string args, std::string delim)
{
	std::vector<std::string>		results;
	size_t							i = 0;

	while(i < args.size())
	{
		size_t 	delimIndex(args.find(delim, i));
		if (delimIndex == std::string::npos)
			delimIndex = args.size();
		if ((delimIndex - i) > 0)
			results.push_back(args.substr(i, delimIndex - i));
		i = delimIndex + delim.size();
	}
	return results;
}
