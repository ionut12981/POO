#include <iostream>
#include <string>
using namespace std;

/*
	1.Clasa principala
		-din aceasta vom face mostenire
*/
class parcare {
protected:
	string inmatriculare;//Numar de inmatriculare
	int durata;//Durata masinii in parcare
	float tarif;//Tariful pe ora
	string marca;//Marca masinii
	string model;//Modelul masinii
	string motor;//Hibrid/Electri/Carburant
	float incarcare;//Doar pentru hibrid/electric in cazul daca se vrea 
public:
	parcare(string inmatriculare, int durata, float tarif, string marca, string model, string motor, float incarcare) : inmatriculare(inmatriculare), durata(durata), tarif(tarif), marca(marca), model(model), motor(motor), incarcare(incarcare) {}
	void inf_masina() {
		cout << "Marca: " << marca << ", Durata: " << durata << ", Nr. de inmatriculare: " << inmatriculare << ", Tarif: " << tarif << ", Motor: " << motor << ", Tarif pe incarcare: " << incarcare << ", Model: " << model << endl;
	}

};

/*
	2.Clasa derivata: STANDARD
*/
class standard : public parcare {
private:
	float plata;//Plata parcarii
public:
	standard(string inmatriculare, int durata, float tarif, string marca, string model, string motor, float incarcare) : parcare(inmatriculare, durata, tarif, marca, model, motor, incarcare),plata() {}
	void inf_standard() {
		plata = (tarif + incarcare) * durata;
		cout << "Marca: " << marca << ", Durata: " << durata << ", Nr. de inmatriculare: " << inmatriculare << ", Tarif: " << tarif << ", Motor: " << motor << ", Tarif pe incarcare: " << incarcare << ", Model: " << model << endl;
		cout << "Aveti de platit: " << plata << endl << endl;
	}
};

/*
	2.Clasa derivata: DIZABILITATE
		persoanele cu dizabilitate
*/
class dizabilitate : public parcare {
private:
	float plata;
public:
	dizabilitate(string inmatriculare, int durata, float tarif, string marca, string model, string motor, float incarcare) : parcare(inmatriculare, durata, tarif, marca, model, motor, incarcare),plata(0) {}
	void inf_dizabilitate() {
		plata = (tarif + incarcare) * durata;
		cout << "Tariful la oamneii cu dizabilitati este jumatate din cel standard.";
		cout << "Marca: " << marca << ", Durata: " << durata << ", Nr. de inmatriculare: " << inmatriculare << ", Tarif: " << tarif << ", Motor: " << motor << ", Tarif pe incarcare: " << incarcare << ", Model: " << model << endl;
		cout << "Aveti de platit: " << plata << endl << endl;
	}
};

void instructiuni() {
	cout << "Alege de la 1 pentru o masina standard si 2 pentru persoanele cu dizabilitati: \n";
	cout << "     (1) Standard\n";
	cout << "     (2) Persoane cu dizabilitati\n";
}

int main() {
	
	//2 exemple de masini cu informatii specifice
	standard Audi("BC123INF", 4,5,"Audi ","A4", "Termic", 0);
	dizabilitate Tesla("BC26PCS", 3, 2.5, "Tesla", "ModelS", "Electric", 1);
	//Afisare simpla
	Audi.inf_standard();
	Tesla.inf_dizabilitate();

	//Afisare complexa
	int optiune;
	instructiuni();
	cin >> optiune;

	int n; //Ajuta la introducerea unui numar de masini
	cout << "Introduceti un numar de masini: ";
	cin >> n;

	//Optiunea 1 masinile standard
	if (optiune == 1) {
		standard** Standard = new standard * [n];
		for (int i = 0;i < n;i++) {
			string inmatriculare;
			int durata;
			float tarif;
			string marca;
			string model;
			string motor;
			float incarcare;
			float depasire;

			cout << "Introduceti marca: " << i + 1 << endl;
			cin >> marca;
			cout << "Introduceti numarul de inmatriculare: " << i + 1 << endl;
			cin >> inmatriculare;
			cout << "Introduceti modelul: " << i + 1 << endl;
			cin >> model;
			cout << "Introduceti tipul de motorizare: " << i + 1 << endl;
			cin >> motor;
			cout << "Introduceti durata: " << i + 1 << endl;
			cin >> durata;
			cout << "Introduceti tariful: " << i + 1 << endl;
			cin >> tarif;
			cout << "Introduceti, daca este cazul, tariful de incarcare: " << i + 1 << endl;
			cin >> incarcare;
			cout << "Introduceti durata de stationare a masinii: " << i + 1 << endl;
			cin >> depasire;
			cout << endl;

			if (depasire > durata) {
				cout << "Ati depasit intervalul de timp!" << endl;
			}
			else
			{
				cout << "Bravo! Te afli in intervalul stabilit!" << endl;
			}

			Standard[i] = new standard(inmatriculare, durata, tarif, marca, model, motor, incarcare);
		}
		cout << endl;
		cout << "Masinile introduse sunt: " << endl;
		for (int i = 0; i < n; i++) {
			Standard[i]->inf_standard();
		}
	}

	//Optiunea 2 reprezinta persoanele cu dizabilitati
	if (optiune == 2) {
		dizabilitate** Dizabilitate = new dizabilitate * [n];
		for (int i = 0;i < n;i++) {
			string inmatriculare;
			int durata;
			float tarif;
			string marca;
			string model;
			string motor;
			float incarcare;
			float depasire;

			cout << "Tariful la oamneii cu dizabilitati este jumatate din cel standard." << endl;
			cout << "Introduceti marca: " << i + 1 << endl;
			cin >> marca;
			cout << "Introduceti numarul de inmatriculare: " << i + 1 << endl;
			cin >> inmatriculare;
			cout << "Introduceti modelul: " << i + 1 << endl;
			cin >> model;
			cout << "Introduceti tipul de motorizare: " << i + 1 << endl;
			cin >> motor;
			cout << "Introduceti durata: " << i + 1 << endl;
			cin >> durata;
			cout << "Introduceti tariful: " << i + 1 << endl;
			cin >> tarif;
			cout << "Introduceti, daca este cazul, tariful de incarcare: " << i + 1 << endl;
			cin >> incarcare;
			cout << "Introduceti durata de stationare a masinii: " << i + 1 << endl;
			cin >> depasire;
			cout << endl;

			if (depasire > durata) {
				cout << "Ati depasit intervalul de timp!" << endl;
			}
			else
			{
				cout << "Bravo! Te afli in intervalul stabilit!" << endl;
			}

			Dizabilitate[i] = new dizabilitate(inmatriculare, durata, tarif, marca, model, motor, incarcare);
		}
		cout << endl;
		cout << "Masinile introduse sunt: " << endl;
		for (int i = 0; i < n; i++) {
			Dizabilitate[i]->inf_dizabilitate();
		}
	}

	//Ultima optiune reprezinta un numar care nu este specificat in instructiuni
	if (optiune > 2) {
		cout << "Invalid!\n" << endl;;
		main();
	}

	return 0;
}