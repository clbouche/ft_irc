/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:39:55 by elaachac          #+#    #+#             */
/*   Updated: 2022/05/18 11:39:56 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		USER_HPP
# define	USER_HPP

# include <iostream>
# include "config.hpp"

class user
{

	private:

		//user's names
		std::string	_nickName;
		std::string	_realName;
		std::string	_userName;
		std::string	_mode; // mode(s) of the users, a string wth all the modes
		bool		_isOper; // is the user operator or not
//		bool		_isConnected; // did the user give the password ?
		int			_sdUser; // a token to identify the maybe the sd used for the user ?

	public:

		/**
		 * @brief Construct a new user object
		 * 
		 */
		user();
		
		/**
		 * @brief Construct a new user object
		 * @param sd the socket descriptor used for the user
		 */
		user(int sd);

		/**
		 * @brief Destruct a new user object
		 * 
		 */
		~user();

		/**
		 * 
		 * GETTERS
		 * 
		 */
		/**
		 * @brief Access to the nickname
		 * 
		 */
		std::string	getNickName();

		/**
		 * @brief Access to the real name
		 * 
		 */
		std::string	getRealName();

		/**
		 * @brief Access to the username
		 * 
		 */
		std::string	getUserName();

		/**
		 * @brief Access to the mode
		 * 
		 */
		std::string	getMode();

		/**
		 * @brief Access to the sd
		 * 
		 */
		int		getSdUser();

		/**
		 * 
		 * SETTERS
		 * 
		 */
		/**
		 * @brief Set the nick name
		 * @param nickname the nickname you want to set
		 */
		void	setNickName(std::string nickname);

		/**
		 * @brief Set the nick name
		 * @param realname the realname you want to set
		 */
		void	setRealName(std::string realname);

		/**
		 * @brief Set the nick name
		 * @param mode the mode you want to set
		 */
		void	setMode(std::string mode);

		/**
		 * @brief Set the user as operator
		 * 
		 */
		void	setOper();
};


#endif