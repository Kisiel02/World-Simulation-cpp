#pragma once
#include "Zwierze.h"
#define SILA_ANTYLOPY 4
#define INICJATYWA_ANTYLOPY 4
#define ZNAK_ANTYLOPY 'A'
class Antylopa : public Zwierze
{
public:
	Antylopa(Swiat& swiat, Punkt punkt);
	Antylopa(Swiat& swiat, Punkt punkt, int sila, bool rozmnozenie);
	void akcja() override;
	string ToString() override;
protected:
private:
	void kolizja(Organizm* organizm, bool odbity) override;
	void rozmnazanie(Organizm* partner);
	bool czyTenSamGatunek(Organizm* organizm) override;
	bool czyOdbilAtak(Organizm* atakujacy) override;
	std::vector<Punkt> sasiedziDalecy();
	void ucieczka();
};

