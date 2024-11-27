#pragma once

class Matrix {

public: 

	int** wsm;    // <--- WskaŸnik na macierz
	int rozmiar;  //<--- Rozmiar macierzy

    Matrix();                         // <--- konstruktor domyœlny
    Matrix(int n);                    // <--- konstruktor z rozmiarem
    Matrix(int n, int* t);            // <--- konstruktor z tablic¹
    Matrix(const Matrix& m);          // <--- konstruktor kopiuj¹cy
    ~Matrix();                        // <--- Destruktor 


    Matrix& Macierz_Alokacja(int n);
    Matrix& Macierz_Odwroc();

	Matrix& wstaw(int x, int y, int wartosc);
    int pokaz(int x, int y);
    Matrix& kolumna(int x, int* t);
    Matrix& wiersz(int y, int* t);
    Matrix& przekatna(void);
    Matrix& pod_przekatna(void);
    Matrix& nad_przekatna(void);
};