#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <limits.h>


void main_menu(void);
int zadatak_1();
void do_you_want_more(void);
int zadatak_2();
int zadatak_3();
int main(void)
{
	printf("******************************************************************\n");
	printf("*    PMA Vjeba 3 2018/2019                      Josip Vuckovic   *\n");
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
	printf("*    1 - Zadatak 1 - Break i continue                            *\n");
	printf("*    2 - Zadatak 2 - Switch i funkcija                           *\n");
	printf("*    3 - Zadatak 3 - Je li P potencija od Q                      *\n");
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

int zadatak_1(void)
{
	int uneseni_broj, suma=0, najmanji=INT_MAX, najveci=INT_MIN; 
	system("cls");
	printf("**********************************************************************\n");
	printf("*                        Zadatak 1                                   *\n");
	printf("*        Unosimo prirodne brojeve dok ne unesemo 0.                  *\n");
	printf("* Ukoliko korisnik unese negativni broj, tu iteraciju zanemarujemo.  *\n");
	printf("* Zadatak kaže da koristimo break i continue.                        *\n");
	printf("**********************************************************************\n");
	printf("\n");
	for (;;)
	{
		printf("Unesite broj: ");
		scanf("%d", &uneseni_broj);
		printf("\n");
		if (uneseni_broj == 0)
			break;
		if (uneseni_broj < 0)
			continue;
		if (uneseni_broj < najmanji)
			najmanji = uneseni_broj;
		if (uneseni_broj > najveci)
			najveci = uneseni_broj;
		suma += uneseni_broj;
	}
	printf("**********************************************************************\n");
	printf("Suma unesenih brojeva: %d\n", suma);
	printf("Najmanji uneseni broj: %d\n", najmanji);
	printf("Najveci uneseni broj:  %d\n", najveci);
	printf("**********************************************************************\n");
	printf("\n");
	do_you_want_more();
	return 0;
}
int funkcija_zad2_A(int x, int n)
{
	return pow(x, n);
}
int funkcija_zad2_B(int x)
{
	int rezultat;
	rezultat= 2 * x + 3;
	printf("%d", rezultat);
	return 0;
}
int funkcija_zad2_C(int x)
{
	return (x + pow(x,2));
}
int zadatak_2()
{
	int x,n;
	char izbor;
	system("cls");
	printf("**********************************************************************\n");
	printf("*                        Zadatak 2                                   *\n");
	printf("*                  Funkcije i swith case                             *\n");
	printf("*                      Izaberite:                                    *\n");
	printf("*                     A) y=x^n                                       *\n");
	printf("*                     B) y=2*x+3                                     *\n");
	printf("*                     C) y=x+x^2                                     *\n");
	printf("*                     D) Izlaz                                       *\n");
	printf("* Bilo koji drugi unos ce reagirati porukom, nepodrzani unos.        *\n");
	printf("**********************************************************************\n");
	printf("\n");
	printf("Vas izbor: ");
	scanf(" %c", &izbor);
	printf("\n");
	switch (izbor)
	{
	case 'a':
	case 'A':
		printf("Unesite x: ");
		scanf("%d", &x);
		printf("Unesite n: ");
		scanf("%d", &n);
		printf("%d", funkcija_zad2_A(x,n));
		break;
	case 'b':
	case 'B':
		printf("Unesite x: ");
		scanf("%d", &x);
		funkcija_zad2_B(x);
		break;
	case 'c':
	case 'C':
		printf("Unesite x: ");
		scanf("%d", &x);
		printf("%d", funkcija_zad2_C(x));
		break;
	case 'd':
	case 'D':
		printf("Povratak u glavni izbornik.");
		do_you_want_more();
		break;
	default:
		printf("Ne podrzani izbor, vracam Vas u izbornik!\n");
		printf("Enter za nastavak");
		getchar();
		zadatak_2();
		break;
	}
	printf("\n");
	do_you_want_more();
	return 0;
}
int provjera_zad_3(int p, int q)
{
	if (q == 1)
		return 1;
	while (p%q==0)
	{
		p = p / q;
			if (p == 1)
				return 1;

	}
	return 0;
}
int zadatak_3()
{
	int p, q;
	system("cls");
	printf("**********************************************************************\n");
	printf("*                        Zadatak 3                                   *\n");
	printf("* Unosimo prirodni broj P te gledamo je li on potencija broja Q.     *\n");
	printf("**********************************************************************\n");
	printf("\n");
	printf("Unesi P: ");
	scanf("%d", &p);
	printf("\nUnesi Q: ");
	scanf("%d", &q);
	printf("\n");
	if (provjera_zad_3(p, q) == 1)
	{
		printf("Broj %d je potencija broja %d", p, q);
	}
	else
	{
		printf("Broj %d nije potencija broja %d", p, q);
	}
	printf("\n");
	do_you_want_more();
	return 0;
}