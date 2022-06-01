/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:39:55 by elaachac          #+#    #+#             */
/*   Updated: 2022/06/01 11:13:52 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		USER_HPP
# define	USER_HPP

# include <iostream>
# include "config.hpp"

class user
{

	protected:

		//user's names
		std::string		_nickName;
		std::string		_realName;
		std::string		_userName;
		std::string		_mode; // mode(s) of the users, a string wth all the modes
		bool			_checkPassword;
		bool			_isOper; // is the user operator or not
		// bool			_isConnected; // did the user give the password ?
		bool			_welcomeMsg;
		int				_sdUser; // a token to identify the maybe the sd used for the user ?

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
		 * @brief Construct a new user object
		 * @param src the user we want to copy
		 */
		user(user &src);

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
		 * @brief Get the Check Password object
		 * 
		 */
		bool		getCheckPassword();

		/**
		 * @brief Access to the sd
		 * 
		 */
		int		getSdUser();


		/**
		 * @brief Know if welcome msg was already send
		 * 
		 */
		bool	getWelcomeMsg();

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
		 * @brief Set the user name
		 * @param username the username you want to set
		 */
		void	setUserName(std::string username);

		/**
		 * @brief Set the nick name
		 * @param mode the mode you want to set
		 */
		void	setMode(std::string mode);

		/**
		 * @brief Set the Good Password object
		 * 
		 * @param check if the pass send to the client if 
		 * the same password as the one of the server
		 */
		void	setCheckPassword(bool check);

		/**
		 * @brief Set the user as operator
		 * 
		 */
		void	setOper();

		/**
		 * @brief Set true if welcome msg was send
		 * Set false if not 
		 * 
		 */
		void	setWelcomeMsg(bool welcomeMsg);



		bool	check_connexion( void );

		
};


#endif