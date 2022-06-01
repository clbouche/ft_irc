/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:29:46 by clbouche          #+#    #+#             */
/*   Updated: 2022/06/01 11:57:12 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/user.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/headers.hpp"

/**
 * @brief Permet de savoir si les 3 commandes necessaires a la connexion ont ete complete
 * par le user avant d'envoyer le message d'accueil
 * 
 * @param currentUser l'utilisateur qui tente de se connecter au serveur
 * @return true si les 3 sonts sets (si le password existe)
 * @return false s'il manque une des 3 conditions
 */

bool		check_connexion( user *currentUser)
{
	const char						*message = WELCOME_MESSAGE;
	int								sdUser = currentUser->getSdUser();

	if (currentUser->getNickName() != "" && currentUser->getUserName() != "" && currentUser->getCheckPassword() == true) //faire une comparaison entre le password envoye par le user et celui stocker par le serveur
	{
		if(send(sdUser, message, strlen(message), 0) != (ssize_t)strlen(message) )
			std::cerr << std::strerror(errno) << std::endl;
		std::cout << "Welcome message sent successfully" << std::endl;
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