/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:40:05 by elaachac          #+#    #+#             */
/*   Updated: 2022/05/18 11:40:05 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/user.hpp"

user::user() : _nickName(""), _realName(""), _userName(""), _mode(""), _isOper(false)//, _isConnected(false),
					
{
};

user::user(int sd) : _nickName(""), _realName(""), _userName(""),  _mode(""), _isOper(false), _sdUser(sd)//, _isConnected(false)
					
{
}

user::~user()
{
}

		/* ------------------------------------------------------------- */
		/* ------------------------- FUNCTIONS ------------------------- */	
		/* ------------------------------------------------------------- */
	std::string	user::getNickName()
	{
		return (this->_nickName);
	}

	std::string	user::getRealName()
	{
		return (this->_realName);
	}

	std::string	user::getUserName()
	{
		return (this->_userName);
	}

	std::string	user::getMode()
	{
		return (this->_mode);
	}

	int			user::getSdUser()
	{
		return (this->_sdUser);
	}

	void	user::setNickName(std::string nickname)
	{
		this->_nickName = nickname;
	}

	void	user::setRealName(std::string realname)
	{
		this->_realName = realname;
	}

	void	user::setMode(std::string mode)
	{
		this->_mode = mode;
	}

	void	user::setOper()
	{
		this->_isOper = true;
	}