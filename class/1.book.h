#ifndef CLION_CODIGOS_1_BOOK_H
#define CLION_CODIGOS_1_BOOK_H
#include <string>

using namespace std;

class Book {

private:

    string name;
    string gender;
    int pages;
    int price;

public:

    Book();
    void set_name(string name);
    string get_name();
    void set_gender(string gender);
    string get_gender();
    void set_pages(int pages);
    int get_pages();
    void set_price(int price);
    int get_price();
    string to_string(void);

};


#endif //CLION_CODIGOS_1_BOOK_H
