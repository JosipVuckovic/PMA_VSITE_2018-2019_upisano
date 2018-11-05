#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void main_menu(void);
void zadatak_1();
void do_you_want_more(void);
void zadatak_2();
void zadatak_3();
void zadatak_4();
int main(void)
{
	printf("******************************************************************\n");
	printf("*    PMA Vjeba 6 2018/2019                      Josip Vuckovic   *\n");
	printf("*    Ovaj program moze pokretati sve zadatke iz vjezbe te Vas    *\n");
	printf("*    molim da napravite izbor koji zadatak Vas zanima.           *\n");
	printf("******************************************************************\n");
	main_menu();
	return 0;
}
void main_menu(void)
{
	char izbor;
	printf("******************************************************************\n");
	printf("*    1 - Zadatak 1 - Array 10,potencija svakog clana             *\n");
	printf("*    2 - Zadatak 2 - Trazenje indexa clana arraya                *\n");
	printf("*    3 - Zadatak 3 - Aritmeticka sredina, ispis, najblizi clan   *\n");
	printf("*    4 - Zadatak 4 - Provjere ispisa kodnih odsjecaka iz vjezbe  *\n");
	printf("*    5 - Izlaz                                                   *\n");
	printf("******************************************************************\n");
	printf("         Vas izbor: ");
	scanf(" %c", &izbor);
	switch (izbor)
	{
	case '1':
		zadatak_1();
		break;
	case '2':
		zadatak_2();
		break;
	case '3':
		zadatak_3();
		break;
	case '4':
		zadatak_4();
		break;
	case '5':
		printf("\nHvala na koristenju\n");
		printf("pritisnite bilo koju tipku za izlaz\n");
		getchar();
		getchar();
		break;
	default:
		system("cls");
		printf("\n\n **Nepoznat odabir, molim Vas ponovite unos**\n\n");
		main_menu();
		break;
	}
}
void do_you_want_more(void)
{
	char odabir;
	printf("\n**********************************************************************\n");
	printf("*Zelite li drugi zadatak?*\n");
	printf("**********************************************************************\n");
	printf("y/n: ");
	scanf(" %c", &odabir);
	switch (odabir)
	{
	case 'y':
		system("cls");
		main_menu();
		break;
	case 'Y':
		system("cls");
		main_menu();
		break;
	case 'n':
		printf("\nHvala na korištenju\n");
		printf("pritisnite bilo koju tipku za izlaz\n");
		getchar();
		break;
	case 'N':
		printf("\nHvala na korištenju\n");
		printf("pritisnite bilo koju tipku za izlaz\n");
		getchar();
		break;
	default:
		printf("\nNepoznat unos!\n");
		do_you_want_more();
		break;
	}
}
int funkcija_zad_2(float niz[], float trazeni_broj, int br_clanova)
{
	int i=0;
	for (; i<br_clanova;++i)
	{
		/*printf("\n%f", niz[i]);
		printf("\n%d", i);*/
		if (niz[i] == trazeni_broj)
			return i;
	}
	return -1;
}
void zadatak_2()
{
	float* niz=NULL;
	int i = 0, br_clanova;
	float trazeni_broj;
	system("cls");
	printf("**********************************************************************\n");
	printf("*                        Zadatak 2                                   *\n");
	printf("* Unesemo niz od 10 brojeva, nakon toga unesemo broz koji nas zanima *\n");
	printf("* nalazi li se u nizu, ukoliko je, trebamo javiti index.             *\n");
	printf("**********************************************************************\n");
	printf("\n");
	printf("Unesite koliko clanova niza zelite: ");
	scanf("%d", &br_clanova);
	printf("\n");
	niz = calloc(br_clanova, sizeof(float));
	for (;i<br_clanova ;++i)
	{
		printf("Unesite %d clan niza: ", i + 1);
		scanf("%f", &niz[i]);
		printf("\n");
	}
	printf("Unesite broj koji trazimo: ");
	scanf("%f", &trazeni_broj);
	i = funkcija_zad_2(niz, trazeni_broj, br_clanova);
	if (i >= 0)
	{
		printf("\nTrazeni broj %.2f je %d clan niza i nalazi se na indexu %d ", trazeni_broj,i+1,i);
	}
	else
	{
		printf("\nTrazeni broj nije clan niza!");
	}
	printf("\n");
	do_you_want_more();
}
void zadatak_1()
{
	float niz_10[10] = { 0 };
	int i = 0;
	system("cls");
	printf("**********************************************************************\n");
	printf("*                        Zadatak 1                                   *\n");
	printf("* Unesemo niz od 10 brojeva, nakon toga ispisujemo prvu potenciju    *\n");
	printf("* prvog broja, drugu potenciju drugog broja i tako dalje.            *\n");
	printf("**********************************************************************\n");
	printf("\n");
	for (; i < sizeof(niz_10)/sizeof(niz_10[0]); ++i)
	{
		printf("Unesite %d clan niza: ",i+1);
		scanf("%f", &niz_10[i]);
		printf("\n");
	}
	for ( i = 0; i < sizeof(niz_10) / sizeof(niz_10[0]); ++i)
	{
		printf("\n%d clan na %d potenciju: ", i + 1, i + 1);
		printf("%.2f", pow(niz_10[i], i + 1));
	}
	printf("\n");
	do_you_want_more();
}
float* funkcija_zad_3(float niz[], int br_clanova)
{
	int i = 0;
	float* kopija_niza = NULL;
	float naj_blizi_arit_sredini = 0, arit_sred = 0, suma = 0;
	kopija_niza=calloc((br_clanova+1), sizeof(float));
	memmove(kopija_niza, niz, sizeof(float)*br_clanova);
	for (; i < br_clanova; ++i)
	{
		suma += niz[i];
	}
	// zadnji clan koristim za arit sredinu
	kopija_niza[(br_clanova + 1)] = suma/br_clanova;
	arit_sred = kopija_niza[(br_clanova + 1)];
	// pitati zasto iso qsort ne radi!
	//qsort(kopija_niza, sizeof * kopija_niza, br_clanova, );
	for ( i = 0; i < br_clanova+1; ++i)
	{
		for (int j = 0; j < (br_clanova + 1); j++)
		{
			if (kopija_niza[j] > kopija_niza[i])
			{
				float temp = kopija_niza[i];
				kopija_niza[i] = kopija_niza[j];
				kopija_niza[j] = temp;
			}
		}
	}
	/*for ( i = 1; i < br_clanova+1; ++i)
	{
		printf("\n%.2f", kopija_niza[i]);
	}*/
	printf("\nAritmeticka sredina niza je: %.2f", arit_sred);
	printf("\n Ispis svih clanova manjih od aritmeticke sredine: ");
	printf("\n");
	for ( i = 1; i < (br_clanova+1); ++i)
	{
		if (kopija_niza[i] < arit_sred)
			printf("\n%.2f", kopija_niza[i]);
		if (kopija_niza[i] >= arit_sred)
		{
			if (abs(kopija_niza[i] - kopija_niza[(i - 1)]) <= abs(kopija_niza[i] - kopija_niza[(i + 1)]))
			{
				naj_blizi_arit_sredini = kopija_niza[(i - 1)];
			}
			else
			{
				naj_blizi_arit_sredini = kopija_niza[(i + 1)];
			}
			break;
		}
	}
	for ( i = 0; i < (br_clanova); ++i)
	{
			if (niz[i] == naj_blizi_arit_sredini)
			return &niz[i];
	}
	return -1;
}
void zadatak_3()
{
	float* niz = NULL;
	int i = 0, br_clanova;
	system("cls");
	printf("**********************************************************************\n");
	printf("*                        Zadatak 3                                   *\n");
	printf("* Unesemo neki niz, te trazimo aritmeticku sredinu. Ispisujemo sve   *\n");
	printf("* brojeve koji su manji od arit. sred te ispisujemo najblizi clan.   *\n");
	printf("* Funkcija vraca pokazivac na taj najblizi clan.                     *\n");
	printf("**********************************************************************\n");
	printf("\n");
	printf("Unesite koliko clanova niza zelite: ");
	scanf("%d", &br_clanova);
	printf("\n");
	niz = calloc(br_clanova, sizeof(float));
	for (; i<br_clanova; ++i)
	{
		printf("Unesite %d clan niza: ", i + 1);
		scanf("%f", &niz[i]);
		printf("\n");
	}
	/*for (i=0; i < br_clanova; ++i)
	{
		printf("\n %f",niz[i]);
		
	}*/
	printf("\n");
	printf("\nNajblizi broj aritmetickoj sredini je: %.2f",funkcija_zad_3(niz, br_clanova));
	printf("\n");
	do_you_want_more();
}
void foo(char *slovo)
{
	printf("%c", (*slovo)++);
}
void zadatak_4()
{
	char odabir;
	system("cls");
	printf("**********************************************************************\n");
	printf("*                        Zadatak 4                                   *\n");
	printf("*         Pregled ispisa iz vjezbe, vidi PDF za zadatke.             *\n");
	printf("**********************************************************************\n");
	printf("\n");
	printf("Izaberite 1 ili 2 zadatak: ");
	scanf(" %c", &odabir);
	switch (odabir)
	{
	case '1':
	{
		unsigned i = 1, j;
		for (j = 10,i=0; j; --j)
		{
			if (!i)
				printf("%d %d\n", i, j);
			else
			printf("%d\n", j - i);
			i = 1 - i;
			
		}
		break;
	}
	case '2':
	{
		short i = 4;
		char c = 'a', *p = &c;
		while (--i)
		{
			printf("%c", c);
			foo(p);
		}
		break;
	}
	default:
		printf("\nNepoznat unos!\n");
		zadatak_4();
		break;
	}
	printf("\n");
	do_you_want_more();
}

