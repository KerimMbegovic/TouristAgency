#pragma once
#include <vector>
#include "Smjestaj.h"
class Admin
{
private:
	//char username[20], password[20], ime[10] , prezime[20], adresa[50];
	//bool registrovan = false;
	bool rezervisan = false;
	int sifraRezervacije;
public:
	Admin();
	std::vector<Smjestaj> smjestaji;
	static int brojSmjestaja;
	bool getRezervisan();
	int getSifraRezervacije();
	void unosSmjestaja();
	void ispisSmjestaja();
	void rezervacijaSmjestaja(int a);
	void pretragaSmjestajaPoGradu();
	void pretragaSmjestajaPoCijeni();
	void pretragaSmjestajaPoKrevetima();
	void pretragaSmjestaja();
	~Admin();
};