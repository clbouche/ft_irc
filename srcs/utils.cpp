/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:29:46 by clbouche          #+#    #+#             */
/*   Updated: 2022/06/13 15:13:29 by clbouche         ###   ########.fr       */
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
	const char						*version = VERSION;
	const char						*usersmodes = USERSMODES;
	const char						*channelsmodes = CHANNELSMODES;

	if (currentUser->getNickName() != "" && currentUser->getUserName() != "" 
			&& currentUser->getCheckPassword() == true) 
	{
		std::cout << "Welcome message sent successfully" << std::endl;
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), 
							send_replies(1, currentUser, serv, 
								currentUser->getNickName(), currentUser->getUserName(),
								currentUser->getHostNameUser())));
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), 
							send_replies(2, currentUser, serv, 
								serv->_tcpServer.getHostname(),version)));
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), 
							send_replies(3, currentUser, serv)));
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

void			ft_strToupper ( std::string & str )
{
	for (size_t i = 0; i < str.size(); i++)
	{
		str[i] = std::toupper(str[i]);
	}

}

/**
 * @brief Remove space from start
 *
 * @param s string to trim
 */
void	ltrim ( std::string &s )
{
	s.erase(s.begin(), std::find_if(s.begin(), s.end(),
			std::not1(std::ptr_fun<int, int>(std::isspace))));
}

/**
 * @brief Remove space from end of the string
 *
 * @param s string to rtrim
 */
void	rtrim ( std::string &s )
{
	s.erase(std::find_if(s.rbegin(), s.rend(),
			std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
}

/**
 * @brief Remove space at the beggining and the end of a string
 *
 * @param s String to trim
 */
void	trim ( std::string &s )
{
	ltrim(s);
	rtrim(s);
}

/**
 * @brief Remove space from start
 *
 * @param s string to trim
 */
std::string	ltrim_copy ( std::string s )
{
	ltrim(s);
	return s;
}

/**
 * @brief Remove space from end of the string
 *
 * @param s string to rtrim
 */
std::string	rtrim_copy ( std::string s )
{
	rtrim(s);
	return s;
}

/**
 * @brief Remove space at the beggining and the end of a string
 *
 * @param s String to trim
 */
std::string	trim_copy ( std::string s )
{
	trim(s);
	return s;
}