#include <iostream>
#include "LinkedList.h"

using namespace std;

struct Clothes{
    int code;
    string name;
    int waist;
    float listPrice;
    float publicPrice;
    int stock;
    int sold;
};

void saveDates(LinkedList<Clothes> *,Clothes);

int main(){
    struct Clothes c1;
    LinkedList<Clothes> l1;

    saveDates(&l1,c1);


    return 0;
}

void saveDates(LinkedList<Clothes> *l1,Clothes c1){



}