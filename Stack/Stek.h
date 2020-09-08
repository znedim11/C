#pragma once


template <class T>
class Stek
{
public:
	virtual bool jel_pun() = 0;
	virtual void dodaj(T x) = 0;
	virtual T ukloni() = 0;
	virtual bool jel_prazna() = 0;
	virtual void print() = 0;
};