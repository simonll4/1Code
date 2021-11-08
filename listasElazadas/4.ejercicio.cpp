/*
3. Elaborar un sistema de stock, en la cual posee una lista de productos con los siguientes atributos:
codigo, nombre, cantidad, precio lista. Desarrollar las siguientes funciones:

a. Mostrar el stock. (lista de productos)

b. Descontar stock.

c. Reponer stock.

hacer con estructura
*/
#include <iostream>
#include "LinkedList.h"

using namespace std;

struct Stock{
    int code;
    string name;
    int quantity;
    float priceList;
};

int menu();

void addDates(LinkedList<Stock> );

int main(){

    LinkedList<Stock> list;
    struct Stock s1;
    int option = 0;

    addDates(list);
    do {
        option = menu();
        switch (option) {
            case 0:
                break;
            case 1:

                break;
            case 2:

                break;
            case 3:

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
    cout << "1)Mostrar el stock. (lista de productos)" << endl;
    cout << "2)Descontar stock." << endl;
    cout << "3)Reponer stock." << endl;
    cin >> option;
    return option;
}

void addDates(LinkedList<Stock> list){

}