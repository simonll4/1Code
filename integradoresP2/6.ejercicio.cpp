#include<iostream>
#include "LinkedList.h"
#include <queue>

#define GB 20;

using namespace std;

struct Factura {

    int nCliente;
    string ciudad;
    float gb;
    float montopagar;

};

int menu();

void datosDefautl(LinkedList<Factura> &);

void pagoFactura(LinkedList<Factura> &, queue<Factura> &);

void mostrar(LinkedList<Factura> &, queue<Factura> &);

int main(){
    LinkedList<Factura> l1;
    queue<Factura> recibo;
    int option;

    datosDefautl(l1);

    do {
        option = menu();
        switch (option) {
            case 0:
                break;
            case 1:
                pagoFactura(l1, recibo);
                mostrar(l1, recibo);
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
    cout << "1)Pago de fatura." << endl;
    cin >> option;
    return option;
}

void datosDefautl(LinkedList<Factura> &l1) {
    struct Factura f1;

    f1.nCliente = 1;
    f1.ciudad = "Nono";
    f1.gb = 50;
    f1.montopagar = f1.gb * GB;
    l1.insert(0, f1);

    f1.nCliente = 2;
    f1.ciudad = "San javier";
    f1.gb = 100;
    f1.montopagar = f1.gb * GB;
    l1.insert(1, f1);

    f1.nCliente = 3;
    f1.ciudad = "Luyaba";
    f1.gb = 20;
    f1.montopagar = f1.gb * GB;
    l1.insert(2, f1);

    f1.nCliente = 4;
    f1.ciudad = "La Paz";
    f1.gb = 35;
    f1.montopagar = f1.gb * GB;
    l1.insert(3, f1);

}

void pagoFactura(LinkedList<Factura> &l1, queue<Factura> &recibo) {
    struct Factura aux;
    int cliente = 0;
    int dia = 0;

    cout << "A continuacion ingrese los datos pedidos por favor: " << endl;
    cout << "Dia de pago(solamente el numeero): " << endl;
    cin >> dia;
    cout << "Numero de cliente: " << endl;
    cin >> cliente;

    for (int ii = 0; ii < l1.size(); ++ii) {
        if (cliente == l1.get(ii).nCliente) {
            if (dia < 11) {
                cout << "Monto a pagar: " << l1.get(ii).montopagar << endl;
            } else {
                aux = l1.get(ii);
                aux.montopagar += 100;
                l1.replace(ii,aux);
                cout << "Monto a pagar: " << l1.get(ii).montopagar << endl;
            }
            recibo.push(l1.get(ii));
        }
    }

}

void mostrar(LinkedList<Factura> &l1, queue<Factura> &recibo) {

    cout << "" << endl;
    cout << "******************RECIBO*****************" << endl;
    cout << "N cliente: " << recibo.front().nCliente << "\t";
    cout << "Pueblo: " << recibo.front().ciudad << "\t\t";
    cout << "Consumo: " << recibo.front().gb << "\t\t";
    cout << "Monto a pagar: " << recibo.front().montopagar << "\t\t";
    cout << "" << endl;

    cout << "" << endl;
    cout << "" << endl;
    cout << "************** LISTAS DE FACTURAS ****************" << endl;
    for (int ii = 0; ii < l1.size(); ii++) {
        cout << "N cliente: " << l1.get(ii).nCliente << "\t";
        cout << "Pueblo: " << l1.get(ii).ciudad << "\t\t";
        cout << "Consumo: " << l1.get(ii).gb << "\t\t";
        cout << "Monto a pagar: " << l1.get(ii).montopagar << "\t\t";
        cout << "" << endl;
    }

}

