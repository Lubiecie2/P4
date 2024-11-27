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
	return 0;
}