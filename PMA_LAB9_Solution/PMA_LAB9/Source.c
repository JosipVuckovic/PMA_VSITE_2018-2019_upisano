#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
void main_menu(void);
void zadatak_1();
void do_you_want_more(void);
void zadatak_2();
void zadatak_3();
//void zadatak_4();
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
	printf("*    1 - Zadatak 1 - Trazenje koje slovo se najcesce pojavljuje  *\n");
	printf("*    2 - Zadatak 2 - Generiranje lozinke                         *\n");
	printf("*    3 - Zadatak 3 - Micanje razmaka iz stringa                  *\n");
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
	//case '4':
	//	zadatak_4();
	//	break;
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
char* funkcija_zad_3_trim(char const *uneseni_string)
{
	char *p=uneseni_string;
	int j = 0;
	char *string=calloc(strlen(uneseni_string), sizeof(char));
	for (p,string; *p!='\0'; p++)
	{
		if (*p != ' ')
		{
			*string = *p;
			j++;
			string++;
		}
		
	}
	*(string+1) = '\0';
	return (string-j);
}
void zadatak_3()
{
	char uneseni_string[255];
	char *stringzad=NULL;
	system("cls");
	printf("**********************************************************************\n");
	printf("*                        Zadatak 3                                   *\n");
	printf("* Unesemo neki string ( max 254 znaka) te program mu makne razmake   *\n");
	printf("**********************************************************************\n");
	printf("\n");
	getchar();
	printf("Unesite string koji zelite trimati: ");
	gets(uneseni_string);
	/*puts(uneseni_string);*/
	stringzad= funkcija_zad_3_trim(uneseni_string);
	printf("\n");
	printf("Trimani string je: \n");
	puts(stringzad);
	printf("\n");
	do_you_want_more();
}
char funkcija_zad_1(char const *uneseni_string, char *p)
{
	char *tmp_string = NULL;
	int i = 0;
	char brojac[26] = { 0 };
	char tmpVar = 0;
	char index = 0;
	tmp_string =calloc(256, sizeof(char));
	strcpy(tmp_string, uneseni_string);
	for (i=0, tmp_string; *tmp_string != '\0';tmp_string++, i++)
	{
		*tmp_string = tolower(*tmp_string);
		tmpVar = *tmp_string - 'a';
		*(brojac + tmpVar) += 1;
	}
	
	tmpVar = *(brojac);
	for (i=0, brojac; i<26;i++)
	{
		if (*(brojac + i) > tmpVar)
		{
			tmpVar = *(brojac + i);
			index = i;
		}
	}
	*p = tmpVar;
	return (index+'a');
}
void zadatak_1()
{
	char uneseni_string[256];
	char p;
	system("cls");
	printf("**********************************************************************\n");
	printf("*                        Zadatak 1                                   *\n");
	printf("* Unesemo neki string (max 255 znaka) te gledamo koje slovo je bilo  *\n");
	printf("* najcesce i koliko puta se ponovilo.                                *\n");
	printf("**********************************************************************\n");
	printf("\n");
	getchar();
	printf("Unesite recenicu: ");
	gets(uneseni_string);
	printf("Najcesce slovo je bilo slovo %c ",funkcija_zad_1(uneseni_string,&p));
	printf(" te se pojavilo %d puta.", p);
	
	printf("\n");
	do_you_want_more();
}
void funkcija_zad_2(int velicina_lozinke)
{
	char *prijedlog_lozinke = NULL;
	int i = 0;
	int tmpVar = velicina_lozinke-2;
	srand(time(NULL));
	prijedlog_lozinke = (char*)calloc(velicina_lozinke, sizeof(char));
	*prijedlog_lozinke =(char)((rand()%9)+48);
	/*printf("%d", velicina_lozinke);*/
	*(prijedlog_lozinke + (velicina_lozinke - 1)) = (char)((rand() % 15) + 33);
	for ( i = 1; i < velicina_lozinke-1; i++)
	{
		*(prijedlog_lozinke + i) = (char)((rand() % 67) + 66);
	}
	*(prijedlog_lozinke+(rand()%(tmpVar/2)+1))= (char)((rand() % 24) + 66);
	*(prijedlog_lozinke + velicina_lozinke) = '\0';
	printf("\n");
	getchar();
	puts(prijedlog_lozinke);
}
void zadatak_2()
{
	int velicina_lozinke;
	system("cls");
	printf("**********************************************************************\n");
	printf("*                        Zadatak 2                                   *\n");
	printf("* Generacija random lozinke prema upiti iz zadatka.                  *\n");
	printf("**********************************************************************\n");
	printf("\n");
	printf("Unesite zeljenu velicinu lozinke: ");
	scanf("%d", &velicina_lozinke);
	if (velicina_lozinke<6)
	{
		printf("Lozinka je prekratka!");
		printf("Ponovite unos!");
		getchar();
		zadatak_2();
	}
	velicina_lozinke += 1;
	/*printf("\n");*/
	/*printf("%d", velicina_lozinke);*/
	funkcija_zad_2(velicina_lozinke);
	
	printf("\n");
	do_you_want_more();

}
