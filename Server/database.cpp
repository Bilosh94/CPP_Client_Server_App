//	Autor:	Martin Biloš
//	Co:		CPP_Client_Server_App
//	Důvod:	Třída pro komunikaci s databází

#include "database.hpp"

DatabaseController::DatabaseController()
{

}

DatabaseController::~DatabaseController()
{

}

std::string DatabaseController::getData(std::string t_dotaz)
{
	return std::string("Jan Miloš");;
}

bool DatabaseController::setData(std::string t_prikaz)
{
	return true;
}