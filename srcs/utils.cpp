/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:29:46 by clbouche          #+#    #+#             */
/*   Updated: 2022/05/19 13:28:06 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <vector>

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