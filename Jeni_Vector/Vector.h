#include <iostream>
#include<cstdlib>
#include <new>
#include<algorithm>
#include "Iter.h"



#ifndef VECTOR_H
#define VECTOR_H


using namespace std;
namespace Jeni
{


template<class T>
class Vector
{
private:

    size_t vsize; //size of vector

    T* vec_array;

    size_t capacity;  // number of elements the array can hold


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
    friend class Iter<T>;

    Vector()
    {
        vsize = 0;

        capacity = 10;

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
    Vector( const Vector& obj)
    {
        vsize = obj.vsize;

        capacity = obj.capacity;

        if(obj.vsize>0)
        {
            vec_array = new T[obj.vsize];
        }
        else
        {
            vec_array = nullptr;
        }

        for(unsigned int i = 0; i<obj.vsize; i++)
        {
            vec_array[i] = obj.vec_array[i];
        }
    }



// increases the capacity that the array can hold by creating a new array bigger than
//the old array and coping all the old elements into the new elements  and deletes the old array
//but this will only be done when capacity - elements in the array is equal to 1
    void v_reserve(int n)
    {
        T* new_array = new T[n];

        for(size_t i = 0; i< capacity; i++) // copy the elements to new array
        {
            new_array[i] = vec_array[i];
        }

        capacity = n;                    // assign new capacity

        delete[] vec_array;    //delete old array

        vec_array = new_array;
    }



// member function status()
//returns true if the stack is empty, or false otherwise
    bool empty()
    {
        if(vsize == 0)
            return true;
        else
            return false;
    }


//Appends the given element value to the end of the container
    void push_back(const T& value)
    {

        if((capacity - vsize) <= 1)  //increase the capacity if necessary
        {
            v_reserve ( 2*capacity );
        }

        vec_array[vsize] = value;

        ++vsize;
    }


//Removes the last element of the container.
    void pop_back()
    {
        if( !empty() )

            vsize--;
        else
            cout << "container is empty" << endl;
    }




// returns the number of elements in the container.
    size_t v_size()
    {
        return vsize;
    }


// returns the capacity of elements in the container.
    size_t v_capacity()
    {
        return capacity;
    }


//Removes all elements from the container
    void v_clear()
    {
        for(size_t i=0; i<vsize; i++)
        {
            vsize = 0;

            capacity = 10;
        }
    }


//resizes the container
    void v_resize(size_t n)
    {
        if(n<0)
            subsError();
        else
            vsize = n;

    }


//reference to the first element in the container
    T& front()
    {
        if(empty())

            subsError();

        return vec_array[0];
    }


//reference to the last element in the container
    T& back()
    {
        if(empty())

            subsError();

        return vec_array[vsize-1];
    }


//Returns a reference to the element at specified location


    const T& operator [] (size_t n)
    {

        if(n < 0 || n > vsize)   //if subscript is out of bound
        {
            subsError();
        }

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
//increases the size of the container if necessary
//move elements after the insertion point by one
    void insert(Iter<T> n, const T& value)
    {
        int i = vsize;

        if((capacity-vsize) <= 1)  //increase the capacity if necessary
        {
            v_reserve ( 2*capacity );
        }

        for(Iter<T>it = end(); it != n; it--)
        {
            i--;
            vec_array [i+1] = vec_array [i];

        }

        *n = value;
        vsize++;

    }


// inserts count copies of the value before pos

    void insert(Iter<T> n, size_t counts, const T& value)
    {
        int i = vsize;

        if((capacity - vsize) < counts )  //increase the capacity if necessary
        {
            v_reserve ( 2*capacity );
        }

        for(Iter<T>it = end(); it != n; it--)
        {
            i--;
            vec_array [ i + counts ] = vec_array [i];

        }
        for( size_t j = 0; j < counts; j++)
        {
            vec_array[ i+j ] = value;
        }


        vsize += value;

    }



    void insert(Iter<T> pos, Iter<T> first, Iter<T> last )
    {
        size_t i=0, n=0;
        size_t j = vsize;

        for(auto it = first; it!=last; it++)
        {
            i++;
        }
        if((capacity - vsize) < i )  //increase the capacity if necessary
        {
            v_reserve ( 2*capacity );
        }
        T* temp = new T[i];

        for(auto it = first; it!=last; it++)
        {
            temp[n] = *it ;
            n++;
        }

        for(Iter<T>it = end(); it != pos; it--)
        {
            j--;
            vec_array [j+i] = vec_array [j];

        }

        for( size_t n = 0; n < i; n++)
        {
            vec_array[ j + n ]=temp[n];
        }
        vsize+=i;
        delete []temp;

    }



//Returns a reference to the element at specified location, with bounds checking.
//If location is not within the range of the container, an exception of type subsError is thrown.
    T& at(size_t n)
    {
        if (n < 0 || n >= vsize)

            subsError();

        return vec_array[n];
    }


//Returns an iterator to the first element of the container

    Iter<T>begin()
    {
        Iter <T> temp;

        temp = vec_array;

        return temp;
    }
//Returns a constant iterator to the first element of the container
    const Iter<T> cbegin() const
    {
        Iter<T>temp;

        temp = vec_array;

        return temp;
    }


//  Returns an iterator to the element following the last element of the container.
    Iter<T> end() const
    {
        Iter<T>temp;

        temp = vec_array + vsize;

        return temp;
    }

    //when reverse transversing through the container, use the decrement pointer
//  Returns a constant iterator to the element following the last element of the container.
    const Iter<T> cend() const
    {
        Iter<T>temp;

        temp = vec_array + vsize;

        return temp;
    }

//Returns an iterator to the element following the last element of the container.
    Iter<T> rbegin()
    {
        Iter<T>temp;

        temp = vec_array + (vsize-1);

        return temp;
    }

    //Returns a constant iterator to the element following the last element of the container.
    const Iter<T> crbegin() const
    {
        Iter<T>temp;

        temp = vec_array + (vsize-1);

        return temp;
    }


//Returns an iterator to the first element of the container
    Iter<T> rend()
    {
        Iter<T>temp;

        temp =  vec_array-1;

        return temp;
    }

    //Returns a constant iterator to the first element of the container
    const Iter<T> crend() const
    {
        Iter<T>temp;

        temp = vec_array-1;

        return temp;
    }


//Exchanges the contents of the container with those of other
    void swap( Vector<T>& obj )
    {
        size_t temp = vsize;

        vsize = obj.vsize;

        obj.vsize = temp;


        T* temps = vec_array;

        vec_array = obj.vec_array;

        obj.vec_array = temps;
    }



    //Compares the contents of two containers.

    friend  bool operator == ( Vector<T>&  first,  Vector<T>& second)
    {
        if(first.vsize != second.vsize)
        {
            return false;
        }
        else
        {
            for(size_t i = 0; i < first.vsize; ++i)
            {
                if( first[i] != second[i] );

                return false;
            }
        }

        return true;
    }

//Compares the contents of two containers

    friend bool operator != ( Vector<T>&  first,  Vector<T>& second)
    {
        return !(first == second);
    }




    //Compares the contents of two containers
    friend bool operator < ( Vector<T>&  first,  Vector<T>& second)
    {
        if(first.empty() && second.empty())
        {
            return false;
        }
        else if (first.empty())
        {
            return true;
        }
        else if(second.empty())
        {
            return false;

        }
        else if(first.vsize==second.vsize)
        {

            if(first[0]<second[0])
                return true;
            else
                return false;

        }
        else if(first.vsize<second.vsize)

            return true;

        else

            return false;


    }

//Compares the contents of two containers
    friend bool operator <=  ( Vector<T>&  first,  Vector<T>& second)
    {
        if(first.empty() && second.empty())
        {
            return false;
        }
        else if (first.empty())
        {
            return true;
        }
        else if(second.empty())
        {
            return false;

        }
        else if(first.vsize == second.vsize)
        {
            if(first[0] <= second[0])
                return true;
            else
                return false;

        }
        else if(first.vsize < second.vsize)
            return true;
        else
            return false;


    }

    //Compares the contents of two containers
    friend bool operator >  ( Vector<T>&  first,  Vector<T>& second)
    {
        return !(first <= second);
    }

//Compares the contents of two containers
    friend bool operator >= ( Vector<T>&  first,  Vector<T>& second)
    {
        return !(first <= second);
    }



    Iter<T> erase(Iter<T> n)
    {
        int i=0;
        for(auto it = (*this).begin(); it != n; it++) //get number of elements before the item to be deleted
        {
            i++;
        }
        for(auto it = n+1; it != (*this).end(); it++)
        {

            vec_array[i] = vec_array[i+1];
            i++;
        }
        vsize--;
        return n;

    }



    Iter<T> erase(Iter<T> first, Iter<T> last )
    {
        int i=0;

        int j=0;

        for(auto it = (*this).begin(); it != first; ++it) //get number of elements before the item to be deleted
        {
            ++i;
        }
        for(auto it = first; it != last; ++it) //get number of elements inbetween the range to be deleted
        {
            ++j;
        }
        for(auto it = last; it != (*this).end(); it++)
        {

            vec_array[i] = vec_array[i+1];
            ++i;
        }
        vsize -= j;

        return last;

    }


    void assign(size_t counts, const T& value)
    {
        if (counts < 0)
        {
            subsError();
        }
        if((capacity - vsize) < counts )  //increase the capacity if necessary
        {
            v_reserve ( 2*capacity );
        }

        vsize=counts;
        for(size_t i = 0; i<vsize; i++)
        {
            vec_array[i] = value;
        }
    }


//Destructor
    ~Vector()
    {

        if( !empty() )

            delete[] vec_array;
    }






};








} //end of name space

#endif // VECTOR_H


