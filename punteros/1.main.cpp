/*
 * 1.Escribir un programa que declare una variable llamada a, un puntero del tipo de la variable creada,
 * inicialice la variable e inicialice el puntero para que apunte a la variable creada. Luego que imprima por pantalla:
 * la dirección de memoria de la variable, el valor que almacena la variable, el valor del puntero y el valor al que
 * apunta el puntero.
 */

#include <iostream>



using namespace std;

int main(){

    int a=5;
    int *ptrA;

    ptrA=&a;


    cout<<"Direccion de memoria de la variable: "<<&a<<endl;
    cout<<"Valor de la variable: "<<a<<endl;
    cout<<"Valor del puntero: "<<ptrA<<endl;
    cout<<"Valor donde apunta el puntero: "<<*ptrA<<endl;



    return 0;
}
