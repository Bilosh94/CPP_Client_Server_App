//	Autor:	Martin Biloš
//	Co:		CPP_Client_Server_App
//	Důvod:	Header třídy pro síťové spojení klient/server

#pragma once

class Network
{
public:
	//3 konstruktory (host + port || port || minulý socket)
	Network(short t_port);
	Network(short t_port, string t_host);
	Network(int t_sock);
	bool getError();

private:
	bool m_error {false};
	int m_socket {-50};
	short m_port {0};
	short m_Network_mode {0};
}