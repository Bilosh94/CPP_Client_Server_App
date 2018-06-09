//	Autor:	Martin Biloš
//	Co:		CPP_Client_Server_App
//	Důvod:	Třída pro komunikaci přes síť pro klienta

#include "client_network.hpp"

CliNetwork::CliNetwork(std::string t_host, int t_port)
{
	m_port = t_port;
	m_host = t_host;
}

CliNetwork::~CliNetwork()
{
	close(m_socket);
}

void CliNetwork::initialize()
{
	m_servAddress.sin_family = AF_INET;
    m_servAddress.sin_port = htons(m_port);
    m_servAddress.sin_addr.s_addr = inet_addr(m_host.c_str());
 
    m_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (m_socket < 0)
    {
        std::cerr << "###ERROR### Nepodařilo se správně otevřít socket, ukončuji klienta." << std::endl;
        m_error = true;
        return;
    }

    if (connect(m_socket,(struct sockaddr *) &m_servAddress, sizeof(m_servAddress)) < 0)
    {
    	std::cerr << "###ERROR### Nepodařilo se spojit se serverem na daném portu (selhala funkce connect)." << std::endl;
    	m_error = true;
    	return;
    }
}