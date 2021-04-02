#pragma once
#include "Zwierze.h"
#define SILA_OWCY 4
#define INICJATYWA_OWCY 4
#define ZNAK_OWCY 'O'
class Owca : public Zwierze
{
public:
	Owca(Swiat& swiat, Punkt punkt);
	Owca(Swiat& swiat, Punkt punkt, int sila, bool rozmnozenie);
	void akcja() override;
	string ToString() override;
protected:
private:
	void kolizja(Organizm* organizm, bool odbity) override;
	bool czyTenSamGatunek(Organizm* organizm) override;
	bool czyOdbilAtak(Organizm* atakujacy) override;
	void rozmnazanie(Organizm* partner);
};

