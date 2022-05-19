/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:29:46 by clbouche          #+#    #+#             */
/*   Updated: 2022/05/19 11:36:55 by clbouche         ###   ########.fr       */
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


// void	StrSplit
// 	(std::vector<std::string> &results, std::string const &str, std::string const &delim)
// {
// 	size_t	i(0);

// 	while (i < str.size())
// 	{
// 		size_t delimIdx(str.find(delim, i));
// 		if (delimIdx == std::string::npos)
// 			delimIdx = str.size();
// 		if ((delimIdx - i) > 0)
// 			results.push_back(str.substr(i, delimIdx - i));
// 		i = delimIdx + delim.size();
// 	}
// }






// std::vector<std::string>		ft_split(std::string s, std::string splitter)
// {
// 	std::vector<std::string>	now;
// 	std::string					tmp;
// 	size_t						ret = 0;
// 	size_t						k = 0;

// 	ret = 0;
// 	if (splitter.empty())
// 	{
// 		now.push_back("");
// 		return (now);
// 	}
// 	while (ret < s.length())
// 	{
// 		k = ret;
// 		ret = s.find(splitter, ret);
// 		if (k != ret)
// 		{
// 			if (ret == std::string::npos)
// 				now.push_back(s.substr(k));
// 			else
// 			{
// 				now.push_back(s.substr(k));
// 				now.back().resize(ret - k);
// 			}
// 		}
// 		if (ret == std::string::npos)
// 			break;
// 		ret += splitter.length();
// 	}
// 	return (now);
// }
