#include "Roslina.h"

Roslina::Roslina(Swiat& swiat, int sila, Punkt punkt, char znak, double szansaRozmnozenia)
	: Organizm(swiat, sila, 0, punkt, znak)
{
	this->szansaRozmnozenia = szansaRozmnozenia;
}

bool Roslina::sprobujSieRozmnozyc()
{
	int losowa = rand() % 100 + 1;
	return this->szansaRozmnozenia * 100 >= losowa;
}

void Roslina::umrzyj(Organizm* atakujacy)
{
	this->swiat.getKomentator()->informacjaOZjedzeniu(atakujacy, this);
	swiat.zabij(this);
}

void Roslina::rozmnozenie()
{
}
