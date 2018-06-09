//	Autor:	Martin Biloš
//	Co:		CPP_Client_Server_App
//	Důvod:	Main soubor pro serverovou aplikaci

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
	
	std::cout << Parser.getMode() << Parser.getPort() << Parser.getHost() << std::endl;

	if (Parser.getMode())
	{
		SerNetwork Sit(Parser.getPort());
		Sit.initialize();
		Sit.prijmuti();
		//Pro každe přijmutí vytvoří nový thread
		std::string mess = Sit.getMessage();
		if (mess == "Ahoj\r\n")
		{
			mess = "Ahoj\n";
		}
		else
		{
			mess = "Neahoj\n";
		}
		Sit.sendMessage(mess);
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