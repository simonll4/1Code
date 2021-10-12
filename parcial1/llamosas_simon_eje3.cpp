#include <iostream>

using namespace std;

int menu();

int *inDatos(int *, int &);

int *nuevosDatos(int *, int &);

void mostrarDatos(int *, int &);

int main() {
    int option = 0;
    int *numeros, cantidad;

    cout << "Definir el tamanio del vector de numeros: " << endl;
    cin >> cantidad;

    do {
        option = menu();
        switch (option) {
            case 0:
                break;
            case 1:
                numeros = new int[cantidad];
                numeros = inDatos(numeros, cantidad);
                cout << endl;
                break;
            case 2:
                numeros = nuevosDatos(numeros, cantidad);
                cout << endl;
                break;
            case 3:
                mostrarDatos(numeros, cantidad);
                break;
            default:
                cout << "Ingrese una opcion correcta por favor" << endl;
        }
    } while (option != 0);

    return 0;
}

int menu() {
    int option;
    cout << endl;
    cout << "OPERACIONES:" << endl;
    cout << "0)Salir." << endl;
    cout << "1)Introduccion de datos enteros" << endl;
    cout << "2)Agregar memoria y nuevos datos enteros" << endl;
    cout << "3)Mostrar datos" << endl;
    cin >> option;
    return option;
}

int *inDatos(int *numeros, int &cantidad) {

    cout << "**INGRESAR DATOS**" << endl;
    for (int ii = 0; ii < cantidad; ++ii) {
        cin >> numeros[ii];
    }
    return numeros;
}

int *nuevosDatos(int *numeros, int &cantidad) {
    int *temp;
    int cantidad2 = 0;

    cout << "Ingrese cantidad de enteros agregar: " << endl;
    cin >> cantidad2;

    temp = new int[cantidad + cantidad2];
    for (int ii = 0; ii < cantidad; ++ii) {
        temp[ii] = numeros[ii];
    }

    cout << "Ingresar nuevos datos: " << endl;
    for (int ii = cantidad; ii < cantidad + cantidad2; ii++) {
        cin >> temp[ii];
    }
    delete numeros;
    cantidad += cantidad2;

    return temp;

}

void mostrarDatos(int *numeros, int &cantidad) {

    cout << endl;
    cout << "Impresion de manera normal: " << endl;
    for (int ii = 0; ii < cantidad; ii++) {
        cout << numeros[ii] << "\t";
    }

    cout << endl;
    cout << "Impresion de manera inversa: " << endl;
    for (int ii = 0; ii < cantidad; ii++) {
        cout << numeros[cantidad - (ii + 1)] << "\t";
    }
}