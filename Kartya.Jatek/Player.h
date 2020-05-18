#ifndef Player_H
#define Player_H
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef struct Kartya {

	int szam;
	int szin;

}Kartya;

void PrintLapokVizszintes(Kartya** kartyak, int n);

void PrintSor(int symbol, int szam, int sor);

void printEllensegKartya(Kartya** ellensegPlayer);

void printKeretSor(int keretSor);

typedef struct Player {

	int hp;
	int szint;
	char* nev;
	Kartya ** lapok;
	int lapszam;

}Player;

Player* CreateNev();

void CreateLapok(Player* player);

Kartya* RandKartya();

void PrintPlayer1(Player* player);
void PrintPlayer2(Player* player2);
void printSymbol(int symbol);
void printMagasLap(int szam);
void printLetetKartya(Kartya* letetKartya);

#endif
