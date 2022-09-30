/*
Estudiante: José De Jesús Nava Cuellar
Numero de Control: 18011108
Practica: Hormiguitas
Nombre del archivo: main.cpp
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Matrix.h"

using namespace std;

int circleCA(int,int);  // Funcion que asigna un valor valido en un incremento de columna, dentro del rango [0...n]
int circleCR(int,int);  // Funcion que asigna un valor valido en un decremento de columna, dentro del rango [0...m]
int circleRA(int,int);  // Funcion que asigna un valor valido en un incremento de fila, dentro del rango [0...m]
int circleRR(int,int);  // Funcion que asigna un valor valido en un decremento de fila, dentro del rango [0...m]

int main(){
    int opc=0;
    srand(time(NULL));
    int x,y;
    cout << "Type n: ";
    cin >> x;
    cout << "Type m: ";
    cin >> y;
    cout << "Cols: " << x << "\tRows: " << y << endl;

    Matrix matrix(x,y);
    matrix.printMatrix();

    int r1 = (rand() % x) + 1;  // Valor aleatorio con rango de [0...n]
    int r2 = (rand() % y) + 1;  // Valor aleatorio con rango de [0...m]  
    matrix.write(r1,r2,matrix.read(r1,r2)+1);   // Itera en los aleatorios de n y m en +1 
    
    cout << "\nInicial position: [" << r2 << "," << r1 << "]" << endl;

    do{       // Menu
        system("cls");
        cout << "\nReal position: [" << r2 << "," << r1 << "]" << endl;
        matrix.printMatrix();
        opc = 0;
        cout << "\nType your movement" << endl;
        cout << "1.- Go Up" << endl;
        cout << "2.- Go Down" << endl;
        cout << "3.- Go Right" << endl;
        cout << "4.- Go Left" << endl;
        cout << "5.- End Program" << endl;
        cin >> opc;
        switch (opc){
            case 1: 
                matrix.neighbors(circleRR(y,r1-1),r2);
                r1 = circleRR(y,r1-1);                
                break;  
            case 2: 
                matrix.neighbors(circleRA(y,r1+1),r2);
                r1 = circleRA(y,r1+1);
                break;  
            case 3: 
                matrix.neighbors(r1,circleCA(x,r2+1));
                r2 = circleCA(x,r2+1);
                break;  
            case 4:
                matrix.neighbors(r1,circleCR(x,r2-1));
                r2 = circleCR(x,r2-1);
                break;
            case 5:
                cout << "Good Bye" << endl; 
                break;              
            default:
                cout << "Choose one option upside" << endl;
                break;
        }
    }while(opc!=5);

    return EXIT_SUCCESS;
}

int circleCA(int c, int x){ // Funcion que asigna un valor valido en un incremento de columna, dentro del rango [0...n]
    if(x>c){
        return 1;
    } else {
        return x;
    }
}

int circleCR(int c, int x){ // Funcion que asigna un valor valido en un decremento de columna, dentro del rango [0...m]
    if(x<1){
        return c;
    } else {
        return x;
    }
}

int circleRA(int r, int y){ // Funcion que asigna un valor valido en un incremento de fila, dentro del rango [0...m]
    if(y>r){
        return 1;
    } else {
        return y;
    }
}

int circleRR(int r, int y){ // Funcion que asigna un valor valido en un decremento de fila, dentro del rango [0...m]
    if(y<1){
        return r;
    } else {
        return y;
    }
}