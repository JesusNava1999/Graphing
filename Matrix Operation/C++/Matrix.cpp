#include "Matrix.h"

using namespace std;

Matrix::Matrix(int x, int y){
    rowSize = x;
    colSize = y;
    matrix = new int* [colSize];
    for (int i = 0; i < colSize; i++){
        matrix[i] = new int[rowSize];
    }
    for (int i = 0; i < colSize; i++){
        for (int j = 0; j < rowSize; j++){
            matrix[i][j] = 0;
        }
    }
}
Matrix::Matrix(int** m, int x, int y){    
    rowSize = y;
    colSize = x;
    matrix = new int* [colSize];
    for (int i = 0; i < colSize; i++){
        matrix[i] = new int[rowSize];
    }
    for (int i = 0; i < colSize; i++){
        for (int j = 0; j < rowSize; j++){
            matrix[i][j] = m[i][j];
        }
    }
}

int Matrix::getRowSize(){
    return rowSize;
}

int Matrix::getColSize(){
    return colSize;
}

int** Matrix::getMatrix(){
    return matrix;
}

void Matrix::setMatrix(int** m){
    matrix = m;
}

void Matrix::printMatrix(){
    for (int i = 0; i < colSize; i++){
        for (int j = 0; j < rowSize; j++){
            cout << matrix[i][j];
        }
        cout << endl;
    }
}