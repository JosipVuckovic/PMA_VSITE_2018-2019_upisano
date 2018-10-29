#define _CRT_SECURE_NO_DEPRECATE
#define M_PI 3.14159265358979323846
#include <stdio.h>
#include <conio.h>
#include <math.h>


void main_menu(void);
void zadatak_1();
void do_you_want_more(void);
int zadatak_2();
void zadatak_3();
void zadatak_4();
int main(void)
{
	printf("******************************************************************\n");
	printf("*    PMA Vjeba 5 2018/2019                      Josip Vuckovic   *\n");
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
	printf("*    1 - Zadatak 1 - Ispis s popisa zadatka                      *\n");
	printf("*    2 - Zadatak 2 - Umnzak i zbroj znamenki, kontrola viseznam  *\n");
	printf("*    3 - Zadatak 3 - Preracun radijana u stupnjeve,minute,sek    *\n");
	printf("*    4 - Zadatak 4 - Heronova formula, trokut, cetverokut        *\n");
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

void zadatak_1(void)
{
	char odabir;
	system("cls");
	printf("**********************************************************************\n");
	printf("*                        Zadatak 1                                   *\n");
	printf("* Provjera ispisa iz zadatka. Izaberite a,b ili c za zadatke         *\n");
	printf("**********************************************************************\n");
	printf("\n");
	printf("Izaberite zadatak: ");
	scanf(" %c", &odabir);
	switch (odabir)
	{
	case 'a':
	case 'A':
	{
		int a, b, c; 
		a = b = c = 2; 
		printf("a=%d b=%d c=%d\n", a, b, c);
		b += ++a + 4;
		printf("b += ++a + 4\n");
		printf("b=%d\n", b);
		b -= a--;
		printf("b -= a--\n");
		printf("b=%d\n", b);
		c += a % b;
		printf("c += a %% b\n");
		printf("c=%d\n", c);
		break;
	}
	case 'b':
	case 'B':
	{
		int i, j, suma; 
		suma = 0; 
		for (i = 3, j = 1; i > 0 || j < 5; i--, j++)
		{
			printf("i= %d\n", i);
			printf("j= %d\n", j);
			suma += i + j;
			printf("suma= %d\n", suma);
			printf("\n");
			
		}
		break;
	}
	case 'c':
	case 'C':
	{
		int a, b, c; 
		a = 10; 
		c = b = a % 4 ? a + 1 : a;
		printf("c=%d\n", c);
		break;
	}
	default:
		printf("Nepoznat odabir, ponovite izbor!");
		zadatak_1();
		break;
	}

	printf("\n");
	do_you_want_more();
}
int provjera_zadatak_2(int uneseni_broj, int *zbroj_znamenki, int *umnozak_znamenki)
{
	int znamenka;
	if (uneseni_broj / 10 == 0)
		return -1;
	while (uneseni_broj!=0)
	{
		znamenka = uneseni_broj % 10;
		*zbroj_znamenki += znamenka;
		*umnozak_znamenki *= znamenka;
		uneseni_broj = uneseni_broj / 10;
	}
	return 0;
}
int zadatak_2()
{
	int uneseni_broj, zbroj_znamenki=0, umnozak_znamenki=1;
	system("cls");
	printf("**********************************************************************\n");
	printf("*                        Zadatak 1                                   *\n");
	printf("* Ispisujemo zbroj i umnozak znamenki broja. Radimo kontrolu je li   *\n");
	printf("* broj vise znamenkast ili ne.                                       *\n");
	printf("**********************************************************************\n");
	printf("\n");
	printf("Unesite broj za provjeru: ");
	scanf("%d", &uneseni_broj);
	printf("\n");
	if ((provjera_zadatak_2(uneseni_broj, &zbroj_znamenki, &umnozak_znamenki)) == -1)
		{
			printf("Uneseni broj nije viseznamenkast broj!\n");
		}
	else
		{
			printf("Uneseni broj: %d\n", uneseni_broj);
			printf("Zbroj znamenki: %d\n", zbroj_znamenki);
			printf("Umnozak znamenki: %d\n", umnozak_znamenki);
		}
	printf("\n");
	do_you_want_more();
	return 0;
}
void kut_u_rad_u_stup_min_sek(float kut_radijani, int *kut_sekunde, int *kut_minute, int *kut_stupnjevi)
{
	int kut_sekunde_ukupno;
	kut_sekunde_ukupno = (int)round((kut_radijani * 180*60*60) / (M_PI));
	*kut_sekunde = kut_sekunde_ukupno % 60;
	*kut_minute = (kut_sekunde_ukupno / 60) % 60;
	*kut_stupnjevi = kut_sekunde_ukupno / (60*60);
}
void zadatak_3()
{
	int uneseni_kut_radijani[2],kut_sekunde=0,kut_minute=0,kut_stupnjevi=0;
	float kut_radijani;
	system("cls");
	printf("**********************************************************************\n");
	printf("*                        Zadatak 3                                   *\n");
	printf("* Preracun kuta iz radijana u stupnjeve, minute i sekunde. Unesite   *\n");
	printf("* kut u obliku razlomka bez pi, npr za 2 pi, unosite 2/1.            *\n");
	printf("**********************************************************************\n");
	printf("\n");
	printf("Unesite kut u radijanima: ");
	scanf("%d/%d", &uneseni_kut_radijani[0],&uneseni_kut_radijani[1]);
	/*printf("%d / %d\n", uneseni_kut_radijani[0], uneseni_kut_radijani[1]);*/
	kut_radijani = (uneseni_kut_radijani[0]*M_PI) / ((float)(uneseni_kut_radijani[1]));
	/*printf("%f", kut_radijani);*/
	kut_u_rad_u_stup_min_sek(kut_radijani,&kut_sekunde,&kut_minute,&kut_stupnjevi);
	printf("\nKut u stupnjevima: \n");
	printf("Stupnjevi: %d\n", kut_stupnjevi);
	printf("Minute: %d\n", kut_minute);
	printf("Sekunde %d\n", kut_sekunde);
	printf("\n");
	do_you_want_more();
}
float provjera_zad_4_trokut(float xA,float xB,float xC,float yA, float yB, float yC, float *opseg)
{
	float s, S, stranica_AB, stranica_AC, stranica_CB;
	stranica_AB = sqrt(pow((xA - xB), 2) + pow((yA - yB), 2));
	stranica_AC = sqrt(pow((xA - xC), 2) + pow((yA - yC), 2));
	stranica_CB = sqrt(pow((xC - xB), 2) + pow((yC - yB), 2));
	s = (stranica_AB + stranica_AC + stranica_CB) / 2;
	*opseg = s*2;
	S = sqrt(s*(s - stranica_AB)*(s -stranica_AC)*(s - stranica_CB));
	return S;
}
float provjera_zad_4_cetverokut(float xA, float xB, float xC,float xD, float yA, float yB, float yC, float yD,float *opseg)
{
	float povrsina=0;
	povrsina+= provjera_zad_4_trokut(xA, xB, xC, yA, yB, yC, opseg);
	povrsina+= provjera_zad_4_trokut(xA, xD, xC, yA, yD, yC, opseg);
	return povrsina;
}
void zadatak_4()
{
	char odabir;
	float xA, xB, xC, xD, yA, yB, yC, yD;
	float opseg;
	system("cls");
	printf("**********************************************************************\n");
	printf("*                        Zadatak 4                                   *\n");
	printf("* Heronova formula, povrsina i opseg trokuta i cetverokuta .         *\n");
	printf("* Izaberite 1 - trokut   2- cetverokut                               *\n");
	printf("**********************************************************************\n");
	printf("\n");
	printf("Vas odabir: ");
	scanf(" %c", &odabir);
	switch (odabir)
	{
	case '1':
		printf("\n Unesite stranice trokuta: \n");
		printf("Tocka A: \n");
		printf("xA= ");
		scanf("%f", &xA);
		printf("\nyA= ");
		scanf("%f", &yA);
		printf("Tocka B: \n");
		printf("xB= ");
		scanf("%f", &xB);
		printf("\nyB= ");
		scanf("%f", &yB);
		printf("Tocka C: \n");
		printf("xB= ");
		scanf("%f", &xC);
		printf("\nyB= ");
		scanf("%f", &yC);
		printf("\nPovrsina: %.2f\n", provjera_zad_4_trokut(xA, xB, xC, yA, yB, yC, &opseg));
		printf("Opseg: %.2f\n", opseg);
		break;
	case '2':
		printf("\n Unesite stranice cetverokuta: \n");
		printf("Tocka A: \n");
		printf("xA= ");
		scanf("%f", &xA);
		printf("\nyA= ");
		scanf("%f", &yA);
		printf("Tocka B: \n");
		printf("xB= ");
		scanf("%f", &xB);
		printf("\nyB= ");
		scanf("%f", &yB);
		printf("Tocka C: \n");
		printf("xB= ");
		scanf("%f", &xC);
		printf("\nyB= ");
		scanf("%f", &yC);
		printf("Tocka D: \n");
		printf("xD= ");
		scanf("%f", &xD);
		printf("\nyD= ");
		scanf("%f", &yD);
		printf("\nPovrsina: %.2f\n", provjera_zad_4_cetverokut(xA, xB, xC, xD, yA, yB, yC,yD, &opseg));
		printf("Opseg: %.2f\n", opseg);
		break;
	default:
		printf("Nepodrzazni odabir!");
		zadatak_4();
		break;
	}
	printf("\n");
	do_you_want_more();
}