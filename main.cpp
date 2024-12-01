#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
    cout << "Macierz wyglada nastepujaco: " << endl;
    Matrix macierz(5);  // Zmieniamy rozmiar macierzy na 5x5
    for (int i = 0; i < 5; i++) {  // Zmieniamy zakres pętli na 5
        for (int j = 0; j < 5; j++) {  // Zmieniamy zakres pętli na 5
            macierz.wstaw(i, j, i + j);
            cout << macierz.pokaz(i, j) << " ";
        }
        cout << endl;
    }

    cout << "Wstawianie wartosci 5 na pozycje 1,1" << endl;
    macierz.wstaw(1, 1, 5);
    cout << "Macierz wyglada nastepujaco: " << endl;
    for (int i = 0; i < 5; i++) {  // Zmieniamy zakres pętli na 5
        for (int j = 0; j < 5; j++) {  // Zmieniamy zakres pętli na 5
            cout << macierz.pokaz(i, j) << " ";
        }
        cout << endl;
    }

	cout << "Odwrocenie macierzy: " << endl;
	macierz.Macierz_Odwroc();
	cout << "Macierz wyglada nastepujaco: " << endl;
	for (int i = 0; i < 5; i++) {  // Zmieniamy zakres pętli na 5
		for (int j = 0; j < 5; j++) {  // Zmieniamy zakres pętli na 5
			cout << macierz.pokaz(i, j) << " ";
		}
		cout << endl;
	}

    cout << "Zmiana pierwszej kolumny: " << endl;
    int kolumna[] = { 7, 6, 7, 7, 6 };  // Dostosowanie do 5 elementów
    macierz.kolumna(0, kolumna);
    cout << "Macierz wyglada nastepujaco: " << endl;
    for (int i = 0; i < 5; i++) {  // Zmieniamy zakres pętli na 5
        for (int j = 0; j < 5; j++) {  // Zmieniamy zakres pętli na 5
            cout << macierz.pokaz(i, j) << " ";
        }
        cout << endl;
    }

    cout << "Zmiana drugiego wiersza: " << endl;
    int wiersz[] = { 9, 0, 9, 9, 0 };  // Dostosowanie do 5 elementów
    macierz.wiersz(1, wiersz);
    cout << "Macierz wyglada nastepujaco: " << endl;
    for (int i = 0; i < 5; i++) {  // Zmieniamy zakres pętli na 5
        for (int j = 0; j < 5; j++) {  // Zmieniamy zakres pętli na 5
            cout << macierz.pokaz(i, j) << " ";
        }
        cout << endl;
    }

    cout << "Przekatna: " << endl;
    macierz.przekatna();
    cout << "Macierz wyglada nastepujaco: " << endl;
    for (int i = 0; i < 5; i++) {  // Zmieniamy zakres pętli na 5
        for (int j = 0; j < 5; j++) {  // Zmieniamy zakres pętli na 5
            cout << macierz.pokaz(i, j) << " ";
        }
        cout << endl;
    }

    cout << "Pod przekatna: " << endl;
    macierz.pod_przekatna();
    cout << "Macierz wyglada nastepujaco: " << endl;
    for (int i = 0; i < 5; i++) {  // Zmieniamy zakres pętli na 5
        for (int j = 0; j < 5; j++) {  // Zmieniamy zakres pętli na 5
            cout << macierz.pokaz(i, j) << " ";
        }
        cout << endl;
    }

    cout << "Nad przekatna: " << endl;
    macierz.nad_przekatna();
    cout << "Macierz wyglada nastepujaco: " << endl;
    for (int i = 0; i < 5; i++) {  // Zmieniamy zakres pętli na 5
        for (int j = 0; j < 5; j++) {  // Zmieniamy zakres pętli na 5
            cout << macierz.pokaz(i, j) << " ";
        }
        cout << endl;
    }

    cout << "Losowe liczby: " << endl;
    macierz.losuj(3);

    cout << "Macierz wyglada nastepujaco: " << endl;
    for (int i = 0; i < 5; i++) {  // Zmieniamy zakres pętli na 5
        for (int j = 0; j < 5; j++) {  // Zmieniamy zakres pętli na 5
            cout << macierz.pokaz(i, j) << " ";
        }
        cout << endl;
    }

    cout << "Powiekszenie macierzy o 1: " << endl;
    macierz.operator+=(1);
    cout << "Macierz wyglada nastepujaco: " << endl;
    for (int i = 0; i < 5; i++) {  // Zmieniamy zakres pętli na 5
        for (int j = 0; j < 5; j++) {  // Zmieniamy zakres pętli na 5
            cout << macierz.pokaz(i, j) << " ";
        }
        cout << endl;
    }

    cout << "Pomniejszenie macierzy o 1: " << endl;
    macierz.operator-=(1);
    cout << "Macierz wyglada nastepujaco: " << endl;
    for (int i = 0; i < 5; i++) {  // Zmieniamy zakres pętli na 5
        for (int j = 0; j < 5; j++) {  // Zmieniamy zakres pętli na 5
            cout << macierz.pokaz(i, j) << " ";
        }
        cout << endl;
    }

    cout << "Pomnozenie macierzy przez 2: " << endl;
    macierz.operator*=(2);
    cout << "Macierz wyglada nastepujaco: " << endl;
    for (int i = 0; i < 5; i++) {  // Zmieniamy zakres pętli na 5
        for (int j = 0; j < 5; j++) {  // Zmieniamy zakres pętli na 5
            cout << macierz.pokaz(i, j) << " ";
        }
        cout << endl;
    }

    cout << "Powiekszenie macierzy o 1: " << endl;
    macierz.operator++(1);
    cout << "Macierz wyglada nastepujaco: " << endl;
    for (int i = 0; i < 5; i++) {  // Zmieniamy zakres pętli na 5
        for (int j = 0; j < 5; j++) {  // Zmieniamy zakres pętli na 5
            cout << macierz.pokaz(i, j) << " ";
        }
        cout << endl;
    }

    cout << "Pomniejszenie macierzy o 1: " << endl;
    macierz.operator--(1);
    cout << "Macierz wyglada nastepujaco: " << endl;
    for (int i = 0; i < 5; i++) {  // Zmieniamy zakres pętli na 5
        for (int j = 0; j < 5; j++) {  // Zmieniamy zakres pętli na 5
            cout << macierz.pokaz(i, j) << " ";
        }
        cout << endl;
    }

    cout << "Szachownica: " << endl;
    macierz.szachownica();
    cout << "Macierz wyglada nastepujaco: " << endl;
    for (int i = 0; i < 5; i++) {  // Zmieniamy zakres pętli na 5
        for (int j = 0; j < 5; j++) {  // Zmieniamy zakres pętli na 5
            cout << macierz.pokaz(i, j) << " ";
        }
        cout << endl;
    }

    cout << "Dodawanie macierzy: " << endl;
    Matrix macierz2(5);  // Zmieniamy rozmiar macierzy na 5x5
    for (int i = 0; i < 5; i++) {  // Zmieniamy zakres pętli na 5
        for (int j = 0; j < 5; j++) {  // Zmieniamy zakres pętli na 5
            macierz2.wstaw(i, j, i + j);
            cout << macierz2.pokaz(i, j) << " ";
        }
        cout << endl;
    }

    macierz.operator+(macierz2);
    cout << "Macierz wyglada nastepujaco: " << endl;
    for (int i = 0; i < 5; i++) {  // Zmieniamy zakres pętli na 5
        for (int j = 0; j < 5; j++) {  // Zmieniamy zakres pętli na 5
            cout << macierz.pokaz(i, j) << " ";
        }
        cout << endl;
    }

    cout << "Dodawanie liczby do macierzy: " << endl;
    macierz.operator+(5);
    cout << "Macierz wyglada nastepujaco: " << endl;
    for (int i = 0; i < 5; i++) {  // Zmieniamy zakres pętli na 5
        for (int j = 0; j < 5; j++) {  // Zmieniamy zakres pętli na 5
            cout << macierz.pokaz(i, j) << " ";
        }
        cout << endl;
    }

    cout << "Mnozenie macierzy przez liczbe: " << endl;
    macierz.operator*(5);
    cout << "Macierz wyglada nastepujaco: " << endl;
    for (int i = 0; i < 5; i++) {  // Zmieniamy zakres pętli na 5
        for (int j = 0; j < 5; j++) {  // Zmieniamy zakres pętli na 5
            cout << macierz.pokaz(i, j) << " ";
        }
        cout << endl;
    }

    cout << "Odejmowanie liczby od macierzy: " << endl;
    macierz.operator-(5);
    cout << "Macierz wyglada nastepujaco: " << endl;
    for (int i = 0; i < 5; i++) {  // Zmieniamy zakres pętli na 5
        for (int j = 0; j < 5; j++) {  // Zmieniamy zakres pętli na 5
            cout << macierz.pokaz(i, j) << " ";
        }
        cout << endl;
    }

    cout << "Diagonalna: " << endl;
    int diagonalna[] = { 1, 2, 3, 4, 5 };  // Zmieniamy zakres na 5 elementów
    macierz.diagonalna(diagonalna);
    cout << "Macierz wyglada nastepujaco: " << endl;
    for (int i = 0; i < 5; i++) {  // Zmieniamy zakres pętli na 5
        for (int j = 0; j < 5; j++) {  // Zmieniamy zakres pętli na 5
            cout << macierz.pokaz(i, j) << " ";
        }
        cout << endl;
    }

    cout << "Diagonalna k: " << endl;
    int diagonalna_k[] = { 1, 2, 3, 4, 5 };  // Zmieniamy zakres na 5 elementów
    macierz.diagonalna_k(1, diagonalna_k);
    cout << "Macierz wyglada nastepujaco: " << endl;
    for (int i = 0; i < 5; i++) {  // Zmieniamy zakres pętli na 5
        for (int j = 0; j < 5; j++) {  // Zmieniamy zakres pętli na 5
            cout << macierz.pokaz(i, j) << " ";
        }
        cout << endl;
    }

    Matrix m_plus = macierz + 5;
    cout << "Macierz po dodaniu 5 wyglada nastepujaco: " << endl;
    for (int i = 0; i < 5; i++) {  // Zmieniamy zakres pętli na 5
        for (int j = 0; j < 5; j++) {  // Zmieniamy zakres pętli na 5
            cout << m_plus.pokaz(i, j) << " ";
        }
        cout << endl;
    }

    Matrix m_minus = macierz - 5;
    cout << "Macierz po odjeciu wyglada nastepujaco: " << endl;
    for (int i = 0; i < 5; i++) {  // Zmieniamy zakres pętli na 5
        for (int j = 0; j < 5; j++) {  // Zmieniamy zakres pętli na 5
            cout << m_minus.pokaz(i, j) << " ";
        }
        cout << endl;
    }

    Matrix m_razy = 5 * macierz;
    cout << "Macierz po pomnozeniu razy 5 wyglada nastepujaco: " << endl;
    for (int i = 0; i < 5; i++) {  // Zmieniamy zakres pętli na 5
        for (int j = 0; j < 5; j++) {  // Zmieniamy zakres pętli na 5
            cout << m_razy.pokaz(i, j) << " ";
        }
        cout << endl;
    }

    std::cout << std::endl;

	std::cout << "Poronanie macierzy:\n";
	std::cout << "Macierz1:\n";
    // Tworzenie macierzy macierz1 3x3 i wypełnianie wartościami
    Matrix mc1(3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mc1.wstaw(i, j, (i + 1) * (j + 1)); 
            std::cout << mc1.pokaz(i, j) << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\n";
	std::cout << "Macierz2:\n";
    // Tworzenie macierzy macierz2 3x3 i wypełnianie wartościami
    Matrix mc2(3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mc2.wstaw(i, j, i + j); 
            std::cout << mc2.pokaz(i, j) << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\nTest porownania macierzy:\n";

    // Operator '>'
    if (mc1 > mc2) {
        std::cout << "macierz1 > macierz2: PRAWDA" << std::endl;
    }
    else {
        std::cout << "macierz1 > macierz2: FALSZ" << std::endl;
    }

    // Operator '<'
    if (mc1 < mc2) {
        std::cout << "macierz1 < macierz2: PRAWDA" << std::endl;
    }
    else {
        std::cout << "macierz1 < macierz2: FALSZ" << std::endl;
    }
    

    Matrix mac(1);

    // Wywołanie metody wczytaj_z_pliku
    mac.wczytaj_z_pliku("macierz.txt");

	std::cout << std::endl;
    // Wyświetlenie zawartości macierzy po wczytaniu
    cout << "Macierz po wczytaniu z pliku:" << endl;
    for (int i = 0; i < 11; ++i) {
        for (int j = 0; j < 11; ++j) {
            cout << mac.pokaz(i, j) << " ";
        }
        cout << endl;
    }
    return 0;
    
}
