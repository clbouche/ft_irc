/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channels.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:39:29 by elaachac          #+#    #+#             */
/*   Updated: 2022/06/16 16:29:39 by clbouche         ###   ########.fr       */
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
		std::map<std::string, user *>	_operators;
		std::vector<std::string>		_banUsers;
		std::vector<std::string>		_InvitList;
		bool							_passSet;
		int								_userLimit;
		int								_nbUsers;

	public:

		channels();
		channels(std::string name, user	*chanOperator);
		~channels();

		std::string						getName();
		std::string						getMode();
		std::string						getModeParams();
		std::map<std::string, user *>	&getOper();
		std::map<int, user*>&			getUsers();
		std::string						getTopic();
		std::string						getPassword();
		std::vector<std::string> &		getBanList();
		int								getUserLimit();
		int								getNbUsers();
		bool							getPassSet();

		void							setName(std::string name);
		void							setTopic(std::string topic);
		void							setMode(std::string mode);
		void							setModeParams(std::string mode);
		void							setPassword(std::string mode);
		void							setPassSet(bool isPass);
		void							setNbUsers(int newLimit);
		
		void							removeMode(std::string mode);
		void							removeModeParams(std::string mode);
		void							removeOper(user *newOper);
		void							removeUser(user *user);

		void							addOper(user *newOper);
		void							addUser(user *newUser);
		void							addBan(std::string	newBan);
		void							addInvit(std::string	newInvit);

		bool							UserIsBanNick(std::string nick);
		bool							UserInChan(user *user);
		bool							UserInChan ( const std::string & user ) const;
		bool							UserIsBan(user *currentUser);
		bool							UserIsInvite(user *currentUser);
		
		void							sendToAllUsers (tcpServer *tcp, std::string msg );
		bool							checkOperator(user *currentUser);

};


#endif