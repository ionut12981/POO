/*
	Sa se scrie un program in c++ pt gestiunea unei gradini zoologice ,folosind clase ,obiecte,mostenire
		-ex. pasari: lungime aripilor ,durata de viata
		-ex. caini: rasa ,tip de caine(vanatoare ,ajutor,etc.)
*/

#include <iostream>
#include <string>
using namespace std;

/*
	1.Clasa principala
		-din aceasta vom face mostenire
*/
class animal {
protected:
	string nume; //Nume animal
	int varsta; //Varsta animal
	string mancare; //Tipul de mancare
	float kg; //Kilograme animal
	string culoare; //Culoare animal
public:
	animal(string nume, int varsta, string mancare, float kg, string culoare) : nume(nume), varsta(varsta), mancare(mancare), kg(kg), culoare(culoare) {}
	void inf_animal() {
		cout << "Animal: " << nume << endl << "Varsta: " << varsta << endl << "Mancare: " << mancare << endl << "Kilograme: " << kg << endl << "Culoare: " << culoare << endl;
	}
};

/*
	2.Clasa derivata: MAMIFER
		-totalitatea mamiferelor din ZOO
*/
class mamifer : public animal {
protected:
	string tip_alimentar; //Ierbivor, Carnivor, Omnivor
public:
	mamifer(string nume, int varsta, string mancare, float kg, string culoare, string tip_alimentar) : animal(nume, varsta, mancare, kg, culoare), tip_alimentar(tip_alimentar){}
	void inf_mamifer() {
		cout << "Animal: " << nume << endl << "Varsta: " << varsta << endl << "Mancare: " << mancare << endl << "Kilograme: " << kg << endl << "Tip alimentar: " << tip_alimentar << endl << "Culoare: " << culoare << endl << endl;
	}
};

/*
	3.Clasa derivata: FAUNA MARINA
		-totalitatea vietuitoarelor marine din ZOO
*/
class fauna_marina : public animal {
protected:
	string tip_animal; //Crustaceu, Molusca, etc.
public:
	fauna_marina(string nume, int varsta, string mancare, float kg, string culoare, string tip_animal) : animal(nume, varsta, mancare, kg, culoare), tip_animal(tip_animal) {}
	void inf_fauna_marina() {
		cout << "Animal: " << nume << endl << "Varsta: " << varsta << endl << "Mancare: " << mancare << endl << "Kilograme: " << kg << endl << "Tip de animal: " << tip_animal << endl << "Culoare: " << culoare << endl << endl;
	}
};

/*
	4.Clasa derivata: PASARE
		-totalitatea pasarilor din ZOO
*/
class pasare : public animal {
protected:
	float lungime_aripi; //Lungimea aripilor
public:
	pasare(string nume, int varsta, string mancare, float kg, string culoare, float lungime_aripi) : animal(nume, varsta, mancare, kg, culoare), lungime_aripi(lungime_aripi) {}
	void inf_pasare() {
		cout << "Animal: " << nume << endl << "Varsta: " << varsta << endl << "Mancare: " << mancare << endl << "Kilograme: " << kg << endl << "Lungime aripi: " << lungime_aripi << endl << "Culoare: " << culoare << endl << endl;
	}
};

void instructiuni() {
	cout << "Alege de la 1-3 tipul de animal pe care il ai la ZOO: \n";
	cout << "     (1) Mamifer\n";
	cout << "     (2) Fauna marina\n";
	cout << "     (3) Pasare\n";
}

int main() {
	//Exemple de animale cu informatii specifice
	mamifer leu("Leu", 4, "Carne", 175.5, "Portocaliu", "Carnivor");
	fauna_marina rac("Rac", 2, "Carne", 0.15, "Maro", "Crustaceu");
	pasare papagal("Papagal", 3, "Seminte", 0.45, "Multicolor", 0.95);

	//Afisare simpla
	leu.inf_mamifer();
	rac.inf_fauna_marina();
	papagal.inf_pasare();

	//Afisare complexa
	int optiune; //Ajuta la alegerea tipului de animal pe care il vrei
	instructiuni();
	cin >> optiune;

	int n; //Ajuta la introducerea unui numar de animale
	cout << "Introduceti un numar de animale: ";
	cin >> n;
	
	//Optiunea 1 reprezinta mamiferele
	if (optiune == 1) {
		mamifer** mamiferi = new mamifer * [n];
		for (int i = 0; i < n; i++) {
			string nume;
			int varsta;
			string mancare;
			float kg;
			string culoare;
			string tip_alimentar;

			cout << "Introduceti numele: " << i + 1 << endl;
			cin >> nume;
			cout << "Introduceti varsta: " << i + 1 << endl;
			cin >> varsta;
			cout << "Introduceti mancarea: " << i + 1 << endl;
			cin >> mancare;
			cout << "Introduceti kilogramele: " << i + 1 << endl;
			cin >> kg;
			cout << "Introduceti culoarea: " << i + 1 << endl;
			cin >> culoare;
			cout << "Introduceti tipul alimentar: " << i + 1 << endl;
			cin >> tip_alimentar;
			cout << endl;

			mamiferi[i] = new mamifer(nume, varsta, mancare, kg, culoare, tip_alimentar);
		}

		cout << "Animalele introduse sunt: ";
		for (int i = 0; i < n; i++) {
			mamiferi[i]->inf_mamifer();
		}
	}

	//Optiunea 2 reprezinta fauna marina
	else if (optiune == 2) {
		fauna_marina** faune_marine = new fauna_marina * [n];
		for (int i = 0; i < n; i++) {
			string nume;
			int varsta;
			string mancare;
			float kg;
			string culoare;
			string tip_animal;

			cout << "Introduceti numele: " << i + 1 << endl;
			cin >> nume;
			cout << "Introduceti varsta: " << i + 1 << endl;
			cin >> varsta;
			cout << "Introduceti mancarea: " << i + 1 << endl;
			cin >> mancare;
			cout << "Introduceti kilogramele: " << i + 1 << endl;
			cin >> kg;
			cout << "Introduceti culoarea: " << i + 1 << endl;
			cin >> culoare;
			cout << "Introduceti tipul de animal: " << i + 1 << endl;
			cin >> tip_animal;
			cout << endl;

			faune_marine[i] = new fauna_marina(nume, varsta, mancare, kg, culoare, tip_animal);
		}

		cout << "Animalele introduse sunt: " << endl;
		for (int i = 0; i < n; i++) {
			faune_marine[i]->inf_fauna_marina();
		}
	}

	//Optiunea 3 reprezinta pasarile
	else if (optiune == 3) {
		pasare** pasari = new pasare * [n];
		for (int i = 0; i < n; i++) {
			string nume;
			int varsta;
			string mancare;
			float kg;
			string culoare;
			float lungime_aripi;

			cout << "Introduceti numele: " << i + 1 << endl;
			cin >> nume;
			cout << "Introduceti varsta: " << i + 1 << endl;
			cin >> varsta;
			cout << "Introduceti mancarea: " << i + 1 << endl;
			cin >> mancare;
			cout << "Introduceti kilogramele: " << i + 1 << endl;
			cin >> kg;
			cout << "Introduceti culoarea: " << i + 1 << endl;
			cin >> culoare;
			cout << "Introduceti lungimea aripilor: " << i + 1 << endl;
			cin >> lungime_aripi;
			cout << endl;

			pasari[i] = new pasare(nume, varsta, mancare, kg, culoare, lungime_aripi);
		}

		cout << "Animalele introduse sunt: " << endl;
		for (int i = 0; i < n; i++) {
			pasari[i]->inf_pasare();
		}
	}

	return 0;
}