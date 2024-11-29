#include "Matrix.h"
#include <iostream>
#include <ctime>
#include <cstdlib>


// Konstruktory
Matrix::Matrix() : wsm(nullptr), rozmiar(0) {}     // <--- Konstruktor domyslny 

Matrix::Matrix(int n) : wsm(nullptr), rozmiar(0) {     // <--- Konstruktor alokujacy pamiec 
    if (n > 0) {
        rozmiar = n;
        wsm = new int* [rozmiar];
        for (int i = 0; i < rozmiar; ++i) {
            wsm[i] = new int[rozmiar];
            for (int j = 0; j < rozmiar; ++j) {
                wsm[i][j] = 0;
            }
        }
    }
}

Matrix::Matrix(int n, int* t) : wsm(nullptr), rozmiar(0) {  // <--- Konstruktor alokujacy pamiec i inicjalizujacy wartosci
    if (n > 0) {
        rozmiar = n;
        wsm = new int* [rozmiar];
        for (int i = 0; i < rozmiar; ++i) {
            wsm[i] = new int[rozmiar];
            for (int j = 0; j < rozmiar; ++j) {
                wsm[i][j] = t[i * rozmiar + j]; 
            }
        }
    }
}

Matrix::Matrix(const Matrix& m) : wsm(nullptr), rozmiar(0) {  // <--- Konstruktor kopiujacy 
    if (m.rozmiar > 0) {
        rozmiar = m.rozmiar;
        wsm = new int* [rozmiar];
        for (int i = 0; i < rozmiar; ++i) {
            wsm[i] = new int[rozmiar];
            for (int j = 0; j < rozmiar; ++j) {
                wsm[i][j] = m.wsm[i][j]; 
            }
        }
    }
}

// Destruktor

Matrix::~Matrix() {
    if (wsm) {
        for (int i = 0; i < rozmiar; ++i) {
            delete[] wsm[i]; 
        }
        delete[] wsm; 
        wsm = nullptr;
        rozmiar = 0; 
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
	if (x >= 0 && x < rozmiar && y >= 0 && y < rozmiar) {
		wsm[x][y] = wartosc;  // <--- Wstawianie wartosci do macierzy 
	}
	return *this;  // <--- Zwracana jest referencja do obiektu 
}

int Matrix::pokaz(int x, int y) {
	if (x >= 0 && x < rozmiar && y >= 0 && y < rozmiar) {
		return wsm[x][y];  // <--- Zwracanie wartosci z macierzy 
	}
	return 0;
}

//Transformacje macierzy

Matrix& Matrix::Macierz_Odwroc() {
    for (int i = 0; i < rozmiar; ++i) {          // <--- Petla do wierszy
        for (int j = i + 1; j < rozmiar; ++j) {  // <--- Petla do kolumn 
            std::swap(wsm[i][j], wsm[j][i]);  // <--- Zamiana elementow w macierzy 
        }
    }
    return *this;  // <--- Zwracana jest referencja do obiektu 
}


Matrix& Matrix::Macierz_Losowa_wartosc_0_9() {
    
    for (int i = 0; i < rozmiar; ++i) {
        for (int j = 0; j < rozmiar; ++j) {
            wsm[i][j] = std::rand() % 10;  // Losujemy liczby z zakresu 0-9
        }
    }
    return *this;  // Zwracamy referencje do obiektu
}

Matrix& Matrix::losuj(int x) {
	if (rozmiar > 0 && x > 0) {
		std::srand(std::time(nullptr)); // <--- Inicjalizacja generatora liczb pseudolosowych
		for (int i = 0; i < x; ++i) {
			int LosowyWiersz = std::rand() % rozmiar;
			int LosowaKolumna = std::rand() % rozmiar;
			wsm[LosowyWiersz][LosowaKolumna] = std::rand() % 10; // <Losujemy liczby z zakresu 0-9>--
		}
	}
	return *this; // Zwracamy referencje do obiektu
}

// Uklady macierzy

Matrix& Matrix::diagonalna(int* t) {

}

Matrix& Matrix::diagonalna_k(int k, int* t) {
	
}

Matrix& Matrix::kolumna(int x, int* t) {
	if (x >= 0 && x < rozmiar) {
		for (int i = 0; i < rozmiar; ++i) {
			wsm[i][x] = t[i];  // <--- Wstawianie wartoœci do kolumny 
		}
	}
	return *this;  // <--- Zwracana jest referencja do obiektu 
}

Matrix& Matrix::wiersz(int y, int* t) {
	if (y >= 0 && y < rozmiar) {
		for (int i = 0; i < rozmiar; ++i) {
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
	return *this;  // <--- Zwracana jest referencja do obiektu
}

Matrix& Matrix::pod_przekatna(void) {
    for (int i = 0; i < rozmiar; ++i) {
        for (int j = 0; j < rozmiar; ++j) {
            wsm[i][j] = (i > j) ? 1 : 0;  // <--- Wstawianie wartosci pod przekatna
        }
    }
	return *this;  // <--- Zwracana jest referencja do obiektu
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
	return *this;  // <--- Zwracana jest referencja do obiektu 
}

// Operacje matematyczne na macierzy

Matrix& Matrix::operator+(Matrix& m) {
	if (rozmiar == m.rozmiar) {
		for (int i = 0; i < rozmiar; ++i) {
			for (int j = 0; j < rozmiar; ++j) {
				wsm[i][j] += m.wsm[i][j];  // <--- Dodawanie macierzy 
			}
		}
	}
	return *this;  // <--- Zwracana jest referencja do obiektu 
}

Matrix& Matrix::operator*(Matrix& m) {
	if (rozmiar == m.rozmiar) {
		Matrix temp(rozmiar);
		for (int i = 0; i < rozmiar; ++i) {
			for (int j = 0; j < rozmiar; ++j) {
				for (int k = 0; k < rozmiar; ++k) {
					temp.wsm[i][j] += wsm[i][k] * m.wsm[k][j];  // <--- Mnozenie macierzy 
				}
			}
		}
		*this = temp;
	}
	return *this;  // <--- Zwracana jest referencja do obiektu 
}

Matrix& Matrix::operator+(int a) {
	for (int i = 0; i < rozmiar; ++i) {
		for (int j = 0; j < rozmiar; ++j) {
			wsm[i][j] += a;  // <--- Dodawanie wartosci do macierzy 
		}
	}
	return *this;  // <--- Zwracana jest referencja do obiektu 
}

Matrix& Matrix::operator*(int a) {
	for (int i = 0; i < rozmiar; ++i) {
		for (int j = 0; j < rozmiar; ++j) {
			wsm[i][j] *= a;  // <--- Mnozenie wartosci macierzy 
		}
	}
	return *this;  // <--- Zwracana jest referencja do obiektu 
}

Matrix& Matrix::operator-(int a) {
	for (int i = 0; i < rozmiar; ++i) {
		for (int j = 0; j < rozmiar; ++j) {
			wsm[i][j] -= a;  // <--- Odejmowanie wartosci od macierzy 
		}
	}
	return *this;  // <--- Zwracana jest referencja do obiektu 
}

Matrix operator+(int a, Matrix& m) {

}

Matrix operator*(int a, Matrix& m) {

}

Matrix operator-(int a, Matrix& m) {

}

Matrix& Matrix::operator++(int) {
	for (int i = 0; i < rozmiar; ++i) {
		for (int j = 0; j < rozmiar; ++j) {
			wsm[i][j]++;  // <--- Inkrementacja wartosci macierzy 
		}
	}
	return *this;  // <--- Zwracana jest referencja do obiektu 
}

Matrix& Matrix::operator--(int) {
	for (int i = 0; i < rozmiar; ++i) {
		for (int j = 0; j < rozmiar; ++j) {
			wsm[i][j]--;  // <--- Dekrementacja wartosci macierzy 
		}
	}
	return *this;  // <--- Zwracana jest referencja do obiektu
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
	return *this;  // <--- Zwracana jest referencja do obiektu 
}

Matrix& Matrix::operator*=(int a) {
	for (int i = 0; i < rozmiar; ++i) {
		for (int j = 0; j < rozmiar; ++j) {
			wsm[i][j] *= a;  // <--- Mnozenie wartosci macierzy 
		}
	}
	return *this;  // <--- Zwracana jest referencja do obiektu 
}

Matrix& Matrix::operator(double) {

}

bool Matrix::operator==(const Matrix& m) {

}

bool Matrix::operator>(const Matrix& m) {

}

bool Matrix::operator<(const Matrix& m) {

}

std::ostream& operator<<(std::ostream& o, Matrix& m) {

}