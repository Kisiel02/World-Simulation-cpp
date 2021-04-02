//#include "Odczyt.h"
//
//Odczyt::Odczyt() :
//{
//	odczyt.open("zapis.txt");
//	int x, y;
//	odczyt >> x >> y;
//	this->swiat(x, y);
//	//swiat(x, y);  
//}
//
//void Odczyt::wczytaj()
//{
//	
//	Swiat swiat1(x, y);
//	swiat = swiat1;
//	char znak;
//	int sila;
//	int kordX;
//	int kordY;
//	int rozmnozenie;
//	int licznik;
//
//	while (odczyt >> znak >> sila >> kordX >> kordY >> rozmnozenie)
//	{
//
//		Punkt punkt(kordX, kordY);
//		bool rozmnazanie;
//		rozmnozenie == 1 ? rozmnazanie = true : rozmnazanie = false;
//		switch (znak)
//		{
//		case 'C':
//			odczyt >> licznik;
//			Czlowiek(swiat, punkt, sila, rozmnazanie, licznik);
//			break;
//		case 'A':
//			Antylopa(swiat, punkt, sila, rozmnazanie);
//			break;
//		case 'W':
//			Wilk(swiat, punkt, sila, rozmnazanie);
//			break;
//		case 'O':
//			Owca(swiat, punkt, sila, rozmnazanie);
//			break;
//		case 'Z':
//			Zolw(swiat, punkt, sila, rozmnazanie);
//			break;
//		case 'L':
//			Lis(swiat, punkt, sila, rozmnazanie);
//			break;
//		case 'B':
//			BarszczSosnowskiego(swiat, punkt, sila);
//			break;
//		case 'G':
//			Guarana(swiat, punkt, sila);
//			break;
//		case 'M':
//			Mlecz(swiat, punkt, sila);
//			break;
//		case 'T':
//			Trawa(swiat, punkt, sila);
//			break;
//		case 'J':
//			WilczeJagody(swiat, punkt, sila);
//			break;
//		}
//	}
//	odczyt.close();
//
//}