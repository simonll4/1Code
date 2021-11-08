/*
 * 1. Crear un programa en la cual el usuario cargue una serie de valores en una cola. Luego se pide:
- mostrar en pantalla el los elementos de la cola
- borrar un elemento de la cola
- agregar un elemento que no este en la cola
 */
#include <iostream>
#include <queue>

using namespace std;

void enterDate(queue<int> *);

void showQueue(queue<int> *);

void remove(queue<int> *);

void addDate(queue<int> *);

int main(){
    queue<int> c1;
    int option = 0;


    do {
        cout << endl << "0)Para finalizar " << endl;
        cout << "1)Ingresar datos" << endl;
        cout << "2)Mostrar datos en pantalla. " << endl;
        cout << "3)Borrar elementos de la cola." << endl;
        cout << "4)agregar elemento que no este en la cola." << endl;
        cin >> option;

        switch (option) {
            case 0:
                break;
            case 1:
                enterDate(&c1);
                break;
            case 2:
                showQueue(&c1);
                break;
            case 3:
                remove(&c1);
                break;
            case 4:
                addDate(&c1);
                break;
            default:
                cout << "Ingrese una opcion correcta" << endl;
        }


    } while (option != 0);


    remove(&c1);

    return 0;
}

void enterDate(queue<int> *c1){

    int num = 0;

    cout << "Ingresar datos enteros(0 para finalizar la carga): ";
    do {
        cin >> num;
        if (num != 0) {
            c1->push(num);
        }
    } while (num != 0);

}

void showQueue(queue<int> *c1) {
    queue<int> aux;

    cout << "Elementos de la cola: " << endl;
    while (!c1->empty()) {
        cout << c1->front() << "\t";
        aux.push(c1->front());
        c1->pop();
    }
    *c1 = aux;
}

void remove(queue<int> *c1) {

    int dato = 0;

    cout << "Ingrese la cantidad de elementos a borrar: " << endl;
    cin >> dato;

    for (int ii = 0; ii < dato; ++ii) {
        c1->pop();
    }

}

void addDate(queue<int> *c1) {
    int date = 0;

    cout << "Ingresar un numero que no este en la cola: " << endl;
    cin >> date;
    c1->push(date);

}
