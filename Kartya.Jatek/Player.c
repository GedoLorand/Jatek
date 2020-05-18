#include "Player.h"
#include <fcntl.h>
#include <io.h>

//A jatekos nevenek hp nak es szintjenek letrehozasa 
Player* CreateNev()
{
	//nev letrehozas
	Player *player = (Player*)(calloc(1, sizeof(Player)));
	if (!player) {
		printf("Nincs player!");
		exit(1);
	}

	player->nev = (char*)(calloc(10, sizeof(char)));
	if (!player->nev) {
		printf("Nincs nev!");
		exit(1);
	}
	//elet es szint letrehozas
	player->hp = 6;
	player->szint = 1;

	printf("Adja meg a jatekos nevet: ");
	scanf("%s", player->nev);
	
	return player;
}
//a jatekos "kezeben" levo lapok tomb letrehozasa es feltoltese random kartyakkal
void CreateLapok(Player* player)
{
		
	player->lapok = (Kartya**)(calloc(20, sizeof(Kartya*)));
	if (!player->lapok) {
		printf("Nincsenek lapok");
		exit(1);
	}
	player->lapszam = 6;
	Kartya* ujRand;
	for (int i = 0; i < player->lapszam; ++i) {
		player->lapok[i]= RandKartya();
	}
}
//kartya randomolas szin es szam
 Kartya* RandKartya()
{
    int szam = rand() % 14;
	if (szam == 0) {
		szam += 1;
	}
	int szimbolSzam = rand() % 4;

	Kartya* kartya = (Kartya*)(calloc(1, sizeof(Kartya)));
	if (!kartya) {
		printf("Nincs kartya");
		exit(1);
	}
	kartya->szam = szam;
	kartya->szin = szimbolSzam;

	return kartya;
}

 //Jatekosok adatainak kiiratasa : elet szint kartyak
void PrintPlayer1(Player* player)
{	
	system("cls");

	printf("Elet: ");

	for (int i = 0; i < player->hp; ++i) {

		printf("*  ");

	}
	
	printf("                                       %s", player->nev);

	printf("                                      Szint: %i", player->szint);

	printf("\n");
	PrintLapokVizszintes(player->lapok, player->lapszam);
	
}
void PrintPlayer2(Player* player2)
{

	printf("Elet: ");

	for (int i = 0; i < player2->hp; ++i) {

		printf("*  ");

	}

	printf("                                       %s", player2->nev);

	printf("                                    Szint: %i", player2->szint);

	printf("\n");
	PrintLapokVizszintes(player2->lapok, player2->lapszam);
}
void printKeretSor(int keretSor) {
	if (keretSor == 0) {
		printf("\t");
		printf("___________");
	}
	if (keretSor == 1) {
		printf("\t");
		printf("|         |");
	}
	if (keretSor == 2) {
		printf("\t");
		printf("|         |");
	}
	if (keretSor == 3) {
		printf("\t");
		printf("|         |");
	}
	if (keretSor == 4) {
		printf("\t");
		printf("|         |");
	}
	if (keretSor == 5) {
		printf("\t");
		printf("|         |");
	}
	if (keretSor == 6) {
		printf("\t");
		printf("|         |");

	}
	if (keretSor == 7) {
		printf("\t");
		printf("|_________|");
	}
}
 void printEllensegKartya(int ellensegLapSzam) 
{
	 for (int i = 0; i < 8; ++i) {
		 for (int j = 0; j < ellensegLapSzam; ++j) {
			 printKeretSor(i);
		 }
		 printf("\n");
	}
}
//a jatek elejen letrehozott kartya amire a kesobbiekbe lehet tenni a mar a "kezben" levo kartyakat
void printLetetKartya(Kartya* kartya)
{
	for (int i = 0; i < 11; ++i) {
		printf("\t\t\t\t\t");
		PrintSor(kartya->szin, kartya->szam, i);
	printf("\n");
	}
}
//A randomolt kartyak kiiratasa egyszerre soronkent
void PrintLapokVizszintes(Kartya** kartyak, int n)
{
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < n; ++j) {
			PrintSor(kartyak[j]->szin, kartyak[j]->szam, i);
		}
		printf("\n");
	}
}
//A kartyak megjelenitese
void PrintSor(int symbol, int szam, int sor)
{
	//Asz
	if (szam == 1) {
		if (sor == 0) {
			printf("\t");
			printf("___________");
		}
		if (sor == 1) {
			printf("\t");
			printf("|");
			printMagasLap(szam);
			printf("        |");
		}
		if (sor == 2) {
			printf("\t");
			printf("|");
			printSymbol(symbol);
			printf("        |");
		}
		if (sor == 3) {
			printf("\t");
			printf("|         |");
		}
		if (sor == 4) {
			printf("\t");
			printf("|    ");
			printSymbol(symbol);
			printf("    |");
		}
		if (sor == 5) {
			printf("\t");
			printf("|         |");
		}
		if (sor == 6) {
			printf("\t");
			printf("|        ");
			printSymbol(symbol);
			printf("|");

		}
		if (sor == 7) {
			printf("\t");
			printf("|________");
			printMagasLap(szam);
			printf("|");
		}
	}
	//2
	if (szam == 2) {
		if (sor == 0) {
			printf("\t");
			printf("___________");
		}
		if (sor == 1) {
			printf("\t");
			printf("|");
			printMagasLap(szam);
			printf("        |");
		}
		if (sor == 2) {
			printf("\t");
			printf("|");
			printSymbol(symbol);
			printf("   ");
			printSymbol(symbol);
			printf("    |");
		}
		if(sor == 3) {
			printf("\t");
			printf("|         |");
		}
		if (sor == 4) {
			printf("\t");
			printf("|         |");
		}
		if (sor == 5) {
			printf("\t");
			printf("|         |");
		}
		if (sor == 6) {
			printf("\t");
			printf("|    ");
			printSymbol(symbol);
			printf("   ");
			printSymbol(symbol);
			printf("|");
		}
		if (sor == 7) {
			printf("\t");
			printf("|________");
			printMagasLap(szam);
			printf("|");
		}
	}
	//3
	if(szam == 3) {
		if (sor == 0) {
			printf("\t");
			printf("___________");
		}
		if (sor == 1) {
			printf("\t");
			printf("|");
			printMagasLap(szam);
			printf("        |");
		}
		if (sor == 2) {
			printf("\t");
			printf("|");
			printSymbol(symbol);
			printf("   ");
			printSymbol(symbol);
			printf("    |");
		}
		if (sor == 3) {
			printf("\t");
			printf("|         |");
		}
		if (sor == 4) {
			printf("\t");
			printf("|    ");
			printSymbol(symbol);
			printf("    |");
		}
		if (sor == 5) {
			printf("\t");
			printf("|         |");
		}
		if (sor == 6) {
			printf("\t");
			printf("|    ");
			printSymbol(symbol);
			printf("   ");
			printSymbol(symbol);
			printf("|");
		}
		if (sor == 7) {
			printf("\t");
			printf("|________");
			printMagasLap(szam);
			printf("|");
		}
	}
	//4
	if (szam == 4) {
		if (sor == 0) {
			printf("\t");
			printf("___________");
		}
		if (sor == 1) {
			printf("\t");
			printf("|");
			printMagasLap(szam);
			printf("        |");
		}
		if (sor == 2) {
			printf("\t");
			printf("|");
			printSymbol(symbol);
			printf("        |");
		}
		if (sor == 3) {
			printf("\t");
			printf("|  ");
			printSymbol(symbol);
			printf("   ");
			printSymbol(symbol);
			printf("  |");
		}
		if (sor == 4) {
			printf("\t");
			printf("|         |");
		}
		if (sor == 5) {
			printf("\t");
			printf("|  ");
			printSymbol(symbol);
			printf("   ");
			printSymbol(symbol);
			printf("  |");
		}
		if (sor == 6) {
			printf("\t");
			printf("|        ");
			printSymbol(symbol);
			printf("|");

		}
		if (sor == 7) {
			printf("\t");
			printf("|________");
			printMagasLap(szam);
			printf("|");
		}
	}
	//5
	if (szam == 5) {
		if (sor == 0) {
			printf("\t");
			printf("___________");
		}
		if (sor == 1) {
			printf("\t");
			printf("|");
			printMagasLap(szam);
			printf("        |");
		}
		if (sor == 2) {
			printf("\t");
			printf("|");
			printSymbol(symbol);
			printf("        |");
		}
		if (sor == 3) {
			printf("\t");
			printf("|  ");
			printSymbol(symbol);
			printf("   ");
			printSymbol(symbol);
			printf("  |");
		}
		if (sor == 4) {
			printf("\t");
			printf("|    ");
			printSymbol(symbol);
			printf("    |");
		}
		if (sor == 5) {
			printf("\t");
			printf("|  ");
			printSymbol(symbol);
			printf("   ");
			printSymbol(symbol);
			printf("  |");
		}
		if (sor == 6) {
			printf("\t");
			printf("|        ");
			printSymbol(symbol);
			printf("|");

		}
		if (sor == 7) {
			printf("\t");
			printf("|________");
			printMagasLap(szam);
			printf("|");
		}
	}
	//6
	if (szam == 6) {
		if (sor == 0) {
			printf("\t");
			printf("___________");
		}
		if (sor == 1) {
			printf("\t");
			printf("|");
			printMagasLap(szam);
			printf("        |");
		}
		if (sor == 2) {
			printf("\t");
			printf("|");
			printSymbol(symbol);
			printf("        |");
		}
		if (sor == 3) {
			printf("\t");
			printf("|  ");
			printSymbol(symbol);
			printf("   ");
			printSymbol(symbol);
			printf("  |");
		}
		if (sor == 4) {
			printf("\t");
			printf("|  ");
			printSymbol(symbol);
			printf("   ");
			printSymbol(symbol);
			printf("  |");
		}
		if (sor == 5) {
			printf("\t");
			printf("|  ");
			printSymbol(symbol);
			printf("   ");
			printSymbol(symbol);
			printf("  |");
		}
		if (sor == 6) {
			printf("\t");
			printf("|        ");
			printSymbol(symbol);
			printf("|");

		}
		if (sor == 7) {
			printf("\t");
			printf("|________");
			printMagasLap(szam);
			printf("|");
		}
	}
	//7
	if (szam == 7) {
		if (sor == 0) {
			printf("\t");
			printf("___________");
		}
		if (sor == 1) {
			printf("\t");
			printf("|");
			printMagasLap(szam);
			printf("        |");
		}
		if (sor == 2) {
			printf("\t");
			printf("|");
			printSymbol(symbol);
			printf(" ");
			printSymbol(symbol);
			printf("   ");
			printSymbol(symbol);
			printf("  |");
		}
		if (sor == 3) {
			printf("\t");
			printf("|    ");
			printSymbol(symbol);
			printf("    |");
		}
		if (sor == 4) {
			printf("\t");
			printf("| ");
			printf(" ");
			printSymbol(symbol);
			printf("   ");
			printSymbol(symbol);
			printf("  |");
		}
		if (sor == 5) {
			printf("\t");
			printf("|         |");
		}
		if (sor == 6) {
			printf("\t");
			printf("|  ");
			printSymbol(symbol);
			printf("   ");
			printSymbol(symbol);
			printf(" ");
			printSymbol(symbol);
			printf("|");
		}
		if (sor == 7) {
			printf("\t");
			printf("|________");
			printMagasLap(szam);
			printf("|");
		}
	}
	//8
	if (szam == 8) {
		if (sor == 0) {
			printf("\t");
			printf("___________");
		}
		if (sor == 1) {
			printf("\t");
			printf("|");
			printMagasLap(szam);
			printf("        |");
		}
		if (sor == 2) {
			printf("\t");
			printf("|");
			printSymbol(symbol);
			printf(" ");
			printSymbol(symbol);
			printf("   ");
			printSymbol(symbol);
			printf("  |");
		}
		if (sor == 3) {
			printf("\t");
			printf("|    ");
			printSymbol(symbol);
			printf("    |");
		}
		if (sor == 4) {
			printf("\t");
			printf("| ");
			printf(" ");
			printSymbol(symbol);
			printf("   ");
			printSymbol(symbol);
			printf("  |");
		}
		if (sor == 5) {
			printf("\t");
			printf("|    ");
			printSymbol(symbol);
			printf("    |");
		}
		if (sor == 6) {
			printf("\t");
			printf("|  ");
			printSymbol(symbol);
			printf("   ");
			printSymbol(symbol);
			printf(" ");
			printSymbol(symbol);
			printf("|");
		}
		if (sor == 7) {
			printf("\t");
			printf("|________");
			printMagasLap(szam);
			printf("|");
		}
	}
	//9
	if (szam == 9) {
		if (sor == 0) {
			printf("\t");
			printf("___________");
		}
		if (sor == 1) {
			printf("\t");
			printf("|");
			printMagasLap(szam);
			printf("        |");
		}
		if (sor == 2) {
			printf("\t");
			printf("|");
			printSymbol(symbol);
			printf(" ");
			printSymbol(symbol);
			printf("   ");
			printSymbol(symbol);
			printf("  |");
		}
		if (sor == 3) {
			printf("\t");
			printf("|    ");
			printSymbol(symbol);
			printf("    |");
		}
		if (sor == 4) {
			printf("\t");
			printf("| ");
			printf(" ");
			printSymbol(symbol);
			printf(" ");
			printSymbol(symbol);
			printf(" ");
			printSymbol(symbol);
			printf("  |");
		}
		if (sor == 5) {
			printf("\t");
			printf("|    ");
			printSymbol(symbol);
			printf("    |");
		}
		if (sor == 6) {
			printf("\t");
			printf("|  ");
			printSymbol(symbol);
			printf("   ");
			printSymbol(symbol);
			printf(" ");
			printSymbol(symbol);
			printf("|");
		}
		if (sor == 7) {
			printf("\t");
			printf("|________");
			printMagasLap(szam);
			printf("|");
		}
	}
	//10
	if (szam == 10) {
		if (sor == 0) {
			printf("\t");
			printf("___________");
		}
		if (sor == 1) {
			printf("\t");
			printf("|");
			printMagasLap(szam);
			printf("       |");
		}
		if (sor == 2) {
			printf("\t");
			printf("|");
			printSymbol(symbol);
			printf(" ");
			printSymbol(symbol);
			printf(" ");
			printSymbol(symbol);
			printf(" ");
			printSymbol(symbol);
			printf("  |");
		}
		if (sor == 3) {
			printf("\t");
			printf("|    ");
			printSymbol(symbol);
			printf("    |");
		}
		if (sor == 4) {
			printf("\t");
			printf("| ");
			printf(" ");
			printSymbol(symbol);
			printf("   ");
			printSymbol(symbol);
			printf("  |");
		}
		if (sor == 5) {
			printf("\t");
			printf("|    ");
			printSymbol(symbol);
			printf("    |");
		}
		if (sor == 6) {
			printf("\t");
			printf("|  ");
			printSymbol(symbol);
			printf(" ");
			printSymbol(symbol);
			printf(" ");
			printSymbol(symbol);
			printf(" ");
			printSymbol(symbol);
			printf("|");
		}
		if (sor == 7) {
			printf("\t");
			printf("|_______");
			printMagasLap(szam);
			printf("|");
		}
	}
	//11
	if (szam == 11) {
		if (sor == 0) {
			printf("\t");
			printf("___________");
		}
		if (sor == 1) {
			printf("\t");
			printf("|");
			printMagasLap(szam);
			printf("_______ |");
		}
		if (sor == 2) {
			printf("\t");
			printf("|");
			printSymbol(symbol);
			printf("|     | |");
		}
		if (sor == 3) {
			printf("\t");
			printf("| |     | |");
		}
		if (sor == 4) {
			printf("\t");
			printf("| |     | |");
		}
		if (sor == 5) {
			printf("\t");
			printf("| |     | |");
		}
		if (sor == 6) {
			printf("\t");
			printf("| |_____|");
			printSymbol(symbol);
			printf("|");
		}
		if (sor == 7) {
			printf("\t");
			printf("|________");
			printMagasLap(szam);
			printf("|");
		}
	}
	//12
	if (szam == 12) {
		if (sor == 0) {
			printf("\t");
			printf("___________");
		}
		if (sor == 1) {
			printf("\t");
			printf("|");
			printMagasLap(szam);
			printf("_______ |");
		}
		if (sor == 2) {
			printf("\t");
			printf("|");
			printSymbol(symbol);
			printf("|     | |");
		}
		if (sor == 3) {
			printf("\t");
			printf("| |     | |");
		}
		if (sor == 4) {
			printf("\t");
			printf("| |     | |");
		}
		if (sor == 5) {
			printf("\t");
			printf("| |     | |");
		}
		if (sor == 6) {
			printf("\t");
			printf("| |_____|");
			printSymbol(symbol);
			printf("|");
		}
		if (sor == 7) {
			printf("\t");
			printf("|________");
			printMagasLap(szam);
			printf("|");
		}
	}
	//13
	if (szam == 13) {
		if (sor == 0) {
			printf("\t");
			printf("___________");
		}
		if (sor == 1) {
			printf("\t");
			printf("|");
			printMagasLap(szam);
			printf("_______ |");
		}
		if (sor == 2) {
			printf("\t");
			printf("|");
			printSymbol(symbol);
			printf("|     | |");
		}
		if (sor == 3) {
			printf("\t");
			printf("| |     | |");
		}
		if (sor == 4) {
			printf("\t");
			printf("| |     | |");
		}
		if (sor == 5) {
			printf("\t");
			printf("| |     | |");
		}
		if (sor == 6) {
			printf("\t");
			printf("| |_____|");
			printSymbol(symbol);
			printf("|");
		}
		if (sor == 7) {
			printf("\t");
			printf("|________");
			printMagasLap(szam);
			printf("|");
		}
	}
}
//a kartya szinenek megjelenitese:pikk,kor,treff,karo
void printSymbol(int symbol) {
	_setmode(_fileno(stdout), _O_U16TEXT);
	switch (symbol)
	{
	case 0:
		wprintf(L"♥");
		break;
	case 1:
		wprintf(L"♠");
		break;
	case 2:
		wprintf(L"♣");
		break;
	case 3:
		wprintf(L"♦");
		break;
	}
	_setmode(_fileno(stdout), _O_TEXT);
}
//A kartya szamanak megjelenitese : 2,3,4...J,Q,K,A
void printMagasLap(int szam)
{
	switch (szam)
	{
	case 1:
		printf("A");
		break;
	case 2:
		printf("2");
		break;
	case 3:
		printf("3");
		break;
	case 4:
		printf("4");
		break;
	case 5:
		printf("5");
		break;
	case 6:
		printf("6");
		break;
	case 7:
		printf("7");
		break;
	case 8:
		printf("8");
		break;
	case 9:
		printf("9");
		break;
	case 10:
		printf("10");
		break;
	case 11:
		printf("J");
		break;
	case 12:
		printf("Q");
		break;
	case 13:
		printf("K");
		break;
	}
}

