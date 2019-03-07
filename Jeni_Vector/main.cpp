#include <iostream>
#include "Jeni.h"
using namespace std;

int main()
{
    Jeni<int>vec;
    vec.pushs_back(9);
    vec.pushs_back(7);
    vec.pushs_back(8);
    vec.pushs_back(67);
    vec.pushs_back(4);
    vec.pushs_back(9);
    vec.inserts(4,1);


    vec.display();
    cout<<vec._size();

    return 0;
}
