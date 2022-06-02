/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channels.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:39:29 by elaachac          #+#    #+#             */
/*   Updated: 2022/06/02 14:58:54 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		CHANNELS_HPP
# define	CHANNELS_HPP

# include "config.hpp"
# include "IrcServer.hpp"
# include "user.hpp"
#include "channels.hpp"

class channels
{
	private:

		std::string				_mode;
		std::string				_name;
		std::map<int, user *>	_currentUsers;
		user					*_oper;

	public:

		channels();
		channels(std::string name, user	*chanOperator);
		~channels();

		std::string				getName();
		user					*getOper();
		std::map<int, user*>	getUsers();

		void					setName(std::string name);
		void					setOper(user *oper);
		void					addUser(user *newUser);		
};


#endif