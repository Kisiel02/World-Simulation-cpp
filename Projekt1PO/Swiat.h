#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "Organizm.h"
#include "Komentator.h"
using namespace std;
class Organizm;
class Komentator;
struct Punkt;

class Swiat
{
public:
	Swiat(int x, int y);
	void wykonajTure();
	void rysujSwiat() const;
	void nowyOrganizm(Organizm* organizm, Punkt punkt);
	void zaktualizuj(Organizm* organizm);
	void wypiszOrganizmy() const;
	void zabij(Organizm* organizm);
	bool czyZajete(Punkt punkt) const;
	int getX() const;
	int getY() const;
	int getTura() const;
	void setTura(int tura);
	void zapisz();
	Punkt getWolnePole();
	Organizm*& operator[](Punkt punkt);
	Swiat& operator=(const Swiat& swiat);
	Komentator* getKomentator();
	void oswiez();
	~Swiat();
private:
	int x;
	int y;
	int tura;
	vector<Organizm*> usuniete;
	vector<Punkt> pola;
	vector<Punkt> znajdzPola();
	Organizm*** plansza;
	vector<Organizm*> organizmy;
	void zapelnij();
	void wyczysc();
	void sortuj();
	void resetujRozmnazanie();
	ofstream zapis;
	struct porownajInicjatywe
	{
		bool operator()(const Organizm* a, const Organizm* b) const;
	};
	bool porownaj(const Organizm* a, const Organizm* b);
	Komentator* komentator;
};

