#include <iostream>
#include "ClassData.h"
using namespace std;
int main()
{
    Data a(32, 01, 1999);
    Data b(34, 05, 2005);

    cout << a;
    cout << endl;
    cout << b;
    cout << endl;
    a.setDay(24);
    b.setDay(25);
    cout << endl;
}