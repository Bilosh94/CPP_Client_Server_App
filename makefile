# Vytvořil: Martin Biloš
# Název:	CPP_Client_Server_App

CC = g++
CFLAGS = -Wall -Wextra -pedantic -Wshadow -Wnon-virtual-dtor -std=c++17 -pthread

SERVERFILES = Server/server_main.cpp Server/server_network.cpp
CLIENTFILES = Client/client_main.cpp Client/client_network.cpp
FILES = Support_Classes/parameter_parser.cpp Support_Classes/network.cpp 


all: Server_App Client_App

Server_App:
	$(CC) $(SERVERFILES) $(FILES) $(CFLAGS) -o Server_App

Client_App:
	$(CC) $(CLIENTFILES) $(FILES) $(CFLAGS) -o Client_App

clean:
	rm -f Server_App Client_App

#TODO samotné soubory, možnost spustit jen jeden, clean