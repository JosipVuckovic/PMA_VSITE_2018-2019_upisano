#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <math.h>



void main_menu(void);
void zadatak_1(void);
void do_you_want_more(void);
void zadatak_2(void);
void zadatak_3(void);

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
	printf("*    1 - Zadatak 1 - Operacije s realnim i cijelim brojevima     *\n");
	printf("*    2 - Zadatak 2 - Pregled posljedica po prekoracenju brzine   *\n");
	printf("*    3 - Zadatak 3 - Odredivanje rabata prema kolicini           *\n");
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
	printf("****************************************************************\n");
	printf("*Zelite li drugi zadatak?*\n");
	printf("****************************************************************\n");
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

void zadatak_3(void)
{
	float jedinicna_cijena;
	int kolicina_proizvoda;
	float ukupna_cijena;
	system("cls");
	printf("**********************************************************************\n");
	printf("*                        Zadatak 3                                   *\n");
	printf("* Pregledavamo koliki rabat dajemo na neki proizvod prema kolicini   *\n");
	printf("* kupljenih komada. Korisnik unosi cijenu u decimalnom obliku.       *\n");
	printf("*                 do 5 kom nema popusta                              *\n");
	printf("*                 od 5 do 10 kom 5%%                                 *\n");
	printf("*                 iznad 10 kom  10%%                                 *\n");
	printf("**********************************************************************\n");
	printf("\n");
	printf("Molim unesite jedinicnu cijenu: ");
	scanf("%f", &jedinicna_cijena);
	printf("\n");
	printf("**********************************************************************\n");
	printf("Molim Vas unesite kolicinu narucenog artikla: ");
	scanf("%d" , &kolicina_proizvoda);
	printf("\n");
	printf("**********************************************************************\n");
	if (kolicina_proizvoda <= 5)
	{
		printf("Na kolicinu od %d komada nema nikakvg rabata!\n",kolicina_proizvoda);
		ukupna_cijena = kolicina_proizvoda * jedinicna_cijena;
		printf("Iznos racuna je: %2.f\n", ukupna_cijena);
	}
	else if (kolicina_proizvoda <=10)
	{
		printf("Na kolicinu od %d dajemo 5%% rabata!\n",kolicina_proizvoda);
		ukupna_cijena = (kolicina_proizvoda * jedinicna_cijena);
		ukupna_cijena = ukupna_cijena - (ukupna_cijena*0.05);
		printf("Iznos racuna je: %2.f\n", ukupna_cijena);
	}
	else
	{
		printf("Na kolicinu od %d dajemo 10%% rabata!\n",kolicina_proizvoda);
		ukupna_cijena = (kolicina_proizvoda * jedinicna_cijena);
		ukupna_cijena = ukupna_cijena - (ukupna_cijena*0.10);
		printf("Iznos racuna je: %2.f\n", ukupna_cijena);
	}
	printf("\n");
	do_you_want_more();
	
}

void zadatak_2(void)
{
	float unesena_brzina;
	int dozvoljena_brzina;
	
	system("cls");
	printf("**********************************************************************\n");
	printf("*                        Zadatak 2                                   *\n");
	printf("* Provjera prekoracenja brzine s porukom ovisnom koliko je bilo      *\n");
	printf("* prekoracenje od unesene dozvoljene brzine prema slijedecim vrijed  *\n");
	printf("*                 do 20 km//h 1 kazneni bod                          *\n");
	printf("*                 do 40 km//h 2 kaznena boda                         *\n");
	printf("*                 iznad 40 km//h ""Oduzimanje vozacke""              *\n");
	printf("*   Ukoliko nije bilo prekoracenja, ispisuje se takva poruka         *\n");
	printf("**********************************************************************\n");
	printf("\n");
	printf("Unesite brzinu kojom ste vozili: ");
	scanf("%f", &unesena_brzina);
	printf("\n");
	printf("Unesite koliko ja bila dozvoljena brzina: ");
	scanf("%d", &dozvoljena_brzina);
	printf("**********************************************************************\n");
	
	if (unesena_brzina-dozvoljena_brzina<0 | unesena_brzina-dozvoljena_brzina==0)
	{
		printf("Nema prekoracenja brzine!\n");
		printf("Hvala na sigurnoj voznj!\n");
	}
	else if ((unesena_brzina-dozvoljena_brzina) <= 20)
	{
		printf("Prekoracenje brzine do 20 km//h! \n");
		printf("Dobili ste 1 kazneni bod!\n");
	}
	else if ((unesena_brzina - dozvoljena_brzina) <= 40)
	{
		printf("Prekoracenje brzine do 40 km//h! \n");
		printf("Dobili ste 2 kazneni bod!\n");
	}
	else
	{
		printf("Prekoracenje brzine iznad 40 km//h! \n");
		printf("Ostali ste bez vozacke!!\n");
	}
		
	printf("\n");
	do_you_want_more();
}

void zadatak_1(void)
{
	float prvi_broj;
	float drugi_broj;
	system("cls");
	printf("**********************************************************************\n");
	printf("*                        Zadatak 1                                   *\n");
	printf("* Unos realnih brojeva i valjda ispis cjelobrojne njihove vrijednosti*\n");
	printf("* Provjera dali je prvi dijeljiv s drugim bez ostatka.               *\n");
	printf("* Ukoliko je drugi broj nula, dati poruku o gresci.                  *\n");
	printf("**********************************************************************\n");
	printf("\n");
	printf("Unesite prvi broj: ");
	scanf("%f", &prvi_broj);
	printf("\n");
	printf("Unesite drugi broj: ");
	scanf("%f", &drugi_broj);
	printf("\n");
	printf("**********************************************************************\n");
	printf("Njihove cjelobrojne vrijednosti su: \n");
	printf("Prvi broj: %d \n", (int)prvi_broj);
	printf("Drugi broj: %d \n", (int)drugi_broj);
	printf("\n");
	printf("Provjera dali je prvi djelji bez ostatka: \n");
	if ((int)prvi_broj == 0 | (int)drugi_broj == 0)
	{
		printf("Ne mozemo dijeliti nulama! \n");
	}
	else if ((int)prvi_broj % (int)drugi_broj!=0)
	
	{
		printf("Prvi broj nije djeljiv s drugim bez ostatka!\n");
	}
	else
	{
		printf("Prvi broj je djeljiv s drugim bez ostatka!\n");
	}
	printf("\n");
	do_you_want_more();
}