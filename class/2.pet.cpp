#include <iostream>
#include <string>
#include "2.pet_class.h"

#define TAM 2
using namespace std;

void carry_pet(Pet_class *);
void show_list(Pet_class *);
void show_list_type_animal(Pet_class *);

int main(){

    Pet_class pets[TAM];
    int option=0;

    cout<<"0)salir."<<endl;
    cout<<"1)Mostrar lista."<<endl;
    cout<<"2)Mostrar lista tipo animal."<<endl;
    do{
        cin>>option;
        switch(option){
            case 0:
                break;
            case 1:
                show_list(pets);
                break;
            case 2:
                show_list_type_animal(pets);
                break;
            default:
                cout<<"Ingrese una opcion correcta."<<endl;
        }

    }while(option!=0);


return 0;
}

void carry_pet(Pet_class *p){


}