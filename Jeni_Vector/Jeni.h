#include <iostream>

using namespace std;


#ifndef JENI_H
#define JENI_H



template<class T>
class Jeni
{

private:

    int vsize; //size of vector

    T* vec_array;

    int capacity;  // number of elements the array can hold




public:
    Jeni();

    Jeni(int n); //one arg constructor

    Jeni(const Jeni &obj);//copy constructor

    void _reserve(int n);

    bool status(); // returns true if the stack is empty, or false otherwise.


    void pushs_back(const T& value);

    void pops_back();

    void display();

    unsigned int _size();

    unsigned int _capacity();

    void _resize(unsigned int n);

    void _clear();

    T& _front();

    T& _back();

    T& operator [] (unsigned int n);

    void inserts(T value, int i);

    void erases(int n);


    ~Jeni();

protected:


};

#endif // JENI_H
