#include <iostream>
#include "LinkedList.h"
#include <queue>

#define GB 70

using namespace std;

struct Comuna {
    int nCliente;
    string comuna;
    float consumo;
    float montoPagar;
};

int menu();

void datosDefautl(LinkedList<Comuna> &, Comuna &);

void pagoFactura(LinkedList<Comuna> &, queue<Comuna> &);

void mostrarLista(LinkedList<Comuna> &);

void mostrarCola(queue<Comuna>);

int main() {
    LinkedList<Comuna> l1;
    struct Comuna c1;
    queue<Comuna> q1;
    int opcion;

    datosDefautl(l1, c1);

    do {
        opcion = menu();
        switch (opcion) {
            case 0:
                break;
            case 1:
                pagoFactura(l1, q1);
                break;
            case 2:
                mostrarCola(q1);
                break;
            case 3:
                mostrarLista(l1);
                break;
            default:
                cout << "Ingrese una opcion correcta por favor" << endl;
        }
    } while (opcion != 0);


    return 0;
}

int menu() {
    int option;
    cout << endl;
    cout << "OPERACIONES:" << endl;
    cout << "0)Salir." << endl;
    cout << "1)Pago de fatura." << endl;
    cout << "2)Mostrar recibo." << endl;
    cout << "3)Mostrar lista de facturas." << endl;
    cin >> option;
    return option;
}

void datosDefautl(LinkedList<Comuna> &l1, Comuna &c1) {

    c1.nCliente = 1;
    c1.comuna = "Anisacate";
    c1.consumo = 100;
    c1.montoPagar = c1.consumo * GB;
    l1.insert(0, c1);

    c1.nCliente = 2;
    c1.comuna = "La Bolsa";
    c1.consumo = 30;
    c1.montoPagar = c1.consumo * GB;
    l1.insert(1, c1);

    c1.nCliente = 3;
    c1.comuna = "Villa Los Aromos";
    c1.consumo = 35;
    c1.montoPagar = c1.consumo * GB;
    l1.insert(2, c1);

}

void pagoFactura(LinkedList<Comuna> &l1, queue<Comuna> &q1) {
    int cliente, dia;
    struct Comuna aux;

    cout << "Numero de cliente: " << endl;
    cin >> cliente;
    cout << "" << endl;
    cout << "*********FACTURA A PAGAR*******" << endl;
    for (int ii = 0; ii < l1.size(); ii++) {
        if (cliente == l1.get(ii).nCliente) {
            cout << "N cliente: " << l1.get(ii).nCliente << "\t";
            cout << "Pueblo: " << l1.get(ii).comuna << "\t\t";
            cout << "Consumo: " << l1.get(ii).consumo << "\t\t";
            cout << "Monto a pagar: " << l1.get(ii).montoPagar << "\t\t";
            cout << "" << endl;
        }
    }
    cout << "" << endl;
    cout << "" << endl;
    cout << "A continuacion ingrese los datos pedidos por favor: " << endl;
    cout << "Dia de pago(solamente el numero): ";
    cin >> dia;

    for (int ii = 0; ii < l1.size(); ++ii) {
        if (l1.get(ii).nCliente == cliente) {
            if (dia <= 11) {
                cout << "Monto a pagar: " << l1.get(ii).montoPagar << endl;
            } else {
                aux = l1.get(ii);
                aux.montoPagar += (float) (dia - 11) * 10;
                l1.replace(ii, aux);
                cout << "Monto a pagar: " << l1.get(ii).montoPagar << endl;
            }
            q1.push(l1.get(ii));
        }
    }

}

void mostrarCola(queue<Comuna> q1) {

    while (!q1.empty()) {
        cout << "******************RECIBO*****************" << endl;
        cout << "N cliente: " << q1.front().nCliente << "\t";
        cout << "Pueblo: " << q1.front().comuna << "\t\t";
        cout << "Consumo: " << q1.front().consumo << "\t\t";
        cout << "Monto a pagar: " << q1.front().montoPagar << "\t\t";
        cout << "" << endl;
        q1.pop();
    }


}

void mostrarLista(LinkedList<Comuna> &l1) {

    cout << "" << endl;
    cout << "************** LISTAS DE FACTURAS ****************" << endl;
    for (int ii = 0; ii < l1.size(); ii++) {
        cout << "N cliente: " << l1.get(ii).nCliente << "\t";
        cout << "Pueblo: " << l1.get(ii).comuna << "\t\t";
        cout << "Consumo: " << l1.get(ii).consumo << "\t\t";
        cout << "Monto a pagar: " << l1.get(ii).montoPagar << "\t\t";
        cout << "" << endl;
    }

}
