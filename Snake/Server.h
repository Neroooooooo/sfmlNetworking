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
	// the server tcp listener
	sf::TcpListener listener;

	// a container containing a socket for each client
	std::vector<sf::TcpSocket*> clients;

	// haven't used this, might need in future idk
	int serverPort;

	// anything received from a client should be stored in this string, to then be displayed on the screen
	std::string receivedText;
	sf::Packet packetToReceive;

	// when this is true, the server closes
	bool toCloseServer = false;
};

