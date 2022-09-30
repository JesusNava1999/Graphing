/*
Estudiante: José De Jesús Nava Cuellar
Numero de Control: 18011108
Practica: Hormiguitas
Nombre del archivo: Matrix.h
*/

#ifndef Matrix_h
#define Matrix_h

#include <stdlib.h>
#include <iostream>

using namespace std;

class Matrix{
    int** matrix;  // Doble apuntador que guarda la matriz de forma dinamica
    int rows; // valor de m
    int columns; // valor de n
public:
    Matrix(int,int); // Constructor

    int read(int,int); // Funcion de lectura del valor en [n,m]
    void write(int,int,int); // Funcion de escritura de un valor x en [n,m]    

    void printMatrix(); // Funcion que imprime la matriz
    
    int circleColAdd(int); // Funcion que asigna un valor valido en un incremento de columna, dentro del rango [0...n]
    int circleRowAdd(int); // Funcion que asigna un valor valido en un incremento de fila, dentro del rango [0...m]
    int circleColRest(int); // Funcion que asigna un valor valido en un decremento de columna, dentro del rango [0...m]
    int circleRowRest(int); // Funcion que asigna un valor valido en un decremento de fila, dentro del rango [0...m]
    int circleWrite(int); // Funcion que escribe un valor valido en la coordenada [n,m], dentro del rango [0...9]

    void neighbors(int,int); // Funcion que busca las 8 coordenadas adyacentes a la nueva posicion seleccionada por el usuario
};
#endif 