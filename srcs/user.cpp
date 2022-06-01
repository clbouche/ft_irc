/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:40:05 by elaachac          #+#    #+#             */
/*   Updated: 2022/06/01 11:41:43 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/user.hpp"
#include "../includes/headers.hpp"

	user::user() : _nickName(""), _realName(""), _userName(""), _mode(""),
				_checkPassword(false), _isOper(false), _welcomeMsg(false)
				//, _isConnected(false),
	{};

	user::user(int sd) : _nickName(""), _realName(""), _userName(""), 
						_mode(""), _checkPassword(false), _isOper(false),
						_welcomeMsg(false), _sdUser(sd)//, _isConnected(false)
	{}

	user::user(user & src) : _nickName(src._nickName), _realName(src._realName), 
							_userName(src._userName), _mode(src._mode), 
							_checkPassword(src._checkPassword), _isOper(src._isOper),
							_welcomeMsg(src._welcomeMsg), _sdUser(src._sdUser)
	{}

	user::~user()
	{}

		/* ------------------------------------------------------------- */
		/* ------------------------- FUNCTIONS ------------------------- */	
		/* ------------------------------------------------------------- */

	/* ------------------------- GETTER ------------------------- */
	std::string		user::getNickName()
	{
		return (this->_nickName);
	}

	std::string		user::getRealName()
	{
		return (this->_realName);
	}

	std::string		user::getUserName()
	{
		return (this->_userName);
	}

	std::string		user::getMode()
	{
		return (this->_mode);
	}

	bool		user::getCheckPassword()
	{
		return (this->_checkPassword);
	}

	int			user::getSdUser()
	{
		return (this->_sdUser);
	}

	bool		user::getWelcomeMsg()
	{
		return (this->_welcomeMsg);
	}	

	/* ------------------------- SETTER ------------------------- */

	void	user::setNickName(std::string nickname)
	{
		this->_nickName = nickname;
	}

	void	user::setRealName(std::string realname)
	{
		this->_realName = realname;
	}

	void	user::setUserName(std::string username)
	{
		this->_userName = username;
	}

	void	user::setMode(std::string mode)
	{
		this->_mode = mode;
	}

	void	user::setCheckPassword(bool check)
	{
		this->_checkPassword = check;
	}

	void	user::setOper()
	{
		this->_isOper = true;
	}

	void	user::setWelcomeMsg(bool welcomeMsg)
	{
		this->_welcomeMsg = welcomeMsg;
	}

	/* ------------------------- OTHERS ------------------------- */



