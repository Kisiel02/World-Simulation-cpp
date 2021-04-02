#pragma once
#include "Roslina.h"
#define SILA_GUARANY 0
#define ZNAK_GUARANY 'G'
#define SZANSZA_ROZMNOZENIA_GUARANY 0.04
class Guarana : public Roslina
{
public:
	Guarana(Swiat& swiat, Punkt punkt);
	Guarana(Swiat& swiat, Punkt punkt, int sila);
	string ToString() override;
private:
	void kolizja(Organizm* atakujacy, bool odbity) override;
	virtual void akcja() override;
	void rozmnozenie() override;
};

