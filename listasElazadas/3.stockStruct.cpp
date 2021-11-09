/*
3. Elaborar un sistema de stock, en la cual posee una lista de productos con los siguientes atributos:
codigo, nombre, cantidad, precio lista. Desarrollar las siguientes funciones:
a. Mostrar el stock. (lista de productos)
b. Descontar stock.
c. Reponer stock.
(hacer con estructura - clases y objetos)
 CON estructura
 */

#include <iostream>
#include "LinkedList.h"

using namespace std;

struct Product {
    int code;
    string name;
    int cant;
    float priceList;
};

int menu();

void datesDefault(LinkedList<Product> &, Product);

void showStock(LinkedList<Product> &);

void discountStock(LinkedList<Product> &,Product);

void replaceStock(LinkedList<Product> &,Product);

int main() {
    LinkedList<Product> l1;
    struct Product p1;
    int option;

    datesDefault(l1, p1);

    do {
        option = menu();
        switch (option) {
            case 0:
                break;
            case 1:
                showStock(l1);
                cout << endl;
                break;
            case 2:
                discountStock(l1,p1);
                cout << endl;
                break;
            case 3:
                replaceStock(l1,p1);
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
    cout << "1)Mostrar stock." << endl;
    cout << "2)Descontar stock." << endl;
    cout << "3)Reponer stock." << endl;
    cin >> option;
    return option;
}

void datesDefault(LinkedList<Product> &l1, Product p1) {

    p1.code = 1;
    p1.name = "coca";
    p1.cant = 10;
    p1.priceList = 200;
    l1.insert(0, p1);

    p1.code = 2;
    p1.name = "pepsi";
    p1.cant = 5;
    p1.priceList = 180;
    l1.insert(1, p1);

    p1.code = 3;
    p1.name = "fernet";
    p1.cant = 15;
    p1.priceList = 500;
    l1.insert(2, p1);

}

void showStock(LinkedList<Product> &l1) {

    for (int ii = 0; ii < l1.size(); ++ii) {
        cout << endl;
        cout << "PRDODUCTO " << ii + 1 << endl;
        cout << "Codigo: " << l1.get(ii).code << endl;
        cout << "Nombre: " << l1.get(ii).name << endl;
        cout << "Cantidad: " << l1.get(ii).cant << endl;
        cout << "Precio de lista: " << l1.get(ii).priceList << endl;
    }
}

void discountStock(LinkedList<Product> &l1,Product p1){
    int code;
    int cant;

    cout << "Ingresar codigo del producto a descontar:" << endl;
    cin >> code;
    cout << "Cuantos productos desea descontar?" << endl;
    cin >> cant;

    for (int ii = 0; ii < l1.size(); ++ii) {
        if(code == l1.get(ii).code){
            if(cant <= l1.get(ii).cant){
                p1 = l1.get(ii);
                p1.cant = p1.cant - cant;
                l1.replace(ii,p1);
                cout<<"STOCK ACTUALIZADO"<<endl;
                cout<<"Cantidad en stock: "<<l1.get(ii).cant<<endl;
            }
            else{
                cout<<"LA CANTIDAD A DESCONTAR ES MAYOR A LO QUE HAY EN STOCK, POR FAVOR INTENTE OTRA VEZ"<<endl;
            }

        }
    }

}

void replaceStock(LinkedList<Product> &l1,Product p1){
    int code;
    int cant;

    cout << "Ingresar codigo del producto a agregar:" << endl;
    cin >> code;
    cout << "Cuantos productos desea agregar?" << endl;
    cin >> cant;

    for (int ii = 0; ii < l1.size(); ++ii) {
        if(code == l1.get(ii).code){
            if(cant <= l1.get(ii).cant){
                p1 = l1.get(ii);
                p1.cant = p1.cant + cant;
                l1.replace(ii,p1);
                cout<<"STOCK ACTUALIZADO"<<endl;
                cout<<"Cantidad en stock: "<<l1.get(ii).cant<<endl;
            }

        }
    }

}