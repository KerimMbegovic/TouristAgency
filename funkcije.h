#pragma once
#include <iostream>
#include <Windows.h>
using std::cout;
using std::cin;

void uvodMeni() {
	cout << "\n\t1.Admin meni";
	cout << "\n\t2.Korisnicki meni";
	cout << "\n\t3.Izlaz iz programa";
	cout << "\nIzbor: ";
}

void prvimeni() {
	//system("cls");
	cout << "\n\t1.Registracija";
	cout << "\n\t2.Login";
	cout << "\n\t3.Izlaz";
	cout << "\nIzbor: ";
}

void adminMeni() {
	cout << "\n\t1.Unos smjestaja";
	cout << "\n\t2.Ispis smjestaja";
	//cout << "\n\t3.Pretraga smjestaja";
	cout << "\n\t3.Izlaz";
	cout << "\nIzbor: ";
}
void korisnickiMeni() {
	cout << "\n\t1.Ispis smjestaja\n";
	cout << "\t2.Rezervacija smjestaja\n";
	cout << "\t3.Pretraga smjestaja\n";
	cout << "\t4.Moji podaci\n";
	cout << "\t5.Promjena passworda\n";
	cout << "\t6.Izlaz\n";
	cout << "Izbor: ";
}

void korisnickaPretraga() {
	cout << "\n\t1.Pretraga po gradu\n";
	cout << "\t2.Pretraga po cijeni\n";
	cout << "\t3.Pretraga po broju kreveta\n";
	cout << "\t4.Izlaz\n";
	cout << "Izbor: ";
}








