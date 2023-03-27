#include <iostream>
#include <string>

using namespace std;
class Zaposleni
{
public:
	Zaposleni();
	Zaposleni(int id, string ime, string prezime, double plata);
	~Zaposleni();
	int getId() const;
	void setId(int id);
	string getIme() const;
	void setIme(string ime);
	string getPrezime() const;
	void setPrezime(string prezime);
	double getPlata() const;
	void setPlata(double plata);
	virtual int dodajBonus() = 0;

	friend ostream& operator <<(ostream& os, const Zaposleni& Zaposleni);


protected:
	int id;
	string ime;
	string prezime;
	double plata;
};

class MedicinskaSestra : public Zaposleni
{
public:
	MedicinskaSestra();
	MedicinskaSestra(int id, string ime, string prezime, double plata, int smena);
	int getSmena() const;
	void setSmena(int smena);
	~MedicinskaSestra();
	int dodajBonus() override;
	friend ostream& operator <<(ostream& os, const MedicinskaSestra& MedicinskaSestra);
	friend istream& operator >>(istream& is, MedicinskaSestra& MedicinskaSestra);



protected:
	int smena;
};

class Lekar : public Zaposleni
{
public:
	Lekar();
	Lekar(int id, string ime, string prezime, double plata, string fakultet);
	string getFakultet() const;
	void setFakultet(string);
	~Lekar();
	int dodajBonus() override;
	friend ostream& operator <<(ostream& os, const Lekar& Lekar);
	friend istream& operator >>(istream& is, Lekar& Lekar);

protected:
	string fakultet;
};
