#include "classMascota.h"


Mascota::Mascota() {

}

void Mascota::set_tipoAnimal(string tipoAnimal) {

    this->tipoAnimal = tipoAnimal;
}

void Mascota::set_raza(string raza) {

    this->raza = raza;
}

void Mascota::set_nombre(string nombre) {

    this->nombre = nombre;
}

void Mascota::set_edad(int edad) {

    this->edad = edad;
}

string Mascota::get_tipoAnimal(){
    return tipoAnimal;
}

void Mascota::to_string() {
    cout << "Tipo de animal: " << tipoAnimal << endl;
    cout << "Raza: " << raza << endl;
    cout << "nombre: " << nombre << endl;
    cout << "edad: " << std::to_string(edad) << endl;
}