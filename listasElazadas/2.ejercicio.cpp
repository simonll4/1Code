/*
 * 2. Crear una lista con 20 letras y luego contar la cantidad de vocales y consonantes.
 * Luego mostrar el listado completo y la cantidad de vocales y consonantes.
 */
#include <iostream>
#include "LinkedList.h"
#include <ctime>

using namespace std;

int main() {
    srand(time(NULL));

    LinkedList<char> list;

    int vowel = 0;
    int consonant = 0;

    for (int ii = 0; ii < 20; ++ii) {
        list.insert(ii, rand() % 25 + 65);
    }
    list.print();

    for (int ii = 0; ii < list.size(); ++ii) {
        if (list.get(ii) == 'A' ||
            list.get(ii) == 'E' ||
            list.get(ii) == 'I' ||
            list.get(ii) == 'O' ||
            list.get(ii) == 'U'
                ) {
            vowel++;
        } else {
            consonant++;
        }
    }

    cout << "Cantidad de vocales: " << vowel << endl;
    cout << "Cantidad de consonantes: " << consonant << endl;

    return 0;
}