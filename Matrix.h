#pragma once

class Matrix {

public: 

	int** wsm;    // <--- Wskaznik na macierz
	int rozmiar;  //<--- Rozmiar macierzy

    Matrix();                         // <--- konstruktor domyslny
    Matrix(int n);                    // <--- konstruktor z rozmiarem
    Matrix(int n, int* t);            // <--- konstruktor z tablica
    Matrix(const Matrix& m);          // <--- konstruktor kopiujacy
    ~Matrix();                        // <--- Destruktor 


    Matrix& Macierz_Alokacja(int n);
    Matrix& Macierz_Odwroc();
    Matrix& Macierz_Losowa_wartosc_0_9();
    Matrix& losuj(int x);
    Matrix& wstaw(int x, int y, int wartosc);
    int pokaz(int x, int y);
    Matrix& kolumna(int x, int* t);
    Matrix& wiersz(int y, int* t);
    Matrix& przekatna(void);
    Matrix& pod_przekatna(void);
    Matrix& nad_przekatna(void);

    Matrix& operator+=(int a);
    Matrix& operator-=(int a);
};