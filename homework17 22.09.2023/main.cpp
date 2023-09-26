#include <iostream>
#include "Matrix.h"
#include "A.h"

using namespace std;

int main() {
    setlocale(0, "");
    srand(time(NULL));

    int index_i = 0, index_j = 0;

    Matrix<A> a(5, 5), b(5, 5), c(0, 0);

    cout << "a: " << endl;
    a.Init();
    a.Print();
    cout << endl;

    cout << "b: " << endl;
    b.Init();
    b.Print();
    cout << endl;

    // 1
    cout << "Rez (obj + obj): " << endl;
    Matrix<A> rez = a + b;
    rez.Print();
    cout << endl;
    
    cout << "Rez (obj + 10): " << endl;
    rez = a + 10;
    rez.Print();
    cout << endl;

    cout << "Rez (10 + obj): " << endl;
    rez = 10 + a;
    rez.Print();
    cout << endl;

    
    // 2
    cout << "Rez (obj - obj): " << endl;
    rez = a - b;
    rez.Print();
    cout << endl;

    cout << "Rez (obj - 10): " << endl;
    rez = a - 10;
    rez.Print();
    cout << endl;

    cout << "Rez (10 - obj): " << endl;
    rez = 10 - a;
    rez.Print();
    cout << endl;


    // 3
    cout << "Rez (obj * obj): " << endl;
    rez = a * b;
    rez.Print();
    cout << endl;

    cout << "Rez (obj * 10): " << endl;
    rez = a * 10;
    rez.Print();
    cout << endl;

    cout << "Rez (10 * obj): " << endl;
    rez = 10 * a;
    rez.Print();
    cout << endl;


    // 4
    cout << "Rez (obj / obj): " << endl;
    rez = a / b;
    rez.Print();
    cout << endl;

    cout << "Rez (obj / 10): " << endl;
    rez = a / 10;
    rez.Print();
    cout << endl;

    cout << "Rez (10 / obj): " << endl;
    rez = 10 / a;
    rez.Print();
    cout << endl;


    // 5 Search
    cout << "MAX:" << endl;
    a.SearchMax(index_i, index_j);
    cout << "index_i: " << index_i << ", index_j: " << index_j << endl;
    a.PrintIndex(index_i, index_j);
    cout << endl << endl;

    cout << "MIN:" << endl;
    a.SearchMin(index_i, index_j);
    cout << "index_i: " << index_i << ", index_j: " << index_j << endl;
    a.PrintIndex(index_i, index_j);
    cout << endl << endl;


    return 0;
}