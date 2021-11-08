/*
2. Elaborar un sistema de stock, en la cual posee una cola de productos con los siguientes atributos: código, nombre,
 cantidad, precio lista. Desarrollar las siguientes funciones:
a. Mostrar el stock. (cola de productos)
b. Descontar stock.
c. Reponer stock.
 */

#include <iostream>
#include <queue>

using namespace std;

struct Product {
    int code;
    string name;
    int quantity;
    float price;
};

void enterDates(queue<Product> *);

int menu();

void showStock(queue<Product> *);

void discount(queue<Product> *);

void addStock(queue<Product> *);

int main() {
    queue<Product> p1;
    int option;

    cout<<"Ingresar datos del stock de productos: "<<endl;
    enterDates(&p1);

    do {
        option = menu();
        switch (option) {
            case 0:
                break;
            case 1:
                showStock(&p1);
                cout << endl;
                break;
            case 2:
                discount(&p1);
                cout << endl;
                break;
            case 3:
                addStock(&p1);
                break;
            default:
                cout << "Ingrese una opcion correcta por favor" << endl;
        }
    } while (option != 0);


    return 0;
}

void enterDates(queue<Product> *p1) {
    struct Product p;

    p.code = 1;
    p.name = "coca cola";
    p.quantity = 3;
    p.price = 100;
    p1->push(p);

    p.code = 2;
    p.name = "pepsi";
    p.quantity = 5;
    p.price = 80;
    p1->push(p);

    p.code = 3;
    p.name = "fanta";
    p.quantity = 6;
    p.price = 80;
    p1->push(p);
}

int menu() {
    int option;
    cout << endl;
    cout << "OPERACIONES:" << endl;
    cout << "0)Salir." << endl;
    cout << "1)Mostrar stock" << endl;
    cout << "2)Descontar stock" << endl;
    cout << "3)Reponer stock" << endl;
    cin >> option;
    return option;
}

void showStock(queue<Product> *p1) {
    queue<Product> aux_p1;
    struct Product aux;

    cout << "*********PRUDCUTOS EN STOCK**********" << endl;
    while (!p1->empty()) {
        aux = p1->front();
        cout << endl;
        cout << "Codigo: " << aux.code << "\t" << "Nombre: " << aux.name << "\t";
        cout << "Cantidad: " << aux.quantity << "\t" << "Precio: " << aux.price << "\t";
        cout << "" << endl;
        aux_p1.push(p1->front());
        p1->pop();
    }
    *p1 = aux_p1;
}

void discount(queue<Product> *p1) {
    Product p;
    queue<Product> aux_p1;
    int code;
    int quantityDiscount;

    cout << "Ingrese el codigo del producto a descontar: " << endl;
    cin >> code;

    while (!p1->empty()) {
        p = p1->front();
        if (p.code == code) {
            cout << "Cantidad en stock: " << p.quantity << endl;
            cout << "Ingresar cantidad a descontar: " << endl;
            cin >> quantityDiscount;
            while (quantityDiscount > p.quantity) {
                cout << "Ingrese una cantidad menor o igual al numero de stock: " << endl;
                cin >> quantityDiscount;
            }
            p.quantity = p.quantity - quantityDiscount;
        }
        aux_p1.push(p);
        p1->pop();
    }
    *p1 = aux_p1;
}

void addStock(queue<Product> *p1){
    Product p;
    queue<Product> aux_p1;
    int code;
    int addQuantity;

    cout << "Ingrese el codigo del producto a agregar: " << endl;
    cin >> code;
    while(!p1->empty()){
        p = p1->front();
        if(code == p.code ){
            cout << "Cantidad en stock: " << p.quantity << endl;
            cout << "Ingresar cantidad a agregar: " << endl;
            cin >> addQuantity;
            p.quantity = p.quantity + addQuantity;
        }
        aux_p1.push(p);
        p1->pop();
    }
    *p1 = aux_p1;
}