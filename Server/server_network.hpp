//	Autor:	Martin Biloš
//	Co:		CPP_Client_Server_App
//	Důvod:	Header třídy komunikace přes síť pro server
//	TODO:	Oddělit konstruktory se stejným typem (teoreticky short x int, ale nedostačující)

#pragma once

#include "../Support_Classes/network.hpp"

class SerNetwork : public Network
{
public:
	// jak oddělit 2 konstruktory se stejným 
	SerNetwork(int t_socket, bool t_type);
	SerNetwork(int t_port);
	~SerNetwork();
	void initialize();
	int prijmuti();
private:
	struct sockaddr_in m_servAddress;
	struct sockaddr_in m_cliAddress;
	int m_port {NO_PORT};
};