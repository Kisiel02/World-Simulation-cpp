#include "Zwierze.h"
Zwierze::Zwierze(Swiat& swiat, int sila, int inicjatywa, Punkt punkt, char znak)
	: Organizm(swiat, sila, inicjatywa, punkt, znak)
{
	
}

void Zwierze::rozmnazanie(Organizm* partner)
{
}

void Zwierze::umrzyj(Organizm* atakujacy)
{
	this->swiat.getKomentator()->informacjaOSmierci(atakujacy, this);
	swiat.zabij(this);
}

bool Zwierze::czyOdbilAtak(Organizm* atakujacy)
{
	if (this->sila > atakujacy->getSila()) return true;
	else return false;
}

void Zwierze::wykonajRuch(int kierunek)
{
	switch (kierunek)
	{
	case PRAWO: //w prawo
		this->punkt.x++;
		break;
	case LEWO: //w lewo
		this->punkt.x--;
		break;
	case GORA: //w górê
		this->punkt.y--;
		break;
	case DOL: //w dó³
		this->punkt.y++;
		break;
	}
	this->swiat.zaktualizuj(this);
}

void Zwierze::idzNaPunkt(Punkt nowy)
{
	this->punkt = nowy;
	this->swiat.zaktualizuj(this);
}
