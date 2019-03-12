#include <iostream>
#include<cstdlib>
#include "Vector.h"

using namespace std;



int main()
{
    Jeni::Vector<int>vec;

    vec.pushs_back(9);
    vec.pushs_back(7);
    vec.pushs_back(8);
    vec.pushs_back(67);
    vec.pushs_back(4);
    vec.pushs_back(9);
    vec.inserts(3,4);
 Jeni::Vector<int>mas(vec);
  mas.display();



    return 0;
}
