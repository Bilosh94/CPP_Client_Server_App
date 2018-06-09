//	Autor:	Martin Biloš
//	Co:		CPP_Client_Server_App
//	Důvod:	Soubor pro třídu zajišťující komuníkaci přes síť

#include "network.hpp"

Network::~Network()
{
	
}

void Network::sendMessage(std::string t_mess)
{
	if(send(m_socket,t_mess.c_str(),t_mess.size(), 0) < 1)
	{
		m_error = true;
	}
}

std::string Network::getMessage()
{
	if (recv(m_socket, m_buffer, 1024, 0) < 1)
	{
		m_error = true;
		return std::string("");
	}
	else
	{
		std::string message = m_buffer;
		std::memset(m_buffer,'-',1024);
		return message;
	}
}

bool Network::getError()
{
	return m_error;
}