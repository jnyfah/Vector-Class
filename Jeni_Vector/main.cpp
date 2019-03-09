#include <iostream>
#include<cstdlib>
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
    vec.inserts(4,16);



cout<<vec.v_size();

    return 0;
}
