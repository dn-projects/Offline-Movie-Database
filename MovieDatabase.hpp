/*******************************************************************************
 File        : MovieDatabase.hpp

 Include     : MovieDatabase.hh, Movie.hpp

 Description : A class made to mimic a database by implementing a vector that
               stores Movie objects. The class overloads the input and output
               operators to allow the class to add a film entry to the database
               as well as print out all the films in the database. The class
               also has the functionality of sorting and filtering the database
               to answer specific queries about the films in the database.

 Author      : Dovydas Novikovas

 Date        : Wednesday 6th May 2020
*******************************************************************************/

#ifndef CPP_COURSEWORK_MOVIEDATABASE_HPP
#define CPP_COURSEWORK_MOVIEDATABASE_HPP

#include <vector>
#include "MovieDatabase.hh"
#include "Movie.hpp"

using namespace std;

//TODO unique ptr?

class MovieDatabase
{
private:

    vector<Movie> movieList;

public:

    explicit MovieDatabase()
    = default;

    /**
     * an inline method to return the vector used to store Movies
     *
     * @return vector of Movies
     */
    inline vector<Movie> getMovieList() const
    {
        return movieList;
    }

    /**
     * Adds a Movie passed in the parameter to the vector in MovieDatabase
     *
     * @param mov - Movie to add to the vector
     */
    inline void addMovieToDatabase(Movie mov)
    {
        movieList.push_back(mov);
    }

    /**
     * Overloads the square brackets operator to access and retrieve a
     * specified element in the vector
     *
     * @param index - int to access element position in vector
     * @return Movie at specific element
     */
    inline Movie& operator[](const int& index)
    {
        return movieList[index];
    }









    inline void sort()
    {
        std::sort(movieList.begin(), movieList.end());
    }

    template<typename T>
    inline void sort(T compare)
    {
        std::sort(movieList.begin(), movieList.end(), compare);
    }


//    template<typename T>
//    MovieDatabase filter(T selector)
//    {
//        MovieDatabase vector;
//
//        for (const Movie& v : movieList)
//        {
//            if(selector(v))
//            {
//                vector.addMovieToDatabase(v);
//            }
//        }
//        return vector;
//    }

    //TODO testing function here
};





















/**
 * Overloading the input operator to read a input stream and for each line in
 * the stream convert the string (a film entry) into a Movie object adding the
 * object to a vector of Movies.
 *
 * @param is            - input stream with movie entries
 * @param movieDatabase - object to add movies to
 * @return the input stream after populating MovieDatabase
 */
istream& operator>>(istream& is, MovieDatabase& movieDatabase);

/**
 * Overloading the output operator to iterate through every element in the
 * vector in MovieDatabase.
 *
 * @param os            - output stream with all the films in the database
 * @param movieDatabase - object storing films in database
 * @return output stream after each film is passed to output
 */
ostream& operator<<(ostream& os, MovieDatabase& movieDatabase);

#endif //CPP_COURSEWORK_MOVIEDATABASE_HPP