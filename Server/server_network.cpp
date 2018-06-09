//	Autor:	Martin Biloš
//	Co:		CPP_Client_Server_App
//	Důvod:	Třída pro komunikaci přes síť pro server

#include "server_network.hpp"

SerNetwork::SerNetwork(int t_port)
{
	m_port = t_port;
}

SerNetwork::~SerNetwork()
{
	close(m_socket);
}

void SerNetwork::initialize()
{
	std::cout << "Vyšlo to" << std::endl;
	m_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (m_socket < 0)
 	{
 		std::cerr << "###ERROR### Nepodařilo se otevřít socket!" << std::endl;
 		m_error = true;
 		return;
 	}

 	memset(&m_servAddress, '\0', sizeof(m_servAddress));
 	m_servAddress.sin_family = AF_INET;
   	m_servAddress.sin_addr.s_addr = INADDR_ANY;
   	m_servAddress.sin_port = htons(m_port);

   	if (bind(m_socket, (struct sockaddr *) &m_servAddress,sizeof(m_servAddress)) < 0)
   	{
   		std::cerr << "###ERROR### Nepodařilo se obsadit port!" << std::endl;
 		m_error = true;
 		return;
   	}

   	listen(m_socket,5);
   	std::cout << "Vyšlo to" << std::endl;
}

int SerNetwork::prijmuti()
{
	int newsock = -65;
	socklen_t clilen = sizeof(m_cliAddress);
	//Později předělat na while -> threads
	newsock = accept(m_socket, (struct sockaddr *) &m_cliAddress, &clilen);
	if(newsock > 0)
	{
		m_socket = newsock;
		return newsock;
	}
	else
	{
		m_error = true;
		return (-50);
	}
}