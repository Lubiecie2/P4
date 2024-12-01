#pragma once

class Matrix {
private:
    int** wsm;    // <--- Wskaznik na macierz
    int rozmiar;  //<--- Rozmiar macierzy

public:

    Matrix();                         // <--- konstruktor domyslny
    Matrix(int n);                    // <--- konstruktor z rozmiarem
    Matrix(int n, int* t);            // <--- konstruktor z tablica
    Matrix(const Matrix& m);          // <--- konstruktor kopiujacy

    ~Matrix();                        // <--- Destruktor 

    Matrix& Macierz_Alokacja(int n);

    Matrix& wstaw(int x, int y, int wartosc);
    int pokaz(int x, int y);

    Matrix& Macierz_Odwroc();
    Matrix& Macierz_Losowa_wartosc_0_9();
    Matrix& losuj(int x);

    Matrix& diagonalna(int* t);
    Matrix& diagonalna_k(int k, int* t);
    Matrix& kolumna(int x, int* t);
    Matrix& wiersz(int y, int* t);
    Matrix& przekatna(void);
    Matrix& pod_przekatna(void);
    Matrix& nad_przekatna(void);
    Matrix& szachownica(void);

    Matrix& operator+(Matrix& m);
    Matrix& operator*(Matrix& m);
    Matrix& operator+(int a);
    Matrix& operator*(int a);
    Matrix& operator-(int a);
    friend Matrix operator+(int a, Matrix& m);
    friend Matrix operator*(int a, Matrix& m);
    friend Matrix operator-(int a, Matrix& m);

    Matrix& operator++(int);
    Matrix& operator--(int);
    Matrix& operator+=(int a);
    Matrix& operator-=(int a);
    Matrix& operator*=(int a);
    //Matrix& operator(double);
    
    //bool operator==(const Matrix& m);
    bool operator>(const Matrix& m);
    bool operator<(const Matrix& m);

    //friend std::ostream& operator<<(std::ostream& o, Matrix& m);

    //Matrix& wczytaj_z_pliku(std::string nazwa);*/
};