#include "Server.h"

#include <iostream>

Server::Server(int port)
	: serverPort(port)
{
	if (listener.listen(serverPort) != sf::Socket::Done)
	{
		std::cout << "The server couldn't listen to the selected port." << std::endl;
		toCloseServer = true;
	}

	clients.push_back(new sf::TcpSocket());
	clients[0]->setBlocking(false);
}

Server::~Server()
{
}

void Server::run()
{
	std::cout << "The server is running..." << std::endl;

	while (true)
	{
		// iterating through each socket
		for (int i = 0; i < clients.size(); i++)
		{
			// if it's the last socket
			if (i == (clients.size() - 1))
			{
				// use this last socket to check if new clients connect to the server
				// if a new client connected, create a new last socket to check if new clients connect to the server
				if (listener.accept(*clients[i]) == sf::Socket::Done)
				{
					std::cout << "A new client connected to the server!" << std::endl;
					clients.push_back(new sf::TcpSocket());
					clients[clients.size() - 1]->setBlocking(false);
				}
			}
			// if it's any but the last socket (so a connected client)
			else
			{
				// if anything is received, print it on the screen
				if (clients[i]->receive(packetToReceive) == sf::Socket::Done)
				{
					packetToReceive >> receivedText;
					std::cout << "Message received from the client[";
					std::cout << clients[i]->getRemoteAddress().toString();
					std::cout << "]: " << receivedText << std::endl;
				}
			}
		}

		if (toCloseServer == true)
		{
			return;
		}
	}
}
