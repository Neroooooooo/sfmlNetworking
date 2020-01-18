#include <iostream>

#include "Server.h"
#include "Client.h"

int main()
{
	// easier for me to copy paste stuff if I have those printed
	std::cout << "Your local ip: " << sf::IpAddress::getLocalAddress() << std::endl << std::endl;	
	std::cout << "Your public ip: " << sf::IpAddress::getPublicAddress() << std::endl << std::endl;	

	std::cout << "Are you a server(s) or a client(c)?\n>";

	char what;
	std::cin >> what;

	if (what == 's')
	{
		Server server;

		server.run();
	}
	else if (what == 'c')
	{
		std::string ip;
		std::cout << "What's the IP you want to connect to?\n>";
		std::cin >> ip;

		Client client(ip);

		client.run();
	}

	while (true)
	{

	}

	return 0;
}
