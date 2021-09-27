/*
 * 3. Escribir un programa que cree un vector de estructura llamada articulo que tenga los atributos nombre y precio,
 * de tamaño 3. Luego mostrar el listado. Utilice punteros.
 */
#include <iostream>

using namespace std;

struct Article{

    string name;
    int price;

};

void show_list(Article *);
void add_date(Article *);

int main(){
    struct Article a1[3];

    add_date(a1);
    show_list(a1);

    return 0;
}

void add_date(Article *a1){

    for(int ii=0;ii<3;ii++){
        cout<<"Ingresar datos del producto "<<ii+1<<endl;
        cout<<"Nombre: "<<endl;
        cin>>a1[ii].name;
        cout<<"Precio: "<<endl;
        cin>>a1[ii].price;
    }
}

void show_list(Article *a1){

    for(int ii=0;ii<3;ii++){
        cout<<"Producto "<<ii+1<<endl;
        cout<<a1[ii].name<<endl;
        cout<<a1[ii].price<<endl;
    }
}