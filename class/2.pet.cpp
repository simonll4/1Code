#include <iostream>
#include <string>
#include "2.pet_class.h"

#define TAM 2
using namespace std;

void add_date(Pet_class *);
void show_list(Pet_class *);
void show_list_type_animal(Pet_class *);

int main(){

    Pet_class pets[TAM];
    int option=0;

    do{
        cout<<"0)salir."<<endl;
        cout<<"1)Mostrar lista."<<endl;
        cout<<"2)Mostrar lista tipo animal."<<endl;
        cout<<"3)Cargar datos de mascotas."<<endl;
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
            case 3:
                add_date(pets);
                break;
            default:
                cout<<"Ingrese una opcion correcta."<<endl;
        }

    }while(option!=0);


return 0;
}

void add_date(Pet_class *p){

    string animal_type,race,pet_name,responsable_person;
    int age=0;

    for(int ii=0;ii<TAM;ii++){
        cout<<"Ingresar datos de la mascota: "<<ii+1<<endl;
        cout<<"Tipo: "<<endl;
        cin>>animal_type;
        cout<<"Race: "<<endl;
        cin>>race;
        cout<<"Nombre: "<<endl;
        cin>>pet_name;
        cout<<"Persona responsable: "<<endl;
        cin>>responsable_person;
        cout<<"Edad: "<<endl;
        cin>>age;

        p[ii].set_animal_type(animal_type);
        p[ii].set_race(race);
        p[ii].set_pet_name(pet_name);
        p[ii].set_responsable_person(responsable_person);
        p[ii].set_age(age);
    }



}
void show_list(Pet_class *p){

    for(int ii=0;ii<TAM;ii++){
        cout<<"Datos de la mascota "<<ii+1<<endl;
        cout<<"Tipo de animal: "<<p[ii].get_animal_type()<<endl;
        cout<<"Raza: "<<p[ii].get_race()<<endl;
        cout<<"Nombre: "<<p[ii].get_pet_name()<<endl;
        cout<<"Persona responsable: "<<p[ii].get_responsable_person()<<endl;
        cout<<"Edad: "<<p[ii].get_age()<<endl;
    }

}

void show_list_type_animal(Pet_class *p){

    for(int ii=0;ii<TAM;ii++){
        cout<<"Lista tipo de mascotas: "<<endl;
        cout<<p[ii].get_animal_type()<<endl;
    }
}