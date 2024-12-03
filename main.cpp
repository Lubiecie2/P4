#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
	// ----------------- Macierz standardowa -----------------

	cout << "Standardowa macierz: " << endl;
    cout << "Macierz wyglada nastepujaco: " << endl;
    
    Matrix macierz(5);  
   
    for (int i = 0; i < 5; i++) {  
        for (int j = 0; j < 5; j++) {  
            macierz.wstaw(i, j, i + j);
            cout << macierz.pokaz(i, j) << " ";
        }
        cout << endl;
    }

	// ----------------- Koniec Macierz standardowa -----------------
	// ----------------- Macierz wstawianie 5 na pozycje 1,1 -----------------

	std::cout << std::endl;
    cout << "Wstawianie wartosci 5 na pozycje 1,1" << endl;
    macierz.wstaw(1, 1, 5);
    cout << "Macierz wyglada nastepujaco: " << endl;
    for (int i = 0; i < 5; i++) { 
        for (int j = 0; j < 5; j++) {  
            cout << macierz.pokaz(i, j) << " ";
        }
        cout << endl;
    }
    std::cout << std::endl;

	// ----------------- Koniec Macierz wstawianie 5 na pozycje 1,1 -----------------
	// ----------------- Macierz odwracanie -----------------

	cout << "Odwrocenie macierzy: " << endl;
	macierz.Macierz_Odwroc();
	cout << "Macierz wyglada nastepujaco: " << endl;
	for (int i = 0; i < 5; i++) {  
		for (int j = 0; j < 5; j++) { 
			cout << macierz.pokaz(i, j) << " ";
		}
		cout << endl;
	}

	// ----------------- Koniec Macierz odwracanie -----------------
	// ----------------- Macierz zamiana pierwszej kolumny -----------------

    std::cout << std::endl;
    cout << "Zmiana pierwszej kolumny: " << endl;
    int kolumna[] = { 7, 6, 7, 7, 6 };  
    macierz.kolumna(0, kolumna);
    cout << "Macierz wyglada nastepujaco: " << endl;
    for (int i = 0; i < 5; i++) { 
        for (int j = 0; j < 5; j++) {  
            cout << macierz.pokaz(i, j) << " ";
        }
        cout << endl;
    }
    std::cout << std::endl;

	// ----------------- Koniec Macierz zamiana pierwszej kolumny -----------------
	// ----------------- Macierz zamiana drugiego wiersza -----------------

    cout << "Zmiana drugiego wiersza: " << endl;
    int wiersz[] = { 9, 0, 9, 9, 0 };  
    macierz.wiersz(1, wiersz);
    cout << "Macierz wyglada nastepujaco: " << endl;
    for (int i = 0; i < 5; i++) { 
        for (int j = 0; j < 5; j++) {  
            cout << macierz.pokaz(i, j) << " ";
        }
        cout << endl;
    }
    std::cout << std::endl;

	// ----------------- Koniec Macierz zamiana drugiego wiersza -----------------
	// ----------------- Macierz przekatna -----------------

    cout << "Przekatna: " << endl;
    macierz.przekatna();
    cout << "Macierz wyglada nastepujaco: " << endl;
    for (int i = 0; i < 5; i++) {  
        for (int j = 0; j < 5; j++) {  
            cout << macierz.pokaz(i, j) << " ";
        }
        cout << endl;
    }
	std::cout << std::endl;

	// ----------------- Koniec Macierz przekatna -----------------
	// ----------------- Macierz pod przekatna -----------------

    cout << "Pod przekatna: " << endl;
    macierz.pod_przekatna();
    cout << "Macierz wyglada nastepujaco: " << endl;
    for (int i = 0; i < 5; i++) { 
        for (int j = 0; j < 5; j++) {  
            cout << macierz.pokaz(i, j) << " ";
        }
        cout << endl;
    }
    std::cout << std::endl;

	// ----------------- Koniec Macierz pod przekatna -----------------
	// ----------------- Macierz nad przekatna -----------------

    cout << "Nad przekatna: " << endl;
    macierz.nad_przekatna();
    cout << "Macierz wyglada nastepujaco: " << endl;
    for (int i = 0; i < 5; i++) {  
        for (int j = 0; j < 5; j++) {  
            cout << macierz.pokaz(i, j) << " ";
        }
        cout << endl;
    }
    std::cout << std::endl;

	// ----------------- Koniec Macierz nad przekatna -----------------
	// ----------------- Macierz losowa -----------------

    cout << "Losowe liczby: " << endl;
    macierz.losuj(5);

    cout << "Macierz wyglada nastepujaco: " << endl;
    for (int i = 0; i < 5; i++) {  
        for (int j = 0; j < 5; j++) {  
            cout << macierz.pokaz(i, j) << " ";
        }
        cout << endl;
    }
    std::cout << std::endl;

	// ----------------- Koniec Macierz losowa -----------------
    // ----------------- Macierz losowa -----------------

    cout << "Losowe liczby wszystkie: " << endl;
    macierz.losuj();

    cout << "Macierz wyglada nastepujaco: " << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << macierz.pokaz(i, j) << " ";
        }
        cout << endl;
    }
    std::cout << std::endl;

    // ----------------- Koniec Macierz losowa ----------------- 
    
	// ----------------- Macierz powiekszona o 1 -----------------

    std::cout << "***********************************" << std::endl;
    cout << "Powiekszenie macierzy o okreslona liczbe (2): " << endl;

    cout << "Przed operacja: " << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            macierz.wstaw(i, j, i + j); 
            cout << macierz.pokaz(i, j) << " "; 
        }
        cout << endl;
    }
    cout << endl;

    macierz.operator+=(2);

    cout << "Po operacji: " << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << macierz.pokaz(i, j) << " ";  
        }
        cout << endl;
    }

    std::cout << "***********************************" << std::endl;
    std::cout << std::endl;

	// ----------------- Koniec Macierz powiekszona o 1 -----------------
	// ----------------- Macierz pomniejszona o 1 -----------------

    std::cout << "***********************************" << std::endl;
    cout << "Pomniejszenie macierzy o okreslona liczbe (2): " << endl;

    cout << "Przed operacja: " << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            macierz.wstaw(i, j, i + j);  
            cout << macierz.pokaz(i, j) << " "; 
        }
        cout << endl;
    }
    cout << endl;

    macierz.operator-=(2);

    cout << "Po operacji: " << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << macierz.pokaz(i, j) << " ";  
        }
        cout << endl;
    }

    std::cout << "***********************************" << std::endl;
    std::cout << std::endl;

	// ----------------- Koniec Macierz pomniejszona o 1 -----------------
	// ----------------- Macierz pomnozona przez 2 -----------------

	std::cout << "***********************************" << std::endl;
    cout << "Pomnozenie macierzy przez 2 " << endl;
    cout << "Przed operacji: " << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            macierz.wstaw(i, j, i + j);
            cout << macierz.pokaz(i, j) << " ";
        }
        cout << endl;
    }
    cout << endl;

    macierz.operator*=(2);  

    cout << "Po operacji: " << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << macierz.pokaz(i, j) << " ";
        }
        cout << endl;
    }
    std::cout << "***********************************" << std::endl;
    std::cout << std::endl;
    
    // ----------------- Koniec Macierz pomnozona przez 2 -----------------
	// ----------------- Macierz inkrementacja -----------------

    std::cout << "***********************************" << std::endl;
    cout << "Macierz inkrementacja: " << endl;

    cout << "Przed operacja: " << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            macierz.wstaw(i, j, i + j); 
            cout << macierz.pokaz(i, j) << " ";  
        }
        cout << endl;
    }
    cout << endl;

    macierz.operator++(1);  

    cout << "Po operacji: " << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << macierz.pokaz(i, j) << " "; 
        }
        cout << endl;
    }

    std::cout << "***********************************" << std::endl;
    std::cout << std::endl;

	// ----------------- Koniec Macierz inkrementacja -----------------
	// ----------------- Macierz dekrementacja -----------------

    std::cout << "***********************************" << std::endl;
    cout << "Macierz dekrementacja: " << endl;

    cout << "Przed operacja: " << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            macierz.wstaw(i, j, i + j); 
            cout << macierz.pokaz(i, j) << " "; 
        }
        cout << endl;
    }
    cout << endl;

    macierz.operator--(1);  

    cout << "Po operacji: " << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << macierz.pokaz(i, j) << " ";  
        }
        cout << endl;
    }

    std::cout << "***********************************" << std::endl;
    std::cout << std::endl;

	// ----------------- Koniec Macierz dekrementacja -----------------
	// ----------------- Macierz szachownica -----------------

    cout << "Szachownica: " << endl;
    macierz.szachownica();
    cout << "Macierz wyglada nastepujaco: " << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) { 
            cout << macierz.pokaz(i, j) << " ";
        }
        cout << endl;
    }
    std::cout << std::endl;
    
	// ----------------- Koniec Macierz szachownica -----------------
	// ----------------- Macierz dodawanie -----------------

    Matrix macierz2(5); 

    std::cout << "***********************************" << std::endl;
    cout << "Dodawanie macierzy: " << endl;

    cout << "Macierz 1 przed operacja: " << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            macierz.wstaw(i, j, i + j);  
            cout << macierz.pokaz(i, j) << " ";  
        }
        cout << endl;
    }
    cout << endl;

    cout << "Macierz 2 przed operacja: " << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            macierz2.wstaw(i, j, (i + j) * 2); 
            cout << macierz2.pokaz(i, j) << " ";  
        }
        cout << endl;
    }
    cout << endl;

    macierz = macierz + macierz2;  

    cout << "Po operacji dodawania: " << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << macierz.pokaz(i, j) << " ";  
        }
        cout << endl;
    }

    std::cout << "***********************************" << std::endl;
    std::cout << std::endl;

	// ----------------- Koniec Macierz dodawanie -----------------
	// ----------------- Macierz mnozenie -----------------

    std::cout << "***********************************" << std::endl;
    cout << "Mnozenie macierzy przez liczbe (5): " << endl;

    cout << "Macierz przed operacja: " << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            macierz.wstaw(i, j, i + j); 
            cout << macierz.pokaz(i, j) << " ";  
        }
        cout << endl;
    }
    cout << endl;

    macierz.operator*(5);  

    cout << "Macierz po operacji: " << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << macierz.pokaz(i, j) << " ";  
        }
        cout << endl;
    }
    std::cout << "***********************************" << std::endl;
    std::cout << std::endl;

	// ----------------- Koniec Macierz mnozenie -----------------
    // ---------------- Odejmowanie liczby od macierzy ----------------

    std::cout << "***********************************" << std::endl;
	cout << "Odejmowanie liczby od macierzy (5): " << endl;
    cout << "Macierz przed operacja: " << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << macierz.pokaz(i, j) << " ";
        }
        cout << endl;
    }
    cout << endl;

    macierz.operator-=(5); 

    cout << "Macierz po operacji: " << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << macierz.pokaz(i, j) << " ";
        }
        cout << endl;
    }
    std::cout << "***********************************" << std::endl;
    std::cout << std::endl;

    // ----------------Koniec Odejmowanie liczby od macierzy ----------------
	// ---------------- Macierz diagonalna ----------------

    cout << "Diagonalna: " << endl;
    int diagonalna[] = { 1, 2, 3, 4, 5 };  
    macierz.diagonalna(diagonalna);
    cout << "Macierz wyglada nastepujaco: " << endl;
    for (int i = 0; i < 5; i++) { 
        for (int j = 0; j < 5; j++) {  
            cout << macierz.pokaz(i, j) << " ";
        }
        cout << endl;
    }
    std::cout << std::endl;

	// ----------------- Koniec Macierz diagonalna -----------------
	// ----------------- Macierz diagonalna_k -----------------

    cout << "Diagonalna k: " << endl;
    int diagonalna_k[] = { 1, 2, 3, 4, 5 };  
    macierz.diagonalna_k(1, diagonalna_k);
    cout << "Macierz wyglada nastepujaco: " << endl;
    for (int i = 0; i < 5; i++) {  
        for (int j = 0; j < 5; j++) {  
            cout << macierz.pokaz(i, j) << " ";
        }
        cout << endl;
    }
    std::cout << std::endl;

	// ----------------- Koniec Macierz diagonalna_k -----------------
	// ----------------- Friend functions -----------------

	std::cout << "**************** Friend functions *******************" << std::endl;
    std::cout << std::endl;
    Matrix m_plus = macierz + 5;
    cout << "Macierz po dodaniu 5 wyglada nastepujaco: " << endl;
    for (int i = 0; i < 5; i++) {  
        for (int j = 0; j < 5; j++) {  
            cout << m_plus.pokaz(i, j) << " ";
        }
        cout << endl;
    }
    std::cout << std::endl;
                                                                        
    Matrix m_minus = macierz - 5;
    cout << "Macierz po odjeciu wyglada nastepujaco: " << endl;
    for (int i = 0; i < 5; i++) {  
        for (int j = 0; j < 5; j++) {  
            cout << m_minus.pokaz(i, j) << " ";
        }
        cout << endl;
    }
    std::cout << std::endl;

    Matrix m_razy = 5 * macierz;
    cout << "Macierz po pomnozeniu razy 5 wyglada nastepujaco: " << endl;
    for (int i = 0; i < 5; i++) {  
        for (int j = 0; j < 5; j++) { 
            cout << m_razy.pokaz(i, j) << " ";
        }
        cout << endl;
    }


    std::cout << std::endl;
	std::cout << "***********************************" << std::endl;
	std::cout << std::endl;
	// ----------------- Koniec Friend functions -----------------
	// ----------------- Porownanie macierzy -----------------
    std::cout << "***********************************" << std::endl;
	std::cout << "Poronanie macierzy:\n";
	std::cout << "Macierz1:\n";
 
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
   
    Matrix mc2(3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mc2.wstaw(i, j, i + j); 
            std::cout << mc2.pokaz(i, j) << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\nTest porownania macierzy:\n";

    if (mc1 > mc2) {
        std::cout << "macierz1 > macierz2: PRAWDA" << std::endl;
    }
    else {
        std::cout << "macierz1 > macierz2: FALSZ" << std::endl;
    }

    if (mc1 < mc2) {
        std::cout << "macierz1 < macierz2: PRAWDA" << std::endl;
    }
    else {
        std::cout << "macierz1 < macierz2: FALSZ" << std::endl;
    }
    
    if (mc1 == mc2) {
        std::cout << "macierz1 == macierz2: PRAWDA" << std::endl;
    }
    else {
        std::cout << "macierz1 == macierz2: FALSZ" << std::endl;
    }
    std::cout << "***********************************" << std::endl;
	// ----------------- Koniec Porownanie macierzy -----------------

    Matrix mac(1);

    mac.wczytaj_z_pliku("macierz.txt");

	std::cout << std::endl;

    cout << "Macierz po wczytaniu z pliku:" << endl;
    for (int i = 0; i < 11; ++i) {
        for (int j = 0; j < 11; ++j) {
            cout << mac.pokaz(i, j) << " ";
        }
        cout << endl;
    }
    
	std::cout << std::endl;
    
    Matrix BigMacierz(33);
    
	std::cout << "Macierz skladajaca sie z ponad 30 elementow: " << std::endl;
    for (int i = 0; i < 33; i++) {
        for (int j = 0; j < 33; j++) {
            int value = ((i * 33 + j) % 9) + 1;  
            BigMacierz.wstaw(i, j, value);  
            std::cout << BigMacierz.pokaz(i, j) << " "; 
        }
        std::cout << std::endl;
    }

    return 0;
}
