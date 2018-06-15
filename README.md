Název:		CPP_Client_Server_App

Autor:		Martin Biloš

Cíl aplikace:

		Cílem je vytvořit 2 aplikace, které budou komunikovat přes síť.
		Server bude ukládat informace v databázi a bude mít 2 módy (lokální a síťový)
		Lokální provede změny v databázi, síťový provede změny přes síť.
		Klient bude mít možnost měnit a pracovat s daty přes síť.

Fáze vývoje:
		
		V aplikaci chybí komentáře, snaha o co největší pochopitelnost bez nich správným nazváním entit.
		Zatím aplikace funguje pouze jako Client/Server, kdy server vrací vstup zpět klientovi. (možnost více klientů)
		Zatím neřešen neošetřený vstup nebo některé chyby.
		V plánu je aktuálně dokončit klienta a správné napojení serveru na vstup od klienta. Následně bude na řadě databáze

Popis ovládání:

		Například:
			./Client_App -p 7853 -h 0.0.0.0
			./Server_App -p 7853 -m n
			Později v plánu test na rozdílných PC/serverech a možnost zadat adresu jinak než IPv4

Testování:

		Zatím netestováno