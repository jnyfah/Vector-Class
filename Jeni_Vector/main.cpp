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
    vec.pushs_back(2);
    vec.inserts(3,4);

 Jeni::Vector<int>mas;
 if(vec==mas)
 {
     cout<<"yes";
 }else
 {
     cout<<"no";
 }

  for(auto ptr=mas.v_begin(); ptr!=mas.v_end(); ++ptr)
  {
      if(*ptr==69)
      {
          mas.pushs_back(29);
      }
  }

for(auto ptr=mas.v_begin(); ptr!=mas.v_end(); ++ptr)
  {
        cout<<*ptr<<" ";
  }

  cout<<mas.v_size();
    return 0;
}
