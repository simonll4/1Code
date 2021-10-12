/*
 * 1. Crear un programa en la cual cargue una lista de 10 numeros aleatoriamente. Luego mostrar en pantalla,
 * el listado completo, el promedio de ellos, y un listado con los múltiplos de 5.
 */
#include <iostream>
#include "LinkedList.h"
#include <ctime>

using namespace std;


int main() {
    srand(time(NULL));

    LinkedList<int> lista;
    float average = 0;


    for (int ii = 0; ii < 10; ii++) {
        lista.insert(ii, rand() % 10);
    }

    for (int ii = 0; ii < lista.size(); ++ii) {
        cout << lista.get(ii) << "\t";
    }

    for (int ii = 0; ii < lista.size(); ++ii) {
        average += lista.get(ii);
    }

    cout << endl;
    average = average / lista.size();
    cout << "proemdio: " << average << endl;

    for (int ii = 0; ii < lista.size(); ++ii) {
        if (lista.get(ii) % 5 == 0) {
            cout << "Multiplos de 5: " << lista.get(ii) << endl;
        }
    }

    return 0;
}