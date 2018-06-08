//	Autor:	Martin Biloš
//	Co:		CPP_Client_Server_App
//	Důvod:	Třída pro třízení a kontrolu parametrů
//  TODO: The Bilosh 3: Bug Hunt, Překopat, mít veškterou funkčnost v inicializaci je blbost!

#include "parameter_parser.hpp"

using namespace std;

ParameterParser::ParameterParser(int t_argc, char* t_argv[])
{
	bool mode_duplication = false;
	for(int i = 1; i < t_argc; i++)
	{
		//port
		if (string(t_argv[i]) == "-p")
		{
			if (m_port != 0)
			{
				m_error = true;
			}
			m_port = stoi(t_argv[++i]);
			if ((m_port < 0)||(m_port > 65535))
			{
				m_port = 0;
			}
		}

		//mode
		else if((string(t_argv[i]) == "-m") && (string(t_argv[0]) == "./Server_App")
			&& !(mode_duplication))
		{
			++i;
			if (string(t_argv[i]) == "l")
			{
				m_mode = false;
				mode_duplication = true;
			}
			else if (string(t_argv[i]) == "n")
			{
				m_mode = true;
				mode_duplication = true;
			}
			else
			{
				m_error = true;
			}
		}

		//host
		else if((string(t_argv[i]) == "-h") && (string(t_argv[0]) == "./Client_App")
			&& (m_host.size() == 0))
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

ParameterParser::~ParameterParser()
{
	
}

std::string ParameterParser::getHost()
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


