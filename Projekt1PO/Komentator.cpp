#include "Komentator.h"

using namespace std;

Komentator::Komentator()
{
}

void Komentator::wyczyscKomentarz()
{
	komentarz.clear();
}

void Komentator::informacjaOSmierci(Organizm* atakujacy, Organizm* umierajacy)
{
	komentarz.push_back(atakujacy->ToString() + " zabil " + umierajacy->ToString());
}

void Komentator::informacjaOZjedzeniu(Organizm* kto, Organizm* co)
{
	komentarz.push_back(kto->ToString() + " zjadl " + co->ToString());
}

void Komentator::wypiszKomenarz(int tura) const
{
	cout <<"Jakub Kisiel 180327"<<endl<< "Tura nr: " <<tura << endl;
	cout << "Moc specjalna - c   Zapis swiata - z" << endl;
	for (string relacja : komentarz)
		cout << relacja << endl;
}

void Komentator::skomentuj(int tura)
{

	wypiszKomenarz(tura);
	wyczyscKomentarz();
}

void Komentator::dodajWiadomosc(string wiadomosc)
{
	komentarz.push_back(wiadomosc);
}

Komentator::~Komentator()
{
	vector<string>().swap(komentarz);
}
