/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_motd.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:04:48 by clbouche          #+#    #+#             */
/*   Updated: 2022/06/03 10:17:13 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.hpp"
#include "../includes/commands.hpp"
#include "../includes/channels.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"

void    cmd_motd( IrcServer *serv, user *currentUser, std::string & args )
{
    // if (check_args(serv, currentUser, args) == true)
    // {
        
    // }
    std::cout << "enter in cmd motd" << std::endl;
    (void)serv;
    (void)currentUser;
	(void)args;
}