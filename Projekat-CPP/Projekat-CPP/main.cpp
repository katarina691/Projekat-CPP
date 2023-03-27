#include <iostream>
#include "Zaposleni.h"
#include "IzuzetakFile.h"
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <stack>
#include <string>

using namespace std;
int main() {
	int izbor;
	ofstream out;
	Lekar lekar;
	MedicinskaSestra medSestra;

	stack<Lekar> LS;
	stack<MedicinskaSestra> MS;

	ifstream fin;
	int plata, idKorisnik;
	string id, ime, prezime, temp;
	int find = 0;
	cout << "Dobrodosli u sistem bolnice. Unesite broj u zavisnosti od toga sta zelite da ucinite: " << endl;
	while (true) {
		cout << endl << "1 - Upis novog lekara" << endl;
		cout << "2 - Upis nove medicinske sestre" << endl;
		cout << "3 - Ispis svih lekara, u novi fajl upisan bonus svakom lekaru" << endl;
		cout << "4 - Ispis svih medicinskih sestara, u novi fajl upisan bonus svakoj medicinskoj sestri" << endl;
		cout << "5 - Pretraga zaposlenog po ID-u" << endl;
		cout << "6 - Izlazak iz programa" << endl;
		cin >> izbor;

		switch (izbor) {

		case 1:

			out.open("zaposleni.txt", std::ios_base::app);
			cout << "Unesite ID, ime, prezime, platu, fakultet lekara: ";
			cin >> lekar;
			out << endl << "L" << lekar.getId() << " " << lekar.getIme() << " " << lekar.getPrezime() << " " << lekar.getPlata() << " " << lekar.getFakultet();
			out.close();
			break;
		case 2:

			out.open("zaposleni.txt", std::ios_base::app);
			cout << "Unesite ID, ime, prezime, platu, smenu medicinske sestre: ";
			cin >> medSestra;
			out << endl << "M" << medSestra.getId() << " " << medSestra.getIme() << " " << medSestra.getPrezime() << " " << medSestra.getPlata() << " " << medSestra.getSmena();
			out.close();
			break;
		case 3:
			try {
				fin.open("zaposleni.txt");
				if (!fin) {
					throw IzuzetakFile("FajlNePostojiException");
				}
				else {
					cout << "Uspesno otvorio fajl o zaposlenima." << endl;
				}
			}
			catch (IzuzetakFile& e)
			{
				cerr << "Nastao je izuzetak pri otvaranju fajla o zaposlenima." << e.GetError() << endl;
			}


			while (fin >> id >> ime >> prezime >> plata >> temp) {
				if (id.find("L") == 0) {
					id = id.substr(1, id.length());
					lekar.setId(stoi(id));
					lekar.setIme(ime);
					lekar.setPrezime(prezime);
					lekar.setPlata(plata);
					lekar.setFakultet(temp);
					LS.push(lekar);
				}

			}
			fin.close();
			out.open("lekariBonusi.txt");
			while (!LS.empty()) {
				cout << LS.top() << endl;
				out << LS.top() << " Bonus: " << LS.top().dodajBonus() << endl;
				LS.pop();
			}
			out.close();
			break;

		case 4:

			try {
				fin.open("zaposleni.txt");
				if (!fin) {
					throw IzuzetakFile("FajlNePostojiException");
				}
				else {
					cout << "Uspesno otvorio fajl o zaposlenima." << endl;
				}
			}
			catch (IzuzetakFile& e)
			{
				cerr << "Nastao je izuzetak pri otvaranju fajla o zaposlenima." << e.GetError() << endl;
			}
			while (fin >> id >> ime >> prezime >> plata >> temp) {
				if (id.find("L") != 0) {
					id = id.substr(1, id.length());
					medSestra.setId(stoi(id));
					medSestra.setIme(ime);
					medSestra.setPrezime(prezime);
					medSestra.setPlata(plata);
					medSestra.setSmena(stoi(temp));
					MS.push(medSestra);
				}

			}

			fin.close();
			out.open("medicinskeSestreBonusi.txt");
			while (!MS.empty()) {
				cout << MS.top() << endl;
				out << MS.top() << " Bonus: " << MS.top().dodajBonus() << endl;
				MS.pop();
			}
			out.close();
			break;

		case 5:
			try {
				fin.open("zaposleni.txt");
				if (!fin) {
					throw IzuzetakFile("FajlNePostojiException");
				}
				else {
					cout << "Uspesno otvorio fajl o zaposlenima." << endl;
				}
			}
			catch (IzuzetakFile& e)
			{
				cerr << "Nastao je izuzetak pri otvaranju fajla o zaposlenima." << e.GetError() << endl;
			}
			cout << "Unesite ID zaposlenog cije podatke zelite da procitate: " << endl;
			cin >> idKorisnik;
			while (fin >> id >> ime >> prezime >> plata >> temp) {
				if (id.find("L") != 0) {
					id = id.substr(1, id.length());
					medSestra.setId(stoi(id));
					medSestra.setIme(ime);
					medSestra.setPrezime(prezime);
					medSestra.setPlata(plata);
					medSestra.setSmena(stoi(temp));
					MS.push(medSestra);
				}
				else {
					id = id.substr(1, id.length());
					lekar.setId(stoi(id));
					lekar.setIme(ime);
					lekar.setPrezime(prezime);
					lekar.setPlata(plata);
					lekar.setFakultet(temp);
					LS.push(lekar);
				}

			}
			fin.close();

			while (!MS.empty()) {
				if (MS.top().getId() == idKorisnik) {
					find = 1;
					cout << MS.top() << endl;
				}
				MS.pop();
			}
			if (find == 0) {
				while (!LS.empty()) {
					if (LS.top().getId() == idKorisnik) {
						find = 1;
						cout << LS.top() << endl;
					}
					LS.pop();
				}
			}
			if (find == 0) {
				cout << "Nije pronadjen zaposleni sa ID-em = " << idKorisnik << endl;
			}
			break;
		case 6:
			return 0;
			break;
		default:
			cout << "los upis" << endl;
			break;
		}


	}
}
