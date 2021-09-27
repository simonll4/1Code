/*
 * 4. Desarrolle un programa que declare e inicialice un vector de 5 valores (4.5,8,2.3,1.1,3). Luego,
 * se pide que halle el valor máximo, mínimo y el promedio de ellos. Finalmente mostrar los resultados.
 * Utilice punteros para realizar el ejercicio.
 */

#include <iostream>

using namespace std;

void min(float *);
void max(float *);
void average(float *);

int main(){

    float vector[5]={4.5,8,2.3,1.1,3};

    min(vector);
    max(vector);
    average(vector);

    return 0;
}

void min(float *vector){
    float aux=1000;

    for(int ii=0;ii<5;ii++){
        if(vector[ii] < aux){
            aux=vector[ii];
        }
    }
    cout<<"Minimo:"<<aux<<endl;
}

void max(float *vector){
    float aux=0;

    for(int ii=0;ii<5;ii++){
        if(vector[ii]>aux){
            aux=vector[ii];
        }
    }
    cout<<"Maximo:"<<aux<<endl;
}

void average(float *vector){

    float sum = 0;
    float av;

    for(int ii=0;ii<5;ii++){
        sum+=vector[ii];
    }
    av = sum/5;

    cout<<"Promedio:"<<av<<endl;


}
