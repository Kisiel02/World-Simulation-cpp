#include "Czlowiek.h"
#include <conio.h>

Czlowiek::Czlowiek(Swiat& swiat, Punkt punkt)
	: Zwierze(swiat, SILA_CZLOWIEKA, INICJATYWA_CZLOWIEKA, punkt, ZNAK_CZLOWIEKA)
{
	this->aktywnaMoc = false;
	this->licznik = -LICZBA_TUR_SILY_SPECJALNEJ;
}

Czlowiek::Czlowiek(Swiat& swiat, Punkt punkt, int sila, bool rozmnozenie, int licznik)
	: Zwierze(swiat, sila, INICJATYWA_CZLOWIEKA, punkt, ZNAK_CZLOWIEKA)
{
	this->aktywnaMoc = false;
	this->licznik = licznik;
}

void Czlowiek::akcja()
{
	swiat.rysujSwiat();
	swiat.getKomentator()->skomentuj(swiat.getTura());
	int kierunek = _getch();
	if (kierunek == 224) ruch();
	else if (kierunek == 99 && licznik <= -LICZBA_TUR_SILY_SPECJALNEJ)
	{
		swiat.getKomentator()->dodajWiadomosc("Moc specjalna uzyta!");
		licznik = LICZBA_TUR_SILY_SPECJALNEJ;
		akcja();
	}
	else if (kierunek == 99 && licznik <= -LICZBA_TUR_SILY_SPECJALNEJ + 1)
	{
		swiat.getKomentator()->dodajWiadomosc("Moc specjalna niedostepna");
		akcja();
	}
	else if (kierunek == 122)
	{
		this->swiat.zapisz();
		swiat.getKomentator()->dodajWiadomosc("Zapisano swiat!");
	}
	else akcja();

}

string Czlowiek::ToString()
{
	return "czlowiek";
}

void Czlowiek::zapisz(ostream& os) const
{
	os << "C" << " " << sila << " " << punkt.x << " " << punkt.y << " " << czySieRozmnozyl << " " << licznik << " ";
}

void Czlowiek::kolizja(Organizm* atakujacy, bool odbity)
{
	if (!this->czyOdbilAtak(atakujacy))
		this->umrzyj(atakujacy);
	else if (!odbity) (atakujacy->kolizja(this, true));
}

bool Czlowiek::czyTenSamGatunek(Organizm* organizm)
{
	if (dynamic_cast<Czlowiek*>(organizm) != nullptr) return true;
	else return false;
}

bool Czlowiek::czyOdbilAtak(Organizm* atakujacy)
{
	if (this->sila > atakujacy->getSila()) return true;
	else return false;
}

void Czlowiek::ruch()
{
	szybkoscAntylopy();
	int kierunek = _getch();
	Punkt docelowy(this->punkt.x, this->punkt.y);
	if (licznik > 1)
	{
		string wiadomosc = "Moc aktywna przez jescze " + to_string(licznik - 1) + " tur";
		swiat.getKomentator()->dodajWiadomosc(wiadomosc);
	}
	if (!aktywnaMoc) docelowy = kierunekNaPunkt(kierunek);
	else docelowy = kierunekNaPunktSpecjalny(kierunek);
	if (docelowy.x >= 0 && docelowy.x < swiat.getX() && docelowy.y >= 0 && docelowy.y < swiat.getY())
	{
		if (swiat[docelowy] != nullptr) swiat[docelowy]->kolizja(this, false);
		if (swiat[docelowy] == nullptr) idzNaPunkt(docelowy);
		licznik--;
	}
	else
	{
		swiat.getKomentator()->dodajWiadomosc("Niedozwolony ruch");
		akcja();
	}
}

void Czlowiek::szybkoscAntylopy()
{
	if (licznik > 2) aktywnaMoc = true;
	else if (licznik > 0 && licznik < 3)
	{
		cout << "losu losu";
		int losowa = rand() % 2;
		if (losowa) aktywnaMoc = true;
		else aktywnaMoc = false;
	}
	else aktywnaMoc = false;
}

void Czlowiek::rozmnazanie(Organizm* partner)
{
	vector<Punkt> pola1 = this->wolnePola();
	vector<Punkt> pola2 = partner->wolnePola();
	for (Punkt x : pola2)
		pola1.push_back(x);
	int random = rand() % pola1.size();
	Czlowiek* czlowiek = new Czlowiek(swiat, pola1[random]);
}

Punkt Czlowiek::kierunekNaPunkt(int kierunek)
{

	switch (kierunek)
	{
	case KEY_UP:
		return Punkt(this->punkt.x, this->punkt.y - 1);
		break;
	case KEY_DOWN:
		return Punkt(this->punkt.x, this->punkt.y + 1);
		break;
	case KEY_RIGHT:
		return Punkt(this->punkt.x + 1, this->punkt.y);
		break;
	case KEY_LEFT:
		return Punkt(this->punkt.x - 1, this->punkt.y);
		break;
	}
}

Punkt Czlowiek::kierunekNaPunktSpecjalny(int kierunek)
{
	switch (kierunek)
	{
	case KEY_UP:
		return Punkt(this->punkt.x, this->punkt.y - 2);
		break;
	case KEY_DOWN:
		return Punkt(this->punkt.x, this->punkt.y + 2);
		break;
	case KEY_RIGHT:
		return Punkt(this->punkt.x + 2, this->punkt.y);
		break;
	case KEY_LEFT:
		return Punkt(this->punkt.x - 2, this->punkt.y);
		break;
	}

}

