/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channels.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:31:24 by elaachac          #+#    #+#             */
/*   Updated: 2022/06/07 16:54:00 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/channels.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/tcpServer.hpp"
#include "../includes/user.hpp"
#include "../includes/commands.hpp"
#include "../includes/headers.hpp"

	/* ------------------------------------------------------------- */
	/* ------------------------ CONSTRUCTORS ----------------------- */	
	/* ------------------------------------------------------------- */

channels::channels() : _topic("")
{
}

channels::channels(std::string name, user *chanOperator) : _topic("")
{
	// if (CHECK_NAME == ok) // ->> CHECK IF THE NAME RESPECT THE NORM
	// {
		this->setName(name);
	// }
	this->setOper(chanOperator);
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

user		*channels::getOper()
{
	return (this->_oper);
}

std::map<int, user*>&	channels::getUsers()
{
	return (this->_currentUsers);
}

std::string			channels::getTopic()
{
	return (this->_topic);
}

void		channels::setName(std::string name)
{
	this->_name = name;
}

void		channels::setOper(user *oper)
{
	this->_oper = oper;
}

void		channels::setTopic(std::string topic)
{
	this->_topic = topic;
}

void		channels::addUser(user *newUser)
{
	this->_currentUsers.insert(std::make_pair(newUser->getSdUser(), 	newUser));
}

bool		channels::UserInChan(user *user)
{
	if (getUsers().find(user->getSdUser()) != getUsers().end())
		return true;
	return false;
}
