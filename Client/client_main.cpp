//	Autor:	Martin Biloš
//	Co:		CPP_Client_Server_App
//	Důvod:	Main soubor pro klientskou aplikaci

#include "client_main.hpp"

int main(int argc, char* argv[])
{
	ParameterParser Parser(argc, argv);
	if (Parser.getError())
	{
		std::cout << "Nastala chyba, špatné parametry nebo jejich duplikace" << std::endl;
		return 1;
	}
	std::cout << "Client: " << Parser.getPort() << Parser.getHost() << std::endl;

	//Připojení

	//Cyklus: Komunikace se serverem

	//Konec: výpis úspěch nebo chyba
	return 0;
}