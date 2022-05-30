/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:25:28 by clbouche          #+#    #+#             */
/*   Updated: 2022/05/30 15:44:58 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.hpp"
#include "../includes/utils.hpp"
#include "../includes/commands.hpp"
#include "../includes/channels.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"
 
void    cmd_NULL( IrcServer *serv, user	*currentUser, std::string & args )
{
	(void)serv;
	(void)currentUser;
	(void)args;
	std::cout << "cmd not found" << std::endl;
}

/**
 * @brief Permet de delimiter la commande (pour l'envoyer a la bonne fonction)
 * des arguments, stocker dans une meme string pour definir le parsing selon 
 * la commande.
 * 
 * @param args L'integralite des arguments envoye par le user sans parsing
 * @param IRC Le serveur
 * @param currentUser L'utilisateur qui a envoie la commande
 */
void    parse_cmd(std::string args, IrcServer *IRC, user *currentUser)
{
	std::vector<std::string>		commands;
	std::string						args_of_commands, cmd_to_find;
	
	commands = ft_split(args, "\n");
	std::string	tmp = commands.front(); //la cmd elle meme + args
	size_t	pos = tmp.find_first_of(' '); //recuperer la position du 1e espace de notre commands
	
	if (pos != std::string::npos) //si cet espace ne se trouve pas a la fin de notre string = pas d'args
	{
		cmd_to_find = tmp.substr(0, pos); //recuperer le premier mot de la ligne
		args_of_commands = tmp.substr(pos, tmp.length()); //stocker le reste des args
	}
	else 
	{
		cmd_to_find = tmp.substr(0, pos);
		args_of_commands = "";
	}
	IRC->recup_cmd(cmd_to_find)(IRC, currentUser, args_of_commands);
}
