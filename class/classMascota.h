
#ifndef CLION_CODIGOS_CLASSMASCOTA_H
#define CLION_CODIGOS_CLASSMASCOTA_H
#include <iostream>
#include "classMascota.h"
#include <string>


using namespace std;

class Mascota {

private:
    string tipoAnimal;
    string raza;
    string nombre;
    int edad;

public:
    Mascota();
    //setters
    void set_tipoAnimal(string);
    void set_raza(string);
    void set_nombre(string);
    void set_edad(int);
    //getters
    string get_tipoAnimal();
    //impresion
    void to_string();
};


#endif //CLION_CODIGOS_CLASSMASCOTA_H
