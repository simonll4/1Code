#include <iostream>
#include "LinkedList.h"
#include <queue>
#include <ctime>

using namespace std;

struct Producto{

    int num1;
    int num2;
    int respuesta;
    int resultado;

};

int menu();

void multiplicacion(LinkedList<Producto> &, queue<Producto> &, int &, int &);

void mostrar(LinkedList<Producto> , queue<Producto> , int , int );

int main() {
    LinkedList<Producto> producto;
    queue<Producto> incorrectas;
    int numCorrectas = 0, numIncorrectas = 0;
    int option;

    do {
        option = menu();
        switch (option) {
            case 0:
                break;
            case 1:
                multiplicacion(producto,incorrectas,numCorrectas,numIncorrectas);

                break;
            case 2:
                mostrar(producto,incorrectas,numCorrectas,numIncorrectas);
                break;
            default:
                cout << "Ingrese una opcion correcta por favor" << endl;
        }
    } while (option != 0);

    return 0;
};

int menu() {
    int option;
    cout << endl;
    cout << "OPERACIONES:" << endl;
    cout << "0)Salir." << endl;
    cout << "1)Realizar una multiplicacion." << endl;
    cout <<"2)Ver operaciones realizadas"<<endl;
    cin >> option;
    return option;
}

void multiplicacion(LinkedList<Producto> &producto, queue<Producto> &incorrectas, int &numCorrectas, int &numIncorrectas){
    srand(time(NULL));
    int num1;
    int num2;
    int respuesta;
    struct Producto aux;

    num1 = rand()%10+2;
    num2 = rand()%10+2;

    cout<<"Cuanto es la multiplicacion: "<<endl;
    cout<<num1<< "x" <<num2<<endl;
    cin >> respuesta;

    aux.num1 = num1;
    aux.num2 = num2;
    aux.respuesta = respuesta;
    aux.resultado = num1*num2;

    if(respuesta == num1*num2){
        producto.push_back(aux);
        numCorrectas++;
    } else {
        incorrectas.push(aux);
        numIncorrectas++;
    }
}

void mostrar(LinkedList<Producto> l1, queue<Producto> q1, int a, int b) {

    cout << "" << endl;
    cout << "*********** CORRECTAS ***********" << endl;
    for (int ii = 0; ii < l1.size(); ++ii) {
        cout << "OPERACION " << ii + 1 << endl;
        cout << "Numero 1:" << l1.get(ii).num1 << endl;
        cout << "Numero 2:" << l1.get(ii).num2 << endl;
        cout << "Respuesta:" << l1.get(ii).respuesta << endl;
        cout << "Resultado:" << l1.get(ii).resultado << endl;
        cout<<endl;
        cout<<endl;
    }
    cout << "Respuestas correctas: " << a << endl;

    int ii = 1;
    cout << "" << endl;
    cout << "*********** INCORRECTAS ***********" << endl;
    while (!q1.empty()) {
        cout << "OPERACION " << ii << endl;
        cout << "Numero 1:" << q1.front().num1 << endl;
        cout << "Numero 2:" << q1.front().num2 << endl;
        cout << "Respuesta:" << q1.front().respuesta << endl;
        cout << "Resultado:" << q1.front().resultado << endl;
        cout<<endl;
        cout<<endl;
        q1.pop();
        ii++;
    }
    cout << "Respuestas incorrectas: " << b << endl;

}