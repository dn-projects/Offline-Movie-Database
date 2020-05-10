/*******************************************************************************
 File        : MovieDatabase.cpp

 Include     : MovieDatabase.hpp, Movie.hpp

 Description : Contains the implementations for the overloaded input and output
               operators for class MovieDatabase.

 Author      : Dovydas Novikovas

 Date        : Wednesday 6th May 2020
*******************************************************************************/

#include <iterator>
#include <iostream>
#include <sstream>
#include "MovieDatabase.hpp"
#include "Movie.hpp"

using namespace std;

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
 * Function body for overloaded input operator for input stream, MovieDatabase
 */
istream& operator>>(istream& is, MovieDatabase& movieDatabase)
{
    Movie movie;
    string movieEntry;

    // reads data found on every new line of input stream
    while (getline(is, movieEntry))
    {
        // turning film entry string into movie object
        istringstream iss(movieEntry);
        iss >> movie;

        movieDatabase.addMovieToDatabase(movie);
    }
    // sorts list of films into chronological order (year released)
    movieDatabase.sort();
    return is;
}

/**
 * Function body for overloaded output operator for output stream, MovieDatabase
 */
ostream& operator<<(ostream& os, MovieDatabase& movieDatabase)
{
    for (Movie& movie: movieDatabase.getMovieList())
    {
        os << movie << endl;
    }
    return os;
}