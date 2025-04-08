#include <iostream>
#include <string>
using namespace std;

/*
	Clasa pricipala: MAGAZIN
		- din aceasta vom face mostenire
*/
class magazin {
protected:
	string produs;
	float pret_kg;
	float pret_buc;
	float cantitate;
public:
	//Constructor pentru magazin
	magazin(string produs, float pret_kg, float pret_buc, float cantitate) {
		this->produs = produs;
		this->pret_kg = pret_kg;
		this->pret_buc = pret_buc;
		this->cantitate = cantitate;
	}
	//Destructor
	~magazin(){}
	//Clasa prieten
	friend class afisare;
};

/*
	Clasa derivata: APROVIZIONARE
		- in aceasta vom folosi elemente di clasa principala
*/
class aprovizionare : public magazin {
private:
	float total;
public:
	//Constructor pentru aprovizionare
	aprovizionare(string produs, float pret_kg, float pret_buc, float cantitate) : magazin(produs, pret_kg, pret_buc, cantitate), total(){}

	//Cream o functie petru totalul de produse pe care le avem
	float totalul() {
		total = (pret_kg + pret_buc) * cantitate;
		return total;
	}
};

/*
	Clasa prieten: AFISARE
		- foloseste variabilele din clasa principala fara sa le scriem din nou
*/
class afisare {
public:
	void afisare_aprov(const magazin& a) {
		float total = (a.pret_kg + a.pret_buc) * a.cantitate;
		cout << "---------------------------------------------------------------------------------" << endl;
		cout << "Produs: " << a.produs << ", Pret pe Kilogram: " << a.pret_kg << ", Pret pe Bucata: " << a.pret_buc << ", Cantitate: " << a.cantitate << endl;
		cout << "Pretul total pentru acesta cantitate de produs este: " << total << " lei" << endl;
		cout << "---------------------------------------------------------------------------------" << endl;
	}
};

//Cream o functie pentru o introducere
void instructiuni() {
	cout << "Bine ati venit la magazin!\n";
	cout << "Va rugam sa aprovizioati magazinul!\n";
	cout << "----------------------------------------" << endl << endl;
}

int main() {
	//Afisare simpla
	aprovizionare mere("Mere", 4.5, 0, 10);
	afisare gestiune;
	gestiune.afisare_aprov(mere);

	//Afisare complexa
	instructiuni();
	int n;//Ajuta la introducerea de produse in gestiune
	cout << "Introduceti nu numar de produse la magazin: ";
	cin >> n;

	
	aprovizionare** Aprovizionare = new aprovizionare * [n];
	for (int i = 0; i < n; i++) {
		string produs;
		float pret_kg;
		float pret_buc;
		float cantitate;

		cout << "Introduceti produsul: " << i + 1 << endl;
		cin >> produs;
		cout << "Introduceti pretul pe kilogram: " << i + 1 << endl;
		cin >> pret_kg;
		cout << "Introduceti pretul pe bucata: " << i + 1 << endl;
		cin >> pret_buc;
		cout << "Introduceti cantitatea: " << i + 1 << endl;
		cin >> cantitate;
		
		Aprovizionare[i] = new aprovizionare(produs, pret_kg, pret_buc, cantitate);
	}
	cout << endl;
	cout << "----------------------------------------" << endl;
	cout << "Produsele introduse sunt: " << endl;
	for (int i = 0;i < n;i++) {
		gestiune.afisare_aprov(*Aprovizionare[i]);
	}

	//Ia pretul de la fiecare produs introdus si il calculeaza
	float total_prod = 0;
	for (int i = 0; i < n; i++) {
		total_prod += Aprovizionare[i]->totalul();
	}
	cout << "================================================================" << endl;
	cout << "Pretul tuturor produselor din gestiunea magazinului este: " << total_prod << " lei" << endl;
	cout << "================================================================" << endl;

	return 0;
}