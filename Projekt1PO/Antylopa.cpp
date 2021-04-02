#include "Antylopa.h"

Antylopa::Antylopa(Swiat& swiat, Punkt punkt)
	: Zwierze(swiat, SILA_ANTYLOPY, INICJATYWA_ANTYLOPY, punkt, ZNAK_ANTYLOPY)
{
}

Antylopa::Antylopa(Swiat& swiat, Punkt punkt, int sila, bool rozmnozenie)
	: Zwierze(swiat, sila, INICJATYWA_ANTYLOPY, punkt, ZNAK_ANTYLOPY)
{
}

void Antylopa::akcja()
{
	vector<Punkt> pola = sasiedziDalecy();
	if (pola.size() > 0)
	{
		int losowa = rand() % pola.size();
		if (swiat[pola[losowa]] == nullptr) idzNaPunkt(pola[losowa]);
		else (swiat[pola[losowa]]->kolizja(this, false));
		if (swiat[pola[losowa]] == nullptr) idzNaPunkt(pola[losowa]);
	}
}

string Antylopa::ToString()
{
	return "antylopa";
}

void Antylopa::kolizja(Organizm* atakujacy, bool odbity)
{
	int random = rand() % 2;
	if (czyTenSamGatunek(atakujacy))
	{
		if (!this->czySieRozmnozyl && !atakujacy->getCzySieRozmnozyl()) rozmnazanie(atakujacy);
		this->czySieRozmnozyl = true;
		atakujacy->setRozmnozenie(true);
	}
	else
	{
		if (random)
		{
			if (!this->czyOdbilAtak(atakujacy))
				this->umrzyj(atakujacy);
			else if (!odbity) (atakujacy->kolizja(this, true));
		}
		else ucieczka();
	}
}

bool Antylopa::czyTenSamGatunek(Organizm* organizm)
{
	if (dynamic_cast<Antylopa*>(organizm) != nullptr) return true;
	else return false;
}

bool Antylopa::czyOdbilAtak(Organizm* atakujacy)
{
	if (this->sila > atakujacy->getSila()) return true;
	else return false;
}

std::vector<Punkt> Antylopa::sasiedziDalecy()
{
	vector<Punkt> tmp;
	if (this->punkt.x > 1) tmp.push_back(Punkt(punkt.x - 2, punkt.y));
	if (this->punkt.x < swiat.getX() - 2) tmp.push_back(Punkt(punkt.x + 2, punkt.y));
	if (this->punkt.y > 1) tmp.push_back(Punkt(punkt.x, punkt.y - 2));
	if (this->punkt.y < swiat.getY() - 2) tmp.push_back(Punkt(punkt.x, punkt.y + 2));
	return tmp;
}


void Antylopa::rozmnazanie(Organizm* partner)
{
	vector<Punkt> pola1 = this->wolnePola();
	vector<Punkt> pola2 = partner->wolnePola();
	for (Punkt x : pola2)
		pola1.push_back(x);
	int random = rand() % pola1.size();
	Antylopa* antylopa = new Antylopa(swiat, pola1[random]);
}

void Antylopa::ucieczka()
{
	vector<Punkt> pola = this->wolnePola();
	int random = rand() % pola.size();
	idzNaPunkt(pola[random]);
}