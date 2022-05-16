#ifndef		USER_HPP
# define	USER_HPP

# include <iostream>
# include "config.hpp"

class user
{
private:

	//user's names an pass
	std::string	_password;
	std::string	_nickName;
	std::string	_realName;
	std::string	_userName;
	std::string	_mode; // mode(s) of the users, a string wth all the modes
	bool		_oper; // is the user operator or not
	int			_idUser; // maybe the sd used for the user ?

public:

	/**
	 * @brief Construct a new user object
	 * 
	 */
	user();
	~user();

	/**
	 * @brief Access to 
	 * 
	 */
};


#endif