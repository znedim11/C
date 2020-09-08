#include<iostream>
using namespace std;

class Heap
{
	int max_size = 0;
	int n = 0;
	int* A = new int[max_size + 1];

	void rotiraj(int i, int j) {
		int temp = A[i];
		A[i] = A[j];
		A[j] = temp;
	}

public:
	bool jel_pun() {
		return n = max_size;
	}

	bool jel_prazan() {
		return n == 0;
	}

	void dodaj(int x) {
		n++;
		A[n] = x;
		rekonstrukcijaPremaGore(n);
	}

	void rekonstrukcijaPremaGore(int iVrh) {
		if (iVrh == 1)
			return;

		int roditelj = iVrh / 2;

		if (A[iVrh] > A[roditelj]) {
			rotiraj(iVrh, roditelj);
			rekonstrukcijaPremaGore(roditelj);
		}
	}

	int ukloni() {
		int x = A[1];
		A[1] = A[n];
		n--;
		rekonstrukcijaPremaDole(n);
		return x;
	}

	void rekonstrukcijaPremaDole(int iVrh) {
		//ako je list -> prekid
		if (2 * iVrh > n)
			return;

		int LD = 2 * iVrh;
		int DD = 2 * iVrh + 1;

		int maxI = iVrh;
		if (A[LD] > A[iVrh])
		{
			maxI = LD;
		}
		if (2 * iVrh + 1 >= n && A[DD] > A[maxI])
		{
			maxI = DD;
		}
		if (maxI != iVrh)
		{
			rotiraj(iVrh, maxI);
			rekonstrukcijaPremaDole(maxI);
		}
	}


};




void main() {
	Heap i;
	int a;
	do {
		int b;
		cout << "1.Unesite broj" << endl;
		cout << "2.Uklonite broj" << endl;
		cout << "3.Ukloni sve" << endl;
		cout << "4.Kraj" << endl;
		cin >> a;

		switch (a)
		{
		case 1: 
			cout << "Broj: ";
			cin >> b;
			i.dodaj(b);
			break;
			
		case 2:
			b = i.ukloni();
			cout << "Uklonjeno iz reda: " << b << endl;
			break;
       
		case 3:
			while (!i.jel_prazan()) {
				b = i.ukloni();
				cout << "Uklonjeno iz reda: " << b << endl;
				
			}
			break;
		case 4:
			cout << "Kraj" << endl;
			break;

		default: 
			cout << endl;
			break;
		}
	} while (a != 4);

	

	system("pause>0");


}