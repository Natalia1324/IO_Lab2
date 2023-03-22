#include "pch.h"

namespace MatrixTests {



    // Proste przyk³ady sprawdzeñ:
    //TEST(SampleTestCase, EqualityCheck)
    //{
    //    EXPECT_EQ(1, 2) << "Wartosc 1 nie jest równa 2.";
    //    EXPECT_TRUE(false) << "Warunek EXPECT_TRUE nie zosta³ spe³niony.";
    //    ASSERT_FALSE(true) << "Pierwsze ASSERT_FALSE zakoñczy³o siê b³êdem.";

    //    if (1 == 1)
    //    {
    //        FAIL() << "Przyklad zg³oszenia b³êdu";
    //    }

    //    ASSERT_FALSE(false) << "Drugie ASSERT_FALSE zakoñczy³o siê b³êdem.";
    //}



    /// <summary>
    /// _Przyk³adowy_ test sprawdzaj¹cy, czy liczba wierszy tworzonej macierzy 
    /// jest równa liczbie wierszy odczytanych z metody Rows
    /// </summary>
    TEST(MatrixDimensionsTest, RowsNumber)
    {
        const int rows = 2, cols = 3;
        Matrix A(rows, cols);
        int read_rows = A.Rows();

        // Przyk³ad zastosowania makra ASSERT_EQ
        ASSERT_EQ(rows, read_rows) << "Zwracana liczba wierszy nie odpowiada zadeklarowanej.";
    }

    /// <summary>
    /// _Przyk³adowy_ test sprawdzaj¹cy, czy liczba kolumn tworzonej macierzy 
    /// jest równa liczbie kolumn odczytanych z metody Columns
    /// </summary>
    TEST(MatrixDimensionsTest, ColumnsNumber)
    {
        const int rows = 2, cols = 3;
        Matrix A(rows, cols);

        // Przyk³ad zastosowania makra EXPECT_EQ
        EXPECT_EQ(cols, A.Columns()) << "Zwracana liczba kolumn nie odpowiada zadeklarowanej.";
    }

    // ---------------------------------------------------------------------------------------------
    // Przyk³ad realizacji testu parametryzowanego na podstawie klasy ::testing::TestWithParam
    // ---------------------------------------------------------------------------------------------

    /// <summary>
    /// _Przyk³adowa_ klasa przypadków testowych w oparciu o parametry
    /// </summary>
    class DimensionsTestCaseWithParam : public ::testing::TestWithParam<std::tuple<int, int>>
    {
    };
    // Parametr szablonu TestWithParam mo¿e byæ dowolnego typu,
    // jego instancja jest przekazywana do testów.

    /// <summary>
    /// _Przyk³adowy_ test realizowany w oparciu o klsaê przypadków testowych
    /// </summary>
    TEST_P(DimensionsTestCaseWithParam, DimensionsParamsTest)
    {
        auto const& params = GetParam();
        int rows = std::get<0>(params);
        int cols = std::get<1>(params);

        Matrix A(rows, cols);
        EXPECT_EQ(rows, A.Rows()) << "Zwracana liczba wierszy nie odpowiada zadeklarowanej.";
        EXPECT_EQ(cols, A.Columns()) << "Zwracana liczba kolumn nie odpowiada zadeklarowanej.";
    }

    // Uruchomienie testu z zadanym zestawem parametrów
    INSTANTIATE_TEST_CASE_P(DimensionsTest, DimensionsTestCaseWithParam, ::testing::Values(
        std::make_tuple(11, 12),
        std::make_tuple(22, 30),
        std::make_tuple(100, 100)
    ));
    // Jako parametr mo¿na oczywiœcie przekazaæ równie¿ np. spodziewany wynik operacji




    TEST(Lab2, Konstruktor_Parametryczny) {
        Matrix A(2, 3, 1.0);
        //brak inicjalizacji komorek, BLAD NR 1
        EXPECT_EQ(A.Rows(), 2);
        EXPECT_EQ(A.Columns(), 3);
        EXPECT_DOUBLE_EQ(A(0, 0), 1.0);
        EXPECT_DOUBLE_EQ(A(1, 2), 1.0);

        Matrix B(0, 0, 0);
        //mozliwosc stworzerzenia pustej macierzy BLAD NR 2
       // EXPECT_DOUBLE_EQ(B(0, 0), 1.0);
        Matrix C(1, 0);
        //mozliwosc stworzenia macierzy 1x0????
       // EXPECT_DOUBLE_EQ(C(0, 0), 1.0);
        std::initializer_list<std::initializer_list<double>> lista = { {1.0, 2.0}, {3.0} };
        Matrix D(lista);
        EXPECT_EQ(D.Rows(), 2);
        EXPECT_EQ(D(1, 1), 1);
        Matrix X(0, -2);
        //BRAK EXCEPTION THROW DLA MACIERZY (0, <0) - BLAD NR 3

    }
   
    class Lab_2_Param : public ::testing::TestWithParam<std::tuple<int, int, int>>
    {
    };



    TEST(Lab2, Konstruktor_Kopiujacy) {
        std::initializer_list<std::initializer_list<double>> lista = { {1.0, 2.0}, {3.0, 4.0} };
        Matrix A(lista);
        Matrix B(A);
        EXPECT_EQ(A.Rows(), B.Rows());
        EXPECT_EQ(A.Columns(), B.Columns());
        EXPECT_EQ(A(0, 0), B(0, 0));
        EXPECT_EQ(A(0, 1), B(0, 1));
        EXPECT_EQ(A(1, 0), B(1, 0));
        EXPECT_EQ(A(1, 1), B(1, 1));
        Matrix C(1, 3);
        Matrix D(C);
        EXPECT_EQ(C.Rows(), D.Rows());
        EXPECT_EQ(C.Columns(), D.Columns());
        EXPECT_EQ(C(0, 0), D(0, 0));
        EXPECT_EQ(C(0, 1), D(0, 1));
        EXPECT_EQ(C(0, 2), D(0, 2));

    }

    TEST(Lab2, Dodawanie_Odejmowanie_Equal) {
        Matrix A(2, 2);
        Matrix B = { {1.0, 2.0}, {3.0, 4.0} };
        A += B;
        EXPECT_TRUE(A == B);
        A -= B; //FUNKCJA ODEJMUJACA W PRAKTYCE DODAJE - BLAD NR 4
        Matrix C(2, 2);
        EXPECT_TRUE(A==C);
    }
    TEST(Lab2, Konstruktor_Kopiujacy_Wskaznik) {
        Matrix A(7, 7);
        Matrix B(A);
        auto a = &A(0, 0);
        auto b = &B(0, 0);
        EXPECT_FALSE(a == b);
    }
    TEST(Lab2, Konstruktor_Inicjalizacji) {
        std::initializer_list<std::initializer_list<double>> lista = { {1.0, 2.0}, {3.0, 4.0} };
        Matrix A(lista);
        EXPECT_TRUE(A(0, 0) == 1.0);
        EXPECT_TRUE(A(0, 1) == 2.0);
        EXPECT_TRUE(A(1, 0) == 3.0);
        EXPECT_TRUE(A(1, 1) == 4.0);
    }
    TEST(Lab2, Operator_Porownania) {
        std::initializer_list<std::initializer_list<double>> lista = { {1.0, 2.0}, {3.0, 4.0} };
        Matrix A(lista);
        Matrix B(2, 2);
        EXPECT_FALSE(B == A);
        Matrix C = { {1.0, 2.0}, {3.0, 4.0} };
        EXPECT_TRUE(A == C);
    }

    TEST(Lab2, Konstruktor_Inicjalizacji_Zerowy) {
        std::initializer_list<std::initializer_list<double>> lista = { {}, {} };
        Matrix A(lista);
        //Tworzenie macierzy pustej z listy?
    }


    TEST_P(Lab_2_Param, Konstruktor_Kopiujacy_P) {
        auto const& params = GetParam();
        Matrix A(std::get<0>(params), std::get<1>(params));
        Matrix B(A);
        EXPECT_EQ(A.Rows(), B.Rows()) << "Liczba wierszy nie zgadza sie";
        EXPECT_EQ(A.Columns(), B.Columns()) << "Liczba kolumn nie zgadza sie";
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                EXPECT_EQ(A(i, j), B(i, j)) << "Elementy macierzy nie zgadzają sie";
            }
        }
    }

    TEST(Lab2, Operator_Przypisania) {
        Matrix A(7, 7);
        Matrix B = A;
        
        EXPECT_EQ(A.Rows(), B.Rows());
        EXPECT_EQ(A.Columns(), B.Columns());
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                EXPECT_EQ(A(i, j), B(i, j)) << "Elementy macierzy nie zgadzają sie";
            }
        }
        Matrix C = { {3,3} };
        C = A;
        EXPECT_EQ(A.Rows(), C.Rows());
        EXPECT_EQ(A.Columns(), C.Columns());
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                EXPECT_EQ(A(i, j), C(i, j));
            }
        }
    }

    TEST(Lab2, Operator_Nawiasow) {
        Matrix A(2, 2);
        for (int i = 0; i < A.Rows(); i++)
        {
            for (int j = 0; j < A.Columns(); j++)
            {
                auto val = A(i, j);
                EXPECT_EQ(val, 0);
            }
            std::cout << std::endl;
        }
    }
    TEST(Lab2, Operator_Przypisania_Wskaznik) {
        Matrix A(7, 7);
        Matrix B(A);
        auto a = &A(0, 0);
        auto b = &B(0, 0);
        EXPECT_FALSE(a == b);
    }

    TEST_P(Lab_2_Param, Operator_Przypisania) {
        auto const& params = GetParam();
        Matrix A(std::get<0>(params), std::get<1>(params));
        Matrix B = A;
        EXPECT_EQ(A.Rows(), B.Rows()) << "Liczba wierszy nie zgadza sie";
        EXPECT_EQ(A.Columns(), B.Columns()) << "Liczba kolumn nie zgadza sie";
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                EXPECT_EQ(A(i, j), B(i, j)) << "Elementy macierzy nie zgadzają sie";
            }
        }
        EXPECT_TRUE(A == B);
    }

    TEST(Lab2, Dodawanie) {
        Matrix A = { {1.0, 2.0}, {3.0, 4.0} };
        Matrix B = { {1.0, 1.0}, {1.0, 1.0} };

        Matrix wynik = A + B;

        EXPECT_EQ(wynik.Rows(), 2);
        EXPECT_EQ(wynik.Columns(), 2);
        EXPECT_DOUBLE_EQ(wynik(0, 0), 2.0);
        EXPECT_DOUBLE_EQ(wynik(1, 1), 5.0);
    }

    TEST(Lab2, Odejmowanie) {
        Matrix A = { {1.0, 2.0}, {3.0, 4.0} };
        Matrix B = { {1.0, 1.0}, {1.0, 1.0} };

        Matrix wynik = A - B;

        EXPECT_EQ(wynik.Rows(), 2);
        EXPECT_EQ(wynik.Columns(), 2);
        EXPECT_DOUBLE_EQ(wynik(0, 0), 0.0);
        EXPECT_DOUBLE_EQ(wynik(1, 1), 3.0);
        //NIEPOPRAWNE WYNIKI ODEJMOWANIA - BLAD 5
    }
    
    TEST(Lab2, Mnozenie) {
  
        //mnozenie nie dziala poniewaz konstruktor parametryczny nie dziala!
        Matrix D = { {1.0, 2.0}, {3.0, 4.0} };
        Matrix E = { {1.0, 1.0}, {1.0, 1.0} };
        Matrix Delta(D);
        Matrix Epsilon(E);
        Matrix wynik1 = D * E;
        EXPECT_DOUBLE_EQ(wynik1(0, 0), 3.0);
        EXPECT_DOUBLE_EQ(wynik1(0, 1), 3.0);
        EXPECT_DOUBLE_EQ(wynik1(1, 0), 7.0);
        EXPECT_DOUBLE_EQ(wynik1(1, 1), 7.0);
        EXPECT_TRUE(D == Delta);
        EXPECT_TRUE(E == Epsilon);

        Matrix X = { {} };
        X.ToString(); //Macierz zerowa 1x2

        Matrix F = { {1.0}, {3.0,4.0} }; //nielegalna macierz??? - BLAD NR 6
        Matrix G = { {1.0, 1.0}, {1.0, 1.0} };
        // Matrix wynik2 = F * G;
        //wyrzuca dimensions mismatch 

        EXPECT_EQ(F.Columns(), 2);
        //EXPECT_DOUBLE_EQ(F(1, 1), 4.0); - NIEZGODNOSC Z TO.STRING()    BLAD NR 7
        EXPECT_EQ(F.Rows(), 2);

    }

    TEST_P(Lab_2_Param, Mnozenie) {
        auto const& params = GetParam();
        int x = std::get<0>(params);
        int y = std::get<1>(params);
        int z = std::get<2>(params);
        Matrix A(x, y, z);
        Matrix B(y, x, z);
        Matrix C((A * B));
        EXPECT_DOUBLE_EQ(C(0, 0), (y * z * z));


    }

    //TEST(Lab2, Inicjalizacja) {
    //    Matrix A(1, 2, 3.0);
    //    EXPECT_TRUE(A(0, 0) == 3.0);
    //    EXPECT_TRUE(A(0, 1) == 3.0);
    //}

    TEST(Lab2, Wyznacznik) {
        Matrix B(4, 4, 7.0);
        EXPECT_EQ(B.Det(), 0);
        std::initializer_list<std::initializer_list<double>> lista = { {1.0, 2.0}, {3.0, 4.0} };
        Matrix A(lista);
        EXPECT_EQ(A.Det(), -2);
        std::initializer_list<std::initializer_list<double>> lista2 = { {1} };
        Matrix C(lista2);
        EXPECT_EQ(C.Det(), 1);
        std::initializer_list<std::initializer_list<double>> lista3 = { {1.0, 2.0}, {3.0} };
        Matrix D(lista3);
        Matrix E(D);
        EXPECT_EQ(D.Det(), 0);
        //LICZENIE WYZNACZNIKA DLA NIEKWADRATOWYCH MACIERZY - BLAD 8
        EXPECT_TRUE(E == D);
        //FUNKCJA DET() NADPISUJE MACIERZ BLEDNYMI DANYMI! - BLAD 9
    }

    //TEST(Lab2, Destruktor) {
    //    Matrix* A = new Matrix(2,2);
    //    EXPECT_FALSE(A == nullptr);
    //    delete A;
    //    EXPECT_TRUE(A == nullptr);
    //}


}
