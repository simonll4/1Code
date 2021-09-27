/*3. Escribir un programa utilizando punteros y funciones en la cual se desea cargar en un vector
 * los valores que toma un sensor de temperatura colocando en una pileta de natación, que debe estar
 * entre los 34 y 36 grados siendo esta la temperatura óptima para nadar. El sensor puede tomar valores
 * entre 0 y 50 inclusive, cada 1 hora. Cuando el sensor toma un valor menor a 34 activa la caldera para
 * calentar el agua. Reservar un espacio de memoria de 24, una para cada temperatura. Se pide:

- Cantidad de veces que se activó la caldera en un día.

- Calcular el promedio de temperatura del agua en todo un día.

- Ordenar las temperaturas con quick sort.

- Guardar los datos en un archivo.
 *
 */

#include <iostream>
#include <fstream>
#include <ctime>
#define SIZE 24

using namespace std;

void addValue(float *);

void activeBoiler(float *);

void averageTemp(float *);

void fileSave(float *);

void quicksort(float *,int , int);


int main() {
    float temperatures[SIZE] = {0};

    addValue(temperatures);
    activeBoiler(temperatures);
    averageTemp(temperatures);
    fileSave(temperatures);
    quicksort(temperatures,SIZE-1,0);
    cout<< "" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout<<" "<<temperatures[i];
    }

    return 0;
}

void addValue(float *temperatures) {
    srand(time(NULL));

    for (int ii = 0; ii < SIZE; ++ii) {
        temperatures[ii] = rand() % 51;
    }

}

void activeBoiler(float *temperatures) {
    int quantity = 0;

    for (int ii = 0; ii < SIZE; ++ii) {
        if (temperatures[ii] <= 34) {
            quantity++;
        }
    }
    cout<<"VECES QUE SE ENCENDIO LA CALDERA EN EL DIA: "<< quantity <<endl;
}

void averageTemp(float *temperatures) {
    float temp = 0;

    for (int ii = 0; ii < SIZE; ++ii) {
        temp += temperatures[ii];
    }
    cout << "EL PROMEDIO DE LAS TEMPERATURAS DUANTE TODO EL DIA: " << temp / SIZE << endl;
}

void fileSave(float *temperatures) {
    ofstream file;
    file.open("temperatures.txt");

    if (file.is_open()) {
        for (int ii = 0; ii < SIZE; ++ii) {
            file << "TEMPERATURA " << ii + 1;
            file << ":\t" << temperatures[ii] << endl;
        }
    }
    file.close();
}
void quicksort (float * t, int rightLimit, int leftLimit) {
    int aux = 0;
    int left = 0;
    int right = 0;
    int pivot = 0;
    left = leftLimit;
    right = rightLimit;
    pivot = t[(leftLimit + rightLimit) / 2];
    do {
        while (t[left] < pivot && left < rightLimit) {
            left++;
        }
        while (t[right] > pivot && right > leftLimit) {
            right--;
        }
        if (left <= right) {
            aux = t[left];
            t[left] = t[right];
            t[right] = aux;
            left++;
            right--;
        }
    } while (left <= right);
    if (leftLimit < right) {
        quicksort(t, right, leftLimit);
    }
    if (rightLimit > left) {
        quicksort(t, rightLimit, left);
    }
}