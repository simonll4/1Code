/*
 * 1. Escribir un programa donde se solicite el tamaño del vector (entre 5 y 10) y
 * reservar memoria. Luego al finalizar la ejecucion del programa liberarla. Luego crear las siguientes funciones:

- cargarNumero(), que rellene aleatoriamente el vector con números entre el 1 y 10 utilizando punteros.

- mostrarNumero(), que muestre el vector anterior por medio de punteros los valores del vector y
 las direcciones en las cuales los valores sean mayores a 5 inclusive.

- sumarNumero() que sume todos los números del vector de manera recursiva.
 */
#include <iostream>
#include <ctime>

int menu();

using namespace std;



int *addNums(int *, int &);

void showNums(int *, int &);

int sumNums(int *, int);

int main() {

    int option = 0, quantity = 0;
    int *numbers;
    int sum = 0;

    cout << "Definir el tamanio del vector numero: " << endl;
    cin >> quantity;


    do {
        option = menu();
        switch (option) {
            case 0:
                break;
            case 1:
                numbers = new int[quantity];
                numbers = addNums(numbers, quantity);
                break;
            case 2:
                showNums(numbers, quantity);
                break;
            case 3:
                sum = sumNums(numbers, quantity);
                cout << "la suma es: " << sum;
                break;
            default:
                cout << "Ingrese una opcion correcta por favor" << endl;
        }

    } while (option != 0);

    delete numbers;

    return 0;
}

int menu() {
    int option;
    cout << endl;
    cout << "OPERACIONES:" << endl;
    cout << "0)Salir." << endl;
    cout << "1)Cargar numero" << endl;
    cout << "2)Mostrar numero" << endl;
    cout << "3)Sumar numero" << endl;
    cin >> option;
    return option;
}

int *addNums(int *array, int &quantity) {
    srand(time(NULL));


    for (int ii = 0; ii < quantity; ii++) {
        array[ii] = rand() % 10;
        cout << array[ii] << endl;
    }
    return array;
}

void showNums(int *array, int &quantity) {

    cout << "numeros ingresador aleatoriamente en el vector:" << endl;
    for (int ii = 0; ii < quantity; ii++) {
        cout << array[ii] << endl;
        cout << endl;
        if (array[ii] >= 5) {
            cout << "POSICION DE MEMORIA DEL NUM: " << ii + 1;
            cout << &array[ii] << endl;
            cout << endl;
        }
    }

}

int sumNums(int *array, int quantity) {

    if (quantity == 0) {
        return 0;
    } else {
        return array[quantity - 1] + sumNums(array, quantity - 1);
    }

}