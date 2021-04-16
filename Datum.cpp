#include "Datum.h"
#include <iostream>
using std::cin;
using std::cout;

void Datum::setDatum()
{
	cout << "Unesite datum:\n";
	cout << "Dan: ";
	cin >> this->d;
	cout << "Mjesec: ";
	cin >> this->m;
	cout << "Godina: ";
	cin >> this->g;
}

int Datum::getDatum()
{
	return this->d;
	return this->m;
	return this->g;
}

void Datum::unesiDatum()
{
	this->setDatum();
}

Datum::Datum()
{
	d = 1;
	m = 1;
	g = 1900;
}

Datum::~Datum()
{
}
