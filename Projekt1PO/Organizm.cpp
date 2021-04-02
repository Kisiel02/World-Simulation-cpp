#include "Organizm.h"

class Swiat;

void Organizm::rysowanie() const
{
	cout << this->znak;
}

Organizm::Organizm(Swiat& swiat, int sila, int inicjatywa, Punkt punkt, char znak)
	: swiat(swiat), sila(sila), inicjatywa(inicjatywa), punkt(punkt), znak(znak)
{
	czySieRozmnozyl = false;
	swiat.nowyOrganizm(this, punkt);
}

void Organizm::setRozmnozenie(bool rozmnozenie)
{
	this->czySieRozmnozyl = rozmnozenie;
}

void Organizm::setSila(int sila)
{
	this->sila = sila;
}

int Organizm::getSila() const
{
	return this->sila;
}

int Organizm::getInicjatywa() const
{
	return this->inicjatywa;;
}

char Organizm::getZnak() const
{
	return this->znak;
}

Punkt Organizm::getPunkt() const
{
	return this->punkt;
}

bool Organizm::getCzySieRozmnozyl()
{
	return czySieRozmnozyl;
}

void Organizm::umrzyj(Organizm* atakujacy)
{
	swiat.zabij(this);
	
}

void Organizm::zapisz(ostream& os) const
{
	os << znak << " " << sila << " " << punkt.x << " " << punkt.y << " " << czySieRozmnozyl<<" ";
}

vector<Punkt> Organizm::sasiedzi()
{
	vector<Punkt> tmp;
	if (this->punkt.x > 0) tmp.push_back(Punkt(punkt.x - 1, punkt.y));
	if (this->punkt.x < swiat.getX() - 1) tmp.push_back(Punkt(punkt.x + 1, punkt.y));
	if (this->punkt.y > 0) tmp.push_back(Punkt(punkt.x, punkt.y - 1));
	if (this->punkt.y < swiat.getY() - 1) tmp.push_back(Punkt(punkt.x, punkt.y + 1));
	return tmp;
}

std::vector<Punkt> Organizm::wolnePola()
{
	vector<Punkt> wolnePola;
	vector<Punkt> sasiedzi = this->sasiedzi();
	for (Punkt punkt : sasiedzi)
		if (swiat[punkt] == nullptr) wolnePola.push_back(punkt);

	return wolnePola;
}

std::ostream& operator<<(std::ostream& os, const Organizm* organizm)
{
	organizm->zapisz(os);
	return os;
}
