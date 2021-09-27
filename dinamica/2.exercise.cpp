/*
 * 2. Crear un programa que pregunte al usuario cuántos caracteres desea introducir,
 * reserve espacio para dicho número de caracteres, le permita al usuario introducirlos
 * desde teclado y luego mostrar por pantalla los valores. Luego, el programa pregunta
 * cuántos caracteres desea agregar a la lista de elementos ya introducida, agrega espacio
 * de memoria y solicita el ingreso de los nuevos valores. Por último, mostrar la lista resultante.
 */
#include <iostream>


char *resize(int cant_add, char *array, int &cant_carac);

using namespace std;

int main() {

    char *array;
    int cant_carac, cant_add;

    cout << "Cantidad de array a ingresar:" << endl;
    cin >> cant_carac;
    array = new char[cant_carac];

    cout << "INGRESE EL TEXTO:" << endl;
    cin.ignore();
    cin.getline(array, cant_carac, '\n');
    cin.clear();
    cout << array << endl;


    cout << "Cuantos array desea agregar?" << endl;
    cin >> cant_add;

    array = resize(cant_add, array, cant_carac);

    cout << "Ingrese frase completa con nueevos array:" << endl;
    cin.ignore();
    cin.getline(array, cant_carac, '\n');
    cin.clear();
    cout << array << endl;


    return 0;
}

char *resize(int cant_add, char *array, int &cant_carac) {
    char *temp;
    temp = new char[cant_carac + cant_add];
    for (int ii = 0; ii < cant_carac; ++ii) {  //copio viejo vector en el nuevo
        temp[ii] = array[ii];
    }
    delete array;
    cant_carac += cant_add;
    return temp;

}
