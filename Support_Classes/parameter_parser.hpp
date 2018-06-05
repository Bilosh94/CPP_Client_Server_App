//	Autor:	Martin Biloš
//	Co:		CPP_Client_Server_App
//	Důvod:	Header třídy třídění parametrů

#pragma once

#include <iostream>
#include <string>

//Server -m mode -p port

//Klient -h host -p port

class ParameterParser
{
private:
	bool m_error {false};
	bool m_mode {false};
	int m_port {0};
	std::string m_host {""};

public:
	ParameterParser(int t_argc, char* t_argv[]);
	~ParameterParser();
	std::string getHost();
	bool getError();
	bool getMode();
	int getPort();
};