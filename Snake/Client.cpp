#include "Client.h"

#include <iostream>

Client::Client(std::string ip, int port)
	: serverIp(ip), serverPort(port)
{
	sf::Socket::Status status = socket.connect(serverIp, serverPort);

	if (status != sf::Socket::Done)
	{
		std::cout << "The client couldn't connect to the server." << std::endl;
		toCloseClient = true;
	}
}

Client::~Client()
{
}

void Client::run()
{
	std::cout << "The client is running..." << std::endl;

	while (true)
	{
		std::getline(std::cin, text);
		packetToSend << text;

		socket.send(packetToSend);

		if (toCloseClient)
		{
			return;
		}
	}
}
