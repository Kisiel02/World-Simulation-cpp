#include "Guarana.h"

Guarana::Guarana(Swiat& swiat, Punkt punkt)
	: Roslina(swiat, SILA_GUARANY, punkt, ZNAK_GUARANY, SZANSZA_ROZMNOZENIA_GUARANY)
{
}

Guarana::Guarana(Swiat& swiat, Punkt punkt, int sila)
	: Roslina(swiat, sila, punkt, ZNAK_GUARANY, SZANSZA_ROZMNOZENIA_GUARANY)
{
}

string Guarana::ToString()
{
	return "Guarana";
}

void Guarana::kolizja(Organizm* atakujacy, bool odbity)
{
	atakujacy->setSila(atakujacy->getSila() + 3);
	this->umrzyj(atakujacy);
}

void Guarana::akcja()
{
	this->rozmnozenie();
}

void Guarana::rozmnozenie()
{
	vector<Punkt> pola = wolnePola();
	if (pola.size() > 0 && sprobujSieRozmnozyc())
	{
		int losowa = rand() % pola.size();
		Guarana* guarana = new Guarana(swiat, pola[losowa]);
	}
}

