/*
 * 3. Crear una clase Mascota con sus atributos (tipo_animal, raza, nombre_mascota, persona_resposable_edad)
 * y métodos (setter(), getter() y toString()). Luego, crear una clase Principal en donde se declare un vector
 * de objetos Mascota. Luego llenar este vector con datos y llamar a las  funciones mostrarListado y MostrarListado
 * por tipo_animal.
 *  EJEMPLO IMPRIMIENDO TODO CON TO_STRING
 */
#include "classMascota.h"
#define SIZE 2

int menu();

void cargarLista(Mascota *);
void mostrarListado(Mascota *);
void listadoTipo_animal(Mascota *);

int main(){
    Mascota mascota1[SIZE];
    int option;


    do {
        option = menu();
        switch (option) {
            case 0:
                break;
            case 1:
                cargarLista(mascota1);
                break;
            case 2:
                mostrarListado(mascota1);
                break;
            case 3:
                listadoTipo_animal(mascota1);
                break;
            default:
                cout << "Ingrese una opcion correcta por favor" << endl;
        }

    } while (option != 0);


    return 0;
}

int menu() {
    int option;
    cout << endl;
    cout << "OPERACIONES:" << endl;
    cout << "0)Salir." << endl;
    cout << "1)Cargar listado" << endl;
    cout << "2)Mostrar listado de mascotas" << endl;
    cout << "3)Mostrar listado por tipo de mascotas" << endl;
    cin >> option;
    return option;
}

void cargarLista(Mascota *array){
    string tipoAnimal;
    string raza;
    string nombre;
    int edad;

    cout<<"**INGRESAR DATOS**"<<endl;
    cout<<endl;
    for (int ii = 0; ii < SIZE; ++ii) {
        cout<<"DATOS MASCOTA"<<ii+1<<endl;
        cout<<"Tipo animal: "<<endl;
        cin>>tipoAnimal;
        cout<<"Raza: "<<endl;
        cin>>raza;
        cout<<"Nombre: "<<endl;
        cin>> nombre;
        cout<<"Edad: "<<endl;
        cin>>edad;

        array[ii].set_tipoAnimal(tipoAnimal);
        array[ii].set_raza(raza);
        array[ii].set_nombre(nombre);
        array[ii].set_edad(edad);
    }

}

void mostrarListado(Mascota *array){

    cout<<"**CARACTERISTICAS DE MASCOTAS**"<<endl;
    for (int ii = 0; ii < SIZE; ++ii) {
        array[ii].to_string();
        cout<<endl;
    }


}

void listadoTipo_animal(Mascota *array){

    cout<<"**LISTADO TIPO ANIMAL**"<<endl;
    for (int ii = 0; ii < SIZE; ++ii) {
        cout<<array[ii].get_tipoAnimal()<<endl;
    }
}
