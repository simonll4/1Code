#include <iostream>
#include "1.book.h"



void show_list(Book *);
void sum_prices(Book *);

int main()
{
    class Book list_books[3];
    string name;
    string gender;
    int pages;
    int price;
    int option=0;

    cout<<"Listar tres libros con sus datos"<<endl;
    for(int ii = 0; ii < 3 ; ii++ ){
        cout<<"Ingrese nombre del libro:"<<endl;
        cin>>name;
        list_books[ii].set_name(name);
        cout<<"Ingrese genero del libro:"<<endl;
        cin>>gender;
        list_books[ii].set_gender(gender);
        cout<<"Ingrese cantidad de paginas del libro:"<<endl;
        cin>>name;
        list_books[ii].set_pages(pages);
        cout<<"Ingrese el precio del libro:"<<endl;
        cin>>price;
        list_books[ii].set_price(price);
    }

    cout<<"0)salir."<<endl;
    cout<<"1)mostrar lista."<<endl;
    cout<<"2)sumar precios."<<endl;
    do{
        cin>>option;
        switch(option){
            case 0:
                break;
            case 1:
                show_list(list_books);
                break;
            case 2:
                sum_prices(list_books);
                break;
            default:
                cout<<"Ingrese una opcion correcta"<<endl;
        }
    }while(option!=0);

    for(int ii = 0 ; ii < 3 ; ii++){
        cout<<"libro "<<ii+1<<endl;
        cout<<list_books[ii].get_name()<<endl;
        cout<<list_books[ii].get_gender()<<endl;
        cout<<list_books[ii].get_pages()<<endl;
    }

}

void show_list(Book *list){

    for(int ii=0;ii<3;ii++){
       cout<<list[ii].to_string()<<endl;
    }

}
void sum_prices(Book *list){

    float prices=0;

    for(int ii=0;ii<3;ii++){
        prices=prices+list[ii].get_price();
    }
    cout<<"Precio total de los libros es: "<<prices;
}

