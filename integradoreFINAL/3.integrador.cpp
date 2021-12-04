/*
Escribir un programa donde se solicite el tamaño del vector y reservar memoria. Luego al finalizar la ejecución del programa
liberarla.  (malloc, sizeof). El tamaño debe ser entre 1 y 10, caso contrario debe mostrar el mensaje de error y solicitar
nuevamente el ingreso de otro número. Luego crear las siguientes funciones:
rellenarVector() que rellene aleatoriamente el vector con números del 1 al 20 utilizando punteros.
mostrarVector() que muestre el vector anterior por medio de punteros los valores del vector y sus correspondientes
direcciones.
sumar() que sume los primeros “n” valores del vector de manera recursiva.
Utilizar funciones y punteros en este ejercicio.
 */
#include <iostream>
#include <ctime>

using namespace std;

int menu();

void carryArray(int *,int);

void showArray(int *,int);

void sum(int *,int);

int main(){
    int *array;
    int quantity;
    int option;

    cout << "Ingresar tamanio del vector (entre 1 y 10): " << endl;
    do {
        cin >> quantity;
        if (quantity > 10) {
            cout << "Ingresar tamanio correcto (entre 1 y 10): " << endl;
        }
    } while (quantity > 10);

    array = new int[quantity];

    do {
        option = menu();
        switch (option) {
            case 0:
                break;
            case 1:
                carryArray(array,quantity);
                break;
            case 2:
                showArray(array,quantity);
                break;
            case 3:
                sum(array,quantity);
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
    cout << "1)Cargar vector con numeros aleatorios." << endl;
    cout << "2)Mostrar vector." << endl;
    cout << "3)Sumar valores del vector." << endl;
    cin >> option;
    return option;
}

void carryArray(int *array, int quantity) {
    srand(time(NULL));

    for (int ii = 0; ii < quantity; ++ii) {
        array[ii] = rand() % 20 + 1;
    }
}

void showArray(int *array, int quantity) {

    cout << "******VALORES EN EL ARREGLO******" << endl;
    for (int ii = 0; ii < quantity; ++ii) {
        cout << "Posicion " << ii << endl;
        cout << "Valor: " << array[ii] << endl;
        cout << "Direccion de memoria: " << &array[ii] << endl;
        cout << endl;
    }
}