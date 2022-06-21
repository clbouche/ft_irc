/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:25:28 by clbouche          #+#    #+#             */
/*   Updated: 2022/06/16 18:12:13 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.hpp"
#include "../includes/commands.hpp"
#include "../includes/channels.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"
#include "../includes/utils.hpp"

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
	IrcServer::command				cmd_ptr;
	
	std::cout << YELLOW << currentUser->getNickName()  << " says " << END <<  args << std::endl;

	commands = ft_split(args, "\n");
	while(commands.size())
	{
		std::string	tmp = trim_copy(commands.front()); //la cmd elle meme + args
		size_t	pos = tmp.find_first_of(' '); //recuperer la position du 1e espace de notre commands
		
		if (pos != std::string::npos) //si cet espace ne se trouve pas a la fin de notre string = pas d'args
		{
			cmd_to_find = tmp.substr(0, pos); //recuperer le premier mot de la ligne
			args_of_commands = trim_copy(tmp.substr(pos + 1, tmp.length())); //stocker le reste des args
		}
		else 
		{
			cmd_to_find = tmp.substr(0, pos);
			args_of_commands = "";
		}
		cmd_ptr = IRC->recup_cmd(cmd_to_find);
		if (currentUser->getConnexion() == false && (cmd_ptr != &cmd_user && cmd_ptr != &cmd_nick && cmd_ptr != &cmd_pass
				&& cmd_ptr != &cmd_NULL))
		{
			IRC->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), 
							send_replies(451, currentUser, IRC)));
			return ;
		}
		IRC->recup_cmd(cmd_to_find)(IRC, currentUser, args_of_commands);
		commands.erase(commands.begin());
	}
}
