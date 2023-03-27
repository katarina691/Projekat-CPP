#include "Zaposleni.h"
#include <iostream>
#include <string>


using namespace std;

Zaposleni::Zaposleni()
{
}

Zaposleni::Zaposleni(int id, string ime, string prezime, double plata) :
	id(id), ime(ime), prezime(prezime), plata(plata)
{
}

Zaposleni::~Zaposleni()
{
	//cout << "Uspesno obrisan zaposlenog sa ID-em: " << id << endl;
}

int Zaposleni::getId() const
{
	return id;
}

void Zaposleni::setId(int id)
{
	this->id = id;
}

string Zaposleni::getIme() const
{
	return ime;
}

void Zaposleni::setIme(string ime)
{
	this->ime = ime;
}

string Zaposleni::getPrezime() const
{
	return prezime;
}

void Zaposleni::setPrezime(string prezime)
{
	this->prezime = prezime;
}

double Zaposleni::getPlata() const
{
	return plata;
}

void Zaposleni::setPlata(double plata)
{
	this->plata = plata;
}



ostream& operator<<(ostream& os, const Zaposleni& Zaposleni)
{
	os << "ZID = " << Zaposleni.getId() << " Ime = " << Zaposleni.getIme() << " Prezime = " << Zaposleni.getPrezime() << " Plata = " << Zaposleni.getPlata();
	return os;
}

istream& operator>>(istream& is, Lekar& Lekar)
{
	return is >> Lekar.id >> Lekar.ime >> Lekar.prezime >> Lekar.plata >> Lekar.fakultet;
}

istream& operator>>(istream& is, MedicinskaSestra& MedicinskaSestra)
{
	return is >> MedicinskaSestra.id >> MedicinskaSestra.ime >> MedicinskaSestra.prezime >> MedicinskaSestra.plata >> MedicinskaSestra.smena;
}

ostream& operator<<(ostream& os, const MedicinskaSestra& MedicinskaSestra)
{
	os << "MID = " << MedicinskaSestra.getId() << " Ime = " << MedicinskaSestra.ime << " Prezime = " << MedicinskaSestra.prezime << " Plata = " << MedicinskaSestra.plata << " Smena: " << MedicinskaSestra.smena;
	return os;
}

ostream& operator<<(ostream& os, const Lekar& Lekar)
{
	os << "LID = " << Lekar.getId() << " Ime = " << Lekar.ime << " Prezime = " << Lekar.prezime << " Plata = " << Lekar.plata << " Fakultet: " << Lekar.fakultet;
	return os;
}

MedicinskaSestra::MedicinskaSestra()
{
}

MedicinskaSestra::MedicinskaSestra(int id, string ime, string prezime, double plata, int smena) : Zaposleni(id, ime, prezime, plata)
{
	this->smena = smena;
}

int MedicinskaSestra::getSmena() const
{
	return smena;
}


void MedicinskaSestra::setSmena(int smena)
{
	this->smena = smena;
}


MedicinskaSestra::~MedicinskaSestra()
{
}



int MedicinskaSestra::dodajBonus()
{
	return (plata * 0.1);
}

Lekar::Lekar()
{
}

Lekar::Lekar(int id, string ime, string prezime, double plata, string fakultet) : Zaposleni(id, ime, prezime, plata)
{
	this->fakultet = fakultet;

}

string Lekar::getFakultet() const
{
	return fakultet;
}

void Lekar::setFakultet(string fakultet)
{
	this->fakultet = fakultet;
}

Lekar::~Lekar()
{
}



int Lekar::dodajBonus()
{
	return (plata * 0.3);
}