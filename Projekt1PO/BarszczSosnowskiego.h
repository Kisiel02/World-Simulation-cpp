#pragma once
#include "Roslina.h"
#define SILA_BARSZCZU_SOSNOWSKIEGO 10
#define ZNAK_BARSZCZU_SOSNOWSKIEGO 'B'
#define SZANSZA_ROZMNOZENIA_BARSZCZU_SOSNOWSKIEGO 0.04
class BarszczSosnowskiego : public Roslina
{
public:
	BarszczSosnowskiego(Swiat& swiat, Punkt punkt);
	BarszczSosnowskiego(Swiat& swiat, Punkt punkt, int sila);
	string ToString() override;
private:
	void kolizja(Organizm* atakujacy, bool odbity) override;
	virtual void akcja() override;
	void rozmnozenie() override;
};

