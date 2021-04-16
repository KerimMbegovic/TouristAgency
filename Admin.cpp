#include "Admin.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <windows.h>
#include <fstream>
#include <string>
using std::cin;
using std::cout;

int Admin::brojSmjestaja = 0;

Admin::Admin()
{
}

bool Admin::getRezervisan()
{
	return this->rezervisan;
}

int Admin::getSifraRezervacije()
{
	return this->sifraRezervacije;
}

void Admin::unosSmjestaja()
{
	Smjestaj temp;
	temp.unosSmjestaja();
	smjestaji.push_back(temp);
	brojSmjestaja++;
	cout << "\nUspjesno ste unijeli vas smjestaj!\n\n";
}

void Admin::ispisSmjestaja()
{
	int br = 0;
	cout << "----------------------------------------------------\n";
	cout << "\tSifra\tGrad\t\tBroj soba\tBroj kreveta\t\tCijena/noc\t\tStanje\n\n";
	for (int i = 0; i < brojSmjestaja; i++) {
		br++;
		cout << "\t" << smjestaji[i].getSifraSobe();
		cout << "\t" <<smjestaji[i].getGrad();
		cout << "\t\t" << std::left << smjestaji[i].getBrojSoba();
		cout << "\t\t" << std::left << smjestaji[i].getBrojKreveta();
		cout << "\t\t\t" << std::left << smjestaji[i].getCijena();
		if (smjestaji[i].getStanje() == 1) {
			cout << "\t\t\t" << std::left << "Slobodno\n";
		}
		else {
			cout << "\t\t\t" << std::left << "Zauzeto\n";
		}
	}
	cout << "\n";
	if (br == 0) {
		cout << "\nNema unesenih smjestaja!";
		cout << "\n----------------------------------------------------\n";
		cout << "[ENTER] za povratak\n";
	}
	else {
		cout << "\n----------------------------------------------------\n";
		cout << "[ENTER] za povratak\n";
	}
}

void Admin::rezervacijaSmjestaja(int a)
{
	//Admin a;
	int br = 0;
	
	for (int i = 0; i < Admin::brojSmjestaja; i++) {
		if (smjestaji[i].getSifraSobe() == a && smjestaji[i].getStanje()==slobodno) {
			std::ofstream rezervacija("Potvrda Rezervacije.txt");
			this->sifraRezervacije = smjestaji[i].getSifraSobe();
			br++;
			rezervacija << "Hvala vam na rezervaciji nase sobe u " << smjestaji[i].getGrad() << "\n";
			rezervacija << "Sifra sobe " << smjestaji[i].getSifraSobe();
			rezervacija << "\nCijena smjestaja/noc je " << smjestaji[i].getCijena() << "KM.\n";
			rezervacija << "\n\n[OVAJ DOKUMENT PREDSTAVLJA POTVRDU VASE REGISTRACIJE TE GA ISPRINTANOG PRILAZETE PRILIKOM CHECK INa]";
			smjestaji[i].setZauzetost(zauzeto);
			rezervacija.close();
			
			break;
		}
	}
	this->rezervisan = true;
	if (br == 0) {
		cout << "\nZao nam je! Nismo u mogucnosti rezervisati izabrani smjestaj za vas.\n";
	}
	else {
		cout << "\nRezervacija je uspjesna!\n";
		cout << "Pogledajte dokument Potvrda Rezervacije.txt\n";
	}
}

void Admin::pretragaSmjestajaPoGradu()
{
	cin.ignore();
	char tGrad[20];
	cout << "Unesite ime grada: ";
	cin.getline(tGrad, 20);

	cout << "----------------------------------------------------\n";
	cout << "\tSifra\tGrad\t\tBroj soba\tBroj kreveta\t\tCijena/noc\t\tStanje\n\n";
	int br = 0;
	for (int i = 0; i < Admin::brojSmjestaja; i++) {
		if (_strcmpi(smjestaji[i].getGrad(), tGrad) == 0) {
			br++;
			cout << "\t" << smjestaji[i].getSifraSobe();
			cout << "\t" << smjestaji[i].getGrad();
			cout << "\t\t" << std::left << smjestaji[i].getBrojSoba();
			cout << "\t\t" << std::left << smjestaji[i].getBrojKreveta();
			cout << "\t\t\t" << std::left << smjestaji[i].getCijena();
			if (smjestaji[i].getStanje() == 1) {
				cout << "\t\t\t" << std::left << "Slobodno\n";
			}
			else {
				cout << "\t\t\t" << std::left << "Zauzeto\n";
			}
			cout << "\n";
		}
	}
	if (br == 0) {
		cout << "\nZao nam je. Nije pronadjen ni jedan smjestaj u " << tGrad << "\n\n";
	}
	else {
		//cout << "\nIzaberite sifru sobe: ";
		int rb, YN;

		do {
			cout << "\nUnesite sifru smjestaja za rezervaciju: ";
			cin >> rb;
			//cin.ignore();
			cout << "Da li ste sigurni\n1.Da\n2.Ne\nIzbor: ";
			cin >> YN;
		} while (YN == 2);
		this->rezervacijaSmjestaja(rb);
	}
}

void Admin::pretragaSmjestajaPoCijeni()
{
	cin.ignore();
	double cijenaTemp;
	cout << "Unesite cijenu: ";
	cin >> cijenaTemp;

	cout << "----------------------------------------------------\n";
	cout << "\tSifra\tGrad\t\tBroj soba\tBroj kreveta\t\tCijena/noc\t\tStanje\n\n";
	int br = 0;
	for (int i = 0; i < Admin::brojSmjestaja; i++) {
		if (smjestaji[i].getCijena() <= cijenaTemp) {
			br++;
			cout << "\t" << smjestaji[i].getSifraSobe();
			cout << "\t" << smjestaji[i].getGrad();
			cout << "\t\t" << std::left << smjestaji[i].getBrojSoba();
			cout << "\t\t" << std::left << smjestaji[i].getBrojKreveta();
			cout << "\t\t\t" << std::left << smjestaji[i].getCijena();
			if (smjestaji[i].getStanje() == 1) {
				cout << "\t\t\t" << std::left << "Slobodno\n";
			}
			else {
				cout << "\t\t\t" << std::left << "Zauzeto\n";
			}
			cout << "\n";
		}
	}
	if (br == 0) {
		cout << "\nZao nam je. Nije pronadjen ni jedan smjestaj po cijeni od " << cijenaTemp << " KM.\n\n";
	}
}

void Admin::pretragaSmjestajaPoKrevetima()
{
	int krevetiTemp;
	cout << "Unesite broj kreveta: ";
	cin >> krevetiTemp;

	cout << "----------------------------------------------------\n";
	cout << "\tSifra\tGrad\t\tBroj soba\tBroj kreveta\t\tCijena/noc\t\tStanje\n\n";
	int br = 0;
	for (int i = 0; i < Admin::brojSmjestaja; i++) {
		if (smjestaji[i].getBrojKreveta() == krevetiTemp) {
			br++;
			cout << "\t" << smjestaji[i].getSifraSobe();
			cout << "\t" << smjestaji[i].getGrad();
			cout << "\t\t" << std::left << smjestaji[i].getBrojSoba();
			cout << "\t\t" << std::left << smjestaji[i].getBrojKreveta();
			cout << "\t\t\t" << std::left << smjestaji[i].getCijena();
			if (smjestaji[i].getStanje() == 1) {
				cout << "\t\t\t" << std::left << "Slobodno\n";
			}
			else {
				cout << "\t\t\t" << std::left << "Zauzeto\n";
			}
			cout << "\n";
		}
	}
	if (br == 0) {
		cout << "\nZao nam je. Nije pronadjen ni jedan smjestaj sa " << krevetiTemp << " kreveta.\n\n";
	}
}

void Admin::pretragaSmjestaja()
{
	int izbor;
	do {
		do {
			system("cls");
			cout << "\n\t1.Pretraga po gradu\n";
			cout << "\t2.Pretraga po cijeni\n";
			cout << "\t3.Pretraga po broju kreveta\n";
			cout << "\t4.Izlaz\n";
			cout << "Izbor: ";
			cin >> izbor;
			if (izbor == 1) {
				system("cls");
				this->pretragaSmjestajaPoGradu();
				system("pause");
			}
			if (izbor == 2) {
				system("cls");
				this->pretragaSmjestajaPoCijeni();
				system("pause");
			}
			if (izbor == 3) {
				system("cls");
				this->pretragaSmjestajaPoKrevetima();
				system("pause");
			}
			
		} while (izbor != 4);
	} while (izbor < 1 || izbor>4);

}


Admin::~Admin()
{
}


