// 3 modificatoi :
// 1. Private : Datele sunt accesibile in aceeasi clasa
// 2. Public : Datele sunt accesibile in aceeasi clasa in clasele derivate si in exterior
// 3. Protected : Datele sunt accesibile in aceeasi clasa si in clasele derivate

#include <iostream>
#include <string>
using namespace std;

class Persoana {
protected:
	string nume;
	int varsta;

public:
	//constructor
	Persoana(string nume, int varsta) {
		this->nume = nume;
		this->varsta = varsta;

	}
	//metoda de afisare
	void afisare_detalii(){
		cout << "Nume: " << nume << ", Varsta: " << varsta << endl;
	}
};

//cream o clasa derivata, mostenita din clasa Persoana
class Student : public Persoana {
private:
	float medie;
public:
	Student(string nume, int varsta, float medie) :Persoana(nume,varsta) {
		this->medie = medie;

	}
	//Suprascrierea metodei de afisare:
	void afisare_inf(){
		cout << "Nume: " << nume << ", Varsta: " << varsta << ", Medie: " << medie << endl;
	}
	float getMedie() {
		return medie;
	}
};

int main() {
	//Cream un obiect de tip Student
	Student s("Ion", 21, 10);
	s.afisare_inf();

	/*
	Cititi de la tastatura un numar (n)
*/
	int n;
	cout << "Introduceti un numar de studenti: " << endl;
	cin >> n;

	Student** studenti = new Student * [n];
	for (int i = 0; i < n; i++) {
		string nume;
		int varsta;
		float medie;

		cout << "Introduceti numele: " << i + 1 << endl;
		cin >> nume;
		cout << "Introduceti varsta: " << i + 1 << endl;
		cin >> varsta;
		cout << "Introduceti media: " << i + 1 << endl;
		cin >> medie;

		studenti[i] = new Student(nume, varsta, medie);
	}

	cout << "Studentii introdusi sunt: " << endl;
	for (int i = 0; i < n; i++) {
		studenti[i]->afisare_inf();
	}

	//Media medilor
	float medie_t = 0;
	for (int i = 0;i < n;i++) {
		medie_t += studenti[i]->getMedie();
	}
	medie_t /= n;
	cout << "Media totala a studentilor este: " << medie_t;
}
//sa se scrie un program in c++ pt gestiunea unei gradini zoologice ,folosing clase ,obiecte,mostenire
//ex. pasari: lungime aripilor ,durata de viata
//caini: rasa ,tip de caine(vanatoare ,ajutor,etc.)

