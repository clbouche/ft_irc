/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channels.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:31:24 by elaachac          #+#    #+#             */
/*   Updated: 2022/05/18 16:58:54 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/channels.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/tcpServer.hpp"
#include "../includes/user.hpp"
#include "../includes/commands.hpp"

	/* ------------------------------------------------------------- */
	/* ------------------------ CONSTRUCTORS ----------------------- */	
	/* ------------------------------------------------------------- */

channels::channels()
{
}

channels::channels(std::string name, user *chanOperator)
{
	// if (CHECK_NAME == ok)
	// {
		this->setName(name);
	// }
	this->setOper(chanOperator);
	this->addUser(*chanOperator);
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

std::map<int, user*>	channels::getUsers()
{
	return (this->_currentUsers);
}

void		channels::setName(std::string name)
{
	this->_name = name;
}

void		channels::setOper(user *oper)
{
	this->_oper = oper;
}

void		channels::addUser(user newUser)
{
	this->_currentUsers.insert(std::make_pair(newUser.getSdUser(), &newUser));
}