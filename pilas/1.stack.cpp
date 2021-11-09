/*
 * 1. Crear un programa en la cual el usuario cargue una serie de valores en una pila. Luego se pide:
- mostrar en pantalla el los elementos de la pila
- borrar un elemento de la pila
- agregar un elemento que no este en la pila
 */
#include <iostream>
#include <stack>

using namespace std;

void enterDate(stack<int> *);

void showQueue(stack<int> );

void remove(stack<int> *);

void addDate(stack<int> *);

int main(){
    stack<int> s1;
    int option;

    do {
        cout << endl << "0)Para finalizar " << endl;
        cout << "1)Ingresar datos" << endl;
        cout << "2)Mostrar datos en pantalla. " << endl;
        cout << "3)Borrar elementos de la cola." << endl;
        cout << "4)agregar elemento que no este en la cola." << endl;
        cin >> option;

        switch (option) {
            case 0:
                break;
            case 1:
                enterDate(&s1);
                break;
            case 2:
                showQueue(s1);
                break;
            case 3:
                remove(&s1);
                break;
            case 4:
                addDate(&s1);
                break;
            default:
                cout << "Ingrese una opcion correcta" << endl;
        }


    } while (option != 0);


    return 0;
}

void enterDate(stack<int> *s1){
    int num;

    cout<<"Ingresar valores enteros, para finalizar ingresar 0: "<<endl;
    do{
        cin>>num;
        if(num!=0){
            s1->push(num);
        }
    }while(num !=0);

}

void showQueue(stack<int> ){

}


