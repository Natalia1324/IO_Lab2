#include <iostream>
#include <stdexcept>
#include <conio.h>
#include "Matrix.h"

int main()
{
    Matrix A(2, 3, 0.5);
    int rows = A.Rows();
    int cols = A.Columns();

    std::cout << A.ToString() << std::endl;

    for (int i = 0; i < A.Rows(); i++) 
    {
        for (int j = 0; j < A.Columns(); j++)
        {
            auto val = A(i, j);
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < A.Rows(); i++)
    {
        for (int j = 0; j < A.Columns(); j++)
        {
            A(i, j) = (i + 1) * (j + 1);
        }
        std::cout << std::endl;
    }
    std::cout << A.ToString() << std::endl;

    Matrix M1{ {1, 2}, {3, 4}, {5, 6} };
    std::cout << M1.ToString() << std::endl;

    //Matrix C(2, 2);
    //Matrix B = { {1.0, 2.0}, {3.0, 4.0} };
    //C += B;
    //std::cout << C.ToString() << std::endl;
    //C -= B;
    //std::cout << C.ToString();

    Matrix B = { {1.0, 2.0}, {3.0, 4.0} };
    Matrix Beta(B);
    B.Det();

    std::cout << B.ToString() << std::endl;
    std::cout << Beta.ToString();

    //Matrix X = { {1.0, 4.0, 3.0} };
    //Matrix Y = { {1.0, 2.0}, {4.0,2.0}, {3.0,2.0} };
    Matrix X(5, 5);
    Matrix Y(5, 7);
    Matrix wynik5 = X * Y;

    std::cout << wynik5.ToString();


    std::cout << "Press any key..." << std::endl;
    _getch();

    return 0;
}