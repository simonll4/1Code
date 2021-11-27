#include <iostream>
#include <stack>
#include <ctime>
#include "LinkedList.h"



using namespace std;

int menu();

float cargarNumeros(stack<int> &);

int comprobarNum(stack<int>, int);

void mostrarPila(stack<int>);

void paresImapares(stack<int>, LinkedList<int> &, LinkedList<int> &);

void sumaValores(stack<int>);

void valorMax(stack<int>);

void valorMin(stack<int>);

int main() {
    stack<int> s1;
    LinkedList<int> pares;
    LinkedList<int> impares;

    int opcion;

    cargarNumeros(s1);

    do {
        opcion = menu();
        switch (opcion) {
            case 0:
                break;
            case 1:
                mostrarPila(s1);
                break;
            case 2:
                paresImapares(s1, pares, impares);
                break;
            case 3:
                sumaValores(s1);
                break;
            case 4:
                valorMax(s1);
                break;
            case 5:
                valorMin(s1);
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
    cout << "1)Mostrar valores en pila." << endl;
    cout << "2)Listado por paridad." << endl;
    cout << "3)Suma de los valores." << endl;
    cout << "4)Valor maximo." << endl;
    cout << "5)Valor minimo." << endl;
    cin >> option;
    return option;
}

float cargarNumeros(stack<int> &s1) {
    srand(time(NULL));
    int num;
    int aux;

    for (int ii = 0; ii < 10; ++ii) {
        num = rand() % 100 + 1;
        if (ii == 0) {
            s1.push(num);
        } else {
            aux = comprobarNum(s1, num);
            if (aux != 0) {
                s1.push(num);
            } else {
                ii--;
            }
        }
    }

}

int comprobarNum(stack<int> s1, int num) {

    while (!s1.empty()) {
        if (s1.top() == num) {
            return 0;
        } else {
            s1.pop();
        }
    }
    return 1;
}

void mostrarPila(stack<int> s1) {

    cout << "*************** NUMEROS EN PILA ********************" << endl;
    while (!s1.empty()) {
        cout << s1.top() << "\t";
        s1.pop();
    }
}

void paresImapares(stack<int> s1, LinkedList<int> &pares, LinkedList<int> &impares) {

    while (!s1.empty()) {
        if (s1.top() % 2 == 0) {
            pares.push_back(s1.top());
        } else {
            impares.push_back(s1.top());
        }
        s1.pop();
    }

    cout << "" << endl;
    cout << "********** VALORES PARES **********" << endl;
    for (int ii = 0; ii < pares.size(); ++ii) {
        cout << pares.get(ii) << "\t";
    }

    cout << "" << endl;
    cout << "********** VALORES IMPARES **********" << endl;
    for (int ii = 0; ii < pares.size(); ++ii) {
        cout << impares.get(ii) << "\t";
    }

}

void sumaValores(stack<int> s1) {
    int suma = 0;

    while (!s1.empty()) {
        suma += s1.top();
        s1.pop();
    }
    cout << "" << endl;
    cout << "La suma de todos los valores es:" << suma << endl;
}

void valorMax(stack<int> s1) {
    int max;

    max = s1.top();
    s1.pop();
    while (!s1.empty()) {
        if (s1.top() > max) {
            max = s1.top();
        }
        s1.pop();
    }
    cout << "Valor maximo:" << max << endl;
}

void valorMin(stack<int> s1) {
    int min;

    min = s1.top();
    s1.pop();
    while (!s1.empty()) {
        if (s1.top() < min) {
            min = s1.top();
        }
        s1.pop();
    }
    cout << "Valor minimo:" << min << endl;
}