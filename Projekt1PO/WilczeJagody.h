#pragma once
#include "Roslina.h"
#define SILA_WILCZYCH_JAGOD 99
#define ZNAK_WILCZYCH_JAGOD 'J'
#define SZANSZA_ROZMNOZENIA_WILCZYCH_JAGOD 0.03
class WilczeJagody : public Roslina
{
public:
	WilczeJagody(Swiat& swiat, Punkt punkt);
	WilczeJagody(Swiat& swiat, Punkt punkt, int sila);
	string ToString() override;
private:
	void kolizja(Organizm* atakujacy, bool odbity) override;
	virtual void akcja() override;
	void rozmnozenie() override;
};

