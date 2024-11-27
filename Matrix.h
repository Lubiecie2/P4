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
};