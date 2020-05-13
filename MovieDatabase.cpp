/*******************************************************************************
 File        : MovieDatabase.cpp

 Include     : MovieDatabase.hpp, Movie.hpp

 Description : Contains the implementations for the overloaded input and output
               operators for class MovieDatabase.

 Author      : Dovydas Novikovas

 Date        : Wednesday 6th May 2020
*******************************************************************************/

//#include <iterator>
#include <iostream>
#include <sstream>
#include "MovieDatabase.hpp"
#include "Movie.hpp"

using namespace std;

/**
 * Function body for overloaded input operator for input stream, MovieDatabase
 */
istream& operator>>(istream& is, MovieDatabase& movieDatabase)
{
    string movieEntry;

    // reads data found on every new line of input stream
    while (getline(is, movieEntry))
    {
        shared_ptr<Movie> movie(new Movie);
        // turning film entry string into movie object
        istringstream iss(movieEntry);
        iss >> *movie;

        if(!iss.fail())
        {
            movieDatabase.addMovieToDatabase(movie);
        }
        else
        {
            is.clear(ios_base::failbit);
            cerr << "Failed to add movie to Database" << endl;
        }
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
    for (shared_ptr<Movie> movie: movieDatabase.getMovieList())
    {
        os << *movie << endl;
    }
    return os;
}