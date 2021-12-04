#include <iostream>
#include "LinkedList.h"
#include <queue>

using namespace std;

struct Request {

    int num;
    string lastname;
    string name;
    string item;
    int elements;
    float amountPay;
    int sector;
};

int menu();

void carryDates(LinkedList<Request> &, Request);

void amountPay(LinkedList<Request> &, Request);

void assingSector(LinkedList<Request> &, Request);

void showRequest(LinkedList<Request>);

void shows(LinkedList<Request>);

int main() {
    LinkedList<Request> l1;
    Request r1;
    int option;


    do {
        option = menu();
        switch (option) {
            case 0:
                break;
            case 1:
                carryDates(l1,r1);
                break;
            case 2:
                amountPay(l1,r1);
                break;
            case 3:
                assingSector(l1,r1);
                break;
            case 4:
                showRequest(l1);
                break;
            case 5:
                shows(l1);
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
    cout << "1)Ingresar datos." << endl;
    cout << "2)Calcular monto a pagar." << endl;
    cout << "3)Asignar sector." << endl;
    cout << "4)Mostrar listado de solicitudes." << endl;
    cout << "5)Espectaculos." << endl;
    cin >> option;
    return option;
}

void carryDates(LinkedList<Request> &l1, Request r1) {

    char option;
    int ii = 0;
    string lastname;
    string name;
    string item;
    int elements;

    cout << "*************DATOS DE LA SOLICITUD*************" << endl;
    do {
        cout << "N de solicitud: " << ii + 1 << endl;
        cout << "Apellido: " << endl;
        cin >> lastname;
        cout << "Nombre: " << endl;
        cin >> name;
        cout << "Rubro(Artesania;Gastronomia;Espectaculo;):" << endl;
        cin >> item;
        cout << "Requiere mesa y silla( si(1) no(0)): " << endl;
        cin >> elements;

        r1.num = ii + 1;
        r1.lastname = lastname;
        r1.name = name;
        r1.item = item;
        r1.elements = elements;
        r1.amountPay = 0;
        r1.sector = 0;
        l1.push_back(r1);
        ii++;

        cout << "Quiere seguir cargando solicitudes? ingrese: y(si) n(no)" << endl;
        cin >> option;
    } while (option != 'n');

}

void amountPay(LinkedList<Request> &l1, Request r1){

    for (int ii = 0; ii < l1.size() ; ++ii) {
        if(l1.get(ii).elements == 0){
            r1 = l1.get(ii);
            r1.amountPay = 1000;
            l1.replace(ii,r1);
        }
        else{
            r1 = l1.get(ii);
            r1.amountPay= 1500;
            l1.replace(ii,r1);
        }
    }
}

void assingSector(LinkedList<Request> &l1, Request r1){

    int count = 0;

    for (int ii = 0; ii < l1.size(); ++ii) {
        if(l1.get(ii).item == "Espectaculo"){
            r1 = l1.get(ii);
            r1.sector = 0;
            l1.replace(ii,r1);
            count--;
        }
        else{
            r1 = l1.get(ii);
            r1.sector = count+1;
            l1.replace(ii,r1);
        }
        count++;
    }
}

void showRequest(LinkedList<Request> l1){

    cout<<"*********LISTADO DE SOLICITUDES*********"<<endl;
    for (int ii = 0; ii < l1.size(); ++ii) {
        cout<<"Numero: ";
        cout<<l1.get(ii).num<<endl;
        cout<<"Apellido: ";
        cout<<l1.get(ii).lastname<<endl;
        cout<<"Nombre: ";
        cout<<l1.get(ii).name<<endl;
        cout<<"Rubro:";
        cout<<l1.get(ii).item<<endl;
        cout<<"Requiere mesa/silla: ";
        cout<<l1.get(ii).elements<<endl;
        cout<<"Monto a pagar: ";
        cout<<l1.get(ii).amountPay<<endl;
        cout<<"Sector: ";
        cout<<l1.get(ii).sector<<endl;
        cout<<""<<endl;
    }

}

void shows(LinkedList<Request> l1){
    queue<Request> q1;


    for (int ii = 0; ii < l1.size(); ++ii) {
        q1.push(l1.get(ii));
    }

    cout<<"*********ESPECTACULOS*********"<<endl;
    while(!q1.empty()){
        cout<<"Numero: ";
        cout<<q1.front().num<<endl;
        cout<<"Apellido: ";
        cout<<q1.front().lastname<<endl;
        cout<<"Nombre: ";
        cout<<q1.front().name<<endl;
        cout<<"Rubro:";
        cout<<q1.front().item<<endl;
        cout<<"Requiere mesa/silla: ";
        cout<<q1.front().elements<<endl;
        cout<<"Monto a pagar: ";
        cout<<q1.front().amountPay<<endl;
        cout<<"Sector: ";
        cout<<q1.front().sector<<endl;
        cout<<""<<endl;
        q1.pop();
    }

}