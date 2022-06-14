
#include "../includes/headers.hpp"
#include "../includes/commands.hpp"
#include "../includes/channels.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"

void    cmd_part( IrcServer *serv, user *currentUser, std::string & args )
{
	std::string					chan_name;
	channels					*chan;
	size_t						j = 0;
    size_t pos = args.find_first_of(" ");
    std::string					partMsg;
	std::string					chans = args.substr(0, pos);

	if (chans == "")
	{
		serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
					send_replies(461, currentUser, serv, "PART")));
		return ;
	}

    pos == std::string::npos ? partMsg = "" : partMsg = args.substr(pos + 1, args.size());
    std::vector<std::string>	split_chans = ft_split(chans, ",");

	std::vector<std::string>::iterator		it;
	for(it = split_chans.begin(); it != split_chans.end(); it++)
	{
		chan_name = split_chans[j];

		serv->currentChannels.find(chan_name) == serv->currentChannels.end() ? 
			chan = NULL : chan = serv->currentChannels.find(chan_name)->second;

		if (chan == NULL)
		{
			serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
							send_replies(403, currentUser, serv, chan_name)));
		}
		else if (chan->UserInChan(currentUser) == false)
		{
			std::cout << "enter here" << std::endl;
			serv->_tcpServer.add_to_buffer(std::make_pair(currentUser->getSdUser(),
							send_replies(442, currentUser, serv, chan_name)));
		}
		else if (chan->UserInChan(currentUser) == true)
		{
			//on doit faire partir le user du channel 
			//remove users de la list d'users du chan 
			//remove le chan de la liste de chan du user
			//si c'etait le dernier utilisateur du chan, suppr le chan de currentChannels

					// std::string	answer = user_answer(user);

					// answer.append("PART ");
					// answer.append(chan_name);
					// if (msg_part != "")
					// {
					// 	answer.append(" :");
					// 	answer.append(msg_part);
					// }
					// answer.append("\r\n");

					// chan.second->send_all(serv, answer);
					// chan.second->kickUser(user);
					// if (chan.second->getMembersCount() == 0)
					// {
					// 	serv->remove_channel(chan_name);
					// }
		}
		j++;
	}     
}