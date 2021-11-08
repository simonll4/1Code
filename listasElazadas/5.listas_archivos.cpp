/*1. Una empresa dedicada al rubro de las telecomunicaciones brinda servicios de internet a las cooperativas de las comunas
 * de las Sierras de Calamuchita.

Generar un listado (TDA Lista) de las facturas del mes y año en curso de las cooperativas con los siguientes datos:
 N° de Cliente, Comuna, cantidad GB consumidos en el mes, monto a pagar.
 Realizar los cálculos correspondientes si el costo es 1 GB = $70. Por ejemplo:

Lista de Facturación

        N°Cliente	Comuna	Consumo	Monto a pagar
            1	   Anisacate  100	   7000
            2	   La Bolsa	   30	   2100
            3Villa Los Aromos 35	    2450
Luego, crear un menú de opciones con las siguientes operaciones:

- Pago de factura. Cuando la comuna va pagar la factura, se realiza la búsqueda en el listado, muestra la factura
 y solicita el día de pago. En caso de que el pago se realiza después del día 11 inclusive se le sumará un recargo
 de $10 por día de retraso. Finalmente muestra el recibo por pantalla.

- Mostrar la lista y guardar en un archivo la lista.
 */

#include <iostream>
#include "LinkedList.h"
#include <fstream>

#define SIZE 2

using namespace std;

struct Cooperative {
    int numCustomer;
    string commune;
    float gb;
    float amount;
};

void showDates(LinkedList<Cooperative>);

int menu();

void payFacture(LinkedList<Cooperative>);

int main() {

    struct Cooperative c1;
    LinkedList<Cooperative> l1;
    int option;

    for (int ii = 0; ii < SIZE; ++ii) {
        cout << "Ingresar datos de la comuna " << ii + 1 << endl;
        cout << "Numero:" << endl;
        cin >> c1.numCustomer;
        cout << "Nombre:" << endl;
        cin >> c1.commune;
        cout << "gb consumidos: " << endl;
        cin >> c1.gb;
        c1.amount = c1.gb * 70;
        l1.push_back(c1);
    }

    do {
        option = menu();
        switch (option) {
            case 0:
                break;
            case 1:
                payFacture(l1);
                break;
            case 2:
                showDates(l1);
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
    cout << "1)Pagar factura." << endl;
    cout << "2)Mostrar lista y guardar en archivo." << endl;
    cin >> option;
    return option;
}

void showDates(LinkedList<Cooperative> l1) {
    ofstream ofile;

    cout << "************************************************************************" << endl;
    cout << "N cliente" << "\t\t" << "Comuna" << "\t\t\t" << "Consumo" << "\t\t\t" << "Monto a pagar" << endl;
    for (int ii = 0; ii < l1.size(); ++ii) {
        cout << l1.get(ii).numCustomer << "\t\t\t";
        cout << l1.get(ii).commune << "\t\t\t";
        cout << l1.get(ii).gb << "\t\t\t";
        cout << l1.get(ii).amount << "\t\t\t";
        cout << endl;
    }
    ofile.open("comunas.txt");

    ofile << "************************************************************************" << endl;
    ofile << "N cliente" << "\t\t" << "Comuna" << "\t\t\t" << "Consumo" << "\t\t\t" << "Monto a pagar" << endl;
    for (int ii = 0; ii < l1.size(); ++ii) {
        ofile << "\t" << l1.get(ii).numCustomer << "\t\t\t";
        ofile << "\t" << l1.get(ii).commune << "\t\t\t";
        ofile << "\t" << l1.get(ii).gb << "\t\t\t";
        ofile << "\t" << l1.get(ii).amount << "\t\t\t";
        ofile << endl;
    }
    ofile.close();
}

void payFacture(LinkedList<Cooperative> l1) {
    int num = 0, day = 0;
    float surcharge = 0;

    cout << "Ingrese numero de comuna: " << endl;
    cin >> num;
    for (int ii = 0; ii < l1.size(); ++ii) {
        if (num == l1.get(ii).numCustomer) {
            cout << "Ingrese le dia de pago:" << endl;
            cin >> day;
            if (day < 11) {
                cout << "*****************************" << endl;
                cout << "Monto final a pagar" << l1.get(ii).amount << endl;
                cout << "*****************************" << endl;
            } else {
                day = day - 11;
                surcharge = (day * 10) + l1.get(ii).amount;
                cout << "*****************************" << endl;
                cout << "Monto final a pagar" << surcharge;
                cout << "*****************************" << endl;
            }
        }

    }
}