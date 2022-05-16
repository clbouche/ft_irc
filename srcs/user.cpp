#include"../includes/user.hpp"

user::user() : _isOper(false)
{
};

user::user(int sd) : _isOper(false), _isConnected(false), _sdUser(sd)
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