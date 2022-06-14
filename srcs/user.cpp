/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:40:05 by elaachac          #+#    #+#             */
/*   Updated: 2022/06/14 12:01:10 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/user.hpp"
#include "../includes/headers.hpp"

	user::user() : _nickName(""), _realName(""), _userName(""), _hostName(""),
				_mode("+"), _checkPassword(false), _isOper(false), _welcomeMsg(false),
				_isConnected(false), _channelsJoined(0)
	{};

	user::user(int sd, std::string hostname) : _nickName(""), _realName(""),
									_userName(""), _hostName(hostname), 
									_mode("+"), _checkPassword(false),
									_isOper(false),_welcomeMsg(false), 
									_isConnected(false), _sdUser(sd),
									_channelsJoined(0)
	{}

	user::user(const user & src) : _nickName(src._nickName), _realName(src._realName), 
							_userName(src._userName), _hostName(src._hostName),
							_mode(src._mode), _checkPassword(src._checkPassword), 
							_isOper(src._isOper), _welcomeMsg(src._welcomeMsg),
							_sdUser(src._sdUser), _channelsJoined(src._channelsJoined)
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

	std::string		user::getHostNameUser()
	{
		return (this->_hostName);
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

	bool		user::getConnexion()
	{
		return (this->_isConnected);
	}

	int			user::getChannelsJoined()
	{
		return (this->_channelsJoined);
	}

	std::list<channels *>	user::getListOfChans()
	{
		return (this->_listOfChans);
	}

	channels	*user::findChanInList(std::string target)
	{
		std::list<channels *>::iterator	it;
		for (it = this->_listOfChans.begin(); it != this->_listOfChans.end(); it++)
		{
			if ((**it).getName() == target)
				return (*it);
		}
		return (NULL);
	}

	bool	user::isChanInList(std::string	target)
	{
		std::list<channels *>::iterator	it;
		for (it = this->_listOfChans.begin(); it != this->_listOfChans.end(); it++)
		{
			if ((**it).getName() == target)
				return (true);
		}
		return (false);
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

	void	user::setMode(std::string newMode)
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

	void	user::removeMode(std::string newMode)
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

	void	user::setConnexion(bool connect)
	{
		this->_isConnected = connect;
	}

	void	user::setChannelsJoined(int	nb)
	{
		this->_channelsJoined += nb;
	}
	
	void	user::IncrementChannelsJoined( void )
	{
		this->_channelsJoined++;
	}

	void	user::setListOfChans(channels *chan)
	{
		_listOfChans.push_back(chan);
	}


	/* ------------------------- OTHERS ------------------------- */

	void	user::removeChan(channels *channel)
	{

		std::cout << "before remove chan" << std::endl;
		std::list<channels *>::iterator it1;
		for ( it1 = this->_listOfChans.begin(); it1 != this->_listOfChans.end(); it1++ )
			std::cout << "[" << (**it1).getName() << "]" << std::endl;
		std::cout << "channeljoined : [" << _channelsJoined << "]" << std::endl;

		
		std::list<channels *>::iterator it;
		for (it = this->_listOfChans.begin(); it != this->_listOfChans.end(); it++)
		{
			if ((*it) == channel)
			{
				_listOfChans.erase(it);
				this->_channelsJoined--;
				break;
			}	
		}


		std::cout << "after remove chan" << std::endl;
		std::list<channels *>::iterator it2;
		for ( it2 = this->_listOfChans.begin(); it2 != this->_listOfChans.end(); it2++ )
			std::cout << "[" << (**it2).getName() << "]" << std::endl;
		std::cout << "channeljoined : [" << _channelsJoined << "]" << std::endl;

	}
