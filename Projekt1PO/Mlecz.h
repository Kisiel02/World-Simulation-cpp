#pragma once
#include "Roslina.h"
#define SILA_MLECZA 0
#define ZNAK_MLECZA 'M'
#define SZANSZA_ROZMNOZENIA_MLECZA 0.03
#define ILOSC_PROB_ROZMNOZENIA_MLECZA 3
class Mlecz : public Roslina
{
public:
	Mlecz(Swiat& swiat, Punkt punkt);
	Mlecz(Swiat& swiat, Punkt punkt, int sila);
	string ToString() override;
private:
	void kolizja(Organizm* atakujacy, bool odbity) override;
	virtual void akcja() override;
	void rozmnozenie() override;
};

