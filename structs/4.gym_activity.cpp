/*4. Crear una clase Actividad, las mismas corresponden a las actividades de un gym.
 * Atributos: nombre, cupo, dias de la semana, horario, cant_inscriptos.
 * Funciones: mostrar,buscar, mostrar actividades que aun no tienen el cupo lleno.
 */

#include <iostream>
#include <string>
#define TAM 3

using namespace std;

struct Activity{
    int activity_code;
    string name;
    int capacity;
    int days;
    string schedule;
    int c_enrolled;
};

void menu (void);
void dates_default(Activity *);
void show (Activity *);
void search (Activity *);
void show_activities (Activity *);

int main(){
    struct Activity ac[TAM];
    int option;
    dates_default(ac);

    menu();
    do{
        cout<<"Seleccione una opcion: "<<endl;
        cin>>option;
        switch(option){
            case 1:
                show(ac);
                break;
            case 2:
            search(ac);
                break;
            case 3:
                show_activities(ac);
                break;
            default:
                cout<<"Ingrese una opcion correcta."<<endl;

        }

    }while(option!=0);


    return 0;
}

void menu (void){

    cout<<"1. Mostrar lista de actividades\n2. Buscar actividad\n3. Mostrar actividades con cupo disponible\n0. Salir\n"<<endl;
}

void dates_default(Activity *ac){

    ac[0].name = "Funcional";
    ac[0].capacity = 10;
    ac[0].days = 3;
    ac[0].schedule = "Matutino";
    ac[0].c_enrolled = 10;
    ac[1].name = "Zumba";
    ac[1].capacity = 20;
    ac[1].days = 3;
    ac[1].schedule = "Matutino";
    ac[1].c_enrolled = 17;
    ac[2].name = "Musculacion";
    ac[2].capacity = 25;
    ac[2].days = 5;
    ac[2].schedule = "Matutino y Nocturno";
    ac[2].c_enrolled = 21;

}

void show (Activity *ac){
    for( int ii = 0 ; ii < TAM ; ii++ ){
        cout<<"--------------------------------"<<endl;
        cout<<"Actividad: "<<ac[ii].name<<endl;
        cout<<"Cupo: "<<ac[ii].capacity<<endl;
        cout<<"Dias: "<<ac[ii].days<<endl;
        cout<<"Horario: "<<ac[ii].schedule<<endl;
        cout<<"Inscriptos: "<<ac[ii].c_enrolled<<endl;
        cout<<"---------------------------------"<<endl;
    }
}

void search(Activity *ac){

    string name = " ";

    cout<<"Ingrese el nombre de la actividad para obtener el detalle: "<<endl;
    cin>>name;
    for(int ii = 0 ; ii < TAM ; ii++ ){
        if( name == ac[ii].name ){
            cout<<"--------------------------------"<<endl;
            cout<<"Actividad: "<< ac[ii].name<<endl;
            cout<<"Cupo: "<<ac[ii].capacity<<endl;
            cout<<"Dias: "<<ac[ii].days<<endl;
            cout<<"Horario: "<<ac[ii].schedule<<endl;
            cout<<"Inscriptos: "<<ac[ii].c_enrolled<<endl;
            cout<<"---------------------------------"<<endl;
        }
    }
}

void show_activities(Activity *ac){
    for( int ii = 0 ; ii < TAM ; ii++){
        if( ac[ii].capacity != ac[ii].c_enrolled ){
            cout<<"--------------------------------"<<endl;
            cout<<"Actividad: "<< ac[ii].name<<endl;
            cout<<"Cupo: "<<ac[ii].capacity<<endl;
            cout<<"Dias: "<<ac[ii].days<<endl;
            cout<<"Horario: "<<ac[ii].schedule<<endl;
            cout<<"Inscriptos: "<<ac[ii].c_enrolled<<endl;
            cout<<"---------------------------------"<<endl;
        }
    }
};