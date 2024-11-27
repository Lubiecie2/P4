#pragma once

class Matrix {

public: 

	int** wsm;    // <--- Wska�nik na macierz
	int rozmiar;  //<--- Rozmiar macierzy

    Matrix();                         // <--- konstruktor domy�lny
    Matrix(int n);                    // <--- konstruktor z rozmiarem
    Matrix(int n, int* t);            // <--- konstruktor z tablic�
    Matrix(const Matrix& m);          // <--- konstruktor kopiuj�cy
    ~Matrix();                        // <--- Destruktor 


    Matrix& Macierz_Alokacja(int n);
    Matrix& Macierz_Odwroc();
};