#pragma once
#include "Zwierze.h"
#define SILA_WILKA 9
#define INICJATYWA_WILKA 5
#define ZNAK_WILKA 'W'
class Wilk : public Zwierze
{
public:
	Wilk(Swiat& swiat, Punkt punkt);
	Wilk(Swiat& swiat, Punkt punkt, int sila, bool rozmnozenie);
	void akcja() override;
	string ToString() override;
protected:
private:
	void kolizja(Organizm* organizm, bool odbity) override;
	bool czyTenSamGatunek(Organizm* organizm) override;
	bool czyOdbilAtak(Organizm* atakujacy) override;
	void rozmnazanie(Organizm* partner);
};

