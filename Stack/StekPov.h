#pragma once
#include "Cvor.h"
#include "Stek.h"
#include <iostream>
using namespace std;
template <class T>
class StekPov : public Stek<T>
{
	Cvor<T>* prvi = nullptr;
public:
	void dodaj(T x)
	{
		//korak 1
		Cvor<T>* n = new Cvor<T>(x);

		//korak 2
		n->next = prvi;

		//korak 3
		prvi = n;

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
		Cvor<T>* t = prvi;

		//korak 2
		prvi = prvi->next;

		int b = t->info;

		//korak 3
		delete t;


		return b;
	}

	bool jel_prazna() {
		return prvi == nullptr;
	}

	int get_brojac() {
		int b = 0;
		Cvor<T>* t = prvi;
		while (t != nullptr)
		{
			b++;
			t = t->next;

		}

		return b;
	}

	void print()
	{
		Cvor<T>* t = prvi;
		while (t != nullptr)
		{
			cout << t->info << endl;
			t = t->next;

		}
	}
};
