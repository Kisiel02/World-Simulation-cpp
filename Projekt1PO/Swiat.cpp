#include "Swiat.h"
#include <algorithm> 


Swiat::Swiat(int x, int y) : x(x), y(y)
{
	this->komentator = new Komentator();
	tura = 0;
	plansza = new Organizm * *[y];
	for (int i = 0; i < y; i++)
		plansza[i] = new Organizm * [x];
	this->wyczysc();
	rysujSwiat();
	this->pola = znajdzPola();
}

void Swiat::wykonajTure()
{
	sortuj();
	resetujRozmnazanie();
	for (int i = 0; i < organizmy.size(); i++)
		organizmy[i]->akcja();
	rysujSwiat();
	tura++;
}

void Swiat::rysujSwiat() const
{
	system("CLS");
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (plansza[i][j] == nullptr) cout << "-";
			else plansza[i][j]->rysowanie();
		}
		std::cout << endl;
	}

}

void Swiat::oswiez()
{
	this->wyczysc();
	this->zapelnij();
}

bool Swiat::porownaj(const Organizm* a, const Organizm* b)
{
	return a->getInicjatywa() > b->getInicjatywa();
}

void Swiat::sortuj()
{
	std::stable_sort(organizmy.begin(), organizmy.end(), porownajInicjatywe());
}

void Swiat::resetujRozmnazanie()
{
	for (int i = 0; i < organizmy.size(); i++)
		organizmy[i]->setRozmnozenie(false);
}


void Swiat::nowyOrganizm(Organizm* organizm, Punkt punkt)
{
	this->plansza[punkt.y][punkt.x] = organizm;
	organizmy.push_back(organizm);
}

void Swiat::zapelnij()
{
	for (int i = 0; i < organizmy.size(); i++)
	{
		plansza[organizmy[i]->getPunkt().y][organizmy[i]->getPunkt().x] = organizmy[i];
	}
}

void Swiat::wyczysc()
{
	for (int i = 0; i < y; i++)
		for (int j = 0; j < x; j++)
			plansza[i][j] = nullptr;
}

void Swiat::zaktualizuj(Organizm* organizm)
{
	for (int i = 0; i < this->y; i++)
		for (int j = 0; j < this->x; j++)
			if (plansza[i][j] == organizm)
			{
				plansza[i][j] = nullptr;
				plansza[organizm->getPunkt().y][organizm->getPunkt().x] = organizm;
				break;
			}
}

void Swiat::wypiszOrganizmy() const
{
	for (int i = 0; i < organizmy.size(); i++)
	{
		std::cout << organizmy[i]->getZnak() << organizmy[i]->getPunkt().x << " " << organizmy[i]->getPunkt().y << endl;
	}
	cout << endl;
}

int Swiat::getX() const
{
	return this->x;
}

int Swiat::getY() const
{
	return this->y;
}

int Swiat::getTura() const
{
	return tura;
}

void Swiat::setTura(int tura)
{
	this->tura = tura;
}

void Swiat::zapisz()
{
	zapis.open("zapis.txt");
	zapis << x << " " << y << " " << tura << " ";
	for (int i = 0; i < organizmy.size(); i++)
		zapis << organizmy[i];
	zapis.close();
}


Punkt Swiat::getWolnePole()
{
	Punkt pole = pola.back();
	pola.pop_back();
	return pole;
}

vector<Punkt> Swiat::znajdzPola()
{
	vector<Punkt> pola;
	for (int i = 0; i < this->y; i++)
		for (int j = 0; j < this->x; j++)
			pola.push_back(Punkt(j, i));
	random_shuffle(pola.begin(), pola.end());
	return pola;
}

Organizm*& Swiat::operator[](Punkt punkt)
{
	return this->plansza[punkt.y][punkt.x];
}

Swiat& Swiat::operator=(const Swiat& swiat)
{
	x = swiat.x;
	y = swiat.y;
	return *this;
}

Komentator* Swiat::getKomentator()
{
	return this->komentator;
}


void Swiat::zabij(Organizm* organizm)
{
	//usuniete.push_back(organizm);
	int i = 0;
	while (organizmy[i] != organizm) i++;
	organizmy.erase(organizmy.begin() + i);
	this->plansza[organizm->getPunkt().y][organizm->getPunkt().x] = nullptr;
	
}

bool Swiat::czyZajete(Punkt punkt) const
{
	if (this->plansza[punkt.y][punkt.x] != nullptr) return true;
	else return false;
}

bool Swiat::porownajInicjatywe::operator()(const Organizm* a, const Organizm* b) const
{
	return a->getInicjatywa() > b->getInicjatywa();
}

Swiat::~Swiat()
{
	for (int i = 0; i < y; i++)
		delete[] plansza[i];
	delete[] plansza;
	delete komentator;
	
}