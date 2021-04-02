#include "Mlecz.h"

Mlecz::Mlecz(Swiat& swiat, Punkt punkt)
	: Roslina(swiat, SILA_MLECZA, punkt, ZNAK_MLECZA, SZANSZA_ROZMNOZENIA_MLECZA)
{
	this->czySieRozmnozyl = false;
}

Mlecz::Mlecz(Swiat& swiat, Punkt punkt, int sila)
	: Roslina(swiat, sila, punkt, ZNAK_MLECZA, SZANSZA_ROZMNOZENIA_MLECZA)
{
}

string Mlecz::ToString()
{
	return "mlecz";
}

void Mlecz::kolizja(Organizm* atakujacy, bool odbity)
{
	this->umrzyj(atakujacy);
}

void Mlecz::akcja()
{
	for (int i = 0; i < ILOSC_PROB_ROZMNOZENIA_MLECZA; i++)
		if (!czySieRozmnozyl)
			this->rozmnozenie();
}

void Mlecz::rozmnozenie()
{
	vector<Punkt> pola = wolnePola();
	if (pola.size() > 0 && sprobujSieRozmnozyc())
	{
		int losowa = rand() % pola.size();
		Mlecz* mlecz = new Mlecz(swiat, pola[losowa]);
		czySieRozmnozyl = true;
	}
}
