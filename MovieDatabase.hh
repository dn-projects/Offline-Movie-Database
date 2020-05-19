/*******************************************************************************
 File        : MovieDatabase.hh

 Include     :

 Description :

 Author      : Dovydas Novikovas

 Date        : Wednesday 6th May 2020
*******************************************************************************/

#ifndef CPP_COURSEWORK_MOVIEDATABASE_HH
#define CPP_COURSEWORK_MOVIEDATABASE_HH

using namespace std;

template <typename T>
void exchange(T& x, T& y)
{
    T z = y; y = x; x = z;
}

template <typename T>
struct Ascending
{
    bool operator()(T& x, T& y)
    {
        return x < y;
    }
};

template <typename T>
struct Descending
{
    bool operator()(T& x, T& y)
    {
        return x > y;
    }
};






template <typename T>
struct FilterFunction
{
    bool operator()(T& check)
    {
        if(check.getGenre().Film_Noir)
        {
            return true;
        }
        return false;
    }
};

#endif //CPP_COURSEWORK_MOVIEDATABASE_HH