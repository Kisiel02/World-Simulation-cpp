#pragma once
#include <vector>
#include <string>
#include "Organizm.h"
#include "Swiat.h"
using namespace std;
class Swiat;
class Organizm;

class Komentator
{
	friend class Swiat;
public:
	Komentator();
	void informacjaOSmierci(Organizm* atakujacy, Organizm* umierajacy);
	void informacjaOZjedzeniu(Organizm* kto, Organizm* co);
	void wypiszKomenarz(int tura) const;
	void skomentuj(int tura);
	void dodajWiadomosc(string wiadomosc);
	~Komentator();
private:
	vector<string> komentarz;
	void wyczyscKomentarz();
};

