#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <conio.h>

void main_menu(void);
void zadatak_1();
void do_you_want_more(void);
int zadatak_2();
int zadatak_3();
int main(void)
{
	printf("******************************************************************\n");
	printf("*    PMA Vjeba 4 2018/2019                      Josip Vuckovic   *\n");
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
	printf("*    1 - Zadatak 1 - Pitagora i tri petlje                       *\n");
	printf("*    2 - Zadatak 2 - Ispis 4-znam. brojeva,ista suma i umnozak   *\n");
	printf("*    3 - Zadatak 3 - Unos broja i trazenje tko ga moze dati      *\n");
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

void provjera_zadatak_1(int uneseni_broj)
{
	int i, j, k;
	for ( i = 1; i <= uneseni_broj; i++)
	{
		for (j = 1; j <= uneseni_broj; j++)
		{
			for (k = 1; k <= uneseni_broj; k++)
			{
				if ((i*i) + (j*j) == (k*k))
				{
					printf("\n Jednadzba %d^2+ %d^2 = %d^2 daje pravokutan trokut\n", i, j, k);
				}
			}
		}
	}
}
void zadatak_1()
{
	int uneseni_broj;
	system("cls");
	printf("**********************************************************************\n");
	printf("*                        Zadatak 1                                   *\n");
	printf("* Unesemo neki broj te ispisujemo sve trojke brojeva manjih njumu ili*\n");
	printf("* jednakih njemu koji zadovoljavaju pitagorin poucak.                *\n");
	printf("**********************************************************************\n");
	printf("\n");
	printf("Unesite broj za provjeru: ");
	scanf("%d", &uneseni_broj);
	printf("\n");
	provjera_zadatak_1(uneseni_broj);

	printf("\n");
	do_you_want_more();
}
int prvojera_sume_zadatak_2(int trenutni_broj)
{
	int znamenka;
	int zbroj_znamenki = 0;
	while (trenutni_broj != 0)
	{
		znamenka = trenutni_broj % 10;
		zbroj_znamenki += znamenka;
		trenutni_broj = trenutni_broj / 10;
	}
	return zbroj_znamenki;
}
int provjera_umnoska_zadatak_2(int trenutni_broj)
{
	int znamenka;
	int umnozak_znamenki = 1;
	while (trenutni_broj != 0)
	{
		znamenka = trenutni_broj % 10;
		umnozak_znamenki *= znamenka;
		trenutni_broj = trenutni_broj / 10;
	}
	return umnozak_znamenki;
}
int zadatak_2()
{
	int i;
	system("cls");
	printf("**********************************************************************\n");
	printf("*                        Zadatak 2                                   *\n");
	printf("* Ispisujemo sve cetvero znamenkaste brojeve koji imaju istu sumu i  *\n");
	printf("* umnozak znamenki. Moramo imati posebne funkcije za kontrolu.       *\n");
	printf("**********************************************************************\n");
	printf("\n");
	for (i = 1000; i <10000 ; i++)
	{
		if (prvojera_sume_zadatak_2(i)==provjera_umnoska_zadatak_2(i))
		{
			printf("Broj %d ima istu sumu i umnozak znamenki!\n", i);
		}
	}
	printf("\n");
	do_you_want_more();
	return 0;
}
int zadatak_3()
{
	int uneseni_broj, i, j, flag = 0;
	system("cls");
	printf("**********************************************************************\n");
	printf("*                        Zadatak 3                                   *\n");
	printf("* Unosimo neki broj te gledamo umnozak koja 2 broja daje taj broj.   *\n");
	printf("* Ispisati samo jedan par.                                           *\n");
	printf("**********************************************************************\n");
	printf("\n");
	printf("Unesite broj: ");
	scanf("%d", &uneseni_broj);
	printf("\n");
	for (i=2; i < uneseni_broj/2; i++)
	{
		for (j = uneseni_broj/2; j >= 2; j--)
		{
			if (i*j==uneseni_broj)
			{
				printf("Umnozak brojeva %d i %d daje pocetni broj %d\n", i, j, uneseni_broj);
				flag = 1;
				break;
			}
			if (flag == 1)
				break;
		}
	}
	if (flag == 0)
	{
		printf("Nije bilo moguce dobiti trazeni broj!");
	}
	printf("\n");
	do_you_want_more();
	return 0;
}