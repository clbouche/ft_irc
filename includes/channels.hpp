/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channels.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:39:29 by elaachac          #+#    #+#             */
/*   Updated: 2022/06/13 12:19:10 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		CHANNELS_HPP
# define	CHANNELS_HPP

# include "IrcServer.hpp"
# include "user.hpp"
# include "headers.hpp"

class user;

class channels
{
	private:

		std::string						_mode;
		std::string						_modeParams;
		std::string						_name;
		std::string						_topic;
		std::string						_password;
		std::map<int, user *>			_currentUsers;
		std::vector<std::string>		_banUsers;
		bool							_passSet;
		int								_userLimit;
		int								_nbUsers;
		user							*_oper;

	public:

		channels();
		channels(std::string name, user	*chanOperator);
		~channels();

		std::string				getName();
		std::string				getMode();
		std::string				getModeParams();
		user					*getOper();
		std::map<int, user*>&	getUsers();
		std::string				getTopic();
		std::string				getPassword();
		int						getUserLimit();
		int						getNbUsers();
		bool					getPassSet();


		void					setName(std::string name);
		void					setOper(user *oper);
		void					setTopic(std::string topic);
		void					setMode(std::string mode);
		void					setModeParams(std::string mode);
		
		void					removeMode(std::string mode);
		void					removeModeParams(std::string mode);

		void					addUser(user *newUser);
		bool					UserInChan(user *user);
		bool					UserIsBan(user *currentUser);

};


#endif