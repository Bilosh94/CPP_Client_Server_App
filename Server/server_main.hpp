//	Autor:	Martin Biloš
//	Co:		CPP_Client_Server_App
//	Důvod:	Header main souboru pro server

#pragma once

#include <iostream>
#include "server_network.hpp"
#include "../Support_Classes/parameter_parser.hpp"
#include "../Support_Classes/constants.hpp"

//Třída starající se o celý průchod přes vlákno (musí zajistit obousměrnou komunikaci a její "překlad")
class ThreadMainetence
{
public:
	ThreadMainetence();
	~ThreadMainetence();
	void setSocket(int t_socket);
	void prubeh();

private:
	int m_socket {NO_SOCKET};
	//Síťový objekt
	//Databázový objekt
	//metody pro propojení
};
