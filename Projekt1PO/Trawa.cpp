#include "Trawa.h"

Trawa::Trawa(Swiat& swiat, Punkt punkt)
	: Roslina(swiat, SILA_TRAWY, punkt, ZNAK_TRAWY, SZANSZA_ROZMNOZENIA_TRAWY)
{
}

Trawa::Trawa(Swiat& swiat, Punkt punkt, int sila)
	: Roslina(swiat, sila, punkt, ZNAK_TRAWY, SZANSZA_ROZMNOZENIA_TRAWY)
{
}

string Trawa::ToString()
{
	return "trawa";
}

void Trawa::kolizja(Organizm* atakujacy, bool odbity)
{
	this->umrzyj(atakujacy);
}

void Trawa::akcja()
{
	this->rozmnozenie();
}

void Trawa::rozmnozenie()
{
	vector<Punkt> pola = wolnePola();
	if (pola.size() > 0 && sprobujSieRozmnozyc())
	{
		int losowa = rand() % pola.size();
		Trawa* trawa = new Trawa(swiat, pola[losowa]);
	}
}

//bool Trawa::sprobujSieRozmnozyc()
//{
//	
//}
