#include "Matrix.h"
#include <iostream>

Matrix::Matrix() : wsm(nullptr), rozmiar(0) {}

Matrix::Matrix(int n) : wsm(nullptr), rozmiar(0) {
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

Matrix::Matrix(int n, int* t) : wsm(nullptr), rozmiar(0) {
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


Matrix::Matrix(const Matrix& m) : wsm(nullptr), rozmiar(0) {
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