#pragma once
#include <string>

/**
 * @class Matrix
 * @brief Klasa reprezentujaca macierz kwadratowa.
 *
 * Klasa ta pozwala na tworzenie i manipulowanie macierzami kwadratowymi
 * o dynamicznie alokowanej pamieci. Zawiera metody umozliwiajace wykonywanie
 * roznych operacji na macierzach, takich jak dodawanie, mnozenie, wstawianie
 * wartosci, czy odwracanie macierzy.
 */
class Matrix {
public:
    int** wsm;    ///< Wskaznik na tablice dwuwymiarowa przechowujaca macierz.
    int rozmiar;  ///< Rozmiar macierzy (liczba wierszy/kolumn).

    /// Konstruktor domyslny.
    /// 
    /// Inicjalizuje wskaznik `wsm` na `nullptr` i rozmiar macierzy na 0.
    /// Nie alokuje pamieci dla macierzy.
    Matrix();

    /// Konstruktor przeciazony.
    /// 
    /// Alokuje pamiec dla macierzy o rozmiarze `n x n` i inicjalizuje jej wartosci na 0.
    /// 
    /// @param n Rozmiar macierzy.
    Matrix(int n);

    /// Konstruktor przeciazony z tablica.
    /// 
    /// Alokuje pamiec dla macierzy o rozmiarze `n x n` i przepisuje dane z tablicy `t`.
    /// 
    /// @param n Rozmiar macierzy.
    /// @param t Tablica zawierajaca dane do przypisania do macierzy.
    Matrix(int n, int* t);

    /// Konstruktor kopiujacy.
    /// 
    /// Tworzy kopie macierzy `m`, alokujac nowa pamiec i kopiujac jej zawartosc.
    /// 
    /// @param m Macierz, ktora ma zostac skopiowana.
    Matrix(const Matrix& m);

    /// Destruktor.
    /// 
    /// Zwalnia pamiec zajmowana przez macierz.
    ~Matrix();

    /// Alokuje pamiec dla macierzy o rozmiarze `n x n` jesli pamiec nie byla wczesniej alokowana,
    /// lub w razie potrzeby zmienia rozmiar juz zaalokowanej macierzy.
    /// 
    /// @param n Nowy rozmiar macierzy.
    Matrix& Macierz_Alokacja(int n);

    /// Wstawia wartosc `wartosc` do macierzy na pozycje (x, y).
    /// 
    /// @param x Indeks wiersza.
    /// @param y Indeks kolumny.
    /// @param wartosc Wartosc do wstawienia.
    Matrix& wstaw(int x, int y, int wartosc);

    /// Zwraca wartosc elementu macierzy na pozycji (x, y).
    /// 
    /// @param x Indeks wiersza.
    /// @param y Indeks kolumny.
    /// @return Wartosc elementu na pozycji (x, y).
    int pokaz(int x, int y);

    /// Odwraca macierz (zamienia wiersze z kolumnami).
    /// 
    /// @return Referencja do obiektu macierzy po odwroceniu.
    Matrix& Macierz_Odwroc();

    /// Wypelnia macierz losowymi wartosciami w zakresie od 0 do 9.
    /// 
    /// @return Referencja do obiektu macierzy po wypelnieniu.
    Matrix& losuj();

    /// Losuje `x` wartosci w macierzy i umieszcza je w losowych miejscach.
    /// 
    /// @param x Liczba losowanych wartosci.
    /// @return Referencja do obiektu macierzy po losowaniu.
    Matrix& losuj(int x);

    /// Ustawia wartosci na przekatnej macierzy z tablicy `t`, a pozostale elementy ustawia na 0.
    /// 
    /// @param t Tablica z danymi do ustawienia na przekatnej.
    /// @return Referencja do obiektu macierzy po ustawieniu przekatnej.
    Matrix& diagonalna(int* t);

    /// Ustawia wartosci na k-tej przekatnej macierzy z tablicy `t`, a pozostale elementy ustawia na 0.
    /// Parametr `k` okresla przesuniecie przekatnej w gore lub w dol.
    /// 
    /// @param k Przesuniecie przekatnej.
    /// @param t Tablica z danymi do ustawienia na przekatnej.
    /// @return Referencja do obiektu macierzy po ustawieniu k-tej przekatnej.
    Matrix& diagonalna_k(int k, int* t);

    /// Wstawia wartosci z tablicy `t` do kolumny o indeksie `x`.
    /// 
    /// @param x Indeks kolumny.
    /// @param t Tablica z danymi do wstawienia do kolumny.
    /// @return Referencja do obiektu macierzy po wstawieniu wartosci do kolumny.
    Matrix& kolumna(int x, int* t);

    /// Wstawia wartosci z tablicy `t` do wiersza o indeksie `y`.
    /// 
    /// @param y Indeks wiersza.
    /// @param t Tablica z danymi do wstawienia do wiersza.
    /// @return Referencja do obiektu macierzy po wstawieniu wartosci do wiersza.
    Matrix& wiersz(int y, int* t);

    /// Wypelnia macierz tak, ze 1 znajduje sie na przekatnej, a pozostale elementy to 0.
    /// 
    /// @return Referencja do obiektu macierzy po uzupelnieniu.
    Matrix& przekatna(void);

    /// Wypelnia macierz tak, ze 1 znajduje sie ponizej przekatnej, a pozostale elementy to 0.
    /// 
    /// @return Referencja do obiektu macierzy po uzupelnieniu.
    Matrix& pod_przekatna(void);

    /// Wypelnia macierz tak, ze 1 znajduje sie powyzej przekatnej, a pozostale elementy to 0.
    /// 
    /// @return Referencja do obiektu macierzy po uzupelnieniu.
    Matrix& nad_przekatna(void);

    /// Wypelnia macierz w sposob przypominajacy szachownice.
    /// 
    /// @return Referencja do obiektu macierzy po uzupelnieniu.
    Matrix& szachownica(void);

    /// Operator dodawania dwoch macierzy.
    /// 
    /// @param m Druga macierz do dodania.
    /// @return Referencja do obiektu macierzy po dodaniu.
    Matrix& operator+(Matrix& m);

    /// Operator mnozenia dwoch macierzy.
    /// 
    /// @param m Druga macierz do mnozenia.
    /// @return Referencja do obiektu macierzy po pomnozeniu.
    Matrix& operator*(Matrix& m);

    /// Operator dodawania macierzy i liczby calkowitej.
    /// 
    /// @param a Liczba calkowita do dodania.
    /// @return Referencja do obiektu macierzy po dodaniu liczby.
    Matrix& operator+(int a);

    /// Operator mnozenia macierzy przez liczbe calkowita.
    /// 
    /// @param a Liczba calkowita do pomnozenia.
    /// @return Referencja do obiektu macierzy po pomnozeniu przez liczbe.
    Matrix& operator*(int a);

    /// Operator odejmowania liczby calkowitej od macierzy.
    /// 
    /// @param a Liczba calkowita do odjecia.
    /// @return Referencja do obiektu macierzy po odjeciu liczby.
    Matrix& operator-(int a);

    /// Operator dodawania liczby calkowitej do macierzy.
    /// 
    /// @param a Liczba calkowita do dodania.
    /// @param m Macierz do ktorej dodajemy liczbe.
    /// @return Nowa macierz po dodaniu liczby.
    friend Matrix operator+(int a, Matrix& m);

    /// Operator mnozenia liczby calkowitej przez macierz.
    /// 
    /// @param a Liczba calkowita do pomnozenia.
    /// @param m Macierz, ktora mnozymy przez liczbe.
    /// @return Nowa macierz po pomnozeniu.
    friend Matrix operator*(int a, Matrix& m);

    /// Operator odejmowania liczby calkowitej od macierzy.
    /// 
    /// @param a Liczba calkowita do odjecia.
    /// @param m Macierz, od ktorej odejmujemy liczbe.
    /// @return Nowa macierz po odjeciu.
    friend Matrix operator-(int a, Matrix& m);

    /// Operator inkrementacji (zwieksza kazda liczbe w macierzy o 1).
    /// 
    /// @param a Macierz, ktora ma byc inkrementowana.
    /// @return Referencja do obiektu macierzy po inkrementacji.
    Matrix& operator++(int);

    /// Operator dekrementacji (zmniejsza kazda liczbe w macierzy o 1).
    /// 
    /// @param a Macierz, ktora ma byc dekrementowana.
    /// @return Referencja do obiektu macierzy po dekrementacji.
    Matrix& operator--(int);

    /// Operator dodawania liczby calkowitej do kazdego elementu macierzy.
    /// 
    /// @param a Liczba calkowita do dodania.
    /// @return Referencja do obiektu macierzy po dodaniu liczby.
    Matrix& operator+=(int a);

    /// Operator odejmowania liczby calkowitej od kazdego elementu macierzy.
    /// 
    /// @param a Liczba calkowita do odjecia.
    /// @return Referencja do obiektu macierzy po odjeciu liczby.
    Matrix& operator-=(int a);

    /// Operator mnozenia kazdego elementu macierzy przez liczbe calkowita.
    /// 
    /// @param a Liczba calkowita do mnozenia.
    /// @return Referencja do obiektu macierzy po mnozeniu przez liczbe.
    Matrix& operator*=(int a);

    /// Operator powiekszania macierzy o czesc ca�kowita liczby zmiennoprzecinkowej.
    /// 
    /// @param a Liczba zmiennoprzecinkowa.
    /// @return Referencja do obiektu macierzy po powiekszeniu.
    
    Matrix& operator+=(double a);

    /// Operator wypisania macierzy na ekran.
    /// 
    /// @param o Strumien wyjsciowy.
    /// @param m Macierz do wypisania.
    /// @return Strumien wyj�ciowy.
    friend std::ostream& operator<<(std::ostream& o, Matrix& m);

    /// Operator porownania macierzy.
    /// 
    /// @param m Macierz do porownania.
    /// @return `true` jesli macierze sa rowne, w przeciwnym razie `false`.
    bool operator==(const Matrix& m);

    /// Operator porownania, czy jedna macierz jest wieksza od drugiej.
    /// 
    /// @param m Macierz do porownania.
    /// @return `true` jesli wszystkie elementy macierzy sa wieksze, w przeciwnym razie `false`.
    bool operator>(const Matrix& m);

    /// Operator porownania, czy jedna macierz jest mniejsza od drugiej.
    /// 
    /// @param m Macierz do porownania.
    /// @return `true` jesli wszystkie elementy macierzy sa mniejsze, w przeciwnym razie `false`.
    bool operator<(const Matrix& m);

	/// @parm Metoda do wczytania macierzy z pliku
	/// @return Macierz�� wczytana z pliku
    Matrix& wczytaj_z_pliku(const std::string& nazwa);
};
