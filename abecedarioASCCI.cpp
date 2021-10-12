#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
    srand(time(NULL));
    char abc[10];

    for (int ii = 0; ii < 10 ; ++ii) {
        abc[ii] = rand()%25+65;
        cout << abc[ii] << "\t";
    }

    return 0;
}



