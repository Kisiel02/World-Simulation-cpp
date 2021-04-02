#pragma once
#include "Zwierze.h"
#define SILA_ZOLWIA 2
#define INICJATYWA_ZOLWIA 1
#define ZNAK_ZOLWIA 'Z'
class Zolw : public Zwierze
{
public:
	Zolw(Swiat& swiat, Punkt punkt);
	Zolw(Swiat& swiat, Punkt punkt, int sila, bool rozmnozenie);
	void akcja() override;
	string ToString() override;
protected:
private:
	void kolizja(Organizm* organizm, bool odbity) override;
	bool czyTenSamGatunek(Organizm* organizm) override;
	bool czyOdbilAtak(Organizm* atakujacy) override;
	void rozmnazanie(Organizm* partner);
};

