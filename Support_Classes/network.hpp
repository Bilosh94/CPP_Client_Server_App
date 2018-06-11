//	Autor:	Martin Biloš
//	Co:		CPP_Client_Server_App
//	Důvod:	Header třídy pro síťové spojení klient/server
//  TODO: Rozdělit to na klienta a server? a dědit z třídy network?

#pragma once

#include <iostream>
#include <cstring>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include "constants.hpp"

//díky virtual je to abstraktní třída
class Network
{
public:
	virtual void initialize() = 0;
	virtual ~Network();

	void sendMessage(std::string message);
	std::string getMessage();

	bool getError();

protected:
	bool m_error {false};
	int m_socket {NO_SOCKET};
	char m_buffer [BUFF_MAX] = {0};
};