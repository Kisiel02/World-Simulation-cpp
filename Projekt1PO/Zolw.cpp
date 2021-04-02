#include "Zolw.h"

Zolw::Zolw(Swiat& swiat, Punkt punkt)
	: Zwierze(swiat, SILA_ZOLWIA, INICJATYWA_ZOLWIA, punkt, ZNAK_ZOLWIA)
{
}

Zolw::Zolw(Swiat& swiat, Punkt punkt, int sila, bool rozmnozenie)
	: Zwierze(swiat, sila, INICJATYWA_ZOLWIA, punkt, ZNAK_ZOLWIA)
{
}

void Zolw::akcja()
{
	int losowa = rand() % 4;
	if (losowa == 3)
	{
		vector<Punkt> pola = sasiedzi();
		losowa = rand() % pola.size();
		if (swiat[pola[losowa]] == nullptr) idzNaPunkt(pola[losowa]);
		else (swiat[pola[losowa]]->kolizja(this, false));
		if (swiat[pola[losowa]] == nullptr) idzNaPunkt(pola[losowa]);
	}
}

string Zolw::ToString()
{
	return "Zolw";
}

void Zolw::kolizja(Organizm* atakujacy, bool odbity)
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
		else if(!odbity) (atakujacy->kolizja(this, true));
	}
}

bool Zolw::czyTenSamGatunek(Organizm* organizm)
{
	if (dynamic_cast<Zolw*>(organizm) != nullptr) return true;
	else return false;
}

bool Zolw::czyOdbilAtak(Organizm* atakujacy)
{
	if (atakujacy->getSila() < 5 || this->sila > atakujacy->getSila()) return true;
	else return false;
}

void Zolw::rozmnazanie(Organizm* partner)
{
	vector<Punkt> pola1 = this->wolnePola();
	vector<Punkt> pola2 = partner->wolnePola();
	for (Punkt x : pola2)
		pola1.push_back(x);
	if (pola1.size() > 0)
	{
		int random = rand() % pola1.size();
		Zolw* zolw = new Zolw(swiat, pola1[random]);
	}
}
