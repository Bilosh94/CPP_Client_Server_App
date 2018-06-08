//	Autor:	Martin Biloš
//	Co:		CPP_Client_Server_App
//	Důvod:	Header třídy komunikace přes síť pro server

#pragma once

#include "../Support_Classes/network.hpp"

class SerNetwork : Network
{
public:
	SerNetwork(int t_port);
	void initialize();
	int Accept();
private:
	struct sockaddr_in m_servAddress;
	struct sockaddr_in m_cliAddress;
	int m_port;
};