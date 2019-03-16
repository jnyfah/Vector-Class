#include <iostream>
#include<cstdlib>
#include "Vector.h"
#include "Iter.h"

using namespace std;
using namespace Jeni;



int main()
{
    Jeni::Vector<int>vec;
    Jeni::Iter<int>it;


    vec.push_back(9);
    vec.push_back(7);
    vec.push_back(8);
    vec.push_back(67);
    vec.push_back(4);
    vec.push_back(2);
     vec.erase(vec.begin(),vec.begin()+1);



    cout<<vec.at(3);

    for(it=vec.begin(); it!=vec.end(); ++it)
    {
        cout<<*it<<endl;
    }

}
