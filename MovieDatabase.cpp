/*******************************************************************************
 File        : MovieDatabase.cpp

 Description :

 Author      : Dovydas Novikovas

 Date        : Wednesday 6th May 2020
*******************************************************************************/

#include <string>
#include <iostream>
#include <sstream>
#include "MovieDatabase.h++"
#include "Movie.h++"

using namespace std;

//inline Movie& MovieDatabase::operator[](int i)

//template<typename T>
//MovieDatabase filter(T selector)
//{
//    MovieDatabase vector;
//
//    for (const Movie& v : )
//    {
//        if(selector(v))
//        {
//            vector.addMovieToDatabase(v);
//        }
//    }
//    return vector;
//}

/**
 *
 *
 * @param is
 * @param movieDatabase
 * @return
 */
istream& operator>>(istream& is, MovieDatabase& movieDatabase)
{
    Movie movie;
    string movieEntry;

    while (getline(is, movieEntry))
    {
        istringstream iss(movieEntry);

        iss >> movie;

        movieDatabase.addMovieToDatabase(movie);
    }
    movieDatabase.sort();
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
