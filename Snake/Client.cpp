#include "Client.h"

#include <iostream>

Client::Client(std::string ip, int port)
	: serverIp(ip), serverPort(port)
{
	sf::Socket::Status status = socket.connect(serverIp, serverPort, sf::seconds(5.0f));

	if (status != sf::Socket::Done)
	{
		std::cout << "The client couldn't connect to the server." << std::endl;
		toCloseClient = true;
	}
	else
	{
		std::cout << "The client is running..." << std::endl;
	}

	socket.setBlocking(true);
}

Client::~Client()
{
	std::cout << "The client stopped unning..." << std::endl;
}

void Client::run()
{

	while (true)
	{
		std::getline(std::cin, text);

		packetToSend << text;

		sf::Socket::Status socketStatus = socket.send(packetToSend);
		if (socketStatus == sf::Socket::Status::Done)
		{
			std::cout << "The message was sent to the server." << std::endl;
			packetToSend.clear();
		}
		else
		{
			std::cout << "The message was NOT sent to the server. Error code: ";
			std::cout << socketStatus << std::endl;
		}

		if (toCloseClient)
		{
			return;
		}
	}
}
