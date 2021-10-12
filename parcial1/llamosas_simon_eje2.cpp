#include <iostream>
#include <ctime>

#define SIZE 5

using namespace std;

void cargaVector(int *);

int menu();

void mostrar(int *);

void mayorMenor(int *);

void sumaPares(const int *);

int main() {
    int vector[SIZE] = {0};
    int option = 0;

    cargaVector(vector);

    do {
        option = menu();
        switch (option) {
            case 0:
                break;
            case 1:
                mostrar(vector);
                break;
            case 2:
                mayorMenor(vector);
                break;
            case 3:
                sumaPares(vector);
                break;
            default:
                cout << "Ingrese una opcion correcta por favor" << endl;
        }
    } while (option != 0);


    return 0;
}

void cargaVector(int *vector) {
    srand(time(NULL));

    for (int ii = 0; ii < SIZE; ++ii) {
        vector[ii] = rand() % 9 + 1;
    }

}

int menu() {
    int option;
    cout << endl;
    cout << "OPERACIONES:" << endl;
    cout << "0)Salir." << endl;
    cout << "1)Mostrar valores y direcciones de memoria" << endl;
    cout << "2)Mostrar el numero mayor y el menor" << endl;
    cout << "3)Suma de los valores pares" << endl;
    cin >> option;
    return option;
}

void mostrar(int *vector) {
    cout << "**VALORES DEL ARREGLO Y SUS DIRECCIONES DE MEMORIA**" << endl;
    for (int ii = 0; ii < SIZE; ++ii) {
        cout << vector[ii] << "\t";
        cout << &vector[ii] << endl;
    }
    cout << endl;


}

void mayorMenor(int *vector) {
    int aux1;
    int aux2;

    aux1 = vector[0];
    aux2 = vector[0];
    for (int ii = 0; ii < SIZE; ++ii) {
        if (aux1 < vector[ii]) {
            aux1 = vector[ii];
        }
        if (aux2 > vector[ii]) {
            aux2 = vector[ii];
        }

    }
    cout << "El numero mayor del arreglo es: " << aux1 << endl;
    cout << "El numero menor del arreglo es: " << aux2 << endl;
}

void sumaPares(const int *vector) {
    int suma = 0;

    for (int ii = 0; ii < SIZE; ++ii) {
        if (vector[ii] % 2 == 0) {
            suma += vector[ii];
        }
    }
    cout << "La suma de los valores pares es: " << suma << endl;
}