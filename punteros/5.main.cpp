/*
 * 5.  Escribir un programa que intercambie los valores enteros de a y b, para ello crea una función e
 * intercambie los números usando punteros.
 */
#include <iostream>

using namespace std;

void swap(int *,int *);

int main() {

    int a = 10;
    int b = 5;

    cout<<"valors iniciales: a="<<a<< " b="<<b<<endl;
    swap(&a,&b);
    return 0;
}

void swap(int *a,int *b){

    int aux;

    aux=*a;
    *a=*b;
    *b=aux;
    cout<<"valors finales: a="<<*a<< " b="<<*b<<endl;
}