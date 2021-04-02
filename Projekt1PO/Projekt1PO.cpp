#include "Projekt1PO.h"

using namespace std;

int main()
{
	cout << "Wybierz opcje: " << endl << "1.Nowa gra" << endl << "2.Wczytaj swiat z pliku" << endl;
	int input;
	cin >> input;
	if (input == 1)
	{
		srand(time(NULL));
		Swiat swiat(swiatX, swiatY);
		Czlowiek(swiat, swiat.getWolnePole());
		WilczeJagody(swiat, swiat.getWolnePole());
		WilczeJagody(swiat, swiat.getWolnePole());
		Wilk(swiat, swiat.getWolnePole());
		Wilk(swiat, swiat.getWolnePole());
		Trawa(swiat, swiat.getWolnePole());
		Trawa(swiat, swiat.getWolnePole());
		BarszczSosnowskiego(swiat, swiat.getWolnePole());
		BarszczSosnowskiego(swiat, swiat.getWolnePole());
		Guarana(swiat, swiat.getWolnePole());
		Guarana(swiat, swiat.getWolnePole());
		Mlecz(swiat, swiat.getWolnePole());
		Mlecz(swiat, swiat.getWolnePole());
		Zolw(swiat, swiat.getWolnePole());
		Zolw(swiat, swiat.getWolnePole());
		Lis(swiat, swiat.getWolnePole());
		Lis(swiat, swiat.getWolnePole());
		Antylopa(swiat, swiat.getWolnePole());
		Antylopa(swiat, swiat.getWolnePole());
		Owca(swiat, swiat.getWolnePole());
		Owca(swiat, swiat.getWolnePole());
		swiat.rysujSwiat();
		for (int i = 0; i < LICZBA_TUR; i++)
			swiat.wykonajTure();

	}
	else if (input == 2)
	{
		ifstream odczyt;
		odczyt.open("zapis.txt");
		char znak;
		int sila, tura, kordX, kordY, rozmnozenie, licznik, x, y;
		odczyt >> x >> y >> tura;
		Swiat swiat(x, y);
		swiat.setTura(tura);
		while (odczyt >> znak >> sila >> kordX >> kordY >> rozmnozenie)
		{
			Punkt punkt(kordX, kordY);
			bool rozmnazanie;
			rozmnozenie == 1 ? rozmnazanie = true : rozmnazanie = false;
			Organizm* organizm;
			switch (znak)
			{
			case 'C':
				odczyt >> licznik;
				organizm = new Czlowiek(swiat, punkt, sila, rozmnazanie, licznik);
				break;
			case 'A':
				organizm = new Antylopa(swiat, punkt, sila, rozmnazanie);
				break;
			case 'W':
				organizm = new Wilk(swiat, punkt, sila, rozmnazanie);
				break;
			case 'O':
				organizm = new Owca(swiat, punkt, sila, rozmnazanie);
				break;
			case 'Z':
				organizm = new Zolw(swiat, punkt, sila, rozmnazanie);
				break;
			case 'L':
				organizm = new Lis(swiat, punkt, sila, rozmnazanie);
				break;
			case 'B':
				organizm = new BarszczSosnowskiego(swiat, punkt, sila);
				break;
			case 'G':
				organizm = new Guarana(swiat, punkt, sila);
				break;
			case 'M':
				organizm = new Mlecz(swiat, punkt, sila);
				break;
			case 'T':
				organizm = new Trawa(swiat, punkt, sila);
				break;
			case 'J':
				organizm = new WilczeJagody(swiat, punkt, sila);
				break;
			}
		}
		odczyt.close();
		swiat.rysujSwiat();
		for (int i = 0; i < LICZBA_TUR; i++)
			swiat.wykonajTure();
	}


	return 0;
}

