#include "2.pet_class.h"

Pet_class:: Pet_class(){

}
void Pet_class::set_animal_type(string animal_type){

    this->animal_type= animal_type;
}
string Pet_class::get_animal_type(){

    return animal_type;
}
void Pet_class::set_race(string race){

    this->race=race;
}
string Pet_class::get_race(){

    return race;
}
void Pet_class::set_pet_name(string pet_name){

    this->pet_name=pet_name;
}
string Pet_class::get_pet_name(){

    return pet_name;
}
void Pet_class::set_responsable_person(string responsable_person){

    this->responsible_person=responsable_person;
}
string Pet_class::get_responsable_person(){

    return responsible_person;
}
void Pet_class::set_age(int age){

    this->age=age;
}
int Pet_class::get_age(){

    return age;
}

