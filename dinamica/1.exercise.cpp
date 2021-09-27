/*
 * 1. Crear un programa que pregunte al usuario cuántos caracteres desea introducir,
 * reserve espacio para dicho número de caracteres, le permita al usuario introducirlos
 * desde teclado. Por último se los muestre todos seguidos y en el orden inverso al que
 * fueron introducidos. Crear funciones para cargar, mostrar en orden y mostrar en orden inverso.
 */

#include <iostream>

using namespace std;

void addNums(int *, int);

void printInverse(int *, int);

void printNormal(int *, int);

int main() {

    int cant = 0;
    int *nums;


    cout << "Cantidad de numeros a ingresar:" << endl;
    cin >> cant;

    nums = new int[cant];


    delete nums;
    return 0;
}

void addNums(int *nums, int cant) {

    cout << "ingresar numeros:" << endl;
    for (int ii = 0; ii < cant; ii++) {
        cin >> nums[ii];
    }

}

void printInverse(int *nums, int cant) {

    cout << "impresion de numero de manera inversa a lo ingresado: " << endl;
    for (int ii = 0; ii < cant; ii++) {
        cout << nums[cant - (ii + 1)] << "\t";
    }

}

void printNormal(int *nums, int cant) {

    cout << "impresion de numeros normal: " << endl;
    for (int ii = 0; ii < cant; ii++) {
        cout << nums[cant] << "\t";
    }

}