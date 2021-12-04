/*
 * Escribir un programa que cree un vector de 5 valores aleatorios entre el 1 al 10.
 * Luego crear las siguientes funciones:
Mostrar todos los valores del vector anterior por medio de punteros.
Mostrar los valores mayores a 5 por medio de punteros y su correspondiente dirección.
Calcular la sumatoria de los valores.
Guardar en un archivo los resultados anteriores (los puntos a, b y c)
Utilizar funciones y punteros en este ejercicio.
 */
#include <iostream>
#include <ctime>
#include <fstream>

#define TAM 5

using namespace std;

int menu();

void carryNums(int *);

void showValues(int *);

void showValues5(int *);

void sum(int const *);

void saveFile(int *);

int main() {
    int array[TAM] = {0};
    int option;

    carryNums(array);

    do {
        option = menu();
        switch (option) {
            case 0:
                break;
            case 1:
                showValues(array);
                break;
            case 2:
                showValues5(array);
                break;
            case 3:
                sum(array);
                break;
            case 4:
                saveFile(array);
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
    cout << "1)Mostrar valores." << endl;
    cout << "2)Mostrar valores mayores a 5." << endl;
    cout << "3)Sumatoria de los valores." << endl;
    cout << "4)Guardar todo en archivo." << endl;
    cin >> option;
    return option;
}

void carryNums(int *array) {
    srand(time(NULL));

    for (int ii = 0; ii < TAM; ++ii) {
        array[ii] = rand() % 10 + 1;
    }

}

void showValues(int *array) {

    cout << "*********Valores aleatorios guardados en el vector******" << endl;
    for (int ii = 0; ii < TAM; ++ii) {
        cout << array[ii] << "\t";
    }
}

void showValues5(int *array) {

    cout << "********* VALORES MAYORES A 5 ******" << endl;
    for (int ii = 0; ii < TAM; ++ii) {
        if (array[ii] >= 5) {
            cout << "Posicion: " << ii << endl;
            cout << "Valor: " << array[ii] << endl;
            cout << "Posicion de memoria: " << &array[ii] << endl;
            cout << endl;
            cout << endl;
        }
    }
}

void sum(int const *array) {
    int sum = 0;

    for (int ii = 0; ii < TAM; ++ii) {
        sum += array[ii];
    }
    cout << "Suamtoria total: " << sum << endl;
}

void saveFile(int *array) {
    ofstream f1;

    f1.open("operacionesArreglo.txt");

    f1 << "*********Valores aleatorios guardados en el vector******" << endl;
    for (int ii = 0; ii < TAM; ++ii) {
        cout << array[ii] << "\t";
    }

    f1 << "********* VALORES MAYORES A 5 ******" << endl;
    for (int ii = 0; ii < TAM; ++ii) {
        if (array[ii] >= 5) {
            f1 << "Posicion: " << ii << endl;
            f1 << "Valor: " << array[ii] << endl;
            f1 << "Posicion de memoria: " << &array[ii] << endl;
            f1 << endl;
            f1 << endl;
        }


    }

    int sum = 0;
    for (int ii = 0; ii < TAM; ++ii) {
        sum += array[ii];
    }
    f1 << "Suamtoria total: " << sum << endl;

    f1.close();

}