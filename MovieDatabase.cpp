/*******************************************************************************
 File        : MovieDatabase.cpp

 Description :

 Author      : Dovydas Novikovas

 Date        : Wednesday 6th May 2020
*******************************************************************************/

#include <string>
#include <iostream>
#include <sstream>
#include "MovieDatabase.hpp"
#include "Movie.hpp"

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

/**
 *
 *
 * @param os
 * @param movieDatabase
 * @return
 */
ostream& operator<<(ostream& os, MovieDatabase& movieDatabase)
{
    for (auto it  = std::begin(movieDatabase.getMovieList());
              it != std::end(movieDatabase.getMovieList()); ++it)
    {
        os << *it << endl;
    }
    return os;
}