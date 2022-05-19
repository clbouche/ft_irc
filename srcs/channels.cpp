/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channels.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:31:24 by elaachac          #+#    #+#             */
/*   Updated: 2022/05/19 18:18:02 by elaachac         ###   ########.fr       */
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
	// if (CHECK_NAME == ok) // ->> CHECK IF THE NAME RESPECT THE NORM
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


void		channels::addUser(user &newUser)
{
	user*	tmp = new user(newUser);
	this->getUsers().insert(std::make_pair(newUser.getSdUser(), tmp));
	std::cout << newUser.getNickName() << " has appeared " << std::endl;
	std::map<int, user*>::iterator it;
	for ( it = this->getUsers().begin(); it != this->getUsers().end(); it++)
        std::cout << "USERS : " << it->first;
}

// void		channels::addUser(user newUser)
// {
// 	// user userToAdd = new user(newUser);
// 	this->_currentUsers.insert(std::make_pair(newUser.getSdUser(), &newUser));
// 	std::map<int, user*>::const_iterator it;
// 	int i = 0;
// 	//display all users
// 	// std::map<int, user*>::const_iterator user_it = this->getUsers().begin();
// 	// for (it = this->getUsers().begin(); it != this->getUsers().end(); it++)
// 	for(it = this->getUsers().begin(), i = this->getUsers().size(); i != 0; i--)
//         {
// 			std::cout << "enter: ";
//             std::cout << "DISPLAY USERS:" << it->first << std::endl;
// 			// it++;
//         }
// }