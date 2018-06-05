//	Autor:	Martin Biloš
//	Co:		CPP_Client_Server_App
//	Důvod:	Třída pro třízení a kontrolu parametrů
//  TODO: Dupilkace parametrů

#include "parameter_parser.hpp"

using namespace std;

ParameterParser::ParameterParser(int t_argc, char* t_argv[])
{
	for(int i = 0; i < t_argc; ++i)
	{
		//port
		if (strcmp(t_argv[i], "-p") == 0)
		{
			m_port = stoi(t_argv[++i]);
			if ((m_port < 0)||(m_port > 65535))
			{
				m_port = 0;
			}
			else
			{
				m_error = true;
			}
		}

		//mode
		else if ((strcmp(t_argv[i], "-m") == 0) && (strcmp(t_argv[0], "server") == 0))
		{
			if (strcmp(t_argv[++i], "l") == 0)
			{
				m_mode = false;
			}
			else if (strcmp(t_argv[++i], "n") == 0)
			{
				m_mode = true;
			}
			else
			{
				m_error = true;
			}
		}

		//host
		else if((strcmp(t_argv[i], "-h") == 0) && (strcmp(t_argv[0], "klient") == 0))
		{
			m_host = t_argv[++i];
		}

		//jinak error
		else
		{
			m_error = true;
		}
	}
}

ParameterParser::~ParameterParser();

string ParameterParser::getHost()
{
	return m_host;
}

bool ParameterParser::getMode()
{
	return m_mode;
}

bool ParameterParser::getError()
{
	return m_error;
}

int ParameterParser::getPort()
{
	return m_port;
}


