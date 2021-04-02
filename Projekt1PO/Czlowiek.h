#pragma once
#include "Zwierze.h"
#define LICZBA_TUR_SILY_SPECJALNEJ 5
#define SILA_CZLOWIEKA 5
#define INICJATYWA_CZLOWIEKA 4
#define ZNAK_CZLOWIEKA 'C'
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

class Czlowiek : public Zwierze
{
public:
	Czlowiek(Swiat& swiat, Punkt punkt);
	Czlowiek(Swiat& swiat, Punkt punkt, int sila, bool rozmnozenie, int licznik);
	void akcja() override;
	string ToString() override;
	void zapisz(ostream& os) const override;
private:
	void kolizja(Organizm* atakujacy, bool odbity) override;
	void rozmnazanie(Organizm* partner);
	Punkt kierunekNaPunkt(int kierunek);
	Punkt kierunekNaPunktSpecjalny(int kierunek);
	bool czyTenSamGatunek(Organizm* organizm) override;
	virtual bool czyOdbilAtak(Organizm* atakujacy) override;
	void ruch();
	int licznik;
	bool aktywnaMoc;
	void szybkoscAntylopy();
};

