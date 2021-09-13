
#ifndef CLION_CODIGOS_PET_CLASS_H
#define CLION_CODIGOS_PET_CLASS_H
#include <string>

using namespace std;

class Pet_class{

private:

    string animal_type;
    string race;
    string pet_name;
    string responsible_person;
    int age;

public:

    Pet_class();
    void set_animal_type(string);
    string get_animal_type();
    void set_race(string);
    string get_race();
    void set_pet_name(string);
    string set_pet_name();
    void set_responsable_person(string);
    string get_responsable_person();
    void set_age(int);
    int get_age();
    string to_string(void);

};


#endif //CLION_CODIGOS_PET_CLASS_H
