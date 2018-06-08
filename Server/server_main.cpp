//	Autor:	Martin Biloš
//	Co:		CPP_Client_Server_App
//	Důvod:	Main soubor pro serverovou aplikaci

#include "server_main.hpp"

int main(int argc, char* argv[])
{
	ParameterParser Parser(argc, argv);
	if (Parser.getError())
	{
		std::cout << "Nastala chyba, špatné parametry nebo jejich duplikace" << std::endl;
		return 1;
	}
	std::cout << Parser.getMode() << Parser.getPort() << Parser.getHost() << std::endl;

	if (Parser.getMode())
	{
		SerNetwork Sit(Parser.getPort());
		Sit.initialize();
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