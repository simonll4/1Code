#include <iostream>
using namespace std;

int menu ();
char * load (char *,int );
char * resize (const char *,int *,int);
void show (char *,int);
void show_inverted (char *,int);


int main(){

    int characters = 0;
    int characters_toadd = 0;
    int option = 0;
    char * text;

    do{
        option = menu();
        switch(option){
            case 1:
                cout<<"Introduzca la cantidad de caracteres a escribir"<<endl;
                cin>>characters;
                text = load(text,characters);
                break;
            case 2:
                cout<<"Ingrese la cantidad de caracteres a agregar"<<endl;
                cin>>characters_toadd;
                text = resize(text,&characters,characters_toadd);
                text = load(text,characters);
                cout<<endl;
                break;
            case 3:
                show(text,characters);
                cout<<endl;
                show_inverted(text,characters);
                cout<<endl;
                break;
            default:
                cout<<"Introduzca una opcion valida"<<endl;

        }
    }while(option != 0);

    return 0;
}

int menu (){
    int op = 0;
    cout<<"Ingrese la opcion a realizar"<<endl;
    cout<<"1. Reserva de memoria e introduccion de datos enteros"<<endl;
    cout<<"2. Agregar reserva de memoria e introduccion de nuevos datos enteros"<<endl;
    cout<<"3. Mostrar los datos en el orden y orden invertido al que fueron introducidos"<<endl;
    cout<<"0. Salir"<<endl;
    cin>>op;
    return op;
}

char * load (char * t,int c){

    t= new char [c];
    cout<<"Ingrese el texto"<<endl;
    cin.getline(t,c,'.');
    while(getchar() != '\n');
    cin.clear();

    return t;
}

char * resize (const char * t,int *c,int c_a){
    char * tmp;
    tmp = new char [*c];
    for(int ii = 0; ii < sizeof(t); ii++){
        tmp[ii] = t[ii];
    }
    delete t;
    *c = *c+c_a;
    return tmp;
}

void show (char * t, int c){
    cout<<"Caracteres en orden"<<endl;
    for(int ii = 0; ii < c; ii++){
        cout<<t[ii];
    }
}

void show_inverted (char * t,int c){
    cout<<"Caracteres en orden inverso"<<endl;
    for(int ii = 0; ii < c; ii++){
        cout<<t[(c-1)-ii];
    }
}