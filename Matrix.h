#pragma once
#include <string>

/**
 * @class Matrix
 * @brief Klasa reprezentuj�ca macierz kwadratow�.
 *
 * Klasa ta pozwala na tworzenie i manipulowanie macierzami kwadratowymi
 * o dynamicznie alokowanej pami�ci. Zawiera metody umo�liwiaj�ce wykonywanie
 * r�nych operacji na macierzach, takich jak dodawanie, mno�enie, wstawianie
 * warto�ci, czy odwracanie macierzy.
 */
class Matrix {
public:
    int** wsm;    ///< Wska�nik na tablic� dwuwymiarow� przechowuj�c� macierz.
    int rozmiar;  ///< Rozmiar macierzy (liczba wierszy/kolumn).

    /// Konstruktor domy�lny.
    /// 
    /// Inicjalizuje wska�nik `wsm` na `nullptr` i rozmiar macierzy na 0.
    /// Nie alokuje pami�ci dla macierzy.
    Matrix();

    /// Konstruktor przeci��eniowy.
    /// 
    /// Alokuje pami�� dla macierzy o rozmiarze `n x n` i inicjalizuje jej warto�ci na 0.
    /// 
    /// @param n Rozmiar macierzy.
    Matrix(int n);

    /// Konstruktor przeci��eniowy z tablic�.
    /// 
    /// Alokuje pami�� dla macierzy o rozmiarze `n x n` i przepisuje dane z tablicy `t`.
    /// 
    /// @param n Rozmiar macierzy.
    /// @param t Tablica zawieraj�ca dane do przypisania do macierzy.
    Matrix(int n, int* t);

    /// Konstruktor kopiuj�cy.
    /// 
    /// Tworzy kopi� macierzy `m`, alokuj�c now� pami�� i kopiuj�c jej zawarto��.
    /// 
    /// @param m Macierz, kt�ra ma zosta� skopiowana.
    Matrix(const Matrix& m);

    /// Destruktor.
    /// 
    /// Zwalnia pami�� zajmowan� przez macierz.
    ~Matrix();

    /// Alokuje pami�� dla macierzy o rozmiarze `n x n` je�li pami�� nie by�a wcze�niej alokowana,
    /// lub w razie potrzeby zmienia rozmiar ju� zaalokowanej macierzy.
    /// 
    /// @param n Nowy rozmiar macierzy.
    Matrix& Macierz_Alokacja(int n);

    /// Wstawia warto�� `wartosc` do macierzy na pozycj� (x, y).
    /// 
    /// @param x Indeks wiersza.
    /// @param y Indeks kolumny.
    /// @param wartosc Warto�� do wstawienia.
    Matrix& wstaw(int x, int y, int wartosc);

    /// Zwraca warto�� elementu macierzy na pozycji (x, y).
    /// 
    /// @param x Indeks wiersza.
    /// @param y Indeks kolumny.
    /// @return Warto�� elementu na pozycji (x, y).
    int pokaz(int x, int y);

    /// Odwraca macierz (zamienia wiersze z kolumnami).
    /// 
    /// @return Referencja do obiektu macierzy po odwr�ceniu.
    Matrix& Macierz_Odwroc();

    /// Wype�nia macierz losowymi warto�ciami w zakresie od 0 do 9.
    /// 
    /// @return Referencja do obiektu macierzy po wype�nieniu.
    Matrix& Macierz_Losowa_wartosc_0_9();

    /// Losuje `x` warto�ci w macierzy i umieszcza je w losowych miejscach.
    /// 
    /// @param x Liczba losowanych warto�ci.
    /// @return Referencja do obiektu macierzy po losowaniu.
    Matrix& losuj(int x);

    /// Ustawia warto�ci na przek�tnej macierzy z tablicy `t`, a pozosta�e elementy ustawia na 0.
    /// 
    /// @param t Tablica z danymi do ustawienia na przek�tnej.
    /// @return Referencja do obiektu macierzy po ustawieniu przek�tnej.
    Matrix& diagonalna(int* t);

    /// Ustawia warto�ci na k-tej przek�tnej macierzy z tablicy `t`, a pozosta�e elementy ustawia na 0.
    /// Parametr `k` okre�la przesuni�cie przek�tnej w g�r� lub w d�.
    /// 
    /// @param k Przesuni�cie przek�tnej.
    /// @param t Tablica z danymi do ustawienia na przek�tnej.
    /// @return Referencja do obiektu macierzy po ustawieniu k-tej przek�tnej.
    Matrix& diagonalna_k(int k, int* t);

    /// Wstawia warto�ci z tablicy `t` do kolumny o indeksie `x`.
    /// 
    /// @param x Indeks kolumny.
    /// @param t Tablica z danymi do wstawienia do kolumny.
    /// @return Referencja do obiektu macierzy po wstawieniu warto�ci do kolumny.
    Matrix& kolumna(int x, int* t);

    /// Wstawia warto�ci z tablicy `t` do wiersza o indeksie `y`.
    /// 
    /// @param y Indeks wiersza.
    /// @param t Tablica z danymi do wstawienia do wiersza.
    /// @return Referencja do obiektu macierzy po wstawieniu warto�ci do wiersza.
    Matrix& wiersz(int y, int* t);

    /// Wype�nia macierz tak, �e 1 znajduje si� na przek�tnej, a pozosta�e elementy to 0.
    /// 
    /// @return Referencja do obiektu macierzy po uzupe�nieniu.
    Matrix& przekatna(void);

    /// Wype�nia macierz tak, �e 1 znajduje si� poni�ej przek�tnej, a pozosta�e elementy to 0.
    /// 
    /// @return Referencja do obiektu macierzy po uzupe�nieniu.
    Matrix& pod_przekatna(void);

    /// Wype�nia macierz tak, �e 1 znajduje si� powy�ej przek�tnej, a pozosta�e elementy to 0.
    /// 
    /// @return Referencja do obiektu macierzy po uzupe�nieniu.
    Matrix& nad_przekatna(void);

    /// Wype�nia macierz w spos�b przypominaj�cy szachownic�.
    /// 
    /// @return Referencja do obiektu macierzy po uzupe�nieniu.
    Matrix& szachownica(void);

    /// Operator dodawania dw�ch macierzy.
    /// 
    /// @param m Druga macierz do dodania.
    /// @return Referencja do obiektu macierzy po dodaniu.
    Matrix& operator+(Matrix& m);

    /// Operator mno�enia dw�ch macierzy.
    /// 
    /// @param m Druga macierz do mno�enia.
    /// @return Referencja do obiektu macierzy po pomno�eniu.
    Matrix& operator*(Matrix& m);

    /// Operator dodawania macierzy i liczby ca�kowitej.
    /// 
    /// @param a Liczba ca�kowita do dodania.
    /// @return Referencja do obiektu macierzy po dodaniu liczby.
    Matrix& operator+(int a);

    /// Operator mno�enia macierzy przez liczb� ca�kowit�.
    /// 
    /// @param a Liczba ca�kowita do pomno�enia.
    /// @return Referencja do obiektu macierzy po pomno�eniu przez liczb�.
    Matrix& operator*(int a);

    /// Operator odejmowania liczby ca�kowitej od macierzy.
    /// 
    /// @param a Liczba ca�kowita do odj�cia.
    /// @return Referencja do obiektu macierzy po odj�ciu liczby.
    Matrix& operator-(int a);

    /// Operator dodawania liczby ca�kowitej do macierzy.
    /// 
    /// @param a Liczba ca�kowita do dodania.
    /// @param m Macierz do kt�rej dodajemy liczb�.
    /// @return Nowa macierz po dodaniu liczby.
    friend Matrix operator+(int a, Matrix& m);

    /// Operator mno�enia liczby ca�kowitej przez macierz.
    /// 
    /// @param a Liczba ca�kowita do pomno�enia.
    /// @param m Macierz, kt�r� mno�ymy przez liczb�.
    /// @return Nowa macierz po pomno�eniu.
    friend Matrix operator*(int a, Matrix& m);

    /// Operator odejmowania liczby ca�kowitej od macierzy.
    /// 
    /// @param a Liczba ca�kowita do odj�cia.
    /// @param m Macierz, od kt�rej odejmujemy liczb�.
    /// @return Nowa macierz po odj�ciu.
    friend Matrix operator-(int a, Matrix& m);

    /// Operator inkrementacji (zwi�ksza ka�d� liczb� w macierzy o 1).
    /// 
    /// @param a Macierz, kt�ra ma by� inkrementowana.
    /// @return Referencja do obiektu macierzy po inkrementacji.
    Matrix& operator++(int);

    /// Operator dekrementacji (zmniejsza ka�d� liczb� w macierzy o 1).
    /// 
    /// @param a Macierz, kt�ra ma by� dekrementowana.
    /// @return Referencja do obiektu macierzy po dekrementacji.
    Matrix& operator--(int);

    /// Operator dodawania liczby ca�kowitej do ka�dego elementu macierzy.
    /// 
    /// @param a Liczba ca�kowita do dodania.
    /// @return Referencja do obiektu macierzy po dodaniu liczby.
    Matrix& operator+=(int a);

    /// Operator odejmowania liczby ca�kowitej od ka�dego elementu macierzy.
    /// 
    /// @param a Liczba ca�kowita do odj�cia.
    /// @return Referencja do obiektu macierzy po odj�ciu liczby.
    Matrix& operator-=(int a);

    /// Operator mno�enia ka�dego elementu macierzy przez liczb� ca�kowit�.
    /// 
    /// @param a Liczba ca�kowita do mno�enia.
    /// @return Referencja do obiektu macierzy po mno�eniu przez liczb�.
    Matrix& operator*=(int a);

    /// Operator powi�kszania macierzy o cz�� ca�kowit� liczby zmiennoprzecinkowej.
    /// 
    /// @param a Liczba zmiennoprzecinkowa.
    /// @return Referencja do obiektu macierzy po powi�kszeniu.
    Matrix& operator(double a);

    /// Operator wypisania macierzy na ekran.
    /// 
    /// @param o Strumie� wyj�ciowy.
    /// @param m Macierz do wypisania.
    /// @return Strumie� wyj�ciowy.
    friend std::ostream& operator<<(std::ostream& o, Matrix& m);

    /// Operator por�wnania macierzy.
    /// 
    /// @param m Macierz do por�wnania.
    /// @return `true` je�li macierze s� r�wne, w przeciwnym razie `false`.
    bool operator==(const Matrix& m);

    /// Operator por�wnania, czy jedna macierz jest wi�ksza od drugiej.
    /// 
    /// @param m Macierz do por�wnania.
    /// @return `true` je�li wszystkie elementy macierzy s� wi�ksze, w przeciwnym razie `false`.
    bool operator>(const Matrix& m);

    /// Operator por�wnania, czy jedna macierz jest mniejsza od drugiej.
    /// 
    /// @param m Macierz do por�wnania.
    /// @return `true` je�li wszystkie elementy macierzy s� mniejsze, w przeciwnym razie `false`.
    bool operator<(const Matrix& m);
};
