#pragma once

#include <SFML/Network.hpp>

class Client
{
public:
	Client(std::string ip = "", int port = 20000);
	~Client();

	void run();

private:
	sf::TcpSocket socket;

	sf::IpAddress serverIp;
	int serverPort;

	std::string text = "";
	sf::Packet packetToSend;

	bool toCloseClient = false;
};

