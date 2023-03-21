#pragma once
#pragma warning( disable : 4290 )

#ifdef MATLIB_EXPORTS
#define MATLIB_API __declspec(dllexport)
#else
#define MATLIB_API __declspec(dllimport)
#endif

#include <string>
#include <stdexcept>

class MATLIB_API Matrix
{
protected:
    int rows;
    int cols;
    double** tab;

public:
    /// <summary>
    /// Tworzy macierz o zadanej liczbie wierszy i kolumn, inicjalizowan� zadan� warto�ci�.
    /// Generuje wyj�tek w przypadku pr�by utworzenia macierzy o wymiarach < 0.
    /// </summary>
    /// <param name="rows">Liczba wierszy.</param>
    /// <param name="cols">Liczba kolumn.</param>
    /// <param name="initializer">Pocz�tkowa warto�� element�w macierzy.</param>
    Matrix(int rows, int cols, double initializer = 0.0) throw(std::invalid_argument);

    /// <summary>
    /// Tworzy macierz w oparciu o list� inicjalizacyjn�.
    /// </summary>
    Matrix(std::initializer_list<std::initializer_list<double>>);

    /// <summary>
    /// Konstruktor kopiuj�cy
    /// </summary>
    Matrix(const Matrix&);

    ~Matrix();

    /// <summary>
    /// Zwraca liczb� kolumn macierzy.
    /// </summary>
    inline int Columns() const noexcept;

    /// <summary>
    /// Zwraca liczb� wierszy macierzy.
    /// </summary>
    inline int Rows() const noexcept;


    /// <summary>
    /// Operator przypisania.
    /// </summary>
    Matrix& operator=(const Matrix&);

    /// <summary>
    /// Zapewnia dost�p do elementu macierzy dla zadanych indeks�w.
    /// Generuje wyj�tek std::out_of_range przy wyj�ciu poza zakres.
    /// </summary>
    /// <param name="row">Indeks wiersza.</param>
    /// <param name="col">Indeks kolumny.</param>
    /// <returns>Element macierzy pod wskazanym indeksem.</returns>
    inline double& operator()(int row, int col) throw(std::out_of_range);

    /// <summary>
    /// Operator por�wnania. 
    /// </summary>
    bool operator==(const Matrix&) const;

    /// <summary>
    /// Dodaje do element�w pierwszej macierzy (na rzecz kt�rej operator zosta� wywo�any),
    /// odpowiednie elementy drugiej macierzy (przekazanej jako parametr).
    /// </summary>
    Matrix& operator+=(const Matrix& m) throw(std::invalid_argument);

    /// <summary>
    /// Odejmuje do element�w pierwszej macierzy (na rzecz kt�rej operator zosta� wywo�any),
    /// odpowiednie elementy drugiej macierzy (przekazanej jako parametr).
    /// </summary>
    Matrix& operator-=(const Matrix& m) throw(std::invalid_argument);

    /// <summary>
    /// Realizuje operacj� dodawania macierzy.
    /// </summary>
    Matrix operator+(const Matrix& m) const throw(std::invalid_argument);

    /// <summary>
    /// Realizuje operacj� odejmowania macierzy.
    /// </summary>
    Matrix operator-(const Matrix& m) const throw(std::invalid_argument);

    /// <summary>
    /// Operator, w wyniku zwraca macierz b�d�c� wynikiem mno�enia przez macierz.
    /// </summary>
    Matrix operator*(const Matrix&) const throw(std::invalid_argument);

    /// <summary>
    /// Zwraca wyznacznik macierzy.
    /// </summary>
    double Det() const throw(std::domain_error);

    /// <summary>
    /// Zwraca macierz w postaci tekstowej.
    /// </summary>
    std::string ToString() const noexcept;

};

