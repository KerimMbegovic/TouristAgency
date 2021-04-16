#pragma once
#include <string>
#include "Admin.h"
#include "Smjestaj.h"
//#include "funkcije.h"
class Korisnik
{
private:
	char username[20], password[20], ime[10], prezime[20], adresa[50];
	bool registrovan = false;
	Admin adm;
public:
	Korisnik();
	void setUsername();
	void setPassword();
	void setIme();
	void setPrezime();
	void setAdresa();
	char* getUsername();
	char* getPassword();
	char* getIme();
	char* getPrezime();
	char* getAdresa();
	bool getRegistrovan();
	void registracija();
	bool prijava();
	void ispisiPodatke();
	void promjenaPassworda();
	
	~Korisnik();
};

