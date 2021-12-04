/*
 * Escribir un programa utilizando punteros y funciones en la cual se
 * desea cargar en un vector con las ventas diarias de un negocio, 10
 * como máximo. La carga finaliza cuando el monto igual a cero. Además,
 * se pide:
Cantidad de ventas cargadas.
Calcular la recaudación del día.
Guardar los datos en un archivo.
Utilizar funciones y punteros en este ejercicio.
 */

#include <iostream>
#include <fstream>

#define TAM 10

using namespace std;

int menu();

void carrySales(float *);

void quantity(float const *);

void fundraising(float *);

void saveFile(float *);

int main(){
    float sales[TAM] = {0};
    int option;

    carrySales(sales);

    do {
        option = menu();
        switch (option) {
            case 0:
                break;
            case 1:
                quantity(sales);
                break;
            case 2:
                fundraising(sales);
                break;
            case 3:
                saveFile(sales);
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
    cout << "1)Cantidad de ventas cargadas." << endl;
    cout << "2)Recaudacion del dia." << endl;
    cout << "3)Guardar datos en archivo .txt ." << endl;
    cin >> option;
    return option;
}

void carrySales(float *sales) {

    float sale;
    int ii = 0;

    do {
        cout << "Ingresar las ventas diarias en pesos (10 como maximo ; 0 para finalizar):" << endl;
        cin >> sale;
        sales[ii] = sale;
        ii++;
    } while (sale != 0 || ii >= 10);

}

void quantity(float const *sales) {
    int quantity1 = 0;

    for (int ii = 0; ii < TAM; ++ii) {
        if (sales[ii] != 0) {
            quantity1++;
        }
    }
    cout << "Cantidad de ventas: " << quantity1 << endl;
}

void fundraising(float *sales) {
    int total = 0;

    for (int ii = 0; ii < TAM; ++ii) {
        if (sales[ii] != 0) {
            total += sales[ii];
        }
    }
    cout << "Recaudacion: " << total << endl;
}

void saveFile(float *saves) {
    ofstream f1;

    f1.open("Ventas.txt");

    for (int ii = 0; ii < TAM; ++ii) {
        f1 << "*****Ventas en pesos*****" << endl;
        f1 << "Venta " << ii + 1 <<": $"<< saves[ii] << endl;
    }
    f1.close();
}
