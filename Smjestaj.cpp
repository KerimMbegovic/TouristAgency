#include "Smjestaj.h"
#include <iostream>
using std::cin;
using std::cout;


int Smjestaj::brojac = 1;

void Smjestaj::setBrojSoba()
{
	cout << "Unesite broj soba: ";
	cin >> this->brojSoba;
}

void Smjestaj::setBrojKupatila()
{
	cout << "Unesite broj kupatila: ";
	cin >> this->brojKupatila;
	cin.ignore();
}

void Smjestaj::setBrojKreveta()
{
	cout << "Unesite broj kreveta: ";
	cin >> this->brojKreveta;
}

void Smjestaj::setSifraSobe()
{
	this->sifraSobe = brojac;
	Smjestaj::brojac++;
}

void Smjestaj::setCijena()
{
	cout << "Unesite cijenu nocenja (KM): ";
	cin >> this->cijena;
}

void Smjestaj::setGrad()
{
	cout << "Unesite adresu(grad): ";
	cin.getline(grad, 20);
}


void Smjestaj::setZauzetost(Stanje x)
{
	this->stanje = x;
}

int Smjestaj::getBrojSoba()
{
	return this->brojSoba;
}

int Smjestaj::getBrojKupatila()
{
	return this->brojKupatila;
}

int Smjestaj::getBrojKreveta()
{
	return this->brojKreveta;
}

int Smjestaj::getSifraSobe()
{
	return this->sifraSobe;
}


double Smjestaj::getCijena()
{
	return this->cijena;
}

char* Smjestaj::getGrad()
{
	return this->grad;
}

void Smjestaj::unosSmjestaja()
{
	setSifraSobe();
	//redniBrojevi.push_back(getSifraSobe());
	setBrojSoba();
	setBrojKreveta();
	setBrojKupatila();
	setGrad();
	setCijena();
	int izbor;
	cout << "1.Slobodna\n";
	cout << "2.Zauzeta\n";
	cout << "Izbor: ";
	cin >> izbor;
	if (izbor == 1) {
		setZauzetost(slobodno);
	}
	else {
		setZauzetost(zauzeto);
	}
}

Smjestaj::Smjestaj()
{
	this->brojSoba = 0;
	this->brojKreveta = 0;
	this->brojKupatila = 0;
	this->cijena = 0;
	this->stanje = zauzeto;
	strcpy_s(grad, "Grad");
	//this->sifraSobe++;
}

Smjestaj::~Smjestaj()
{
}
