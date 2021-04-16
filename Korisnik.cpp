#include "Korisnik.h"
#include "Admin.h"
//#include "funkcije.h"
#include <iostream>
#include <fstream>
using std::cin;
using std::cout;

void Korisnik::registracija()
{
	if (getRegistrovan() == false) {

		this->setIme();
		this->setPrezime();
		this->setAdresa();
		this->setUsername();
		this->setPassword();

		std::ofstream file("login.txt");
		file << this->getUsername() << std::endl << getPassword();
		file.close();
		system("cls");
		this->registrovan = true;
		cout << "\n\tCestitamo! Uspjesna registracija.\n\n";
		system("pause");
		//system("cls");
	}
	else {
		cout << "\n\tVec ste registrovani!\n\n";
	}

}


bool Korisnik::prijava()
{
	std::string username1, password1, un, pw;

	if (registrovan == true) {
		cout << "Unesite username: ";
		cin >> username1;
		cout << "Unesite password: ";
		cin >> password1;
		std::ifstream read("login.txt");
		getline(read, un);
		getline(read, pw);
		if (un == username1 && pw == password1) {
			return true;
		}
		else {
			return false;
		}
	}
}

Korisnik::Korisnik()
{
	strcpy_s(this->ime, "Niko");
	strcpy_s(this->prezime, "Nikic");
	strcpy_s(this->adresa, "Tamo negdje daleko");
	strcpy_s(this->username, "User");
	strcpy_s(this->password, "Uassword");


}

void Korisnik::setUsername()
{
	//cin.ignore();
	cout << "Username: ";
	cin.getline(this->username, 20);

}

void Korisnik::setPassword()
{
	//cin.ignore();
	cout << "Password: ";
	cin.getline(this->password, 20);
}

void Korisnik::setIme()
{
	cout << "Unesite ime: ";
	cin.getline(this->ime, 10);
}

void Korisnik::setPrezime()
{
	cout << "Unesite prezime: ";
	cin.getline(this->prezime, 20);

}

void Korisnik::setAdresa()
{
	cout << "Unesite adresu: ";
	cin.getline(this->adresa, 50);
}

char* Korisnik::getUsername()
{
	return this->username;
}

char* Korisnik::getPassword()
{
	return this->password;
}

char* Korisnik::getIme()
{
	return this->ime;
}

char* Korisnik::getPrezime()
{
	return this->prezime;
}

char* Korisnik::getAdresa()
{
	return this->adresa;
}


bool Korisnik::getRegistrovan()
{
	return this->registrovan;
}


void Korisnik::ispisiPodatke()
{
	if (adm.getRezervisan() == true) {
		cout << "Podaci o vasem racunu\n";
		cout << "-------------------------------------------\n\n";
		cout << "Ime: " << this->getIme();
		cout << "\nPrezime: " << this->getPrezime();
		cout << "\nAdresa: " << this->getAdresa();
		cout << "\nUsername: " << this->getUsername();
		cout << "\nPassword: " << this->getPassword() << "\n\n";
		for (int i = 0; i < Admin::brojSmjestaja; i++) {
			if (adm.smjestaji[i].getSifraSobe() == adm.getSifraRezervacije()) {
				cout << "\n\tVasa rezervacija\n";
				cout << "Sifra smjestaja: " << adm.smjestaji[i].getSifraSobe();
				cout << "\nGrad: " << adm.smjestaji[i].getGrad();
				cout << "\nCijena: " << adm.smjestaji[i].getCijena()<<"\n";
			}
		}
	}
	else {
		cout << "Podaci o vasem racunu\n";
		cout << "-------------------------------------------\n\n";
		cout << "Ime: " << this->getIme();
		cout << "\nPrezime: " << this->getPrezime();
		cout << "\nAdresa: " << this->getAdresa();
		cout << "\nUsername: " << this->getUsername();
		cout << "\nPassword: " << this->getPassword() << "\n\n";
	}
}

void Korisnik::promjenaPassworda()
{
	system("cls");
	//char passwodTemp[20];
	std::string passwordTemp, pw, un;
	cout << "Stari password: ";
	cin >> passwordTemp;
	std::ifstream read("login.txt");
	getline(read, un);
	getline(read, pw);
	read.close();
	if (passwordTemp == pw) {
		
		cin.ignore();
		do {
			cout << "Novi ";
			this->setPassword();
			if (this->password == passwordTemp) {
				cout << "Pasword isti kao stari!\n";
			}
		} while (this->password == passwordTemp);
		std::ofstream file("login.txt");
		file << this->getUsername() << std::endl << this->getPassword();
		file.close();
		cout << "Uspjesno ste postavili vas novi password!\n";
	}
	else
	{
		cout << "\nNeispravan stari password!\n";
	}
}



Korisnik::~Korisnik()
{
}
