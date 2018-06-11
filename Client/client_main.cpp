//	Autor:	Martin Biloš
//	Co:		CPP_Client_Server_App
//	Důvod:	Main soubor pro klientskou aplikaci

#include "client_main.hpp"

int main(int argc, char* argv[])
{
	ParameterParser Parser(argc, argv);
	Parser.Parse();
	if (Parser.getError())
	{
		std::cout << "Nastala chyba, špatné parametry nebo jejich duplikace" << std::endl;
		return 1;
	}

	CliNetwork Sit(Parser.getHost(), Parser.getPort());
	Sit.initialize();
	std::string mess = "";

	while(!Sit.getError())
	{
		if (mess != "")
		{
			std::cout << "Zpráva od serveru: " << mess << std::endl;
		}
		std::cout << "Zpráva pro server: " << std::flush;
		std::getline(std::cin, mess);
		Sit.sendMessage(mess);
		if(!Sit.getError())
		{
			mess = Sit.getMessage();
		}
	}


	//Připojení

	//Cyklus: Komunikace se serverem

	//Konec: výpis úspěch nebo chyba
	return 0;
}