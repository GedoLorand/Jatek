#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include "Player.h"

int main() {

	srand(time(0));
	//szamablyzat
	printf("Elso lepeskent tedd a consolt full screen-be!!!!!!!!!!!!\nBevezeto:\n A jatek egy,ket szemelyes kartya partit demonstral.\n Tudnivalok: \n A meccs elejen mindegyik fel kap 6-6 random lapot a paklibol es minden jatekos rendelkezik 6 elettel es egy 1 szintel.\n Cel: \n A jatek fo celja,hogy az osszes lap elfogyjon a jatekos kezebol.\n Szabalyzat: \n 1. A szinre szint,szamra szamot szabalyat kovetve lehet a lapokat tenni ,vagyis ha a jatek soran a mar lent levo lap megegyezik a kezedben talalhato szinnel vagy szammal akkor lehetove valik a lap letetele, ami szabadon valaszthato.\n 2. Ellenben ha nincs amit tenni akkor kotelezo modon huzni kell egy lapot es ez altal veszit a jatekos egy eletet,ha az osszes eletet elvesziti akkor a masik fel nyer,ellenben ha a kezeben talalhato lapok folyamatosan fogynak annak fugvenyebe lep szintet 5-12 lap eseten 1 szint,2-4 lap eseten 2 szint,1 lap eseten 3 szint.\nA jatekohoz tartozo iranyitasi szabalyok:\nHa 0 szamot nyomsz akkor huzol egy kartyat es veszitesz egy eletet.\nA kezedben levo lapok szamat balrol kezdodoen valaszthatod ki(1,2,3,...)\nMind ket jatekos kap egy kodot amivel majd a sajat koren belep a kartya partiba:\nElso jatekos kodja: 1\nMasodik jatekos kodja: 2\n");
	// jatekos1 letrehozasa
	Player* player = CreateNev();
	// jatekos2 letrehozasa
	Player* player2 = CreateNev();
	//ki kovetkezzen es hogy a jatekosok ne lassak egymas lapjat
	//matrix letrehozasa
	// jatekos1 lapjainak letrehozasa
	CreateLapok(player);
	// jatekos2 lapjainak letrehozasa
	CreateLapok(player2);
	//letetKartya letrehozasa
	Kartya* letetKartya = RandKartya();
	//ellenfel kartyai hatanak letrehozasa
	
	int kod=0;
	int lapIndex = 0;

	Player* jelenlegiPlayer;
	Player* ellensegPlayer;

	while (true) {
		//kod beolvasasa scan
		while (true) {
			system("cls");
			printf("Adja meg a jatekos kodjat: ");
			scanf("%i", &kod);
		//jatekos adatainak a kiiratasa
		//leteti kartya kiiratasa
			if (kod == 1) {
				system("cls");
				jelenlegiPlayer = player;
				ellensegPlayer = player2;
				PrintPlayer1(player);
				printLetetKartya(letetKartya);
				printEllensegKartya(ellensegPlayer->lapszam);
				break;
			}
			if (kod == 2) {
				system("cls");
				jelenlegiPlayer = player2;
				ellensegPlayer = player;
				system("cls");
				printEllensegKartya(ellensegPlayer->lapszam);
				printLetetKartya(letetKartya);
				PrintPlayer2(player2);
				break;
			}
		}
		//lap lerakasa vagy lap kerese scan
		while (true)
		{
			//Ha nincs kartya akkor a 0 val lehet huzni
			scanf("%i", &lapIndex);
			if (lapIndex == 0) {
				jelenlegiPlayer->hp -= 1;
			}
			if (
				lapIndex == 0 ||
				(
					lapIndex >= 1 && lapIndex <= jelenlegiPlayer->lapszam && 
					(jelenlegiPlayer->lapok[lapIndex-1]->szam == letetKartya->szam || jelenlegiPlayer->lapok[lapIndex-1]->szin == letetKartya->szin)
				)
			) {
				break;
			}
			else {
				printf("Rossz index :\n1.Ha 0 index akkor huzol egy kartyat.\nHa 1 es az ossz kartyak kozul valasztasz e melett talal a lenti kartyaval akkor helyes index. ");
			}
		}
		if (lapIndex == 0) {
			jelenlegiPlayer->lapok[jelenlegiPlayer->lapszam] = RandKartya();
			jelenlegiPlayer->lapszam += 1;
		}
		//a kezben talalhato kartya letevese 
		//lap ellenorzese es berakasa vagy ujra olvasas
		lapIndex -= 1;
		if (lapIndex >= 0 && lapIndex < jelenlegiPlayer->lapszam) {
			jelenlegiPlayer->lapok[lapIndex] = jelenlegiPlayer->lapok[lapIndex];
			if (jelenlegiPlayer->lapok[lapIndex]->szam == letetKartya->szam) {
				letetKartya->szam = jelenlegiPlayer->lapok[lapIndex]->szam;
				letetKartya->szin = jelenlegiPlayer->lapok[lapIndex]->szin;
			}
			if (jelenlegiPlayer->lapok[lapIndex]->szin == letetKartya->szin) {
				letetKartya->szam = jelenlegiPlayer->lapok[lapIndex]->szam;
				letetKartya->szin = jelenlegiPlayer->lapok[lapIndex]->szin;
			}
			for (int i=lapIndex; i < jelenlegiPlayer->lapszam-1; ++i) {
				jelenlegiPlayer->lapok[i] = jelenlegiPlayer->lapok[i + 1];
			}
			--jelenlegiPlayer->lapszam;
		}
		//jatekallas ellenorzese
		if (jelenlegiPlayer->lapszam == 1) {
			jelenlegiPlayer->szint = 3;
		}
		if (jelenlegiPlayer->lapszam >= 2 && jelenlegiPlayer->lapszam <= 4) {
			jelenlegiPlayer->szint = 2;
		}
		else {
			jelenlegiPlayer->szint = 1;
		}
		if (jelenlegiPlayer->lapszam == 0 || jelenlegiPlayer->hp==0) {
			break;
		}
	}
	system("cls");
	printf("\n\n\n\n\n\t\t\t\t\t\n\n\n\n\n\Meg van a jatek gyoztese!!!!!!!!!!!!!!!!!!\n\n\n\n\n\n\n");

	return 0;
}
