#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
	cout << "Macierz wyglada nastepujaco: " << endl;
	Matrix macierz(3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			macierz.wstaw(i, j, i + j);
			cout << macierz.pokaz(i, j) << " ";
		}
		cout << endl;
	}
	cout << "Wstawianie wartosci 5 na pozycje 1,1" << endl;
	macierz.wstaw(1, 1, 5);
	cout << "Macierz wyglada nastepujaco: " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << macierz.pokaz(i, j) << " ";
		}
		cout << endl;
	}
	cout << "Zmiana pierwszej kolumny: " << endl;
	int kolumna[] = { 7, 6, 7 };
	macierz.kolumna(0, kolumna);
	cout << "Macierz wyglada nastepujaco: " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << macierz.pokaz(i, j) << " ";
		}
		cout << endl;
	}
	cout << "Zmiana drugiego wiersza: " << endl;
	int wiersz[] = { 9, 0, 9 };
	macierz.wiersz(1, wiersz);	
	cout << "Macierz wyglada nastepujaco: " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << macierz.pokaz(i, j) << " ";
		}
		cout << endl;
	}
	cout << "Przekatna: " << endl;
	macierz.przekatna();
	cout << "Macierz wyglada nastepujaco: " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << macierz.pokaz(i, j) << " ";
		}
		cout << endl;
	}
	cout << "Pod przekatna: " << endl;
	macierz.pod_przekatna();
	cout << "Macierz wyglada nastepujaco: " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << macierz.pokaz(i, j) << " ";
		}
		cout << endl;
	}
	cout << "Nad przekatna: " << endl;
	macierz.nad_przekatna();
	cout << "Macierz wyglada nastepujaco: " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << macierz.pokaz(i, j) << " ";
		}
		cout << endl;
	}

	cout << "Losowe liczby: " << endl;
	macierz.losuj(3);

	cout << "Macierz wyglada następujaco: " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << macierz.pokaz(i, j) << " ";
		}
		cout << endl;
	}
	cout << "Powiekszenie macierzy o 1: " << endl;
	macierz.operator+=(1);
	cout << "Macierz wyglada nastepujaco: " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << macierz.pokaz(i, j) << " ";
		}
		cout << endl;
	}
	cout << "Pomniejszenie macierzy o 1: " << endl;
	macierz.operator-=(1);
	cout << "Macierz wyglada nastepujaco: " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << macierz.pokaz(i, j) << " ";
		}
		cout << endl;
	}
	cout << "Pomnozenie macierzy przez 2: " << endl;
	macierz.operator*=(2);
	cout << "Macierz wyglada nastepujaco: " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << macierz.pokaz(i, j) << " ";
		}
		cout << endl;
	}
	cout << "Powiekszenie macierzy o 1: " << endl;
	macierz.operator++(1);
	cout << "Macierz wyglada nastepujaco: " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << macierz.pokaz(i, j) << " ";
		}
		cout << endl;
	}
	cout << "Pomniejszenie macierzy o 1: " << endl;
	macierz.operator--(1);
	cout << "Macierz wyglada nastepujaco: " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << macierz.pokaz(i, j) << " ";
		}
		cout << endl;
	}
	cout << "Szachownica: " << endl;
	macierz.szachownica();
	cout << "Macierz wyglada nastepujaco: " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << macierz.pokaz(i, j) << " ";
		}
		cout << endl;
	}
	cout << "Dodawanie macierzy: " << endl;
	Matrix macierz2(3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			macierz2.wstaw(i, j, i + j);
			cout << macierz2.pokaz(i, j) << " ";
		}
		cout << endl;
	}
	macierz.operator+(macierz2);
	cout << "Macierz wyglada nastepujaco: " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << macierz.pokaz(i, j) << " ";
		}
		cout << endl;
	}
	cout << "Dodawanie liczby do macierzy: " << endl;
	macierz.operator+(5);
	cout << "Macierz wyglada nastepujaco: " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << macierz.pokaz(i, j) << " ";
		}
		cout << endl;
	}
	cout << "Mnozenie macierzy przez liczbe: " << endl;
	macierz.operator*(5);
	cout << "Macierz wyglada nastepujaco: " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << macierz.pokaz(i, j) << " ";
		}
		cout << endl;
	}
	cout << "Odejmowanie liczby od macierzy: " << endl;
	macierz.operator-(5);
	cout << "Macierz wyglada nastepujaco: " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << macierz.pokaz(i, j) << " ";
		}
		cout << endl;
	}
	cout << "Diagonalna: " << endl;
	int diagonalna[] = { 1, 2, 3 };
	macierz.diagonalna(diagonalna);
	cout << "Macierz wyglada nastepujaco: " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << macierz.pokaz(i, j) << " ";
		}
		cout << endl;
	}
	cout << "Diagonalna k: " << endl;
	int diagonalna_k[] = { 1, 2, 3 };
	macierz.diagonalna_k(1, diagonalna_k);
	cout << "Macierz wyglada nastepujaco: " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << macierz.pokaz(i, j) << " ";
		}
		cout << endl;
	}
	Matrix m_plus = macierz + 5;
	cout << "Macierz po dodaniu 5 wyglada nastepujaco: " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << m_plus.pokaz(i, j) << " ";
		}
		cout << endl;
	}
	Matrix m_minus = macierz - 5;
	cout << "Macierz po odjeciu wyglada nastepujaco: " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << m_minus.pokaz(i, j) << " ";
		}
		cout << endl;
	}
	Matrix m_razy = 5 * macierz;
	cout << "Macierz po pomnozeniu razy 5 wyglada nastepujaco: " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << m_razy.pokaz(i, j) << " ";
		}
		cout << endl;
	}
	return 0;
}