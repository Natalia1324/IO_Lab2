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

    std::cout << "Press any key..." << std::endl;
    _getch();

    return 0;
}