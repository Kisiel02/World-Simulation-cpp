#pragma once
#include "Organizm.h"
class Roslina : public Organizm
{
protected:
	Roslina(Swiat& swiat, int sila, Punkt punkt, char znak, double szanszaRozmnozenia);
	double szansaRozmnozenia;
	bool sprobujSieRozmnozyc();
	void umrzyj(Organizm* atakujacy);
private:
	virtual void rozmnozenie() = 0;
};

