
#include <iostream>
#include "Red.h"
#include <vector>
#include "RedSekv.h"
#include "RedPov.h"

using namespace std;










void RedOperacije(Red<int>& x)
{
	int u;
	do
	{
		cout << "========RED=========" << endl << endl;
		cout << "1.	Dodaj u red" << endl;
		cout << "2.	Ukloniiz reda" << endl;
		cout << "3.	Print" << endl;
		cout << "4.	Sve ukloni" << endl;
		cout << "0.	Exit" << endl;
		cin >> u;
		int b;
		switch (u)
		{
		case 1:
			cout << "Unesite broj: ";
			cin >> b;
			x.dodaj(b);
			break;
		case 2:
			b = x.ukloni();
			cout << "Uklonjeno iz reda " << b << endl;
			break;
		case 3:
			x.print();
			break;
		case 4:
			while (!x.jel_prazna())
			{
				b = x.ukloni();
				cout << "Uklonjeno siz reda " << b << endl;
			}
			break;
		default:
			break;
		}
	} while (u != 0);


}



struct Osoba
{
	Osoba()
	{

	}
	Osoba(string i)
	{
		ime = i;
	}
	string ime;

};

ostream& operator << (ostream& out, const Osoba& c)
{
	out << c.ime;
	return out;
}

void main()
{/*
	ListaSekv<int> x;
	ListaPov<int> y;
	ListaOperacije(x);
	ListaOperacije(y);

	StekPov<int> s1;
	StekOperacije(s1);
	*/

	//ListaPov<Osoba> A;
	//ListaPov<Osoba*> B;
	//A.dodaj_na_kraj(Osoba("A A"));
	//B.dodaj_na_kraj(new Osoba("B B"));

	RedPov<int> r1;
	RedSekv<int> r2;
 	RedOperacije(r2);



	/*PrioritetniRedSekv<int> r1;
	PROperacije(r1);*/
}
