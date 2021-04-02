#pragma once
#include "Roslina.h"
#define SILA_TRAWY 0
#define ZNAK_TRAWY 'T'
#define SZANSZA_ROZMNOZENIA_TRAWY 0.03
class Trawa : public Roslina
{
public:
	Trawa(Swiat& swiat, Punkt punkt);
	Trawa(Swiat& swiat, Punkt punkt, int sila);
	string ToString() override;
private:
	void kolizja(Organizm* atakujacy, bool odbity) override;
	virtual void akcja() override;
	void rozmnozenie() override;
};

