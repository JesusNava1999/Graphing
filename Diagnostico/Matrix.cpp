/*
Estudiante: José De Jesús Nava Cuellar
Numero de Control: 18011108
Practica: Hormiguitas
Nombre del archivo: Matrix.cpp
*/

#include <iostream>

#include "Matrix.h"

using namespace std;

Matrix::Matrix(int x, int y){   // Constructor
    columns = x;
    rows = y;
    matrix = new int*[rows];
    for (int i = 0; i <= rows; i++) {
        matrix[i] = new int[columns];
    }         
    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= columns; j++){                      
            matrix[i][j] = 0;
        }
    }
}

int Matrix::read(int col, int row){  // Funcion de lectura del valor en [n,m]
    return matrix[col][row];
}

void Matrix::write(int col, int row, int value){    // Funcion de escritura de un valor x en [n,m]  
    matrix[col][row] = value;
}

void Matrix::printMatrix(){ // Funcion que imprime la matriz
    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= columns; j++){          
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }  
} 

int Matrix::circleColAdd(int col){  // Funcion que asigna un valor valido en un incremento de columna, dentro del rango [0...n]
    int aux = col;
    if(aux>=columns){
        aux = 1;
    } else {
        aux++;
    }
    return aux;
}

int Matrix::circleRowAdd(int row){  // Funcion que asigna un valor valido en un incremento de fila, dentro del rango [0...m]
    int aux = row;
    if(aux>=rows){
        aux = 1;
    } else {
        aux++;
    }
    return aux;
}

int Matrix::circleColRest(int col){ // Funcion que asigna un valor valido en un decremento de columna, dentro del rango [0...m]
    int aux = col;
    if(aux <= 1){
        aux = columns;
    } else {
        aux--;
    }
    return aux;
}

int Matrix::circleRowRest(int row){ // Funcion que asigna un valor valido en un decremento de fila, dentro del rango [0...m]
    int aux = row;
    if(aux <= 1){
        aux = rows;
    } else {
        aux--;
    }
    return aux;
}

int Matrix::circleWrite(int wr){    // Funcion que escribe un valor valido en la coordenada [n,m], dentro del rango [0...9]
    int aux = wr;
    if(aux>=9){
        aux = 0;
    } else {
        aux++;
    }
    return aux;
}

void Matrix::neighbors(int a, int b){   // Funcion que busca las 8 coordenadas adyacentes a la nueva posicion seleccionada por el usuario
    write(circleColRest(a),circleRowRest(b),circleWrite(read(circleColRest(a),circleRowRest(b))));  // valor de (x+1) en [n-1,m-1]
    write(circleColRest(a),b,circleWrite(read(circleColRest(a),b)));    // valor de (x+1) en [n-1,m]
    write(circleColRest(a),circleRowAdd(b),circleWrite(read(circleColRest(a),circleRowAdd(b))));    // valor de (x+1) en [n-1,m+1]

    write(a,circleRowRest(b),circleWrite(read(a,circleRowRest(b))));    // valor de (x+1) en [n,m-1]
    write(a,b,circleWrite(read(a,b)));  // valor de (x+1) en [n,m]
    write(a,circleRowAdd(b),circleWrite(read(a,circleRowAdd(b))));  // valor de (x+1) en [n,m+1]

    write(circleColAdd(a),circleRowRest(b),circleWrite(read(circleColAdd(a),circleRowRest(b)))); // valor de (x+1) en [n+1,m-1]
    write(circleColAdd(a),b,circleWrite(read(circleColAdd(a),b)));  // valor de (x+1) en [n+1,m]
    write(circleColAdd(a),circleRowAdd(b),circleWrite(read(circleColAdd(a),circleRowAdd(b))));  // valor de (x+1) en [n+1,m+1]
}