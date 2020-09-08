
#include <iostream>
#include "Stek.h"
#include "StekSekv.h"
#include "StekPov.h"
#include <vector>
using namespace std;

void StekOperacije(Stek<int>& x)
{
	int u;
	do
	{
		cout << "========STEK=========" << endl << endl;
		cout << "1.	Dodaj na vrh" << endl;
		cout << "2.	Ukloni sa vrha" << endl;
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
			cout << "Uklonjeno sa vrha " << b << endl;
			break;
		case 3:
			x.print();
			break;
		case 4:
			while (!x.jel_prazna())
			{
				b = x.ukloni();
				cout << "Uklonjeno sa vrha " << b << endl;
			}
			break;
		default:
			break;
		}
	} while (u != 0);


}


void main()
{
	StekPov<int> s1;
	StekOperacije(s1);

}
