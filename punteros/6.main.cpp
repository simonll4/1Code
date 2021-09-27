/*
 * 6. Escribir un programa que contenga un menú de opciones con las operaciones que puede realizar: sumar, restar,
 * multiplicar y dividir dos números, elevar a una potencia y calcular la raíz de número.  Las operaciones deben ser
 * programadas utilizando funciones y punteros.
 */
#include <iostream>

using namespace std;

void sum(float *,float *);
void subtracion(float *,float *);
void multiplication(float *,float *);
void division(float *,float *);
void power(float *,float *);
void square(float *,float *);

void menu(void);

int main() {

    int option = 0;

    menu();
    do {
        cout << "Ingrese operacion a realizar: ";
        cin >> option;
        cout<<"Ingrese 2 numeros en el orden que quiere operar";
        switch (option) {
            case 0:
                break;
            case 1:
                sum();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;


        }
    } while (option != 0);


    return 0;
}

void menu(void) {
    cout << "Operaciones con 2 numeros:" << endl;
    cout << "0)Salir." << endl;
    cout << "1)Sumar" << endl;
    cout << "2)Restar" << endl;
    cout << "3)Multiplicar" << endl;
    cout << "4)Dividir" << endl;
    cout << "5)Elevar a una potencia" << endl;
    cout << "6)Raiz cuadrada" << endl;
}