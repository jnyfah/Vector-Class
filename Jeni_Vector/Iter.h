#include <iostream>
#include<cstdlib>
#include <new>
#include<algorithm>





#ifndef ITER_H_INCLUDED
#define ITER_H_INCLUDED



using namespace std;
namespace Jeni
{

template<class T>
class Iter
{
private:
    T* ptr;


public:

    //constructor
    Iter(): ptr(nullptr)
    { }

    Iter(T* n): ptr(n)
    { }


//Compares the contents of two containers.
    bool operator == (const Iter<T>& other)
    {
        return (ptr==other.ptr);
    }
    bool operator != (const Iter<T>& other)
    {
        return (ptr!=other.ptr);
    }
    bool operator < (const Iter<T>& other)
    {
        return (ptr<other.ptr);
    }
    bool operator <= (const Iter<T>& other)
    {
        return (ptr<=other.ptr);
    }
    bool operator > (const Iter<T>& other)
    {
        return (ptr>other.ptr);
    }
    bool operator >= (const Iter<T>& other)
    {
        return (ptr>=other.ptr);
    }

    const T& operator [] (size_t n)
    {
        return *(ptr+n);
    }

    Iter operator +(int n)
    {
        Iter <T>temp;
        temp= ptr+n;
        return temp;
    }

    Iter operator -(int n)
    {
        Iter <T>temp;
        temp= ptr-n;
        return temp;
    }
    Iter operator ++()
    {
        ptr++;
        return *this;
    }

    Iter operator --()
    {
        ptr--;
        return *this;
    }

    Iter operator *()
    {

        return *ptr;
    }

    ~Iter()
    {

    }
};

}
#endif // ITER_H_INCLUDED
