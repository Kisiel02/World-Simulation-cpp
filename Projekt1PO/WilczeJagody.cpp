#include "WilczeJagody.h"

WilczeJagody::WilczeJagody(Swiat& swiat, Punkt punkt)
	: Roslina(swiat, SILA_WILCZYCH_JAGOD, punkt, ZNAK_WILCZYCH_JAGOD, SZANSZA_ROZMNOZENIA_WILCZYCH_JAGOD)
{
}

WilczeJagody::WilczeJagody(Swiat& swiat, Punkt punkt, int sila)
	: Roslina(swiat, sila, punkt, ZNAK_WILCZYCH_JAGOD, SZANSZA_ROZMNOZENIA_WILCZYCH_JAGOD)
{
}

string WilczeJagody::ToString()
{
	return "wilcze jagody";
}

void WilczeJagody::kolizja(Organizm* atakujacy, bool odbity)
{
	
	atakujacy->umrzyj(this);
	this->umrzyj(atakujacy);
}

void WilczeJagody::akcja()
{
	this->rozmnozenie();
}

void WilczeJagody::rozmnozenie()
{
	vector<Punkt> pola = wolnePola();
	if (pola.size() > 0 && sprobujSieRozmnozyc())
	{
		int losowa = rand() % pola.size();
		WilczeJagody* wilczeJagody = new WilczeJagody(swiat, pola[losowa]);
	}
}

