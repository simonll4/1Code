/*
 * 3. Crear un programa en la cual contenga un menú de opciones con distintas operaciones:

            a. Reserva de memoria e introducción de datos enteros

            b. Agregar reserva de memoria e introducción de nuevos datos enteros

            c. Mostrar los datos en el orden y orden invertido al que fueron introducidos
 */

#include <iostream>

using namespace std;

int menu();

int *nums(int *, int &);

int *addNums(const int *, int &);

void printDates(int *, int &);

int main() {

    int option = 0, quantity = 0;
    int *numbers;

    do {
        option = menu();
        switch (option) {
            case 0:
                break;
            case 1:
                numbers = nums(numbers, quantity);
                break;
            case 2:
                numbers = addNums(numbers, quantity);
                break;
            case 3:
                printDates(numbers, quantity);
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
    cout << "OPERACIONES:" << endl;
    cout << "0)Salir." << endl;
    cout << "1)Reserva de memoria e introduccion de datos enteros" << endl;
    cout << "2)Agregar reserva de memoria e introduccion de nuevos datos enteros" << endl;
    cout << "3)Mostrar los datos en el orden y orden invertido al que fueron introducidos" << endl;
    cin >> option;
    return option;
}

int *nums(int *array, int &quantity) {

    cout << "Cantidad de datos a ingresar: " << endl;
    cin >> quantity;
    array = new int[quantity];

    cout << "Ingresar numeros enteros: " << endl;
    for (int ii = 0; ii < quantity; ii++) {
        cin >> array[ii];
    }
    return array;
}

int *addNums(const int *array, int &quantity) {

    int *temp;
    int quant_add = 0;

    cout << "Ingrese cantidad de enteros agregar: " << endl;
    cin >> quant_add;
    quantity += quant_add;

    temp = new int[quantity];
    for (int ii = 0; ii < quantity; ii++) { //copio vector viejo en uno temporal
        temp[ii] = array[ii];
    }
    delete array; //devuelvo espacio en memoria pedido antes

    cout << "Ingrese datos nuevamente: " << endl;
    for (int ii = 0; ii < quantity; ii++) {
        cin >> temp[ii];
    }

    return temp;
}

void printDates(int *array, int &quantity) {
    cout << "Impresion de manera normal: " << endl;
    for (int ii = 0; ii < quantity; ii++) {
        cout << array[ii] << "\t";
    }

    cout << "Impresion de manera inversa: " << endl;
    for (int ii = 0; ii < quantity; ii++) {
        cout << array[quantity - (ii + 1)] << "\t";
    }

}