#pragma once
#include "Zwierze.h"
#define SILA_LISA 3
#define INICJATYWA_LISA 7
#define ZNAK_LISA 'L'
class Lis : public Zwierze
{
public:
	Lis(Swiat& swiat, Punkt punkt);
	Lis(Swiat& swiat, Punkt punkt, int sila, bool rozmnozenie);
	void akcja() override;
	string ToString() override;
protected:
private:
	void kolizja(Organizm* organizm,bool odbity) override;
	void rozmnazanie(Organizm* partner);
	bool czyTenSamGatunek(Organizm* organizm) override;
	bool czyOdbilAtak(Organizm* atakujacy) override;
	std::vector<Punkt> sasiedzi() override;
};

