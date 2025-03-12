
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
	string nume;
	int varsta;
	float medie;

public:

	Student(string nume_student, int varsta_student, float medie_student) {
		nume = nume_student;
		varsta = varsta_student;
		medie = medie_student;
		cout << "Constructorul a fost apelat pentru: " << nume << endl;
	}

	/* Student(string nume_student, int varsta_student, float medie_student) {
		this->nume = nume_student;
		this->varsta = varsta_student;
		this->medie = medie_student;
		cout << "Constructorul a fost apelat pentru: " << nume << endl;
	} */
	~Student() {
		cout << "Constructorul a fost apelat pentru: " << nume << endl;
	}

	void afisare_informatii() {
		cout << "NUME" << nume << ",VARSTA" << varsta << ",MEDIE" << medie;
	}
	float returneaza_medie() const {
		return medie;
	}
};

void sortare_dupa_medie(Student** studenti, int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = 0;j < n - i - 1;j++) {
			if (studenti[j] ->returneaza_medie() > studenti[j + 1]->returneaza_medie())
			{
				Student* aux = studenti[j];
				studenti[j] = studenti[j + 1];
				studenti[j + 1] = aux;
			}
		}
}

int main() {
	int i, k;
	int n = 0;
	cout << "Introduceti nr ed studenti: "; cin >> n;
	Student** studenti = new Student * [n];
	
	for (i = 0; i < n; i++)
	
	for (i = 0;i < n;i++) {

		string nume;
		int varsta;
		float medie;
		cout << "Introduceti numele studentului: " << i + 1 << ": "; cin >> nume;
		cout << "Introduceti varsta studentului: " << i + 1 << ": "; cin >> varsta;
		cout << "Introduceti media studentului: " << i + 1 << ": "; cin >> medie;

		studenti[i] = new Student(nume, varsta, medie);
	}

	for (i = 0;i < n; i++) {
		studenti[i]->afisare_informatii();
	}

	for (i = 0;i < n;i++) {
		delete studenti[i];
	}
	return 0;
}


