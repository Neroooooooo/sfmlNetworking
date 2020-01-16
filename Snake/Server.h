#pragma once

#include <SFML/Network.hpp>
#include <vector>

class Server
{
public:
	Server(int port = 20000);
	~Server();

	void run();

private:
	sf::TcpListener listener;
	std::vector<sf::TcpSocket*> clients;

	int serverPort;

	std::string receivedText;
	sf::Packet packetToReceive;

	bool toCloseServer = false;
};

