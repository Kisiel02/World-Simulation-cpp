#include "Lis.h"

Lis::Lis(Swiat& swiat, Punkt punkt)
	: Zwierze(swiat, SILA_LISA, INICJATYWA_LISA, punkt, ZNAK_LISA)
{
}

Lis::Lis(Swiat& swiat, Punkt punkt, int sila, bool rozmnozenie)
	: Zwierze(swiat, sila, INICJATYWA_LISA, punkt, ZNAK_LISA)
{
}

void Lis::akcja()
{
	vector<Punkt> pola = sasiedzi();
	if (pola.size() > 0)
	{
		int losowa = rand() % pola.size();
		if (swiat[pola[losowa]] == nullptr) idzNaPunkt(pola[losowa]);
		else (swiat[pola[losowa]]->kolizja(this, false));
		if (swiat[pola[losowa]] == nullptr) idzNaPunkt(pola[losowa]);
	}
}

string Lis::ToString()
{
	return "lis";
}

void Lis::kolizja(Organizm* atakujacy, bool odbity)
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

bool Lis::czyTenSamGatunek(Organizm* organizm)
{
	if (dynamic_cast<Lis*>(organizm) != nullptr) return true;
	else return false;
}

bool Lis::czyOdbilAtak(Organizm* atakujacy)
{
	if (this->sila > atakujacy->getSila()) return true;
	else return false;
}

std::vector<Punkt> Lis::sasiedzi()
{
	vector<Punkt> tmp;
	if (this->punkt.x > 0)
		if (swiat[Punkt(punkt.x - 1, punkt.y)] == nullptr || swiat[Punkt(punkt.x - 1, punkt.y)]->getSila() <= this->sila)
			tmp.push_back(Punkt(punkt.x - 1, punkt.y));
	if (this->punkt.x < swiat.getX() - 1)
		if (swiat[Punkt(punkt.x + 1, punkt.y)] == nullptr || swiat[Punkt(punkt.x + 1, punkt.y)]->getSila() <= this->sila)
			tmp.push_back(Punkt(punkt.x + 1, punkt.y));
	if (this->punkt.y > 0)
		if (swiat[Punkt(punkt.x, punkt.y - 1)] == nullptr || swiat[Punkt(punkt.x, punkt.y - 1)]->getSila() <= this->sila)
			tmp.push_back(Punkt(punkt.x, punkt.y - 1));
	if (this->punkt.y < swiat.getY() - 1)
		if (swiat[Punkt(punkt.x, punkt.y + 1)] == nullptr || swiat[Punkt(punkt.x, punkt.y + 1)]->getSila() <= this->sila)
			tmp.push_back(Punkt(punkt.x, punkt.y + 1));
	return tmp;
}

void Lis::rozmnazanie(Organizm* partner)
{
	vector<Punkt> pola1 = this->wolnePola();
	vector<Punkt> pola2 = partner->wolnePola();
	for (Punkt x : pola2)
		pola1.push_back(x);
	int random = rand() % pola1.size();
	Lis* lis = new Lis(swiat, pola1[random]);
}
