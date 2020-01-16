#pragma once

#include <SFML/Network.hpp>

class Client
{
public:
	Client(std::string ip = "", int port = 20000);
	~Client();

	void run();

private:
	// the socket used to communicate with the server
	sf::TcpSocket socket;

	// the port and ip address of the server
	// I didn't use this so far, might use in future
	sf::IpAddress serverIp;
	int serverPort;

	// this string is supposed to be send to the server
	std::string text = "";
	sf::Packet packetToSend;

	// when this is true, the client closes
	bool toCloseClient = false;
};

