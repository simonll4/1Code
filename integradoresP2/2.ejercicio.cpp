/*
 * 2. Crear un listado de juegos y luego crear una pila de aplicaciones que necesitas para
 * instalar cada uno de esos juegos nuevos. En la pila se deberá guardar el nombre de la aplicación y
 * prioridad (1,2,3) que tiene esa aplicación. Luego el usuario consulta que juego desea instalar y se
 * generara un archivo con la pila de aplicaciones a instalar dese juego.
 */
#include <iostream>
#include "LinkedList.h"
#include <stack>
#include <fstream>

using namespace std;

struct Aplicacion {
    string nombre;
    int prioridad;
};

struct Juego {
    int codigo;
    string nombre;
    stack<Aplicacion> aplicaciones;
};

void cargaDatos(LinkedList<Juego> &);

void requisitos(LinkedList<Juego>, int);


int main() {
    LinkedList<Juego> j;
    int num;

    cargaDatos(j);

    do {
        cout << "*****************INSTALADOR DE JUEGOS*****************" << endl;
        cout << "INGRESE: " << endl << "1)COUNTER STRIKE 1.6" << endl << "2)GAT V" << endl;
        cout << "0) salir." << endl;
        cin >> num;
        if (num != 0) {
            requisitos(j, num);
        }
    } while (num != 0);


    return 0;
}

void cargaDatos(LinkedList<Juego> &j) {

    struct Juego j1;
    struct Aplicacion a1;

    j1.nombre = "COUNTER";
    j1.codigo = 1;
    a1.nombre = "STEAM";
    a1.prioridad = 1;
    j1.aplicaciones.push(a1);
    a1.nombre = "DIRECTX";
    a1.prioridad = 2;
    j1.aplicaciones.push(a1);
    j.insert(0, j1);
    //limpio stack
    j1.aplicaciones.pop();
    j1.aplicaciones.pop();

    j1.nombre = "GTAV";
    j1.codigo = 2;
    a1.nombre = "STEAM";
    a1.prioridad = 1;
    j1.aplicaciones.push(a1);
    a1.nombre = "ROCKSTAR LAUNCHER";
    a1.prioridad = 2;
    j1.aplicaciones.push(a1);
    j.insert(1, j1);
    //limpio stack
    j1.aplicaciones.pop();
    j1.aplicaciones.pop();

}

void requisitos(LinkedList<Juego> j, int num) {
    stack<Aplicacion> aux;
    ofstream f1;

    /*cout << "********** APPS PARA REQUERIDAS PARA EL JUEGO ***********" << endl;
      for (int ii = 0; ii < j.size(); ++ii) {
        if (num == j.get(ii).codigo) {
            aux = j.get(ii).aplicaciones;
            while (!aux.empty()) {
               cout << "Aplicacion: " << aux.top().nombre << endl;
               cout << "Prioridad: " << aux.top().prioridad << endl;
               aux.pop();
            }
        }
    }*/

    f1.open("Requisitos.txt");
    f1 << "********** APPS PARA REQUERIDAS PARA EL JUEGO ***********" << endl;
    for (int ii = 0; ii < j.size(); ++ii) {
        if (num == j.get(ii).codigo) {
            aux = j.get(ii).aplicaciones;
            while (!aux.empty()) {
                f1 << "Aplicacion: " << aux.top().nombre << endl;
                f1 << "Prioridad: " << aux.top().prioridad << endl;
                aux.pop();
            }
        }
    }
    f1.close();
}
