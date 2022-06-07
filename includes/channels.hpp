/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channels.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:39:29 by elaachac          #+#    #+#             */
/*   Updated: 2022/06/07 16:42:44 by clbouche         ###   ########.fr       */
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
		std::string				_topic;
		std::map<int, user *>	_currentUsers;
		user					*_oper;

	public:

		channels();
		channels(std::string name, user	*chanOperator);
		~channels();

		std::string				getName();
		user					*getOper();
		std::map<int, user*>&	getUsers();
		std::string				getTopic();

		void					setName(std::string name);
		void					setOper(user *oper);
		void					setTopic(std::string topic);

		void					addUser(user *newUser);	
		bool					UserInChan(user *user);	
};


#endif