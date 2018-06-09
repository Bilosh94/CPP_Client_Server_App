//	Autor:	Martin Biloš
//	Co:		CPP_Client_Server_App
//	Důvod:	Header main souboru pro server

#pragma once

#include <iostream>
#include "server_network.hpp"
#include "../Support_Classes/parameter_parser.hpp"

//Třída starající se o celý průchod přes vlákno (musí zajistit obousměrnou komunikaci a její "překlad")
class ThreadMainetence
{
public:
	ThreadMainetence();
	~ThreadMainetence();

private:
	//Síťový objekt
	//Databázový objekt
	//metody pro propojení
};
