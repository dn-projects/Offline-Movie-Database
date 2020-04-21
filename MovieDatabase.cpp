/*******************************************************************************
 File        : MovieDatabase.cpp

 Description :

 Author      : Dovydas Novikovas

 Date        :
*******************************************************************************/

#include <string>
#include <iostream>
#include "MovieDatabase.h"
#include "MovieDatabase.hh"
#include "Movie.h"

using namespace std;

//TODO use lambda
istream& operator>>(istream& is, MovieDatabase& mdb)
{
    Movie mov;

    if(is >> mov)
    {
        mdb.addMovieToDatabase(mov);
    }
    else
    {
        is.clear(ios_base::failbit);
    }

    return is;
}

ostream& operator<<(ostream& os, MovieDatabase& mdb)
{
    return os << mdb.getMovieList();
}

ostream& operator<<(ostream& os, const vector<Movie> vec)
{
    for ( auto const& v : vec )
    {
        os << v << endl;
    }
    return os;
}