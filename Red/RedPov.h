#pragma once
#include "Cvor.h"
#include "Red.h"
#include <iostream>
using namespace std;
template <class T>
class RedPov : public Red<T>
{
	Cvor<T>* pocetak = nullptr;
	Cvor<T>* kraj = nullptr;
public:
	void dodaj(T x)
	{
		//korak 1
		Cvor<T>* t = new Cvor<T>(x);

		if (!jel_prazna())
		{
			kraj->next = t;
			//	kraj = t;
			kraj = kraj->next;
		}
		else
		{
			kraj = t;
			pocetak = t;
		}
	}


	bool jel_pun()
	{
		return false;
	}




	T ukloni() {

		if (jel_prazna())
		{
			throw exception("stek je prazan");
		}

		//korak 1
		Cvor<T>* t = pocetak;

		//korak 2
		pocetak = pocetak->next;

		T x = t->info;

		//korak 3
		delete t;
		if (pocetak == nullptr)
		{
			kraj = NULL;
		}

		return x;
	}

	bool jel_prazna() {
		return pocetak == nullptr;
	}

	int get_brojac() {
		int b = 0;
		Cvor<T>* t = pocetak;
		while (t != nullptr)
		{
			b++;
			t = t->next;

		}

		return b;
	}

	void print()
	{
		Cvor<T>* t = pocetak;
		while (t != nullptr)
		{
			cout << t->info << endl;
			t = t->next;

		}
	}
};
