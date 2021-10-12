#include <iostream>
#include <fstream>

using namespace std;

#define SIZE 3


struct Celular {

    int codigo;
    string marca;
    float precioLista;
    float precioPublico;
    int stock;


};

void cargaDefecto(Celular *);

int menu();

void mostrarLista(Celular *);

void lista_sinStock(Celular *);

void precioPublico(Celular *);

void ordenar(Celular *);

int main() {
    struct Celular cel1[SIZE];
    int option;

    cargaDefecto(cel1);

    do {
        option = menu();
        switch (option) {
            case 0:
                break;
            case 1:
                mostrarLista(cel1);
                break;
            case 2:
                lista_sinStock(cel1);
                break;
            case 3:
                precioPublico(cel1);
                break;
            case 4:
                ordenar(cel1);
                break;
            default:
                cout << "Ingrese una opcion correcta por favor" << endl;
        }
    } while (option != 0);

    return 0;
}

void cargaDefecto(Celular *cel1) {
    cel1[0].codigo = 1;
    cel1[0].marca = "Apple";
    cel1[0].precioLista = 1000;
    cel1[0].precioPublico = 0;
    cel1[0].stock = 3;
    cel1[1].codigo = 3;
    cel1[1].marca = "Nokia";
    cel1[1].precioLista = 300;
    cel1[1].precioPublico = 0;
    cel1[1].stock = 4;
    cel1[2].codigo = 2;
    cel1[2].marca = "Samsung";
    cel1[2].precioLista = 600;
    cel1[2].precioPublico = 0;
    cel1[2].stock = 0;
}

int menu() {
    int option;
    cout << endl;
    cout << "OPERACIONES:" << endl;
    cout << "0)Salir." << endl;
    cout << "1)Mostrar listado completo de celulares" << endl;
    cout << "2)Listado completo de celulares sin stock, pedir stock" << endl;
    cout << "3)Precio al publico" << endl;
    cout << "4)ordenar por precio al publico" << endl;
    cin >> option;
    return option;
}

void mostrarLista(Celular *cel1) {

    cout << "**LISTADO COMPLETO DE CELULARES**" << endl;
    for (int ii = 0; ii < SIZE; ++ii) {
        cout << endl;
        cout << "CELULAR: " << ii + 1 << endl;
        cout << "Codigo: " << cel1[ii].codigo << endl;
        cout << "Marca: " << cel1[ii].marca << endl;
        cout << "Precio Lista: " << cel1[ii].precioLista << endl;
        cout << "Precio Publico: " << cel1[ii].precioPublico << endl;
        cout << "Stock: " << cel1[ii].stock << endl;
        cout << endl;
    }

}

void lista_sinStock(Celular *cel1) {

    ofstream file;

    cout << "**LISTADO DE CELULARES SIN STOCK**" << endl;
    for (int ii = 0; ii < SIZE; ++ii) {
        if (cel1[ii].stock == 0) {
            cout << "Celular sin stock" << endl;
            cout << "Codigo: " << cel1[ii].codigo << endl;
            cout << "Marca: " << cel1[ii].marca << endl;
            cout << "Precio Lista: " << cel1[ii].precioLista << endl;
            cout << "Precio Publico: " << cel1[ii].precioPublico << endl;
            cout << "Stock: " << cel1[ii].stock << endl;

            file.open("stock.txt");
            if (file.is_open()) {
                file << "Codigo: " << cel1[ii].codigo << endl;
                file << "Marca: " << cel1[ii].marca << endl;
                file << "Precio Lista: " << cel1[ii].precioLista << endl;
                file << "Calcular precio Publico: " << cel1[ii].precioPublico << endl;
                file << "Stock: " << cel1[ii].stock << endl;
            }

        }

    }

}

void precioPublico(Celular *cel1) {


    for (int ii = 0; ii < SIZE; ++ii) {
        cel1[ii].precioPublico = cel1[ii].precioLista * 0.3;
    }
    cout << "******************************" << endl;
    cout << "Precio al pueblico actualizado" << endl;
    cout << "******************************" << endl;

}

void ordenar(Celular *cel1) {

    int codigo2;
    string marca2;
    float precioLista2;
    float precioPublico2;
    int stock2;

    for (int ii = 0; ii < SIZE; ++ii) {
        for (int jj = 0; jj < SIZE; ++jj) {
            if (cel1[jj].precioPublico < cel1[jj + 1].precioPublico) {

                precioPublico2 = cel1[jj].precioPublico;
                cel1[jj].precioPublico = cel1[jj + 1].precioPublico;
                cel1[jj + 1].precioPublico = precioPublico2;

                marca2 = cel1[jj].marca;
                cel1[jj].marca = cel1[jj + 1].marca;
                cel1[jj + 1].marca = marca2;

                codigo2 = cel1[jj].codigo;
                cel1[jj].codigo = cel1[jj + 1].codigo;
                cel1[jj + 1].codigo = codigo2;

                precioLista2 = cel1[jj].precioLista;
                cel1[jj].precioLista = cel1[jj + 1].precioLista;
                cel1[jj + 1].precioLista = precioLista2;

                stock2 = cel1[jj].stock;
                cel1[jj].precioLista = cel1[jj + 1].stock;
                cel1[jj + 1].stock = stock2;

            }

        }
    }
    cout << "****************" << endl;
    cout << "Lista ordenada" << endl;
    cout << "****************" << endl;
}

