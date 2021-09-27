/*
 * 2. Escribir un programa utilizando punteros y funciones en la cual se desea cargar en un vector con
 * las ventas diarias de un negocio, 3 como máximo. La carga finaliza cuando el monto igual a cero.
 * Crear una estructura Factura, en donde tenga los siguientes atributos: numero, fecha y monto total.
 * Además, se pide:

 - Cantidad de ventas cargadas.

- Calcular la recaudación del día de manera recursiva.

- Guardar los datos en un archivo.
 */
#include <iostream>
#include <string>
#include <fstream>

#define SIZE 2

using namespace std;

struct Facture {

    int number = 0;
    string date = " ";
    float totalAmount = 0;

};

int menu();

void addSales(Facture *);

void salesQuantity(Facture *);

float totalSales(Facture *, int);

void saveDates(Facture *);

int main() {
    int option = 0;
    struct Facture daySales[SIZE];
    float total, countSales = SIZE;


    cout << "--CARGAR VENTAS DIARIAS--" << endl;
    addSales(daySales);

    do {
        option = menu();
        switch (option) {
            case 0:
                break;
            case 1:
                salesQuantity(daySales);
                break;
            case 2:
                total = totalSales(daySales, countSales);
                cout << "Cantidad total recaudado: " << total << endl;
                break;
            case 3:
                saveDates(daySales);
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
    cout << "1)Cantidad de ventas" << endl;
    cout << "2)Recuadacion total" << endl;
    cout << "3)Guardar datos en archivo" << endl;
    cin >> option;
    return option;
}

void addSales(Facture *daySales) {

    int ii;

    cout << "INGRESAR DATOS DE LAS VENTAS REALIZADAS" << endl;
    for (ii = 0; ii < SIZE; ii++) {
        cout << "VENTA " << ii + 1 << endl;
        cout << "Venta: " << endl;
        cin >> daySales[ii].number;
        cout << "Ingresar fecha: " << ii + 1 << endl;
        getline(cin, daySales[ii].date, '.');
        cout << "Ingresar total recaudado: " << ii + 1 << endl;
        cin >> daySales[ii].totalAmount;
    }
}

void salesQuantity(Facture *daySales) {
    int count = 0;

    for (int ii = 0; ii < SIZE; ii++) {
        if (daySales[ii].number != 0) {
            count++;
        }
    }
    cout << "Cantidad de ventas cargadas: " << count << endl;


}

float totalSales(Facture *daySales, int countSales) {

    if (countSales == 0) {
        return 0;
    }
    return daySales[countSales - 1].totalAmount + totalSales(daySales, countSales - 1);
}

void saveDates(Facture *daySales) {
    ofstream file;
    file.open("Ventas.txt");

    if (file.is_open()) {
        for (int ii = 0; ii < SIZE; ii++) {
            file << "VENTA: " << endl;
            file << "Numero: " << daySales[ii].number << endl;
            file << "Fecha: " << daySales[ii].date << endl;
            file << "Total recaudado: " << daySales[ii].totalAmount << endl;
        }

    }
    file.close();
}