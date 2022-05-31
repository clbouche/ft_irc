/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:20:47 by clbouche          #+#    #+#             */
/*   Updated: 2022/05/31 16:35:12 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include "headers.hpp"
#include "IrcServer.hpp"

std::vector<std::string>		ft_split(std::string args, std::string delim);
bool							check_connexion(user *currentUser, int sd);




#endif