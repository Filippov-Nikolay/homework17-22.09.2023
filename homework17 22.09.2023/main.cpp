#include <iostream>
#include "Matrix.h"
#include "A.h"

using namespace std;

int main() {
    setlocale(0, "");
    srand(time(NULL));

    /*
    Matrix<int> a(2, 2);

    a.Input();
    a.Print();

    a.Init();
    a.Print();
    */


    Matrix<A> b(2, 2);

    b.Input();
    b.Print();

    b.Init();
    b.Print();

    return 0;
}


