/*
    1. Crear  un programa que genere una cola con una serie de valores enteros sin repetirse del 1 al 10 de manera aleatoria.
    (se ingresa por teclado la cantidad de números a colocar), luego se mostrará un menú de opciones:

a. Agregar un valor a la cola de números y mostrar la cantidad de valores que hay en la cola.
b. Pasar los valores menores a 5 a una pila y los mayores a 5 una lista. En caso de que no haya ningún valor, mostrar un mensaje.
c. Calcular la sumatoria de los valores de la pila, cola y lista.
d. Mostrar todos los valores de la pila, cola y lista.
 */
#include <iostream>
#include <queue>
#include "LinkedList.h"
#include <stack>
#include <ctime>
#include <random>

using namespace std;

void enterDates(queue<int> *, int);

int searchNumber(queue<int>, int);

int menu();

void addDate(queue<int> *);

void passDates(queue<int> *, stack<int> *, LinkedList<int> *);

void sumValues(queue<int> , stack<int> , LinkedList<int> );

void showQueue(queue<int> *);

void showStack(stack<int> *);

void showList(LinkedList<int> *);

int main() {
    queue<int> q1;
    stack<int> s1;
    LinkedList<int> l1;
    int quantity;
    int option;

    cout << "Ingresar cantidad de valores a colocar en la cola: " << endl;
    cin >> quantity;
    enterDates(&q1, quantity);
    showQueue(&q1);

    do {
        option = menu();
        switch (option) {
            case 0:
                break;
            case 1:
                addDate(&q1);
                break;
            case 2:
                passDates(&q1, &s1, &l1);
                break;
            case 3:
                sumValues(q1,s1,l1);
                break;
            case 4:
                cout << endl;
                showQueue(&q1);
                cout << endl;
                showStack(&s1);
                cout << endl;
                showList(&l1);
                cout << endl;
                break;
            default:
                cout << "Ingrese una opcion correcta por favor" << endl;
        }
    } while (option != 0);



    return 0;
}

void enterDates(queue<int> *q1, int quantity) {
    srand(time(NULL));
    int num;
    int continuation;

    for (int ii = 0; ii < quantity; ++ii) {
        num = rand() % 9 + 1;
        if (ii == 0) {
            q1->push(num);
        } else {
            continuation = searchNumber(*q1, num);
            if (continuation != 0) {
                q1->push(num);
            } else {
                ii--;
            }
        }
    }
}

int searchNumber(queue<int> q1, int num) {

    while (!q1.empty()) {
        if (q1.front() == num) {
            return 0;
        } else {
            q1.pop();
        }
    }
    return 1;
}

int menu() {
    int option;
    cout << endl;
    cout << "OPERACIONES:" << endl;
    cout << "0)Salir." << endl;
    cout << "1)Agregar un valor a la cola de números y mostrar la cantidad de valores que hay en la cola." << endl;
    cout << "2)Pasar los valores menores a 5 a una pila y los mayores a 5 una lista." << endl;
    cout << "3)Calcular la sumatoria de los valores de la pila, cola y lista." << endl;
    cout << "4)Mostrar todos los valores de la pila, cola y lista." << endl;
    cin >> option;
    return option;
}

void addDate(queue<int> *q1){
    int num;

    cout<<"Ingresar el valor a agregar a la cola: "<<endl;
    cin >> num;
    q1->push(num);
    cout<< "Cantidad de valores en la cola: "<<q1->size()<<endl;
}

void passDates(queue<int> *q1, stack<int> *s1, LinkedList<int> *l1) {

    queue<int> aux;

    if(q1->size()!=0){
        while(!q1->empty()){
            if (q1->front() < 5) {
                s1->push(q1->front());
                q1->pop();
            }
            if (q1->front() > 5) {
                l1->insert(0,q1->front());
                q1->pop();
            }
            if(q1->front() == 5){
                aux.push(q1->front());
                q1->pop();
            }
        }
        *q1 = aux;
    }
    else{
        cout<<"NO HAY NINGUN VALOR EN LA COLA"<<endl;
    }

}

void sumValues(queue<int> q1, stack<int> s1, LinkedList<int> l1) {
    int sum1 = 0, sum2 = 0, sum3 = 0;


    for (int ii = 0; ii < l1.size(); ++ii) {
        sum1 += l1.get(ii);
    }
    cout << "Sumatoria en lista: " << sum1 << endl;


    while(!q1.empty()){
        sum2 += q1.front();
        q1.pop();
    }
    cout << "Sumatoria en cola es: " << sum2 << endl;


    while(!s1.empty()){
        sum3 += s1.top();
        s1.pop();
    }
    cout << "Sumatoria en pila es: " << sum3 << endl;

}

void showQueue(queue<int> *q1) {
    queue<int> aux;

    cout << "**********************************COLA**************************************" << endl;
    while (!q1->empty()) {
        cout << q1->front() << "\t";
        aux.push(q1->front());
        q1->pop();
    }
    *q1 = aux;
}

void showStack(stack<int> *s1){
    stack<int> aux;

    cout << "**********************************PILA**************************************" << endl;
    while (!s1->empty()) {
        cout << s1->top() << "\t";
        aux.push(s1->top());
        s1->pop();
    }
    *s1 = aux;
}

void showList(LinkedList<int> *l1){

    cout << "**********************************LISTA**************************************" << endl;
    for (int ii = 0; ii < l1->size(); ++ii) {
        cout << l1->get(ii) << "\t";
    }
}


