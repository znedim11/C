#include<iostream>
using namespace std;

class Tacka3D {
public:
	int x;
	int y;
	int z;

	friend ostream& operator<<(ostream& cout, Tacka3D& tacka)
	{
		cout << "(" << tacka.x << ", " << tacka.y << ", " << tacka.z << ")";

		return cout;
	}
	friend istream& operator>>(istream& cin, Tacka3D& tacka)
	{
		cout << "Kordinata x: ";
		cin >> tacka.x;
		cout << "Kordinata y: ";
		cin >> tacka.y;
		cout << "Kordinata z: ";
		cin >> tacka.z;

		return cin;
	}
	bool operator==(Tacka3D& desna)
	{
		return x == desna.x && y == desna.y && z == desna.z;
	}
};

class DvostrukiHashing {
	int max;
	int trenutno;
	Tacka3D* nizV;
	bool* nizZ;
	int Hash1(Tacka3D element) { return sqrt(pow(element.x, 2) / 3. + pow(element.y, 2) / 3. + pow(element.z, 2) / 3.); }
	int Hash2(Tacka3D element) { return sqrt(pow(element.x + element.y + element.z, 2)); }
public:
	DvostrukiHashing()
	{
		max = 2;
		trenutno = 0;
		nizV = new Tacka3D[max];
		nizZ = new bool[max];

		for (int i = 0; i < max; i++)
			nizZ[i] = false;
	}

	void Dodaj(Tacka3D element)
	{
		if (Puno())
			throw exception("Niz je pun.\n");

		int pozicija1 = Hash1(element);

		if (nizZ[pozicija1])
		{
			int pozicija2 = Hash2(element);
			int i = 1;

			while (true)
			{
				int pozicija = (pozicija1 + i * pozicija2) % max;

				if (!nizZ[pozicija])
				{
					nizV[pozicija] = element;
					nizZ[pozicija] = true;
					break;
				}
				i++;
			}
		}
		else
		{
			nizV[pozicija1] = element;
			nizZ[pozicija1] = true;
		}


		trenutno++;
	}
	Tacka3D Ukloni(Tacka3D element)
	{
		if (Prazno())
			throw exception("Nemam sta ukloniti.\n");

		int pozicija1 = Hash1(element);

		if (nizZ[pozicija1] && nizV[pozicija1] == element)
		{
			nizZ[pozicija1] = false;
			trenutno--;
			return nizV[pozicija1];
		}
		else
		{
			int pozicija2 = Hash2(element);
			int i = 1;

			while (i <= max)
			{
				int pozicija = (pozicija1 + i * pozicija2) % max;

				if (nizZ[pozicija] && nizV[pozicija] == element)
				{
					nizZ[pozicija] = false;
					trenutno--;
					return nizV[pozicija];
				}

				i++;
			}

		}
		throw exception("Element ne postoji.\n");
	}

	bool Puno() { return trenutno == max; }
	bool Prazno() { return trenutno == 0; }

	void Ispisi() {
		for (int i = 0; i < max; i++)
		{
			cout << i << " ---> ";
			if (nizZ[i])
				cout << nizV[i];
			cout << endl;
		}


		cout << endl;
	}
};

void main(){
		DvostrukiHashing hash;
		int izbor = 0;
		Tacka3D tacka;

		do {
			cout << "0. Izlaz" << endl;
			cout << "1. Dodaj" << endl;
			cout << "2. Ukloni" << endl;
			cout << "3. Ispisi" << endl << endl;

			cout << "Izbor: ";
			cin >> izbor;

			switch (izbor) {
			case 0:
				break;
			case 1:
				system("cls");

				cout << "UNOS TACKE\n";
				cin >> tacka;

				try
				{
					hash.Dodaj(tacka);
				}
				catch (const exception & ex)
				{
					cout << ex.what();
				}

				cout << endl << endl;

				break;
			case 2:
				system("cls");

				cout << "UNOS TACKE\n";
				cin >> tacka;

				try
				{
					tacka = hash.Ukloni(tacka);
					cout << "Uklonjena je tacka " << tacka << ".";
				}
				catch (const exception & ex)
				{
					cout << ex.what();
				}

				cout << endl << endl;

				break;
			case 3:
				system("cls");

				hash.Ispisi();

				cout << endl << endl;

				break;
			default:
				cout << "Probaj opet.";

				cout << endl << endl;

				break;
			}

		} while (izbor != 0);
	}

