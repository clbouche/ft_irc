/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:39:55 by elaachac          #+#    #+#             */
/*   Updated: 2022/06/14 10:23:29 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		USER_HPP
# define	USER_HPP

# include "headers.hpp"

class channels;

class user
{

	protected:

		//user's names
		std::string				_nickName;
		std::string				_realName;
		std::string				_userName;
		std::string				_hostName;
		std::string				_mode; // mode(s) of the users, a string wth all the modes
		bool					_checkPassword;
		bool					_isOper; // is the user operator or not
		bool					_welcomeMsg;
		bool					_isConnected; // did the user give the password ?
		int						_sdUser; // a token to identify the maybe the sd used for the user ?
		int						_channelsJoined;
		std::list<channels *>	_listOfChans;

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
		user(int sd, std::string hostname);

		/**
		 * @brief Construct a new user object
		 * @param src the user we want to copy
		 */
		user(const user &src);

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
		 * @brief Get the Host Name object
		 * 
		 */
		std::string getHostNameUser();

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
		 * @brief Get the Connexion object
		 * 
		 * @return true if the user is already connected to the server
		 * @return false if not
		 */
		bool	getConnexion();

		/**
		 * @brief Get the Channels Joined object
		 * 
		 * @return int numbers of channels where the user is
		 */
		int		getChannelsJoined();

		/**
		 * @brief Get the List Of Chans object
		 * 
		 * @return std::list<channels *> list of all the users's channels
		 */
		std::list<channels *>	getListOfChans();

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
		 * @brief Set the Host Name object
		 * 
		 * @param hostname the name of the user's hostname
		 */
		void	setHostName(std::string hostname);

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

		/**
		 * @brief Set true if the user is connected
		 * Set false if not
		 * 
		 */
		void	setConnexion(bool connect);

		/**
		 * @brief Set the nb of the chans
		 * 
		 */
		void	setChannelsJoined(int	nb);

		/**
		 * @brief Set the Channels Joined object
		 * 
		 * @param chan Add a channel where the user is in
		 */
		void	setListOfChans(channels *chan);


		void	removeChan(channels *channel);

		
};


#endif