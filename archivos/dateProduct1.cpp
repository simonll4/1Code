#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define TAM 2

struct Product{

    string productName = " ";
    string brand = " ";
    float unitPrice= 0;
    string datePreparation = " ";
    int size = 0;

};

void addProducts(Product *);
void readList();

int main(){

    Product p[TAM];
    int option = 0;
    
    do{

        cout<<"0)Salir."<<endl;
        cout<<"1)Cargar lista de productos: "<<endl;
        cout<<"2)Leer lista de prodcutos: "<<endl;
        cin>>option;

        switch(option){
            case 0:
                break;
            case 1:
                addProducts(p);
                break;
            case 2:
                readList();
                break;
            default:
                cout<<"Ingrese una opcion correcta por favor"<<endl;
        }

    }while(option!=0);

    return 0;
}

void addProducts(Product *p){
    ofstream oFile;

    oFile.open("product1.txt");

    if(oFile.is_open()){
        for(int ii=0;ii<TAM;ii++){
            cout<<"Ingrese los datos del producto "<<ii+1<<endl;
            cout<<"Nombre: "<<endl;
            cin>>p[ii].productName;
            cout<<"Marca: "<<endl;
            cin>>p[ii].brand;
            cout<<"Precio unitario: "<<endl;
            cin>>p[ii].unitPrice;
            cout<<"Fecha de elaboracion: "<<endl;
            cin>>p[ii].datePreparation;
            cout<<"Tamanio: "<<endl;
            cin>>p[ii].size;

            oFile<<"Producto "<<ii+1<<endl;
            oFile<<"Nombre: "<<p[ii].productName<<endl;
            oFile<<"Marca: "<<p[ii].brand<<endl;
            oFile<<"Precio unitario: "<<p[ii].unitPrice<<endl;
            oFile<<"Fecha de elaboracion: "<<p[ii].datePreparation<<endl;
            oFile<<"Tamanio: "<<p[ii].size<<endl;
            oFile<<""<<endl;
            }
        oFile.close();
        }
    else{
        cout<<"el archivo no se pudo abrir";
    }
    }


void readList(){
    ifstream oFile;
    string text=" ";

    oFile.open("product1.txt");

    if(oFile.is_open()){
        while(!oFile.eof()){
            text+=oFile.get();
        }
        cout<<text;
        oFile.close();
    }
    else{
        cout<<"el archivo no existe";
    }

}
