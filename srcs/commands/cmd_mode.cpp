
#include "../includes/headers.hpp"
#include "../includes/commands.hpp"
#include "../includes/channels.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"
#include "../includes/utils.hpp"

static bool check_args(std::string target, std::string *mode, std::string modeParams, user *currentUser, IrcServer *serv)
{
	(void)modeParams;
	(void)mode;
	(void)currentUser;
	(void)serv;
	(void)target;
	std::string toRemove;

	if (*mode != "")
	{
		size_t i = 0;
		while (i < mode->length())
		{
			if (i == 0)
			{
				if (strchr("+-", mode->c_str()[0]) == NULL)
					return (false);
				i++;
			}
			if (strchr(USERSMODES, mode->c_str()[i]) == NULL)
			{
				std::string errorFlag;
				errorFlag += mode->c_str()[i]; // send_replies() need a string as an argument
				toRemove += errorFlag;
				serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), send_replies(472, currentUser, serv, errorFlag, target)));
			}
			i++;
		}
		if (toRemove.size() > 0)
		{
			i = 0;
			while (toRemove.c_str()[i])
			{
				mode->erase(std::remove(mode->begin(), mode->end(), toRemove.c_str()[i]));
				i++;
			}
		}
	}
	return (true);
}

static bool check_target(std::string target, user *currentUser, IrcServer *serv)
{
	if (target == "")
	{
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), send_replies(461, currentUser, serv, "MODE")));
		return (false);
	}
	return (true);
}

void channelMode(channels *targetChannel, std::string mode, std::string modeParams, user *currentUser, IrcServer *serv)
{
	(void)currentUser;
	// if (modeParams != "")
	// {
		std::vector<std::string>	paramsVector= ft_split(modeParams, " ");
		std::string	paramToUse = "";
		std::string	toErase = "";
	// }
	if (mode.c_str()[0] == '+')
	{
		// if (mode.find("o") != std::string::npos)
		// {
		// 	mode.erase(std::remove(mode.begin(), mode.end(), 'o'));
		// 	targetChannel->addOper(userParam);
		// }
		int i = 0;
		while (mode.c_str()[i])
		{
			switch (mode.c_str()[i])
			{
				case 'o':
					toErase += 'o';
					if (paramsVector.size() > 0)
					{
						paramToUse = trim_copy(paramsVector.front());
						user *userParam = serv->getUserByNick(paramToUse);
						targetChannel->addOper(userParam);
					}
			}
			i++;
		}
		if (toErase.size() > 0)
		{
			int j = 0;
			while (toErase.c_str()[j])
			{
				mode.erase(std::remove(mode.begin(), mode.end(), toErase.c_str()[j]));
				j++;
			}
		}
		targetChannel->setMode(mode);
	}
	else if (mode.c_str()[0] == '-')
	{
		// SWITCH - 
		// if (mode.find("o") != std::string::npos)
		// {
		// 	mode.erase(std::remove(mode.begin(), mode.end(), 'o'));
		// 	targetChannel->removeOper(userParam);
		// }
		// targetChannel->removeMode(mode);
		int i = 0;
		while (mode.c_str()[i])
		{
			switch (mode.c_str()[i])
			{
				case 'o':
					toErase += 'o';
					if (paramsVector.size() > 0)
					{
						paramToUse = trim_copy(paramsVector.front());
						user *userParam = serv->getUserByNick(paramToUse);
						targetChannel->removeOper(userParam);
					}
			}
			i++;
		}
	}
}

// static	bool	isOper(std::string target, user *currentUser)
// {
// 	if (currentUser->isChanInList(target) == true)
// 	{
// 		if (currentUser->findChanInList(target)->getOper().find(currentUser->getNickName()) == currentUser->findChanInList(target)->getOper().end())
// 			return (false);
// 	}
// 	return (true);
// }

void cmd_mode(IrcServer *serv, user *currentUser, std::string &args)
{
	(void)serv;
	(void)currentUser;
	(void)args;
	size_t pos = args.find_first_of(" ");
	std::string target = args.substr(0, pos);
	std::string tmp = args.substr(pos + 1, args.length());
	size_t tmpPos = tmp.find_first_of(" ");
	std::string mode;
	std::string modeParams = "";

	pos == std::string::npos ? mode = "" : mode = args.substr(pos + 1 - mode.length(), tmpPos);
	tmpPos == std::string::npos ? modeParams = "" : modeParams = tmp.substr(tmpPos + 1, tmp.length());

	// std::cout << "TARGET : {" << target << "}" << std::endl << "MODE : {" << mode << "}" << std::endl << "MODEPARAMS : {" << modeParams << "}" << std::endl;
	if (check_target(target, currentUser, serv))
	{
		if (strchr(CHANNEL_PREFIX, target.c_str()[0]) != NULL)
		{
			if (currentUser->isOper(target))
			{
				if (check_args(target, &mode, modeParams, currentUser, serv))
				{
					if (serv->currentChannels.find(target) != serv->currentChannels.end())
					{
						std::cout << RED << "TARGET IS A CHANNEL" << END << std::endl;
						if (currentUser->isChanInList(target) == true)
						{
							channels *targetChannel = currentUser->findChanInList(target);
							channelMode(targetChannel, mode, modeParams, currentUser, serv);
							serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), send_replies(324, currentUser, serv, targetChannel->getName(), targetChannel->getMode(), targetChannel->getModeParams())));
						}
						else
							serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), send_replies(442, currentUser, serv, target)));
					}
					else
						serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), send_replies(403, currentUser, serv, target)));
				}
			}
			else
				serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), send_replies(482, currentUser, serv, target)));
		}
		else
		{
			if (check_args(target, &mode, modeParams, currentUser, serv))
			{
				user *userTarget = serv->getUserByNick(target);
				if (userTarget == NULL)
				{
					serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), send_replies(502, currentUser, serv)));
					return;
				}
				if (mode.c_str()[0] == '+')
				{
					if (mode.find("o") != std::string::npos)
						mode.erase(std::remove(mode.begin(), mode.end(), 'o'));
					userTarget->setMode(mode);
				}
				else if (mode.c_str()[0] == '-')
				{
					userTarget->removeMode(mode);
				}
				serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(), send_replies(221, currentUser, serv, currentUser->getMode())));
			}
		}
	}
}