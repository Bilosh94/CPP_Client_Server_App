//	Autor:	Martin Biloš
//	Co:		CPP_Client_Server_App
//	Důvod:	Header třídy pro síťové spojení klient/server
//  TODO: Rozdělit to na klienta a server? a dědit z třídy network?

#pragma once

//díky virtual je to abstraktní třída
class Network
{
public:
	virtual void Inicialize() = 0;

	sendMessage(string message);
	string getMessage();

	bool getError();

protected:
	bool m_error {false};
	int m_socket {-50};
	string m_message;
	struct sockaddr_in m_otherAddress;
	//short m_Network_mode {0}; 
}