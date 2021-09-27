/*
 * 2. Desarrollar un programa que declare e inicialice un vector tipo char con el abecedario.
 * Luego mostrar en pantalla el abecedario en mayúscula y minúscula, utilizando punteros. Nota:
 * la función para pasar a mayúscula es toupper() y a minúsculas es tolower(). Ejemplo: cadena[i] = tolower(cadena[i]);
 */
#include <iostream>
#include <string>

using namespace std;

void mayus(char *);
void minuscula(char *);

int main(){

    char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    mayus(alphabet);
    minuscula(alphabet);

    return 0;
}

void mayus(char *abc){
    string text;

    for(int ii=0;ii<26;ii++){
        text+=toupper(abc[ii]);
    }
    cout<<"Mayuscula:"<<text<<endl;

}
void minuscula(char *abc){
    string text;

    for(int ii=0;ii<26;ii++){
        text+=tolower(abc[ii]);
    }
    cout<<"Minuscula:"<<text<<endl;
}