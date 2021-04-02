#pragma once
#include "Organizm.h"
class Zwierze : public Organizm
{
protected:
	Zwierze(Swiat& swiat, int sila, int inicjatywa, Punkt punkt, char znak);
	void wykonajRuch(int kierunek);
	void idzNaPunkt(Punkt nowy);
	virtual void rozmnazanie(Organizm* partner) = 0;
	void umrzyj(Organizm* atakujacy);
private:
	virtual bool czyTenSamGatunek(Organizm* organizm) = 0;
	virtual bool czyOdbilAtak(Organizm* atakujacy);
};

