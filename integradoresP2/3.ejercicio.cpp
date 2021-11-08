#include<iostream>
#include "LinkedList.h"
#include <fstream>

using namespace std;

struct Auto {
    int nTicket;
    char estado;
    int cantPersonas;
    int monto;
};

int menu();

void valPredeterminados(LinkedList<Auto> *, Auto);

void ticket(LinkedList<Auto> *);

void resumen(LinkedList<Auto> *);

int main() {
    struct Auto a1;
    LinkedList<Auto> l1;
    int option;


    valPredeterminados(&l1, a1);

    do {
        option = menu();
        switch (option) {
            case 0:
                break;
            case 1:
                ticket(&l1);
                break;
            case 2:
                resumen(&l1);
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
    cout << "1)Generar ticket." << endl;
    cout << "2)Generar resumen del dia" << endl;
    cin >> option;
    return option;
}

void valPredeterminados(LinkedList<Auto> *l1, Auto a1) {


    a1.nTicket = 1;
    a1.estado = 69;
    a1.cantPersonas = 3;
    a1.monto = 20;
    l1->insert(0, a1);

    a1.nTicket = 2;
    a1.estado = 83;
    a1.cantPersonas = 1;
    a1.monto = 40;
    l1->insert(1, a1);

    a1.nTicket = 3;
    a1.estado = 69;
    a1.cantPersonas = 2;
    a1.monto = 30;
    l1->insert(2, a1);

    a1.nTicket = 4;
    a1.estado = 83;
    a1.cantPersonas = 4;
    a1.monto = 10;
    l1->insert(3, a1);

    a1.nTicket = 5;
    a1.estado = 83;
    a1.cantPersonas = 2;
    a1.monto = 30;
    l1->insert(4, a1);

}

void ticket(LinkedList<Auto> *l1) {

    int num = 0;

    cout << "Ingrese numero de ticket a imprimir: " << endl;
    cin >> num;

    for (int ii = 0; ii < l1->size(); ++ii) {
        if (num == l1->get(ii).nTicket) {
            cout << "*************** TICKET *****************" << endl;
            cout << "Numero: " << l1->get(ii).nTicket << endl;
            cout << "Estado: " << l1->get(ii).estado << endl;
            cout << "Cant. de personas: " << l1->get(ii).cantPersonas << endl;
            cout << "Monto: " << l1->get(ii).monto << endl;
        }
    }
}

void resumen(LinkedList<Auto> *l1) {
    int cant = 0, cant1 = 0, cant2 = 0, cant3 = 0, cant4 = 0, cant5 = 0;
    ofstream f1;

    for (int ii = 0; ii < l1->size(); ++ii) {
        if (l1->get(ii).estado == 69) {
            cant1++;
            cant2 += l1->get(ii).cantPersonas;
        }
        if (l1->get(ii).estado == 83) {
            cant3++;
            cant4 += l1->get(ii).cantPersonas;
        }
        cant5 += l1->get(ii).monto;
        cant++;
    }

    cout << "*************** RESUMEN DEL DIA *****************" << endl;
    cout << "Cantidad de tickects emitidos en el dia: " << cant << endl;
    cout << "Autos que entran a la ciudad: " << cant1 << endl;
    cout << "Personas que entran a la ciudad: " << cant2 << endl;
    cout << "Autos que salen de la ciudad: " << cant3 << endl;
    cout << "Personas que salen de la ciudad: " << cant4 << endl;
    cout << "Total recaudado: " << cant5 << endl;

    f1.open("Resumen.txt");

    f1 << "*************** RESUMEN DEL DIA *****************" << endl;
    f1 << "Cantidad de tickects emitidos en el dia: " << cant << endl;
    f1 << "Autos que entran a la ciudad: " << cant1 << endl;
    f1 << "Personas que entran a la ciudad: " << cant2 << endl;
    f1 << "Autos que salen de la ciudad: " << cant3 << endl;
    f1 << "Personas que salen de la ciudad: " << cant4 << endl;
    f1 << "Total recaudado: " << cant5 << endl;

    f1.close();
}
