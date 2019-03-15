#include <iostream>
#include<cstdlib>
#include "Vector.h"
#include "Iter.h"

using namespace std;
using namespace Jeni;



int main()
{
    Jeni::Vector<int>vec;
    Iter<int>it;


    vec.pushs_back(9);
    vec.pushs_back(7);
    vec.pushs_back(8);
    vec.pushs_back(67);
    vec.pushs_back(4);
    vec.pushs_back(2);

    it=vec.v_begin();
    cout<<it<<endl;


}
