#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <math.h>



void main_menu(void);
int zadatak_1();
void do_you_want_more(void);
int zadatak_2();
int zadatak_3();
int main(void)
{
	printf("******************************************************************\n");
	printf("*    PMA Vjeba 1 2018/2019                      Josip Vuckovic   *\n");
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
	printf("*    1 - Zadatak 1 - Provjera zbroja sume znamenki dvaju brojeva *\n");
	printf("*    2 - Zadatak 2 - Jaki broj, provjera zbroja faktorijela      *\n");
	printf("*    3 - Zadatak 3 - Relativno prosti brojevi, provjera          *\n");
	printf("*    4 - Izlaz                                                   *\n");
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
		printf("\nHvala na koristenju\n");
		printf("pritisnite bilo koju tipku za izlaz\n");
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

int provjera_zbroja_znamenki(int broj)
{
	int znamenka;
	int zbroj_znamenki = 0;
	while (broj !=0)
	{
		znamenka = broj % 10;
		zbroj_znamenki += znamenka;
		broj = broj / 10;
	}
	return zbroj_znamenki;
}
int zadatak_1()
{
	int prvi_broj, drugi_broj;
	system("cls");
	printf("**********************************************************************\n");
	printf("*                        Zadatak 1                                   *\n");
	printf("* Unosimo dva cijela broja te gledamo zbroj znamenki.                *\n");
	printf("* Ako su isti, ispisujemo poruku koja to potvrduje, ukoliko nisu,    *\n");
	printf("* ispisujemo poruku koja kaže da nisu.                               *\n");
	printf("**********************************************************************\n");
	printf("\n");
	printf("Unesite prvi broj: ");
	scanf("%d", &prvi_broj);
	printf("\nUnesite drugi broj: ");
	scanf("%d", &drugi_broj);
	printf("\n**********************************************************************\n");
	if (provjera_zbroja_znamenki(prvi_broj) == provjera_zbroja_znamenki(drugi_broj))
		{
		printf("Zbroj znamenki brojeva %d i %d je isti te iznosi %d ", prvi_broj, drugi_broj, provjera_zbroja_znamenki(prvi_broj));
		}
	else
		{
		printf("Zbroj znamenki brojeva %d i %d nije isti!", prvi_broj, drugi_broj);
		}
	printf("\n");
	do_you_want_more();
	return 0;
}
int zbroj_faktorijela_znamenki(int broj)
{
	int znamenka,i;
	int zbroj_faktorijela = 0;
	int faktorijel = 1;
	if (broj == 0)
		return zbroj_faktorijela = 1;
	while (broj != 0)
	{
		znamenka = broj % 10;
		for (i = 1; i <= znamenka; i++)
		{
			faktorijel *= i;	
		}
		zbroj_faktorijela += faktorijel;
		faktorijel = 1;
		broj = broj / 10;
	}
	return zbroj_faktorijela;
}
int zadatak_2()
{
	int broj_za_provjeru;
	system("cls");
	printf("**********************************************************************\n");
	printf("*                        Zadatak 2                                   *\n");
	printf("* Unosimo jedan cijeli broj te gledamo je li on jak broj. Jaki       *\n");
	printf("* brojevi su oni, kojima je broj jednak zbroju faktorijela znamenki. *\n");
	printf("* Ispisujemo potvrdu jesu li ili nisu.                               *\n");
	printf("**********************************************************************\n");
	printf("\n");
	printf("Unesite broj za provjeru: ");
	scanf("%d", &broj_za_provjeru);
	printf("\n**********************************************************************\n");
	/*printf("\n%d\n", zbroj_faktorijela_znamenki(broj_za_provjeru));*/
	if (broj_za_provjeru == zbroj_faktorijela_znamenki(broj_za_provjeru))
		{
		printf("Broj %d je jak broj!!", broj_za_provjeru);
		}
	else
	 {
		printf("Broj %d nije jak broj!!", broj_za_provjeru);
	 }
	printf("\n");
	do_you_want_more();
	return 0;
}
int provjera_relativno_prosti(int *prvi_broj, int *drugi_broj)
{
	int i, odluka=0;
	for (i = 2; i <= *prvi_broj && i <= *drugi_broj; i++)
	{
		if (*prvi_broj%i == 0 && *drugi_broj%i == 0)
		{
			odluka = i;
			break;
		}
	}
	return odluka;
}
int zadatak_3()
{
	int prvi_broj, drugi_broj;
	system("cls");
	printf("**********************************************************************\n");
	printf("*                        Zadatak 3                                   *\n");
	printf("* Unosimo dva cijela broja, te gledamo jesu li relativno prosti.     *\n");
	printf("* Relativno prosti su oni koji nemaju zajednickog djeljitelja.       *\n");
	printf("* Ispisujemo potvrdu jesu li ili nisu.                               *\n");
	printf("**********************************************************************\n");
	printf("\n");
	printf("Unesite prvi broj: ");
	scanf("%d", &prvi_broj);
	printf("\n Unesite drugi broj: ");
	scanf("%d", &drugi_broj);
	printf("\n**********************************************************************\n");
	/*printf("%d",provjera_relativno_prosti(&prvi_broj, &drugi_broj));*/
	if (provjera_relativno_prosti(&prvi_broj, &drugi_broj) > 0)
	{
		printf("Brojevi %d i %d nisu relativno prosti!", prvi_broj, drugi_broj);
	}
	else
	{
		printf("Brojevi %d i %d su relativno prosti!", prvi_broj, drugi_broj);
	}
	
	printf("\n");
	do_you_want_more();
	return 0;
}