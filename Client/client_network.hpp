//	Autor:	Martin Biloš
//	Co:		CPP_Client_Server_App
//	Důvod:	Header třídy komunikace přes síť pro klienta

#pragma once

#include "../Support_Classes/network.hpp"
#include <netinet/in.h>
#include <arpa/inet.h>

class CliNetwork : public Network
{
public:
	CliNetwork(std::string t_host, int t_port);
	~CliNetwork();
	void initialize();
private:
	struct sockaddr_in m_servAddress;
	std::string m_host;
	int m_port {-87};
};