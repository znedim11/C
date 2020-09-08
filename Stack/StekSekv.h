#pragma once

#include <iostream>
using namespace std;
#include "Stek.h"


template <class T>
class StekSekv : public Stek<T>
{
	int max_size = 2;
	int brojac = 0;
	T* niz = new T[max_size];
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
		T* noviNiz = new T[max_size * 2];
		for (int i = 0; i < brojac; i++)
		{
			noviNiz[i] = niz[i];
		}
		max_size *= 2;
		delete[]niz;
		niz = noviNiz;
		std::cout << "Niz je prosiren" << std::endl;
	}

	void dodaj(T x)
	{
		if (jel_pun())
		{
			prosiri_niz();
		}
		niz[brojac] = x;
		brojac++;

	}

	T ukloni() {
		brojac--;
		T x = niz[brojac];
		return x;
	}
	bool jel_prazna() {
		return brojac == 0;
	}

	int get_brojac() {
		return brojac;
	}



};