#ifndef Matrix_h
#define Matrix_h

#include <iostream>
#include <stddef.h>

class Matrix {
    int** matrix;
    int rowSize;
    int colSize;
public:
    Matrix(int,int);
    Matrix(int**,int,int);

    int getRowSize();
    int getColSize();
    int** getMatrix();
    void setMatrix(int**);

    void printMatrix();
};
#endif