#include "Wilk.h"

Wilk::Wilk(Swiat& swiat, Punkt punkt)
	: Zwierze(swiat, SILA_WILKA, INICJATYWA_WILKA, punkt, ZNAK_WILKA)
{
}

Wilk::Wilk(Swiat& swiat, Punkt punkt, int sila, bool rozmnozenie)
	: Zwierze(swiat, sila, INICJATYWA_WILKA, punkt, ZNAK_WILKA)
{
}

void Wilk::akcja()
{
	vector<Punkt> pola = sasiedzi();
	int losowa = rand() % pola.size();
	if (swiat[pola[losowa]] == nullptr) idzNaPunkt(pola[losowa]);
	else (swiat[pola[losowa]]->kolizja(this,false));
	if(swiat[pola[losowa]] == nullptr) idzNaPunkt(pola[losowa]);
}

string Wilk::ToString()
{
	return "wilk";
}

void Wilk::kolizja(Organizm* atakujacy, bool odbity)
{
	if (czyTenSamGatunek(atakujacy))
	{
		if (!this->czySieRozmnozyl && !atakujacy->getCzySieRozmnozyl()) rozmnazanie(atakujacy);
		this->czySieRozmnozyl = true;
		atakujacy->setRozmnozenie(true);
	}
	else
	{
		if (!this->czyOdbilAtak(atakujacy))
		{
			this->umrzyj(atakujacy);
		}
		else if (!odbity) (atakujacy->kolizja(this, true));
	}
}

bool Wilk::czyTenSamGatunek(Organizm* organizm)
{
	if (dynamic_cast<Wilk*>(organizm) != nullptr) return true;
	else return false;
}

bool Wilk::czyOdbilAtak(Organizm* atakujacy)
{
	if (this->sila > atakujacy->getSila()) return true;
	else return false;
}

void Wilk::rozmnazanie(Organizm* partner)
{
	vector<Punkt> pola1 = this->wolnePola();
	vector<Punkt> pola2 = partner->wolnePola();
	for (Punkt x : pola2)
		pola1.push_back(x);
	if (pola1.size() > 0)
	{
		int random = rand() % pola1.size();
		Wilk* wilk = new Wilk(swiat, pola1[random]);
	}
}
