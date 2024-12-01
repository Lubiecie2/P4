#pragma once
#include <string>

/**
 * @class Matrix
 * @brief Klasa reprezentuj¹ca macierz kwadratow¹.
 *
 * Klasa ta pozwala na tworzenie i manipulowanie macierzami kwadratowymi
 * o dynamicznie alokowanej pamiêci. Zawiera metody umo¿liwiaj¹ce wykonywanie
 * ró¿nych operacji na macierzach, takich jak dodawanie, mno¿enie, wstawianie
 * wartoœci, czy odwracanie macierzy.
 */
class Matrix {
public:
    int** wsm;    ///< WskaŸnik na tablicê dwuwymiarow¹ przechowuj¹c¹ macierz.
    int rozmiar;  ///< Rozmiar macierzy (liczba wierszy/kolumn).

    /// Konstruktor domyœlny.
    /// 
    /// Inicjalizuje wskaŸnik `wsm` na `nullptr` i rozmiar macierzy na 0.
    /// Nie alokuje pamiêci dla macierzy.
    Matrix();

    /// Konstruktor przeci¹¿eniowy.
    /// 
    /// Alokuje pamiêæ dla macierzy o rozmiarze `n x n` i inicjalizuje jej wartoœci na 0.
    /// 
    /// @param n Rozmiar macierzy.
    Matrix(int n);

    /// Konstruktor przeci¹¿eniowy z tablic¹.
    /// 
    /// Alokuje pamiêæ dla macierzy o rozmiarze `n x n` i przepisuje dane z tablicy `t`.
    /// 
    /// @param n Rozmiar macierzy.
    /// @param t Tablica zawieraj¹ca dane do przypisania do macierzy.
    Matrix(int n, int* t);

    /// Konstruktor kopiuj¹cy.
    /// 
    /// Tworzy kopiê macierzy `m`, alokuj¹c now¹ pamiêæ i kopiuj¹c jej zawartoœæ.
    /// 
    /// @param m Macierz, która ma zostaæ skopiowana.
    Matrix(const Matrix& m);

    /// Destruktor.
    /// 
    /// Zwalnia pamiêæ zajmowan¹ przez macierz.
    ~Matrix();

    /// Alokuje pamiêæ dla macierzy o rozmiarze `n x n` jeœli pamiêæ nie by³a wczeœniej alokowana,
    /// lub w razie potrzeby zmienia rozmiar ju¿ zaalokowanej macierzy.
    /// 
    /// @param n Nowy rozmiar macierzy.
    Matrix& Macierz_Alokacja(int n);

    /// Wstawia wartoœæ `wartosc` do macierzy na pozycjê (x, y).
    /// 
    /// @param x Indeks wiersza.
    /// @param y Indeks kolumny.
    /// @param wartosc Wartoœæ do wstawienia.
    Matrix& wstaw(int x, int y, int wartosc);

    /// Zwraca wartoœæ elementu macierzy na pozycji (x, y).
    /// 
    /// @param x Indeks wiersza.
    /// @param y Indeks kolumny.
    /// @return Wartoœæ elementu na pozycji (x, y).
    int pokaz(int x, int y);

    /// Odwraca macierz (zamienia wiersze z kolumnami).
    /// 
    /// @return Referencja do obiektu macierzy po odwróceniu.
    Matrix& Macierz_Odwroc();

    /// Wype³nia macierz losowymi wartoœciami w zakresie od 0 do 9.
    /// 
    /// @return Referencja do obiektu macierzy po wype³nieniu.
    Matrix& Macierz_Losowa_wartosc_0_9();

    /// Losuje `x` wartoœci w macierzy i umieszcza je w losowych miejscach.
    /// 
    /// @param x Liczba losowanych wartoœci.
    /// @return Referencja do obiektu macierzy po losowaniu.
    Matrix& losuj(int x);

    /// Ustawia wartoœci na przek¹tnej macierzy z tablicy `t`, a pozosta³e elementy ustawia na 0.
    /// 
    /// @param t Tablica z danymi do ustawienia na przek¹tnej.
    /// @return Referencja do obiektu macierzy po ustawieniu przek¹tnej.
    Matrix& diagonalna(int* t);

    /// Ustawia wartoœci na k-tej przek¹tnej macierzy z tablicy `t`, a pozosta³e elementy ustawia na 0.
    /// Parametr `k` okreœla przesuniêcie przek¹tnej w górê lub w dó³.
    /// 
    /// @param k Przesuniêcie przek¹tnej.
    /// @param t Tablica z danymi do ustawienia na przek¹tnej.
    /// @return Referencja do obiektu macierzy po ustawieniu k-tej przek¹tnej.
    Matrix& diagonalna_k(int k, int* t);

    /// Wstawia wartoœci z tablicy `t` do kolumny o indeksie `x`.
    /// 
    /// @param x Indeks kolumny.
    /// @param t Tablica z danymi do wstawienia do kolumny.
    /// @return Referencja do obiektu macierzy po wstawieniu wartoœci do kolumny.
    Matrix& kolumna(int x, int* t);

    /// Wstawia wartoœci z tablicy `t` do wiersza o indeksie `y`.
    /// 
    /// @param y Indeks wiersza.
    /// @param t Tablica z danymi do wstawienia do wiersza.
    /// @return Referencja do obiektu macierzy po wstawieniu wartoœci do wiersza.
    Matrix& wiersz(int y, int* t);

    /// Wype³nia macierz tak, ¿e 1 znajduje siê na przek¹tnej, a pozosta³e elementy to 0.
    /// 
    /// @return Referencja do obiektu macierzy po uzupe³nieniu.
    Matrix& przekatna(void);

    /// Wype³nia macierz tak, ¿e 1 znajduje siê poni¿ej przek¹tnej, a pozosta³e elementy to 0.
    /// 
    /// @return Referencja do obiektu macierzy po uzupe³nieniu.
    Matrix& pod_przekatna(void);

    /// Wype³nia macierz tak, ¿e 1 znajduje siê powy¿ej przek¹tnej, a pozosta³e elementy to 0.
    /// 
    /// @return Referencja do obiektu macierzy po uzupe³nieniu.
    Matrix& nad_przekatna(void);

    /// Wype³nia macierz w sposób przypominaj¹cy szachownicê.
    /// 
    /// @return Referencja do obiektu macierzy po uzupe³nieniu.
    Matrix& szachownica(void);

    /// Operator dodawania dwóch macierzy.
    /// 
    /// @param m Druga macierz do dodania.
    /// @return Referencja do obiektu macierzy po dodaniu.
    Matrix& operator+(Matrix& m);

    /// Operator mno¿enia dwóch macierzy.
    /// 
    /// @param m Druga macierz do mno¿enia.
    /// @return Referencja do obiektu macierzy po pomno¿eniu.
    Matrix& operator*(Matrix& m);

    /// Operator dodawania macierzy i liczby ca³kowitej.
    /// 
    /// @param a Liczba ca³kowita do dodania.
    /// @return Referencja do obiektu macierzy po dodaniu liczby.
    Matrix& operator+(int a);

    /// Operator mno¿enia macierzy przez liczbê ca³kowit¹.
    /// 
    /// @param a Liczba ca³kowita do pomno¿enia.
    /// @return Referencja do obiektu macierzy po pomno¿eniu przez liczbê.
    Matrix& operator*(int a);

    /// Operator odejmowania liczby ca³kowitej od macierzy.
    /// 
    /// @param a Liczba ca³kowita do odjêcia.
    /// @return Referencja do obiektu macierzy po odjêciu liczby.
    Matrix& operator-(int a);

    /// Operator dodawania liczby ca³kowitej do macierzy.
    /// 
    /// @param a Liczba ca³kowita do dodania.
    /// @param m Macierz do której dodajemy liczbê.
    /// @return Nowa macierz po dodaniu liczby.
    friend Matrix operator+(int a, Matrix& m);

    /// Operator mno¿enia liczby ca³kowitej przez macierz.
    /// 
    /// @param a Liczba ca³kowita do pomno¿enia.
    /// @param m Macierz, któr¹ mno¿ymy przez liczbê.
    /// @return Nowa macierz po pomno¿eniu.
    friend Matrix operator*(int a, Matrix& m);

    /// Operator odejmowania liczby ca³kowitej od macierzy.
    /// 
    /// @param a Liczba ca³kowita do odjêcia.
    /// @param m Macierz, od której odejmujemy liczbê.
    /// @return Nowa macierz po odjêciu.
    friend Matrix operator-(int a, Matrix& m);

    /// Operator inkrementacji (zwiêksza ka¿d¹ liczbê w macierzy o 1).
    /// 
    /// @param a Macierz, która ma byæ inkrementowana.
    /// @return Referencja do obiektu macierzy po inkrementacji.
    Matrix& operator++(int);

    /// Operator dekrementacji (zmniejsza ka¿d¹ liczbê w macierzy o 1).
    /// 
    /// @param a Macierz, która ma byæ dekrementowana.
    /// @return Referencja do obiektu macierzy po dekrementacji.
    Matrix& operator--(int);

    /// Operator dodawania liczby ca³kowitej do ka¿dego elementu macierzy.
    /// 
    /// @param a Liczba ca³kowita do dodania.
    /// @return Referencja do obiektu macierzy po dodaniu liczby.
    Matrix& operator+=(int a);

    /// Operator odejmowania liczby ca³kowitej od ka¿dego elementu macierzy.
    /// 
    /// @param a Liczba ca³kowita do odjêcia.
    /// @return Referencja do obiektu macierzy po odjêciu liczby.
    Matrix& operator-=(int a);

    /// Operator mno¿enia ka¿dego elementu macierzy przez liczbê ca³kowit¹.
    /// 
    /// @param a Liczba ca³kowita do mno¿enia.
    /// @return Referencja do obiektu macierzy po mno¿eniu przez liczbê.
    Matrix& operator*=(int a);

    /// Operator powiêkszania macierzy o czêœæ ca³kowit¹ liczby zmiennoprzecinkowej.
    /// 
    /// @param a Liczba zmiennoprzecinkowa.
    /// @return Referencja do obiektu macierzy po powiêkszeniu.
    Matrix& operator(double a);

    /// Operator wypisania macierzy na ekran.
    /// 
    /// @param o Strumieñ wyjœciowy.
    /// @param m Macierz do wypisania.
    /// @return Strumieñ wyjœciowy.
    friend std::ostream& operator<<(std::ostream& o, Matrix& m);

    /// Operator porównania macierzy.
    /// 
    /// @param m Macierz do porównania.
    /// @return `true` jeœli macierze s¹ równe, w przeciwnym razie `false`.
    bool operator==(const Matrix& m);

    /// Operator porównania, czy jedna macierz jest wiêksza od drugiej.
    /// 
    /// @param m Macierz do porównania.
    /// @return `true` jeœli wszystkie elementy macierzy s¹ wiêksze, w przeciwnym razie `false`.
    bool operator>(const Matrix& m);

    /// Operator porównania, czy jedna macierz jest mniejsza od drugiej.
    /// 
    /// @param m Macierz do porównania.
    /// @return `true` jeœli wszystkie elementy macierzy s¹ mniejsze, w przeciwnym razie `false`.
    bool operator<(const Matrix& m);
};
