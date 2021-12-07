#include <iostream>

using namespace std;

void cargardatos(int *);

int *agregarvalores(int *,int &);

int main(){
    int *arreglo;
    int cant = 10;

    arreglo = new int[cant];
    cargardatos(arreglo);

    for (int ii = 0; ii < cant; ++ii) {
        cout<<arreglo[ii]<<endl;
    }

    arreglo = agregarvalores(arreglo,cant);

    for (int ii = 0; ii < cant; ++ii) {
        cout<<arreglo[ii]<<endl;
    }

    delete arreglo;

    return 0;
}

void cargardatos(int *arreglo){

    arreglo[0] = 1;
    arreglo[1] = 1;
    arreglo[2] = 1;
    arreglo[3] = 1;
    arreglo[4] = 1;
    arreglo[5] = 1;
    arreglo[6] = 1;
    arreglo[7] = 1;
    arreglo[8] = 1;
    arreglo[9] = 1;
}

int *agregarvalores(int *arreglo,int &cant){
    int *aux;
    int cant1;

    cout<<"cuantos valores desea agregar??"<<endl;
    cin>>cant1;

    aux = new int[cant1+cant];
    for (int ii = 0; ii < cant; ++ii) {
        aux[ii] = arreglo[ii];
    }
    delete arreglo;

    for(int ii=10;ii<cant1+cant;ii++){
        cout<<"agregar nuevos valores:"<<endl;
        cin >>aux[ii];
    }

    cant += cant1;

    return aux;
}