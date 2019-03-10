#include <iostream>
#include<cstdlib>
#include <new>

using namespace std;


#ifndef JENI_H
#define JENI_H



template<class T>
class Jeni
{

private:

   unsigned int vsize; //size of vector

    T* vec_array;

    int capacity;  // number of elements the array can hold

    void subsError();  // Handles subscripts out of range

    void memError(); // Handles memory allocation errors




public:
    Jeni();


    Jeni(const Jeni &obj);//copy constructor

    void v_reserve(int n);

    bool status(); // returns true if the stack is empty, or false otherwise.


    void pushs_back(const T& value);

    void pops_back();

    void display();

    unsigned int v_size();

    unsigned int v_capacity();

    void v_resize(unsigned int n);

    void v_clear();

    T& v_front();

    T& v_back();

    T& operator [] (const unsigned int n);

    void inserts(T value, unsigned int i);

    void erases(int n);

    T v_at(unsigned int n); //Returns a reference to the element at specified location, with bounds checking


    ~Jeni();

protected:


};
#include "Jeni.tpp"
#endif // JENI_H

