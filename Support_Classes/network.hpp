//	Autor:	Martin Biloš
//	Co:		CPP_Client_Server_App
//	Důvod:	Header třídy pro síťové spojení klient/server
//  TODO: Rozdělit to na klienta a server?

#pragma once

class Network
{
public:
	//3 konstruktory (host + port || port || minulý socket)
	Network(short t_port); // server
	Network(short t_port, string t_host); // klient
	Network(int t_sock); //server_2
	~Network();
	serverInicialize();
	serverAccept(); // možná něco vracet?? -> sock?

	klient_inicialize();
	sendMessage();
	getMessage();

	bool getError();


private:
	bool m_error {false};
	int m_socket {-50};
	short m_port {0};
	//short m_Network_mode {0}; 
}