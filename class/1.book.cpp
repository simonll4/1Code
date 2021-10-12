#include <string>
#include "1.book.h"
#include <iostream>

using namespace std;

Book::Book(){
    string name=" ";
    string gender=" ";
    int pages=0;
    int price=0;
}
void Book::set_name(string name){

    this->name=name;
}
string Book::get_name(){

    return name;
}
void Book::set_gender(string gender){

    this->gender=gender;
}
string Book::get_gender(){

    return gender;
}
void Book::set_pages(int pages){

    this->pages=pages;
}
int Book::get_pages(){

    return pages;
}
void Book::set_price(int price){

this->price=price;
}
int Book::get_price(){

return price;
}

string Book::to_string() {
  string print_string=" ";

    print_string="nombre:" +name+ "genero: " +gender+ "paginas: " +std::to_string(pages)+ "precio: "+ std::to_string(price);
    return print_string;
}
