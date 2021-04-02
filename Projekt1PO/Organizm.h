#pragma once
#include "Swiat.h"
#include <stdlib.h>     
#include <time.h>      
#include <string>

#define GORA 0
#define DOL 1
#define LEWO 2
#define PRAWO 3
typedef struct Punkt
{
	int x;
	int y;
	Punkt(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

class Swiat;

class Organizm
{	
public:
	virtual void kolizja(Organizm* organizm, bool odbity) = 0;
	virtual void rysowanie() const;
	int getSila() const;
	int getInicjatywa() const;
	char getZnak() const;
	Punkt getPunkt() const;
	bool getCzySieRozmnozyl();
	std::vector<Punkt> wolnePola();
	virtual std::string ToString() = 0;
	void setRozmnozenie(bool rozmozenie);
	void setSila(int sila);
	virtual void akcja() = 0;
	Swiat& swiat;
	virtual void umrzyj(Organizm* atakujacy);
	virtual void zapisz(std::ostream& os) const;
	friend std::ostream& operator<<(std::ostream& os, const Organizm* organizm);	
protected:
	Organizm(Swiat& swiat, int sila, int inicjatywa, Punkt punkt, char znak);
	int sila;
	const int inicjatywa;
	Punkt punkt;
	virtual std::vector<Punkt> sasiedzi();
	bool czySieRozmnozyl;
private:
	const char znak;
};

