#include "Matrix.h"  // <--- Plik naglowkowy klasy Matrix
#include <iostream> // <--- Biblioteka zawierajaca funkcje cout i cin
#include <ctime> // <--- Biblioteka zawierajaca funkcje time()
#include <cstdlib> // <--- Biblioteka zawierajaca funkcje srand() i rand()
#include <fstream> // <--- Biblioteka zawierajaca funkcje do obslugi plikow
#include <string> // <--- Biblioteka zawierajaca funkcje do obslugi napisow

// Konstruktory
Matrix::Matrix() : wsm(nullptr), rozmiar(0) {}     // <--- Konstruktor domyslny 

Matrix::Matrix(int n) : wsm(nullptr), rozmiar(0) {     // <--- Konstruktor alokujacy pamiec.
    if (n > 0) {  
		rozmiar = n; // <--- Przypisanie rozmiaru macierzy
		wsm = new int* [rozmiar];  // <--- Alokacja pamieci dla wierszy
		for (int i = 0; i < rozmiar; ++i) {  // <--- Petla alokujaca pamiec dla kolumn
			wsm[i] = new int[rozmiar]; // <--- Alokacja pamieci dla kolumn
			for (int j = 0; j < rozmiar; ++j) { // <--- Petla zerujaca wartosci macierzy
				wsm[i][j] = 0; // <--- Zerowanie wartosci macierzy
            }
        }
    }
}

Matrix::Matrix(int n, int* t) : wsm(nullptr), rozmiar(0) {  // <--- Konstruktor alokujacy pamiec i inicjalizujacy wartosci
    if (n > 0) {                     
		rozmiar = n;  // <--- Przypisanie rozmiaru macierzy
		wsm = new int* [rozmiar];  // <--- Alokacja pamieci dla wierszy
		for (int i = 0; i < rozmiar; ++i) { // <--- Petla alokujaca pamiec dla kolumn
			wsm[i] = new int[rozmiar];  // <--- Alokacja pamieci dla kolumn
			for (int j = 0; j < rozmiar; ++j) {  // <--- Petla wstawiajaca wartosci do macierzy
				wsm[i][j] = t[i * rozmiar + j];  // <--- Wstawianie wartosci do macierzy
            }
        }
    }
}

Matrix::Matrix(const Matrix& m) : wsm(nullptr), rozmiar(0) {  // <--- Konstruktor kopiujacy 
	if (m.rozmiar > 0) {  // <--- Sprawdzenie czy macierz ma rozmiar wiekszy od 0
		rozmiar = m.rozmiar;  // <--- Przypisanie rozmiaru macierzy 
		wsm = new int* [rozmiar];  // <--- Alokacja pamieci dla wierszy 
		for (int i = 0; i < rozmiar; ++i) {  // <--- Petla alokujaca pamiec dla kolumn 
			wsm[i] = new int[rozmiar];  // <--- Alokacja pamieci dla kolumn 
			for (int j = 0; j < rozmiar; ++j) {  // <--- Petla wstawiajaca wartosci do macierzy 
				wsm[i][j] = m.wsm[i][j]; // <--- Wstawianie wartosci do macierzy
            }
        }
    }
}

// Destruktor

Matrix::~Matrix() {
	if (wsm) {  // <--- Sprawdzenie czy macierz ma zaalokowana pamiec
		for (int i = 0; i < rozmiar; ++i) {  // <--- Petla zwalniajaca pamiec
			delete[] wsm[i]; // <--- Zwalnianie pamieci
        }
		delete[] wsm; // <--- Zwalnianie pamieci
		wsm = nullptr;  // <--- Ustawianie wskaznika na nullptr
		rozmiar = 0; // <--- Zerowanie rozmiaru
    }
}   

// Zarzadzanie pamiecia macierzy

Matrix& Matrix::Macierz_Alokacja(int n) {
    
    if (wsm) {               // <--- instrukcja sprawdza czy macierz ma juz zaalokowana pamiec 
        if (rozmiar != n) {    // <--- instrukcja sprawdza czy nowy rozmiar jest inny niz poprzedni
            
            for (int i = 0; i < rozmiar; ++i) {   // <--- Jesli rozmiar jest inny niz porzedni to petla 
                delete[] wsm[i];                  //      zwalnia pamiec 
            }
            delete[] wsm;
            wsm = nullptr;  // <--- Ustawiany jest wskaznik na nullptr
            rozmiar = 0;    // <--- Zerowanie rozmiaru
        }
    }

    if (rozmiar != n) {             // <--- Instrukcja alokuje pamiec w nowym rozmiarze jesli nie ma zaalokowanej
        rozmiar = n;                //      lub po zwolnieniu starej
        wsm = new int* [rozmiar];
        for (int i = 0; i < rozmiar; ++i) {
            wsm[i] = new int[rozmiar];
        }
    }

    return *this;  // <--- Zwracana jest referencja do obiektu 
}

// Operacje na elementach macierzy

Matrix& Matrix::wstaw(int x, int y, int wartosc) { 
	if (x >= 0 && x < rozmiar && y >= 0 && y < rozmiar) {  // <--- Sprawdzanie czy wspolrzedne sa w zakresie
		wsm[x][y] = wartosc;  // <--- Wstawianie wartosci do macierzy
	}
	return *this;  // <--- Zwracana jest referencja do obiektu
}

int Matrix::pokaz(int x, int y) {  
	if (x >= 0 && x < rozmiar && y >= 0 && y < rozmiar) {  // <--- Sprawdzanie czy wspolrzedne sa w zakresie
		return wsm[x][y];  // <--- Zwracanie wartosci z macierzy 
	}
	return 0;
}

Matrix& Matrix::Macierz_Odwroc() {
    for (int i = 0; i < rozmiar; ++i) {          // <--- Petla do wierszy
        for (int j = i + 1; j < rozmiar; ++j) {  // <--- Petla do kolumn 
            std::swap(wsm[i][j], wsm[j][i]);  // <--- Zamiana elementow w macierzy 
        }
    }
    return *this;  // <--- Zwracana jest referencja do obiektu 
}


Matrix& Matrix::losuj() {
    
    for (int i = 0; i < rozmiar; ++i) {
        for (int j = 0; j < rozmiar; ++j) {
            wsm[i][j] = std::rand() % 10;  // <--- Losujemy liczby z zakresu 0-9
        }
    }
    return *this;  
}

Matrix& Matrix::losuj(int x) {
	if (rozmiar > 0 && x > 0 && x <= rozmiar * rozmiar) {  // <--- Sprawdzanie czy macierz ma rozmiar wiekszy od 0
		std::srand(std::time(nullptr)); // <--- Ustawienie ziarna generatora liczb pseudolosowych

		int liczbaWype³nionych = 0; // <--- Zmienna przechowujaca liczbe wypelnionych komorek
		while (liczbaWype³nionych < x) { // <--- Petla losujaca wartosci do macierzy

			int LosowyWiersz = std::rand() % rozmiar; // <--- Losowanie wiersza
			int LosowaKolumna = std::rand() % rozmiar; // <--- Losowanie kolumny 


			if (wsm[LosowyWiersz][LosowaKolumna] == 0) { // <--- Sprawdzanie czy komorka jest pusta
				wsm[LosowyWiersz][LosowaKolumna] = std::rand() % 10; // <--- Losowanie wartosci do komorki
				liczbaWype³nionych++;  // <--- Inkrementacja liczby wypelnionych komorek
			}
		}
	}
	return *this;
}



Matrix& Matrix::diagonalna(int* t) {
	if (rozmiar > 0) {  // <--- Sprawdzanie czy macierz ma rozmiar wiekszy od 0
		for (int i = 0; i < rozmiar; ++i) {  // <--- Petla wstawiajaca wartosci na przekatnej
			for (int j = 0; j < rozmiar; ++j) {  // <--- Petla zerujaca wartosci macierzy
				wsm[i][j] = (i == j) ? t[i] : 0;  // <--- Wstawianie wartosci na przekatnej
			}
		}
	}
	return *this;  // <--- Zwracana jest referencja do obiektu 
}

Matrix& Matrix::diagonalna_k(int k, int* t) {  // <--- Wstawianie wartosci na przekatnej
	for (int i = 0; i < rozmiar; ++i) {  // <--- Petla zerujaca wartosci macierzy
		for (int j = 0; j < rozmiar; ++j) {  // <--- Petla zerujaca wartosci macierzy
			wsm[i][j] = 0;  // <--- Zerowanie wartosci macierzy
		}
	}
	for (int i = 0; i < rozmiar; ++i) {  // <--- Petla wstawiajaca wartosci na przekatnej
		int wiersz = i - k;  // <--- Wiersz na przekatnej
		if (wiersz >= 0 && wiersz < rozmiar) {  // <--- Sprawdzanie czy wiersz jest w zakresie
			wsm[wiersz][i] = t[i];  // <--- Wstawianie wartosci na przekatnej
		}
	}
	return *this;  // <--- Zwracana jest referencja do obiektu
}

Matrix& Matrix::kolumna(int x, int* t) { 
	if (x >= 0 && x < rozmiar) { // <--- Sprawdzanie czy wspolrzedne sa w zakresie
		for (int i = 0; i < rozmiar; ++i) { // <--- Petla wstawiajaca wartosci do kolumny
			wsm[i][x] = t[i];  // <--- Wstawianie wartoœci do kolumny 
		}
	}
	return *this;  // <--- Zwracana jest referencja do obiektu 
}

Matrix& Matrix::wiersz(int y, int* t) {
	if (y >= 0 && y < rozmiar) { // <--- Sprawdzanie czy wspolrzedne sa w zakresie
		for (int i = 0; i < rozmiar; ++i) { // <--- Petla wstawiajaca wartosci do wiersza
			wsm[y][i] = t[i];  // <--- Wstawianie wartoœci do wiersza 
		}
	}
	return *this;  // <--- Zwracana jest referencja do obiektu 
}

Matrix& Matrix::przekatna(void) {
	for (int i = 0; i < rozmiar; ++i) { 
        for (int j = 0; j < rozmiar; ++j) {
			wsm[i][j] = (i == j) ? 1 : 0;  // <--- Wstawianie wartosci na przekatnej
        }
    }
	return *this;  
}

Matrix& Matrix::pod_przekatna(void) {
    for (int i = 0; i < rozmiar; ++i) {
        for (int j = 0; j < rozmiar; ++j) {
            wsm[i][j] = (i > j) ? 1 : 0;  // <--- Wstawianie wartosci pod przekatna
        }
    }
	return *this;  
}

Matrix& Matrix::nad_przekatna(void) {
	for (int i = 0; i < rozmiar; ++i) {
		for (int j = 0; j < rozmiar; ++j) {
			wsm[i][j] = (i < j) ? 1 : 0;  // <--- Wstawianie wartosci nad przekatna
		}
	}
	return *this;  // <--- Zwracana jest referencja do obiektu
}

Matrix& Matrix::szachownica(void) {
	for (int i = 0; i < rozmiar; ++i) {
		for (int j = 0; j < rozmiar; ++j) { 
			wsm[i][j] = (i + j) % 2;  // <--- Wstawianie wartosci do macierzy 
		}
	}
	return *this;  
}

// Operacje matematyczne na macierzy

Matrix& Matrix::operator+(Matrix& m) {
	if (rozmiar == m.rozmiar) { // <--- Sprawdzanie czy rozmiary macierzy sa takie same
		for (int i = 0; i < rozmiar; ++i) { 
			for (int j = 0; j < rozmiar; ++j) {
				wsm[i][j] += m.wsm[i][j];  // <--- Dodawanie macierzy 
			}
		}
	}
	return *this;  
}

Matrix& Matrix::operator*(Matrix& m) {

	if (rozmiar == m.rozmiar) { // <--- Sprawdzanie czy rozmiary macierzy sa takie same
		Matrix temp(rozmiar); // <--- Tworzenie tymczasowej macierzy 
		for (int i = 0; i < rozmiar; ++i) {  
			for (int j = 0; j < rozmiar; ++j) {
				for (int k = 0; k < rozmiar; ++k) {
					temp.wsm[i][j] += wsm[i][k] * m.wsm[k][j];  // <--- Mnozenie macierzy 
				}
			}
		}
		*this = temp;  // <--- Przypisanie wartosci do macierzy
	}
	return *this; 
}

Matrix& Matrix::operator+(int a) { 
	for (int i = 0; i < rozmiar; ++i) {
		for (int j = 0; j < rozmiar; ++j) {
			wsm[i][j] += a;  // <--- Dodawanie wartosci do macierzy 
		}
	}
	return *this;  
}

Matrix& Matrix::operator*(int a) {
	
	
	for (int i = 0; i < rozmiar; ++i) {
		for (int j = 0; j < rozmiar; ++j) {
			wsm[i][j] *= a;  // <--- Mnozenie wartosci macierzy 
		}
	}
	return *this;   
}

Matrix& Matrix::operator-(int a) {
	for (int i = 0; i < rozmiar; ++i) {
		for (int j = 0; j < rozmiar; ++j) {
			wsm[i][j] -= a;  // <--- Odejmowanie wartosci od macierzy 
		}
	}
	return *this;  
}

Matrix operator+(int a, Matrix& m) {
	Matrix wynik(m.rozmiar); // <--- Tworzenie nowej macierzy
	for (int i = 0; i < m.rozmiar; ++i) {
		for (int j = 0; j < m.rozmiar; ++j) {
			wynik.wsm[i][j] = a + m.wsm[i][j];  // <--- Dodawanie wartosci do macierzy 
		}
	}
	return wynik;  
}

Matrix operator*(int a, Matrix& m) {
	Matrix wynik(m.rozmiar); // <--- Tworzenie nowej macierzy
	for (int i = 0; i < m.rozmiar; ++i) {
		for (int j = 0; j < m.rozmiar; ++j) {
			wynik.wsm[i][j] = a * m.wsm[i][j];  // <--- Mnozenie wartosci macierzy 
		}
	}
	return wynik;  
}

Matrix operator-(int a, Matrix& m) {
	Matrix wynik(m.rozmiar); // <--- Tworzenie nowej macierzy
	for (int i = 0; i < m.rozmiar; ++i) {
		for (int j = 0; j < m.rozmiar; ++j) {
			wynik.wsm[i][j] = a - m.wsm[i][j];  // <--- Odejmowanie wartosci od macierzy 
		}
	}
	return wynik;  // <--- Zwracana jest referencja do obiektu
}

Matrix& Matrix::operator++(int) {
	for (int i = 0; i < rozmiar; ++i) {
		for (int j = 0; j < rozmiar; ++j) {
			wsm[i][j]++;  // <--- Inkrementacja wartosci macierzy 
		}
	}
	return *this;  
}

Matrix& Matrix::operator--(int) {
	for (int i = 0; i < rozmiar; ++i) {
		for (int j = 0; j < rozmiar; ++j) {
			wsm[i][j]--;  // <--- Dekrementacja wartosci macierzy 
		}
	}
	return *this;  
}

Matrix& Matrix::operator+=(int a) {
	for (int i = 0; i < rozmiar; ++i) {
		for (int j = 0; j < rozmiar; ++j) {
			wsm[i][j] += a;  // <--- Dodawanie wartosci do macierzy 
		}
	}
	return *this;  // <--- Zwracana jest referencja do obiektu 
}

Matrix& Matrix::operator-=(int a) {
	for (int i = 0; i < rozmiar; ++i) {
		for (int j = 0; j < rozmiar; ++j) {
			wsm[i][j] -= a;  // <--- Odejmowanie wartosci od macierzy 
		}
	}
	return *this; 
}

Matrix& Matrix::operator*=(int a) {
	for (int i = 0; i < rozmiar; ++i) {
		for (int j = 0; j < rozmiar; ++j) {
			wsm[i][j] *= a;  // <--- Mnozenie wartosci macierzy 
		}
	}
	return *this;  
}


bool Matrix::operator>(const Matrix& m) {

if (rozmiar != m.rozmiar) {
		throw std::invalid_argument("Wymiary macierzy musz¹ byæ takie same");
	}
	for (int i = 0; i < rozmiar; ++i) {
		for (int j = 0; j < rozmiar; ++j) {
			if (wsm[i][j] <= m.wsm[i][j]) { // <--- Jeœli którykolwiek element nie spe³nia nierównoœci
				return false; // <--- Nie mo¿emy powiedzieæ, ¿e macierz jest wiêksza
			}
		}
	}
	return true; // <--- Wszystkie elementy s¹ wiêksze

}

bool Matrix::operator<(const Matrix& m) {
if (rozmiar != m.rozmiar) {
		throw std::invalid_argument("Wymiary macierzy musz¹ byæ takie same");
	}
	for (int i = 0; i < rozmiar; ++i) {
		for (int j = 0; j < rozmiar; ++j) {
			if (wsm[i][j] >= m.wsm[i][j]) { // <--- Jeœli którykolwiek element nie spe³nia nierównoœci
				return false; // <--- Nie mo¿emy powiedzieæ, ¿e macierz jest mniejsza
			}
		}
	}
	return true; // <--- Wszystkie elementy s¹ mniejsze

}

//Matrix& Matrix::operator(double) {

//}

bool Matrix::operator==(const Matrix& m) {
	
	if (this->rozmiar != m.rozmiar) {  // <--- Sprawdzamy czy rozmiary macierzy s¹ takie same
		return false;  
	}

	// Porównujemy wartoœci w ka¿dej komórce
	for (int i = 0; i < this->rozmiar; ++i) {
		for (int j = 0; j < this->rozmiar; ++j) {
			if (this->wsm[i][j] != m.wsm[i][j]) {
				return false;  //<--- Wartoœci s¹ ró¿ne, macierze nie s¹ równe
			}
		}
	}

	return true;  // <--- Jeœli rozmiary i wszystkie wartoœci s¹ takie same, macierze s¹ równe
}

Matrix& Matrix::wczytaj_z_pliku(const std::string& nazwa) {
	std::ifstream plik(nazwa);  // <--- Otwieranie pliku
	if (!plik.is_open()) {  // <--- Sprawdzanie czy plik zosta³ otwarty
		throw std::runtime_error("Nie mo¿na otworzyæ pliku"); // <--- Rzucanie wyj¹tku
	}

	int nowyRozmiar; // <--- Zmienna przechowuj¹ca nowy rozmiar macierzy
	plik >> nowyRozmiar;  // <--- Wczytanie rozmiaru macierzy
	if (nowyRozmiar <= 0) { // <--- Sprawdzanie czy rozmiar macierzy jest dodatni
		throw std::invalid_argument("Nieprawid³owy rozmiar macierzy w pliku");
	}

	Macierz_Alokacja(nowyRozmiar);  // <--- Zmieniamy rozmiar macierzy

	for (int i = 0; i < rozmiar; ++i) { // <--- Petla wczytujaca wartosci do macierzy
		for (int j = 0; j < rozmiar; ++j) { // <--- Petla wczytujaca wartosci do macierzy
			if (!(plik >> wsm[i][j])) {  // <--- Wczytujemy dane macierzy
				throw std::runtime_error("B³¹d odczytu danych z pliku"); // <--- Rzucanie wyj¹tku
			}
		}
	}

	plik.close();  // <--- Zamykamy plik
	return *this;  // <--- Zwracamy referencjê do bie¿¹cego obiektu
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {

	for (int i = 0; i < matrix.rozmiar; ++i) { 
		for (int j = 0; j < matrix.rozmiar; ++j) {
			os << matrix.wsm[i][j] << " ";  // <--- Wyœwietlamy elementy z odstêpem
		}
		os << std::endl;  // <--- Przejœcie do nowego wiersza
	}

	return os;  // Zwracamy strumieñ
}