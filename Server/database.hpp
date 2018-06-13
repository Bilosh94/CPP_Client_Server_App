//	Autor:	Martin Biloš
//	Co:		CPP_Client_Server_App
//	Důvod:	Header třídy komunikace s databází

#pragma once

class DatabaseController
{
public:
	DatabaseController();
	~DatabaseController();
	std::string getData(std::string t_dotaz);
	bool setData(std::string t_dotaz);
private:
	//Odkaz na samotnou databázi??
	//možná nějaký parser pro rozklíčování dotazů??
};