#include <iostream>
#include<cstdlib>
#include <new>



#ifndef VECTOR_H
#define VECTOR_H


using namespace std;
namespace Jeni
{


template<class T>
class Vector
{
private:

    unsigned int vsize; //size of vector

    T* vec_array;

    int capacity;  // number of elements the array can hold


    void subsError()
    {
        cout << "ERROR: Subscript out of range."<<endl;
        exit(EXIT_FAILURE);
    }


// memError function. Displays an error message and *
// terminates the program when memory allocation fails.

    void memError()
    {
        cout << "ERROR:Cannot allocate memory"<<endl;
        exit(EXIT_FAILURE);
    }


public:
    Vector()
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


//copy constructor
    Vector(const Vector& obj)
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



// increases the capacity that the array can hold by creating a new array bigger than
//the old array and coping all the old elements into the new elements  and deletes the old array
//but this will only be done when capacity - elements in the array is equal to 1
    void v_reserve(int n)
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
    bool status()
    {
        if(vsize==0)
            return true;
        else
            return false;
    }


//Appends the given element value to the end of the container
    void pushs_back(const T& value)
    {

        if((capacity-vsize)<=1)  //increase the capacity if necessary
        {
            v_reserve(2*capacity);
        }

        vec_array[vsize]=value;
        ++vsize;
    }


//Removes the last element of the container.
    void pops_back()
    {
        if(!status())
            vsize--;
        else
            cout<<"container is empty"<<endl;
    }




// returns the number of elements in the container.
    unsigned int v_size()
    {
        return vsize;
    }


// returns the capacity of elements in the container.
    unsigned int v_capacity()
    {
        return capacity;
    }


//Removes all elements from the container
    void v_clear()
    {
        for(unsigned int i=0; i<vsize; i++)
        {
            vsize=0;
            capacity=10;
        }
    }


//resizes the container
    void v_resize(unsigned int n)
    {
        if(n<0)
            subsError();
        else
            vsize=n;

    }



//reference to the first element in the container
    T& v_front()
    {
        return vec_array[0];
    }


//reference to the last element in the container
    T& v_back()
    {
        return vec_array[vsize-1];
    }


//Returns a reference to the element at specified location


    const T& operator [] (unsigned int n)
    {

        return vec_array[n];


    }


//Replaces the contents of the container
    Vector& operator = (const Vector &obj)
    {
        vsize= obj.vsize;
        capacity=obj.capacity;

        vec_array=new T[obj.vsize];

        for(unsigned int i=0; i<obj.vsize; i++)
        {
            vec_array[i]=obj.vec_array[i];
        }
        return *this;
    }



//inserting at any location
//increases the size of the container by one
//move elements after the insertion point by one
    void inserts(T value, unsigned int i)
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
    T v_at(unsigned int n)
    {
        if (n < 0 || n >= vsize)
            subsError();
        return vec_array[n];
    }


//Returns an iterator to the first element of the container
    T* v_begin()
    {
        return  vec_array;
    }

//Returns a constant iterator to the first element of the container
    const T* v_cbegin() const
    {
        return  vec_array;
    }


//  Returns an iterator to the element following the last element of the container.
    const T* v_end() const
    {
        return  vec_array + vsize;
    }


    //when reverse transversing through the container, use the decrement pointer
//  Returns a constant iterator to the element following the last element of the container.
    T* v_cend()
    {
        return  vec_array + vsize;
    }

//Returns an iterator to the element following the last element of the container.
    T* v_rbegin()
    {
        return  vec_array + (vsize-1);
    }

    //Returns a constant iterator to the element following the last element of the container.
    const T* v_crbegin() const
    {
        return  vec_array + (vsize-1);
    }


//Returns an iterator to the first element of the container
    T* v_rend()
    {
        return  vec_array-1;
    }

    //Returns a constant iterator to the first element of the container
    const T* v_crend() const
    {
        return  vec_array-1;
    }

//Destructor
    ~Vector()
    {

        if(!status())
            delete[] vec_array;
    }


protected:


};




} //end of name space

#endif // VECTOR_H


