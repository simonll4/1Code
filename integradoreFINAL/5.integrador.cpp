#include <iostream>
#include "LinkedList.h"
#include <stack>
#include <queue>
#include <fstream>

#define ANTIGUEDAD 30
#define LINEACODIGO 15
#define SINTAXIS 3
#define ENLACE 5
#define EJECUCION 7
#define SEMANTICA 10

using namespace std;

struct Datos {
    int num;
    float antiguedad = 0;
    float cantLineas = 0;
    float eSintaxis = 0;
    float eEnlace = 0;
    float eEjecucion = 0;
    float eSemantica = 0;
};

struct Incentivos {
    int num = 0;
    float antiguedad = 0;
    float Lineas = 0;
    float Errores = 0;
    float total = 0;
};

int menu();

void carryDates(LinkedList<Datos> &, Datos);

void antiguedad(LinkedList<Datos> &, LinkedList<Incentivos> &, Incentivos);

void cantLineas(LinkedList<Datos> &, LinkedList<Incentivos> &, Incentivos);

void errores(LinkedList<Datos> &, LinkedList<Incentivos> &, Incentivos);

void total(LinkedList<Incentivos> &, Incentivos);

void mostrarIncentivos(LinkedList<Incentivos>);

void mejorProgramador(LinkedList<Datos>);

void incentivosTotales(LinkedList<Incentivos>);

void penalizaciones(LinkedList<Incentivos>);

void guardarArchivo(LinkedList<Incentivos>);

int main() {
    LinkedList<Datos> l1;
    LinkedList<Incentivos> l2;
    Datos d1;
    Incentivos i1;
    int option;


    do {
        option = menu();
        switch (option) {
            case 0:
                break;
            case 1:
                carryDates(l1, d1);
                antiguedad(l1, l2, i1);
                cantLineas(l1, l2, i1);
                errores(l1, l2, i1);
                total(l2, i1);
                break;
            case 2:
                mostrarIncentivos(l2);
                break;
            case 3:
                mejorProgramador(l1);
                break;
            case 4:
                incentivosTotales(l2);
                break;
            case 5:
                penalizaciones(l2);
                break;
            case 6:
                guardarArchivo(l2);
                break;
            default:
                cout << "Ingrese una opcion correcta por favor" << endl;
        }
    } while (option != 0);

    return 0;
}

int menu() {
    int option;
    cout << endl;
    cout << "OPERACIONES:" << endl;
    cout << "0)Salir." << endl;
    cout << "1)Cargar datos." << endl;
    cout << "2)Listado de incentivos por los programadores." << endl;
    cout << "3)Mejor programador del mes." << endl;
    cout << "4)Incentivos totales por programador." << endl;
    cout << "5)Penalizaciones por programador." << endl;
    cout << "6)Guardar incentivos en archivo." << endl;
    cin >> option;
    return option;
}

void carryDates(LinkedList<Datos> &l1, Datos d1) {

    cout << "INGRESAR DATOS POR PROGRAMADOR (para finalizar ingrese 0 en 'numero de programador')" << endl;
    do {
        cout << "Numero de programador" << endl;
        cin >> d1.num;
        if (d1.num != 0) {
            cout << "Atiguedad(en meses): " << endl;
            cin >> d1.antiguedad;
            cout << "Cantidad de lineas programadas en el mes: " << endl;
            cin >> d1.cantLineas;
            cout << "*******ERRORES********: " << endl;
            cout << "Errores de sintaxis: " << endl;
            cin >> d1.eSintaxis;
            cout << "Errores de enlace: " << endl;
            cin >> d1.eEnlace;
            cout << "Errores de ejecucion: " << endl;
            cin >> d1.eEjecucion;
            cout << "Errores de semantica: " << endl;
            cin >> d1.eSemantica;
            l1.push_back(d1);
        }
    } while (d1.num != 0);
}

void antiguedad(LinkedList<Datos> &l1, LinkedList<Incentivos> &l2, Incentivos i1) {

    for (int ii = 0; ii < l1.size(); ++ii) {
        i1.antiguedad = (l1.get(ii).antiguedad * ANTIGUEDAD);
        i1.num = l1.get(ii).num;
        l2.push_back(i1);
    }

}

void cantLineas(LinkedList<Datos> &l1, LinkedList<Incentivos> &l2, Incentivos i1) {

    for (int ii = 0; ii < l1.size(); ++ii) {
        i1 = l2.get(ii);
        i1.Lineas = (l1.get(ii).cantLineas * LINEACODIGO);
        l2.replace(ii, i1);
    }

}

void errores(LinkedList<Datos> &l1, LinkedList<Incentivos> &l2, Incentivos i1) {
    float errores = 0;
    float cant = 0;


    for (int ii = 0; ii < l1.size(); ++ii) {
        cant += l1.get(ii).eSintaxis;
        cant += l1.get(ii).eEnlace;
        cant += l1.get(ii).eEjecucion;
        cant += l1.get(ii).eSemantica;

        if (cant >= l1.get(ii).cantLineas) {
            i1 = l2.get(ii);
            i1.Lineas = 0;
            i1.antiguedad = 0;
            i1.Errores = 0;
            i1.total = 0;
            l2.replace(ii, i1);
        } else {
            errores += l1.get(ii).eSintaxis * SINTAXIS;
            errores += l1.get(ii).eEnlace * ENLACE;
            errores += l1.get(ii).eEjecucion * EJECUCION;
            errores += l1.get(ii).eSemantica * SEMANTICA;
            i1 = l2.get(ii);
            i1.Errores = errores;
            l2.replace(ii, i1);
        }
        cant = 0;
    }

}

void total(LinkedList<Incentivos> &l2, Incentivos i1) {

    float total;

    for (int ii = 0; ii < l2.size(); ++ii) {
        total = (l2.get(ii).Lineas + l2.get(ii).antiguedad - l2.get(ii).Errores);
        i1 = l2.get(ii);
        i1.total = total;
        l2.replace(ii, i1);
    }
}

void mostrarIncentivos(LinkedList<Incentivos> l2) {

    cout << "******INCENTIVOS(en pesos)******" << endl;
    for (int ii = 0; ii < l2.size(); ++ii) {
        cout << "Numero de programador: ";
        cout << l2.get(ii).num << "\t";
        cout << "Por Antiguedad: ";
        cout << l2.get(ii).antiguedad << "$" << "\t";
        cout << "Por Lineas de codigo: ";
        cout << l2.get(ii).Lineas << "$" << "\t";
        cout << "Descuento por Errores: " << "\t";
        cout << l2.get(ii).Errores << "$" << "\t";
        cout << "Total: " << "\t";
        cout << l2.get(ii).total << "$" << "\t";
        cout << endl;
        cout << endl;
    }
}

void mejorProgramador(LinkedList<Datos> l1) {
    int pos = 0;
    float aux = 0;
    float cant = 0;


    for (int ii = 0; ii < l1.size(); ++ii) {
        cant += l1.get(ii).eSintaxis;
        cant += l1.get(ii).eEnlace;
        cant += l1.get(ii).eEjecucion;
        cant += l1.get(ii).eSemantica;
        if (ii == 0) {
            aux = l1.get(ii).cantLineas - cant;
            pos = ii;
        } else {
            if (aux < l1.get(ii).cantLineas - cant) {
                aux = l1.get(ii).cantLineas - cant;
                pos = ii;
            }
        }
    }

    cout << "MEJOR PROGRAMADOR DEL MES: " << endl;
    cout << "Numero de programador: ";
    cout << l1.get(pos).num << "\t";
    cout << "Antiguedad: ";
    cout << l1.get(pos).antiguedad << "\t";
    cout << "Cant Lineas de codigo: ";
    cout << l1.get(pos).cantLineas << "\t";
    cout << "Errores semantica: " << "\t";
    cout << l1.get(pos).eSemantica << "\t";
    cout << "Errores sintaxis: " << "\t";
    cout << l1.get(pos).eSintaxis << "\t";
    cout << "Errores Enlace: " << "\t";
    cout << l1.get(pos).eEnlace << "\t";
    cout << "Errores ejecucion: " << "\t";
    cout << l1.get(pos).eEjecucion << "\t";
    cout << endl;
}

void incentivosTotales(LinkedList<Incentivos> l2) {
    stack<Incentivos> s1;

    for (int ii = 0; ii < l2.size(); ++ii) {
        s1.push(l2.get(ii));
    }

    cout << "*****INCENTIVOS TOTALES POR PROGRAMADOR******" << endl;
    while (!s1.empty()) {
        cout << "Programador: ";
        cout << s1.top().num << endl;
        cout << "Incentivo total: ";
        cout << s1.top().total << endl;
        s1.pop();
    }
}

void penalizaciones(LinkedList<Incentivos> l2) {
    queue<Incentivos> q1;

    for (int ii = 0; ii < l2.size(); ++ii) {
        q1.push(l2.get(ii));
    }

    cout << "*****PENALIZACIONES TOTALES POR PROGRAMADOR******" << endl;
    while (!q1.empty()) {
        cout << "Programador: ";
        cout << q1.front().num << endl;
        cout << "Incentivo total: ";
        cout << q1.front().Errores << endl;
        q1.pop();
    }
}

void guardarArchivo(LinkedList<Incentivos> l2) {
    ofstream f1;

    f1.open("Incentivos.txt");
    for (int ii = 0; ii < l2.size(); ++ii) {
        f1 << "Numero de programador: ";
        f1 << l2.get(ii).num << "\t";
        f1 << "Por Antiguedad: ";
        f1 << l2.get(ii).antiguedad << "$" << "\t";
        f1 << "Por Lineas de codigo: ";
        f1 << l2.get(ii).Lineas << "$" << "\t";
        f1 << "Descuento por Errores: " << "\t";
        f1 << l2.get(ii).Errores << "$" << "\t";
        f1 << "Total: " << "\t";
        f1 << l2.get(ii).total << "$" << "\t";
        f1 << endl;
        f1 << endl;
    }
    f1.close();
}