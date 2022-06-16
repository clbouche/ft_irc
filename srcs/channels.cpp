/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channels.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:31:24 by elaachac          #+#    #+#             */
/*   Updated: 2022/06/16 11:13:18 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/channels.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/tcpServer.hpp"
// #include "../includes/user.hpp"
#include "../includes/commands.hpp"
#include "../includes/headers.hpp"

	/* ------------------------------------------------------------- */
	/* ------------------------ CONSTRUCTORS ----------------------- */	
	/* ------------------------------------------------------------- */

channels::channels() : _mode("+"), _modeParams(""), _topic("")
{
}

channels::channels(std::string name, user *chanOperator) :  _mode("+"), _modeParams(""), _topic(""), _password(""), 
									_passSet(false), _userLimit(INT32_MAX), _nbUsers(0)
{
	// if (CHECK_NAME == ok) // ->> CHECK IF THE NAME RESPECT THE NORM
	// {
		this->setName(name);
	// }
	this->addOper(chanOperator);
	this->addUser(chanOperator);
}

channels::~channels()
{
}

	/* ------------------------------------------------------------- */
	/* -------------------------- FUNCTIONS ------------------------ */	
	/* ------------------------------------------------------------- */

std::string	channels::getName()
{
	return (this->_name);
}

std::string	channels::getMode()
{
	return (this->_mode);
}

std::string	channels::getModeParams()
{
	return (this->_modeParams);
}

std::map<std::string, user *>	&channels::getOper()
{
	return (this->_operators);
}

std::map<int, user*>&	channels::getUsers()
{
	return (this->_currentUsers);
}

std::string			channels::getTopic()
{
	return (this->_topic);
}

std::string			channels::getPassword()
{
	return (this->_password);
}

std::vector<std::string> &	channels::getBanList()
{
	return (this->_banUsers);
}


int					channels::getUserLimit()
{
	return (this->_userLimit);
}

int					channels::getNbUsers()
{
	return (this->_nbUsers);
}

bool				channels::getPassSet()
{
	return (this->_passSet);
}

void		channels::setName(std::string name)
{
	this->_name = name;
}

void		channels::setTopic(std::string topic)
{
	this->_topic = topic;
}

void		channels::setMode(std::string newMode)
{
	size_t	inMode, i = 0;

	while (i < newMode.length())
	{
		inMode = this->_mode.find_first_of(newMode.c_str()[i]);
		if (inMode == std::string::npos)
			this->_mode += newMode.c_str()[i];
		i++;
	}
}

void		channels::setModeParams(std::string newModeParams)
{
	size_t	inModeParams, i = 0;

	while (i < newModeParams.length())
	{
		inModeParams = this->_modeParams.find_first_of(newModeParams.c_str()[i]);
		if (inModeParams == std::string::npos)
			this->_modeParams += newModeParams.c_str()[i];
		i++;
	}
}

void		channels::setPassword(std::string newPassword)
{
	this->_password = newPassword;
}

void		channels::setPassSet(bool isPass)
{
	this->_passSet = isPass;
}

void		channels::setNbUsers(int newLimit)
{
	this->_userLimit = newLimit;
}

void		channels::removeMode(std::string newMode)
{
	size_t	inMode, i = 0;

	while (i < newMode.length())
	{
		inMode = this->_mode.find_first_of(newMode.c_str()[i]);
		if (inMode != std::string::npos)
			this->_mode.erase(std::remove(this->_mode.begin(),this->_mode.end(),newMode.c_str()[i]));
		i++;
	}
}

void		channels::removeModeParams(std::string newModeParams)
{
	size_t	inMode, i = 0;

	while (i < newModeParams.length())
	{
		inMode = this->_mode.find_first_of(newModeParams.c_str()[i]);
		if (inMode != std::string::npos)
			this->_mode.erase(std::remove(this->_mode.begin(),this->_mode.end(),newModeParams.c_str()[i]));
		i++;
	}
}

void		channels::addUser(user *newUser)
{
	this->_currentUsers.insert(std::make_pair(newUser->getSdUser(),	newUser));
}

void		channels::addOper(user *newOper)
{
	this->_operators.insert(std::make_pair(newOper->getNickName(),	newOper));
}

void		channels::addBan(std::string newBan)
{
	this->_banUsers.push_back(newBan);
}

void		channels::removeOper(user *oldOper)
{
	this->_operators.erase(oldOper->getNickName());
}

bool		channels::UserInChan(user *user)
{
	if (getUsers().find(user->getSdUser()) != getUsers().end())
		return true;
	return false;
}

bool		channels::UserIsBan(user *currentUser)
{
	std::vector<std::string>::iterator	it;
	
	it = std::find(_banUsers.begin(), _banUsers.end(), currentUser->getNickName());
	if (it != _banUsers.end())
		return true;
	return false;
}

bool		channels::UserIsBanNick(std::string nick)
{
	std::vector<std::string>::iterator	it;
	
	it = std::find(_banUsers.begin(), _banUsers.end(), nick);
	if (it != _banUsers.end())
		return true;
	return false;
}
