#include "Matrix.h"
#include <iostream>

Matrix::Matrix() : wsm(nullptr), rozmiar(0) {}     // <--- Konstruktor domyœlny 

Matrix::Matrix(int n) : wsm(nullptr), rozmiar(0) {     // <--- Konstruktor alokuj¹cy pamiêæ 
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

Matrix::Matrix(int n, int* t) : wsm(nullptr), rozmiar(0) {  // <--- Konstruktor alokuj¹cy pamiêæ i inicjalizuj¹cy wartoœci
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


Matrix::Matrix(const Matrix& m) : wsm(nullptr), rozmiar(0) {  // <--- Konstruktor kopiuj¹cy 
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

Matrix::~Matrix() {          // <--- Destruktor 
    if (wsm) {
        for (int i = 0; i < rozmiar; ++i) {
            delete[] wsm[i]; 
        }
        delete[] wsm; 
        wsm = nullptr;
        rozmiar = 0; 
    }
}   

Matrix& Matrix::Macierz_Alokacja(int n) {
    
    if (wsm) {               // <--- instrukcja sprawdza czy macierz ma ju¿ zaalokowan¹ pamiêæ 
        if (rozmiar != n) {    // <--- instrukcja sprawdza czy nowy rozmiar jest inny ni¿ poprzedni
            
            for (int i = 0; i < rozmiar; ++i) {   // <--- Jeœli rozmiar jest inny ni¿ porzedni to pêtla 
                delete[] wsm[i];                  //      zwalnia pamiêæ 
            }
            delete[] wsm;
            wsm = nullptr;  // <--- Ustawiany jest wskaŸnik na nullptr
            rozmiar = 0;    // <--- Zerowanie rozmiaru
        }
    }

    if (rozmiar != n) {             // <--- Instrukcja alokuje pamiêæ w nowym rozmiarze jeœli nie ma zaalokowanej
        rozmiar = n;                //      lub po zwolnieniu starej
        wsm = new int* [rozmiar];
        for (int i = 0; i < rozmiar; ++i) {
            wsm[i] = new int[rozmiar];
        }
    }

    return *this;  // <--- Zwracana jest referencja do obiektu 
}

Matrix& Matrix::Macierz_Odwroc() {
    for (int i = 0; i < rozmiar; ++i) {          // <--- Pêtla do wierszy
        for (int j = i + 1; j < rozmiar; ++j) {  // <--- Pêtla do kolumn 
            std::swap(wsm[i][j], wsm[j][i]);  // <--- Zamiana elementów w macierzy 
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
    return *this;  // Zwracamy referencjê do obiektu
}
