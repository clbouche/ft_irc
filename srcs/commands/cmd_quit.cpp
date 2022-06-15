
#include "../includes/headers.hpp"
#include "../includes/commands.hpp"
#include "../includes/channels.hpp"
#include "../includes/IrcServer.hpp"
#include "../includes/user.hpp"

void    cmd_quit( IrcServer *serv, user *currentUser, std::string & args )
{
    std::string							quitMsg;
    std::string							sendToPart;
    std::list<channels *>				listOfChans = currentUser->getListOfChans();
	std::list<channels *>::iterator		it;
    args == "" ? quitMsg = " left " : quitMsg = args;
    
    for(it = listOfChans.begin() ; it != listOfChans.end(); it++)
	{
		sendToPart.append((**it).getName());
		if (it != --(listOfChans.end()))
			sendToPart.append(",");
		else
			sendToPart.append(" ");
	}
	sendToPart.append(quitMsg);
	cmd_part(serv, currentUser, sendToPart);
	serv->_tcpServer.closeConnection(currentUser->getSdUser());
	serv->deleteUser(currentUser->getSdUser());

	//envoyer a tous les users le depart de chaque chan : pq part le fait pas wsh??
    //supprimer l'appartenance au socket
}
