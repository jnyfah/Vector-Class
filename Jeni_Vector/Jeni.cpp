#include "Jeni.h"
#include <iostream>
#include <string>
#include<cstdlib>  //for the exit function
#include <new>
#include "Jeni.h"

using namespace std;





// subErrors function. Displays an error message and *
// terminates the program when a subscript is out of range.

template<class T>
void Jeni<T>::subsError()
{
    cout << "ERROR: Subscript out of range."<<endl;
    exit(EXIT_FAILURE);
}



// memError function. Displays an error message and *
// terminates the program when memory allocation fails.
template<class T>
void Jeni<T>::memError()
{
    cout << "ERROR:Cannot allocate memory"<<endl;
    exit(EXIT_FAILURE);
}


//constructor

template<class T>
Jeni<T>::Jeni()
{
    vsize=0;
    capacity=10;
    try
    {
      vec_array=new T[capacity];
    }
    catch(bad_alloc)
    {
        memError();
    }
}



// copy constructor
template<class T>
Jeni<T>::Jeni(const Jeni &obj)
{
    vsize= obj.vsize;
    capacity=obj.capacity;
    if(obj.vsize>0)
    {
        vec_array=new T[obj.vsize];
    }
    else
    {
        vec_array=nullptr;
    }

    for(unsigned int i=0; i<obj.vsize; i++)
    {
        vec_array[i]=obj.vec_array[i];
    }
}


// increases the capacity that the array can hold by crating a new array bigger than
//the old array and coping all the old elements into the new elements  and deletes the old array
//but this will only be done when capacity - elements in the array is equal to 1
template<class T>
void Jeni<T>::v_reserve(int n)
{
    T* new_array = new T[n];

    for(int i= 0; i< capacity; i++) // copy the elements to new array
    {
        new_array[i]=vec_array[i];
    }

    capacity=n;                    // assign new capacity

    delete[] vec_array;    //delete old array
    vec_array=new_array;
}






// member function status()
//returns true if the stack is empty, or false otherwise

template<class T>
bool Jeni<T>::status()
{
    if(vsize==0)
        return true;
    else
        return false;
}


//Appends the given element value to the end of the container
template<class T>
void Jeni<T>::pushs_back(const T& value)
{

    if((capacity-vsize)<=1)  //increase the capacity if necessary
    {
        v_reserve(2*capacity);
    }

    vec_array[vsize]=value;
    ++vsize;
}


//Removes the last element of the container.
template<class T>
void Jeni<T>::pops_back()
{
    if(!status())
        vsize--;
    else
        cout<<"container is empty"<<endl;


}

template<class T>
void Jeni<T>::display()
{
    for(unsigned int i=0; i<vsize; i++)
    {
        cout<<vec_array[i]<<" , ";
    }
}

// returns the number of elements in the container.
template<class T>
unsigned int Jeni<T>::v_size()
{
    return vsize;
}


// returns the capacity of elements in the container.
template<class T>
unsigned int Jeni<T>::v_capacity()
{
    return capacity;
}


//Removes all elements from the container
template<class T>
void Jeni<T>::v_clear()
{
    for(unsigned int i=0; i<vsize; i++)
    {
        vsize=0;
        capacity=10;
    }
}


//resizes the container
template<class T>
void Jeni<T>::v_resize(unsigned int n)
{
    if(n<0)
        subsError();
    else
       vsize=n;

}



//reference to the first element in the container
template<class T>
T& Jeni<T>::v_front()
{
    return vec_array[0];
}


//reference to the last element in the container
template<class T>
T& Jeni<T>::v_back()
{
    return vec_array[vsize-1];
}


//Returns a reference to the element at specified location
template<class T>
T& Jeni<T>::operator [] (unsigned int n)
{

       return vec_array[n];

}


//inserting at any location
//increases the size of the container by one
//move elements after the insertion point by one
template<class T>
void Jeni<T>::inserts(T value, unsigned int i)
{

    if(i < 0 || i > (vsize+2))   //if subscript is out of bound
    {
       subsError();
    }

    else
       {
         vsize++;
    for(unsigned int j=vsize-1; j>i; j--)
    {
       vec_array[j]=vec_array[j-1] ;
    }
    vec_array[i]=value;
       }

}



//Returns a reference to the element at specified location, with bounds checking.
//If location is not within the range of the container, an exception of type subsError is thrown.
template<class T>
T Jeni<T>::v_at(unsigned int n)
{
    if (n < 0 || n >= vsize)
            subsError();
    return vec_array[n];
}

// Destructor
template<class T>
Jeni<T>::~Jeni()
{
    if(!status())
        delete[] vec_array;
}


//templates
template class Jeni<int>;
template class Jeni<float>;
template class Jeni<string>;
template class Jeni<double>;
template class Jeni<char>;
