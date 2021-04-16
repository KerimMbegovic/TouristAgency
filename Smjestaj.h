#pragma once
#include <vector>
enum Stanje { zauzeto, slobodno };

class Smjestaj
{
private:
	int brojSoba, brojKupatila, brojKreveta;
	static int brojac;
	int sifraSobe;
	double cijena;
	char grad[20];
	Stanje stanje;
public:
	std::vector<int> redniBrojevi;
	void setBrojSoba();
	void setBrojKupatila();
	void setBrojKreveta();
	void setSifraSobe();
	void setCijena();
	void setGrad();
	void setZauzetost(Stanje x);
	int getBrojSoba();
	int getBrojKupatila();
	int getBrojKreveta();
	int getSifraSobe();
	double getCijena();
	Stanje getStanje() {
		return this->stanje;
	}
	char* getGrad();
	void unosSmjestaja();
	

	Smjestaj();
	~Smjestaj();
};

