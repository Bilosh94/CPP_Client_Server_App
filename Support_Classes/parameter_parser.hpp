//	Autor:	Martin Biloš
//	Co:		CPP_Client_Server_App
//	Důvod:	Header třídy třídění parametrů

#pragma once

//Server -m mode -p port

//Klient -h host -p port

class ParameterParser
{
private:
	bool m_mode {false};
	int m_port {0};
	string m_host {""};

public:
	ParameterParser(int t_argc, char* t_argv[]);
	~ParameterParser();s
	string getHost();
	bool getMode();
	int getPort();
}