#include "BarszczSosnowskiego.h"
#include "Zwierze.h"
BarszczSosnowskiego::BarszczSosnowskiego(Swiat& swiat, Punkt punkt)
	: Roslina(swiat, SILA_BARSZCZU_SOSNOWSKIEGO, punkt, ZNAK_BARSZCZU_SOSNOWSKIEGO, SZANSZA_ROZMNOZENIA_BARSZCZU_SOSNOWSKIEGO)
{
}

BarszczSosnowskiego::BarszczSosnowskiego(Swiat& swiat, Punkt punkt, int sila)
	: Roslina(swiat, sila, punkt, ZNAK_BARSZCZU_SOSNOWSKIEGO, SZANSZA_ROZMNOZENIA_BARSZCZU_SOSNOWSKIEGO)
{

}

string BarszczSosnowskiego::ToString()
{
	return "barszcz sosnowskiego";
}

void BarszczSosnowskiego::kolizja(Organizm* atakujacy, bool odbity)
{
	this->swiat.zabij(atakujacy);
	this->umrzyj(atakujacy);
}

void BarszczSosnowskiego::akcja()
{
	vector<Punkt> sasiedzi = this->sasiedzi();
	for (Punkt sasiad : sasiedzi)
		if (dynamic_cast<Zwierze*>(swiat[sasiad]) != nullptr) swiat[sasiad]->umrzyj(this);
	this->rozmnozenie();
}

void BarszczSosnowskiego::rozmnozenie()
{
	vector<Punkt> pola = wolnePola();
	if (pola.size() > 0 && sprobujSieRozmnozyc())
	{
		int losowa = rand() % pola.size();
		BarszczSosnowskiego* barszczSosnowskiego = new BarszczSosnowskiego(swiat, pola[losowa]);
	}
}

