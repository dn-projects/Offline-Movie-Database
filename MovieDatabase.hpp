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

#include <memory>
#include <vector>
#include "MovieDatabase.hh"
#include "Movie.hpp"

//TODO use functor, lambda, function pointer?

using namespace std;

class MovieDatabase {
private:

    vector<shared_ptr<Movie> > movieList;

public:

    explicit MovieDatabase()
    = default;


    inline vector<shared_ptr<Movie> > getMovieList() const {
        return movieList;
    }


    inline void addMovieToDatabase(shared_ptr<Movie> movie) {
        movieList.push_back(movie);
    }


    inline shared_ptr<Movie> operator[](const int &index) {
        return movieList[index];
    }

    inline void sort() {
        std::sort(movieList.begin(), movieList.end(),
                  [](shared_ptr<Movie> pointer1,
                     shared_ptr<Movie> pointer2) -> bool {
                      return *pointer1 < *pointer2;
                  });
    }

    template<typename T>
    inline void sort(T compare) {
        std::sort(movieList.begin(), movieList.end(), compare);
    }

    template<typename T, typename F>
    void printResults(vector<T> vector, F &function) {
        for (int i = 0; i < vector.size(); i++) {
            if (function(*vector[i])) {
                cout << *vector[i] << endl;
            }
        }
    }


    template <typename T, typename F>
    void sortCollection(vector<T> vector, F function)
    {

            for(int i = 1; i < vector.size(); i++)
            {
                if(function(*vector[i-1], *vector[i]))
                {
                    cout << "sorted!" << endl;
                }
                else
                {
                    cout << "not sorted!" << endl;
                }
            }
    }

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

/**
 * Struct used as test harness to test MovieDatabase class functionality
 */
union RunMovieDatabaseTestHarness
{
    RunMovieDatabaseTestHarness()
    {
        cout << "---------------TESTING MOVIEDATABASE CLASS-----------------\n";
    }
};

#endif //CPP_COURSEWORK_MOVIEDATABASE_HPP