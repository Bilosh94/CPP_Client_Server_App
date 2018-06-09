//	Autor:	Martin Biloš
//	Co:		CPP_Client_Server_App
//	Důvod:	Třída pro třízení a kontrolu parametrů
//  TODO: The Bilosh 3: Bug Hunt, Překopat, mít veškterou funkčnost v inicializaci je blbost!

#include "parameter_parser.hpp"

using namespace std;

ParameterParser::ParameterParser(int t_argc, char* t_argv[])
{
	m_parameters.clear();
	for(int i = 0; i < t_argc; i++)
	{
		m_parameters.push_back(std::string(t_argv[i]));
	}
}

ParameterParser::~ParameterParser()
{
	m_parameters.clear();
}

void ParameterParser::Parse()
{
	bool mode_duplication = false;
	for(unsigned int i = 1; i < m_parameters.size(); i++)
	{
		//port
		if (m_parameters[i] == "-p")
		{
			if (m_port != 0)
			{
				m_error = true;
			}
			m_port = stoi(m_parameters[++i]);
			if ((m_port < 0)||(m_port > 65535))
			{
				m_port = 0;
			}
		}

		//mode
		else if((m_parameters[i] == "-m") && (m_parameters[0] == "./Server_App")
			&& !(mode_duplication))
		{
			++i;
			if (m_parameters[i] == "l")
			{
				m_mode = false;
				mode_duplication = true;
			}
			else if (m_parameters[i] == "n")
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
		else if((m_parameters[i] == "-h") && (m_parameters[0] == "./Client_App")
			&& (m_host.size() == 0))
		{
			m_host = m_parameters[++i];
		}

		//jinak error
		else
		{
			m_error = true;
		}
	}
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


