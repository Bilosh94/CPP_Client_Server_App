//	Autor:	Martin Biloš
//	Co:		CPP_Client_Server_App
//	Důvod:	Main soubor pro serverovou aplikaci
//	TODO:	threads a konkurentní server

#include "server_main.hpp"

int main(int argc, char* argv[])
{
	ParameterParser Parser(argc, argv);
	Parser.Parse();
	if (Parser.getError())
	{
		std::cout << "Nastala chyba, špatné parametry nebo jejich duplikace" << std::endl;
		return 1;
	}


	if (Parser.getMode())
	{
		SerNetwork Sit(Parser.getPort());
		Sit.initialize();
		while(!Sit.getError())
		{
			int socket_descriptor = Sit.prijmuti();
			if (socket_descriptor > -1)
			{
				//Není ideální, ale aktuálně nejschůdnější -> chtělo by zpřehlednit
				std::thread vlakno(ThreadFunction, socket_descriptor);
				vlakno.detach();
			}
		}
		/*
		Sit.prijmuti();
		//Pro každe přijmutí vytvoří nový thread
		std::string mess = Sit.getMessage();
		while (!Sit.getError())
		{
			std::cout << "Zpráva od Klienta: " << mess << std::endl;
			std::cout << "Zpráva pro klienta: " << std::flush;
			std::getline(std::cin, mess);
			Sit.sendMessage(mess);
			if(!Sit.getError())
			{
				mess = Sit.getMessage();
			}
		}*/
		//Network Mode
	}
	else
	{
		//Local mode
	}

	// Rozlišení typu spuštštění

	// Thread 1: Cyklus Network NEBO IO

	// Thread 2: Database

	// 
	return 0;
}

ThreadControl::ThreadControl(int t_socket)
{
	m_socket = t_socket;
}

ThreadControl::~ThreadControl()
{

}

void ThreadControl::prubeh()
{
	std::cout << "Vlákno startuje" << std::endl;
	SerNetwork SitThread(m_socket, true);
	std::string mess = SitThread.getMessage();
	while (!SitThread.getError())
	{
		std::cout << "Zpráva od Klienta: " << mess << std::endl;
		SitThread.sendMessage(mess);
		if(!SitThread.getError())
		{
			mess = SitThread.getMessage();
		}
	}
}

void ThreadFunction (int t_socket)
{
	ThreadControl Vlakno(t_socket);
	Vlakno.prubeh();
}