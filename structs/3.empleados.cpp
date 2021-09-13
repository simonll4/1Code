/*3. Crear un programa que gestione el listado de los empleados de la empresa.
Para ello crear una estructura Empleado, en la cual contenga los siguientes datos:
legajo, puesto de trabajo, sueldo.
Luego crear un menú que permita las opciones:

a. agregar un empleado

b. mostrar todos los empleados

c. buscar un empleado por legajo para ver si existe o no.

Generar un vector de estructuras del tipo empleado de tamaño 3.
Para cada uno de los ítems del menú crear una función.
Agregar atributo a la estructura: anios_antiguedad
Agregar funciones: actualizarSueldo(float porcentaje), buscar, ordenar por sueldo, ordenar por anios_antiguedad*/

#include <iostream>
#include <string>

using namespace std;

struct employee{
    int legacy = 0;
    string job = " ";
    int salary = 0;
    int antiquity = 0;
};

int menu (void);
void add_employee (employee *);
void show_employee_list (employee *);
void search_employee (employee *);
void update_salary(employee *);
void salary_order(employee *);
void antiquity_order(employee *);

int main() {
    struct employee e[3];
    int option = 0;
    do{
        option=menu();
        switch(option){
            case 1:
                add_employee(e);
                break;
            case 2:
                show_employee_list(e);
                break;
            case 3:
                search_employee(e);
                break;
            case 4:
                update_salary(e);
                break;
            case 5:
                salary_order(e);
                break;
            case 6:
                antiquity_order(e);
                break;
            default:
                cout<<"La opcion ingresada no es valida"<<endl;
        }
    } while(option!=0);

    return 0;
}

int menu (){
    int op = 0;
    cout<<"Ingrese la opcion a realizar"<<endl;
    cout<<"0) Salir"<<endl;
    cout<<"1) Agregar empleado"<<endl;
    cout<<"2) Mostrar lista de empleados"<<endl;
    cout<<"3) Buscar empleado por numero de legajo"<<endl;
    cout<<"4) Actualizar salario"<<endl;
    cout<<"5) Ordenar empleados por salario"<<endl;
    cout<<"6) Ordenar empleados por antiguedad"<<endl;
    cin>>op;
    return op;
}

void add_employee(employee *em){
    cout<<endl;
    for(int ii = 0; ii<3 ;ii++){
        cout<<"Ingrese el numero de legajo del empleado"<<endl;
        cin>>em[ii].legacy;
        cout<<"Ingrese el puesto del empleado"<<endl;
        getline(cin,em[ii].job,'.');
        cout<<"Ingrese el salario del empleado"<<endl;
        cin>>em[ii].salary;
        cout<<"Ingrese los años de antigüedad del empleado"<<endl;
        cin>>em[ii].antiquity;
        cout<<endl;
    }
}

void show_employee_list (employee *em){
    cout<<endl;
    for(int ii = 0;ii < 3;ii++){
        cout<<"Legajo: "<<em[ii].legacy<<endl;
        cout<<"Puesto: "<<em[ii].job<<endl;
        cout<<"Salario: "<<em[ii].salary<<endl;

        cout<<"Años de antigüedad: "<<em[ii].antiquity<<endl;
        cout<<endl;
    }
}

void search_employee (employee *em){
    int l = 0;
    cout<<endl;
    cout<<"Ingrese el numero de legajo del empleado"<<endl;
    cin>>l;
    for(int ii = 0;ii < 3;ii++){
        if(em[ii].legacy == l){
            cout<<"Legajo: "<<em[ii].legacy<<endl;
            cout<<"Puesto: "<<em[ii].job<<endl;
            cout<<"Salario: "<<em[ii].salary<<endl;
            cout<<"Años de antigüedad: "<<em[ii].antiquity<<endl;
        }
    }
    cout<<endl;
}

void update_salary(employee *em){

    float percent=0;
    int legacy=0;

    cout<<"Numero de legajo del empleado: "<<endl;
    cin>>legacy;
    cout<<"Ingrese el porcentaje a aumentar: "<<endl;
    cin>>percent;

    for(int ii = 0;ii < 3;ii++){
        if(em[ii].legacy == legacy){
            em[ii].salary = em[ii].salary+((em[ii].salary*percent)/100);
            cout<<"Salario actualizado: "<<em[ii].salary<<endl;
        }
    }
}

void salary_order (employee *em){

    employee auxiliar;

    for(int jj=0;jj<2;jj++){
        for(int ii=0;ii<2;ii++){
            if(em[ii].salary>em[ii+1].salary){
                auxiliar=em[ii];
                em[ii]=em[ii+1];
                em[ii+1]=auxiliar;
            }
        }
    }
}

void antiquity_order (employee *em){

    employee auxiliar;

    for(int jj=0;jj<2;jj++){
        for(int ii=0;ii<2;ii++){
            if(em[ii].antiquity>em[ii+1].antiquity){
                auxiliar=em[ii];
                em[ii]=em[ii+1];
                em[ii+1]=auxiliar;
            }
        }
    }
}