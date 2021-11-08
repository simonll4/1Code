#include <iostream>
#include <string>
#include <fstream>

using namespace std;


struct Product{

    string productName = " ";
    string brand = " ";
    float unitPrice= 0;
    string datePreparation = " ";
    int size = 0;

};

int main(){
    ofstream oFile;
    Product p1;

    cout<<"Ingrese datos del producto: "<<endl;
    cout<<"Nombre: "<<endl;
    cin>>p1.productName;
    cout<<"Marca: "<<endl;
    cin>>p1.brand;
    cout<<"Precio unitario: "<<endl;
    cin>>p1.unitPrice;
    cout<<"Fcha de elaboracion: "<<endl;
    cin>>p1.datePreparation;
    cout<<"Tamanio: "<<endl;
    cin>>p1.size;


    oFile.open("Product.txt");
    if(oFile.is_open()){

        oFile<<"Nombre: "<<p1.productName<<endl;
        oFile<<"Marca: "<<p1.brand<<endl;
        oFile<<"Precio unitario: "<<p1.unitPrice<<endl;
        oFile<<"Fcha de elaboracion: "<<p1.datePreparation<<endl;
        oFile<<"Tamanio: "<<p1.size<<endl;

    }
    else{
        cout<<"el archivo no se pudo crear"<<endl;
    }

    oFile.close();

    return 0;
}