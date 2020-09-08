#pragma once

#include <iostream>
using namespace std;
#include "Red.h"

template <class T>
class RedSekv : public Red<T>
{
	int max_size = 100;
	int brojac = 0;
	T* niz = new T[max_size];
	int pocetak = 0;
	int kraj = 0;

public:
	void print()
	{
		for (int i = 0; i < get_brojac(); i++)
		{
			cout << niz[i] << " | ";
		}
		cout << endl;
	}



	bool jel_pun()
	{
		return brojac == max_size;
	}

	void prosiri_niz()
	{
		//
	}

	void dodaj(T x)
	{
		if (jel_pun())
		{
			prosiri_niz();
		}
		niz[kraj] = x;
		kraj++;
		if (kraj == max_size) kraj = 0;
		brojac++;

	}

	T ukloni() {
		brojac--;
		T x = niz[pocetak];

		pocetak++;
		if (pocetak == max_size) pocetak = 0;
		return x;
	}
	bool jel_prazna() {
		return brojac == 0;
	}
	T get(int index) {
		return niz[index];
	}
	int get_brojac() {
		return brojac;
	}

};
