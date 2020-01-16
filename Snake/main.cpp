#include <iostream>

#include "Server.h"
#include "Client.h"

int main()
{
	// easier for me to copy paste it when both the server and the client have the same ip
	std::cout << "Your ip: " << sf::IpAddress::getLocalAddress() << std::endl << std::endl;

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


	return 0;
}
