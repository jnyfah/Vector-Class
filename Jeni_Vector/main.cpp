#include <iostream>
#include<cstdlib>
#include<algorithm>
#include "Vector.h"
#include "Iter.h"

using namespace std;
using namespace Jeni;



int main()
{
    Jeni::Vector<int>vec;
    Jeni::Iter<int>it;


    // iterator invalidation
   for(int i = 1; i < 10; i++)
    {
        vec.push_back(i);
    }

    it = vec.begin();

    for(; it != vec.end(); it++)
    {
        cout << (*it) << " ";
    }

    cout << endl;

    it = vec.begin();

    vec.insert( it+2, 200 );

    for(; it != vec.end(); it++)
    {
        cout << (*it)<<" ";

    }

}
