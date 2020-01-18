#pragma once

#include <SFML/Network.hpp>
#include <vector>
#include <thread>

class Server
{
public:
	Server(int port = 20000);
	~Server();

	void run();

private:
	// not implemented yet, this will send the packet received from client 'except' to all connected clients, but 'except'.
	void sendToTheRestOfTheClients(int except, sf::Packet packet);

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

	// not used yet, will be the packet sent to other clients
	sf::Packet packetToSend;

	// when this is true, the server closes
	bool toCloseServer = false;
};

