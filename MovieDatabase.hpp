/*******************************************************************************
 File        : MovieDatabase.hpp

 Include     : Movie.hpp

 Description : A class made to mimic a database by implementing a vector that
               stores Movie objects. The class overloads the input and output
               operators to allow the class to add a film entry to the database
               as well as print out all the films in the database. The class
               also has the functionality of sorting and filtering the database
               to answer specific queries about the films in the database.

 Author      : Dovydas Novikovas

 Date        : Wednesday 6th May 2020

 Notes       : Method 'sortByGenre' was not implemented because it does not
               seem practical sorting MovieDatabase by genres as it will not
               sort the Movies in a logical order. Considering a Movie can have
               one or multiple genres the sorting order will be too ambiguous
               and will not provide much clarity to the sorting order.
*******************************************************************************/

#ifndef CPP_COURSEWORK_MOVIEDATABASE_HPP
#define CPP_COURSEWORK_MOVIEDATABASE_HPP

#include <memory>
#include <vector>
#include <map>

#include "Movie.hpp"

using namespace std;

enum class Filter
{
    TITLE, YEAR, CERTIFICATE, GENRE, DURATION, RATING
};

class MovieDatabase
{
private:

    vector<shared_ptr<Movie> > movieList;

public:

    explicit MovieDatabase()
    = default;

    inline vector<shared_ptr<Movie> > getMovieList() const
    {
        return movieList;
    }

    inline void deleteAllMovies()
    {
        movieList.clear();
    }

    /**
     *
     * @param movieToAdd
     */
    inline void addMovieToDatabase(shared_ptr<Movie> movieToAdd)
    {
        if((find_if(movieList.begin(), movieList.end(),
        [movieToAdd](const shared_ptr<Movie> movie)
        {
            return *movie == *movieToAdd;
        }))
        == movieList.end())
        {
            movieList.push_back(movieToAdd);
        }
        else
        {
            cout << "Movie already in database!" << endl;
        }
    }

    /**
     *
     * @param movies
     */
    inline void addMoviesToDatabase(MovieDatabase *movies)
    {
        for (shared_ptr<Movie> movie: movies->movieList)
        {
            addMovieToDatabase(movie);
        }
    }

    /**
     *
     * @param movie
     */
    void removeMovieFromDatabase(shared_ptr<Movie> movie)
    {
        movieList.erase(remove_if(movieList.begin(),
         movieList.end(), [movie] (shared_ptr<Movie> mov) { return *movie == *mov; }));
    }

    /**
     *
     * @param movies
     */
    void removeMoviesFromDatabase(MovieDatabase *movies)
    {
        for (shared_ptr<Movie> movie: movies->movieList)
        {
            removeMovieFromDatabase(movie);
        }
    }

    /**
     *
     * @param index
     * @return
     */
    inline shared_ptr<Movie> operator[](const int &index)
    {
        return movieList[index];
    }

    /**
     * Default sort
     */
    inline void sort()
    {
        sortByYear(true);
    }

    /**
     *
     * @param ascending
     */
    void sortByTitle(bool ascending);

    /**
     *
     * @param ascending
     */
    void sortByTitleLength(bool ascending);

    /**
     *
     * @param ascending
     */
    void sortByYear(bool ascending);

    /**
     *
     * @param ascending
     */
    void sortByCertificate(bool ascending);

    /**
     *
     * @param ascending
     */
    void sortByDuration(bool ascending);

    /**
     *
     * @param ascending
     */
    void sortByRating(bool ascending);

    /**
     *
     * @param filter
     * @param predicate
     * @return
     */
    MovieDatabase filterByPredicate(Filter filter, string predicate);

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
 * Union used as test harness to test MovieDatabase class functionality
 */
union RunMovieDatabaseTestHarness
{
    RunMovieDatabaseTestHarness()
    {
        cout << "---------------TESTING MOVIEDATABASE CLASS-----------------\n";

        cout << "MOVIE 1:\n";
        Movie movie1;
        stringstream ssi(R"("The Godfather: Part II",1974,"R","Crime/Drama",202,0")");
        ssi >> movie1;
        cout << movie1 << endl;

        cout << "MOVIE 2:\n";
        Movie movie2;
        stringstream ssii(R"("Sharknado",2013,"TV-14","Horror",86,0")");
        ssii >> movie2;
        cout << movie2 << endl;

        cout << "MOVIE 3:\n";
        Movie movie3;
        stringstream ssiii(R"("Network",1976,"R","Drama/Romance",121,0")");
        ssiii >> movie3;
        cout << movie3 << endl;

        cout << "MOVIE 4:\n";
        Movie movie4;
        stringstream ssiv(R"("The Help",2011,"PG-13","Drama",146,0")");
        ssiv >> movie4;
        cout << movie4 << endl;

        cout << "MOVIE 5:\n";
        Movie movie5;
        stringstream ssv(R"("3 Idiots",2009,"PG-13","Comedy/Drama",170,0")");
        ssv >> movie5;
        cout << movie5 << endl;
        cout << "-----------------------------------------------------------\n";

        cout << "MOVIEDATABASE 1:\n";
        MovieDatabase movieDatabase1;
        cout << movieDatabase1;

        cout << "MOVIEDATABASE 2:\n";
        MovieDatabase movieDatabase2;
        cout << movieDatabase2;
        cout << "-----------------------------------------------------------\n";

        //shared_ptr<Movie> mov(movie1);
        //movieDatabase1.addMovieToDatabase(mov);
    }
};

#endif //CPP_COURSEWORK_MOVIEDATABASE_HPP