/*******************************************************************************
 File        : MovieDatabase.hh

 Include     : Movie.hpp

 Description :

 Author      : Dovydas Novikovas

 Date        : Wednesday 6th May 2020
*******************************************************************************/

#ifndef CPP_COURSEWORK_MOVIEDATABASE_HH
#define CPP_COURSEWORK_MOVIEDATABASE_HH

#include "Movie.hpp"

using namespace std;


// checks a list to check for key

template <typename T>
class ContainsKey
{
public:

    bool operator() (T& key)
    {
        for (T i = 0; i < abs(key); i++ )
        {

        }
        return true;
    }

};

#endif //CPP_COURSEWORK_MOVIEDATABASE_HH
