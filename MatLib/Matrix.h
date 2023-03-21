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
    /// Tworzy macierz o zadanej liczbie wierszy i kolumn, inicjalizowan¹ zadan¹ wartoœci¹.
    /// Generuje wyj¹tek w przypadku próby utworzenia macierzy o wymiarach < 0.
    /// </summary>
    /// <param name="rows">Liczba wierszy.</param>
    /// <param name="cols">Liczba kolumn.</param>
    /// <param name="initializer">Pocz¹tkowa wartoœæ elementów macierzy.</param>
    Matrix(int rows, int cols, double initializer = 0.0) throw(std::invalid_argument);

    /// <summary>
    /// Tworzy macierz w oparciu o listê inicjalizacyjn¹.
    /// </summary>
    Matrix(std::initializer_list<std::initializer_list<double>>);

    /// <summary>
    /// Konstruktor kopiuj¹cy
    /// </summary>
    Matrix(const Matrix&);

    ~Matrix();

    /// <summary>
    /// Zwraca liczbê kolumn macierzy.
    /// </summary>
    inline int Columns() const noexcept;

    /// <summary>
    /// Zwraca liczbê wierszy macierzy.
    /// </summary>
    inline int Rows() const noexcept;


    /// <summary>
    /// Operator przypisania.
    /// </summary>
    Matrix& operator=(const Matrix&);

    /// <summary>
    /// Zapewnia dostêp do elementu macierzy dla zadanych indeksów.
    /// Generuje wyj¹tek std::out_of_range przy wyjœciu poza zakres.
    /// </summary>
    /// <param name="row">Indeks wiersza.</param>
    /// <param name="col">Indeks kolumny.</param>
    /// <returns>Element macierzy pod wskazanym indeksem.</returns>
    inline double& operator()(int row, int col) throw(std::out_of_range);

    /// <summary>
    /// Operator porównania. 
    /// </summary>
    bool operator==(const Matrix&) const;

    /// <summary>
    /// Dodaje do elementów pierwszej macierzy (na rzecz której operator zosta³ wywo³any),
    /// odpowiednie elementy drugiej macierzy (przekazanej jako parametr).
    /// </summary>
    Matrix& operator+=(const Matrix& m) throw(std::invalid_argument);

    /// <summary>
    /// Odejmuje do elementów pierwszej macierzy (na rzecz której operator zosta³ wywo³any),
    /// odpowiednie elementy drugiej macierzy (przekazanej jako parametr).
    /// </summary>
    Matrix& operator-=(const Matrix& m) throw(std::invalid_argument);

    /// <summary>
    /// Realizuje operacjê dodawania macierzy.
    /// </summary>
    Matrix operator+(const Matrix& m) const throw(std::invalid_argument);

    /// <summary>
    /// Realizuje operacjê odejmowania macierzy.
    /// </summary>
    Matrix operator-(const Matrix& m) const throw(std::invalid_argument);

    /// <summary>
    /// Operator, w wyniku zwraca macierz bêd¹c¹ wynikiem mno¿enia przez macierz.
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

