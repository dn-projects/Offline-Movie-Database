/*******************************************************************************
 File        : MovieDatabase.hpp

 Include     : Movie.hpp

 Description : MovieDatabase header file contains an eum class to allow a user
               to choose a predicate to filter on. MovieDatabase class acts as a
               database by implementing a vector that stores Movie objects. The
               class overloads the input and output operators to allow the class
               to add a film entry to the database as well as print out all the
               films in the database. The class also has the functionality of
               sorting and filtering the database to answer specific queries
               about the films in the database.

               also has union

 Author      : Dovydas Novikovas

 Date        : Wednesday 6th May 2020

 Notes       : Method 'sortByGenre' was not implemented because it does not
               seem practical sorting MovieDatabase by genres as it will not
               sort the Movies in a logical order. Considering a Movie can have
               one or multiple genres the sorting order will be too ambiguous
               and will not provide much clarity to the sorting order.
*******************************************************************************/

//TODO finish header comment

#ifndef CPP_COURSEWORK_MOVIEDATABASE_HPP
#define CPP_COURSEWORK_MOVIEDATABASE_HPP

#include <memory>
#include <vector>
#include <map>

#include "Movie.hpp"

using namespace std;

/**
 *  Enum class Filter contains predicates that can be used as a specifier for
 *  which element in the database to filter on
 */
enum class Filter
{
    TITLE, YEAR, CERTIFICATE, GENRE, DURATION, RATING
};

class MovieDatabase
{
private:

    vector< shared_ptr<Movie> > movieList;

public:

    explicit MovieDatabase()
    = default;

    /**
     * An inline function used to return the vector of shared pointers
     *
     * @return vector of shared pointers
     */
    inline vector<shared_ptr<Movie> > getMovieList() const
    {
        return movieList;
    }

    /**
     * Overloaded operator, returns element from movieList at a specific index.
     *
     * @param index - Element index
     * @return Shared pointer at specific index
     */
    inline shared_ptr<Movie> operator[](const int &index)
    {
        return movieList[index];
    }

    /**
     *  Clears all the elements in movieList vector
     */
    inline void deleteAllMovies()
    {
        movieList.clear();
    }

    /**
     * Adds a shared pointer, pointing to a Movie object to the vector in
     * MovieDatabase. The function checks if the movie being added is not
     * already in the vector, if the movie database already contains the movie
     * and error message is displayed.
     *
     * @param movieToAdd - shared pointer that points to a movie object
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
            cerr << "Movie already in database!" << endl;
        }
    }

    /**
     * Iterates through a MovieDatabase passed in by refrence and for each
     * shared pointer in that MovieDatabase the functin makes a call to
     * addMovieToDatabase() function to add that shared pointer to 'this'
     * MovieDatabase.
     *
     * @param movies - MovieDatabase containing shared pointers to Movie objects
     */
    inline void addMoviesToDatabase(MovieDatabase * movies)
    {
        for (shared_ptr<Movie> movie: movies->movieList)
        {
            addMovieToDatabase(movie);
        }
    }

    /**
     * Accepts a shared pointer to a Movie and then checks movieList vector to
     * see if the shared pointer is found. If true, removes the shared pointer.
     *
     * @param movie - Pointer to movie, to be removed
     */
    void removeMovieFromDatabase(shared_ptr<Movie> movie)
    {
        movieList.erase(remove_if(movieList.begin(),
         movieList.end(), [movie] (shared_ptr<Movie> mov) { return *movie == *mov; }));
    }

    /**
     * Iterates through a MovieDatabase passed in and for each Movie calls
     * removeMovieFromDatabase() function.
     *
     * @param movies - MovieDatabase of movie to remove
     */
    void removeMoviesFromDatabase(MovieDatabase *movies)
    {
        for (shared_ptr<Movie> movie: movies->movieList)
        {
            removeMovieFromDatabase(movie);
        }
    }

    /**
     * A default sort that can be used to sort a MovieDatabase. This function
     * calls sortByYear() function. (sorts movieList by year in ascending order)
     */
    inline void sort()
    {
        sortByYear(true);
    }














//-------------------------------------------------------------------------------------------------------------------------------------------
    /**
     * Sorts the movieDatabase by comapring two movie titles
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
    Union used as test harness to test MovieDatabase class functionality
 */
union RunMovieDatabaseTestHarness
{
    RunMovieDatabaseTestHarness()
    {
        cout << "---------------TESTING MOVIEDATABASE CLASS-----------------\n";

        cout << "INITIALISING MOVIEDATABASE 1:\n";
        MovieDatabase movieDatabase1;
        cout << movieDatabase1;

        cout << "INITIALISING MOVIEDATABASE 2:\n";
        MovieDatabase movieDatabase2;
        cout << movieDatabase2;

        cout << "INITIALISING MOVIEDATABASE 3:\n";
        MovieDatabase movieDatabase3;
        cout << movieDatabase3;
        cout << "-----------------------------------------------------------\n";

        cout << "TESTING MOVIEDATABASE INPUT AND OUTPUT OPERATOR:\n";
        stringstream ssi(R"("The Godfather",1974,"R","Crime/Drama",202,0")");
        ssi >> movieDatabase1;
        cout << "MovieDatabase1:\n" << movieDatabase1 << endl;

        cout << "TESTING MOVIEDATABASE INPUT AND OUTPUT OPERATOR:\n";
        stringstream ssii(R"("Sharknado",2013,"TV-14","Horror",86,0")");
        ssii >> movieDatabase1;
        cout << "MovieDatabase1:\n" << movieDatabase1 << endl;

        cout << "TESTING MOVIEDATABASE INPUT AND OUTPUT OPERATOR:\n";
        stringstream ssiii(R"("Network",1976,"R","Drama/Romance",121,0")");
        ssiii >> movieDatabase1;
        cout << "MovieDatabase1:\n" << movieDatabase1 << endl;

        cout << "TESTING MOVIEDATABASE INPUT AND OUTPUT OPERATOR:\n";
        stringstream ssiv(R"("The Help",2011,"PG-13","Drama",146,0")");
        ssiv >> movieDatabase1;
        cout << "MovieDatabase1:\n" << movieDatabase1 << endl;

        cout << "TESTING MOVIEDATABASE INPUT AND OUTPUT OPERATOR:\n";
        stringstream ssv(R"("3 Idiots",2009,"PG-13","Comedy/Drama",170,0")");
        ssv >> movieDatabase1;
        cout << "MovieDatabase1:\n" << movieDatabase1;
        cout << "-----------------------------------------------------------\n";

        shared_ptr<Movie> movPtr(new Movie);
        istringstream is(R"("Platoon",1986,"R","Drama/War",120,0)");
        is >> * movPtr;
        cout << "TESTING addMovieToDatabase():\n";
        cout << "Movie to add = " << * movPtr << endl;
        movieDatabase2.addMovieToDatabase(movPtr);
        cout << "MovieDatabase2:\n" << movieDatabase2;
        cout << "-----------------------------------------------------------\n";

        cout << "TESTING addMoviesToDatabase():\n";
        cout << "Movies to add = \n" << movieDatabase1 << endl;
        movieDatabase2.addMoviesToDatabase(&movieDatabase1);
        cout << "MovieDatabase2:\n" << movieDatabase2;
        cout << "-----------------------------------------------------------\n";

        cout << "TESTING removeMovieFromDatabase():\n";
        cout << "Movie to remove = " << * movPtr << endl;
        movieDatabase2.removeMovieFromDatabase(movPtr);
        cout << "MovieDatabase2:\n" << movieDatabase2;
        cout << "-----------------------------------------------------------\n";

        cout << "TESTING removeMoviesFromDatabase():\n";
        cout << "Movies to remove = \n" << movieDatabase1 << endl;
        movieDatabase2.removeMoviesFromDatabase(&movieDatabase1);
        cout << "MovieDatabase2:\n" << movieDatabase2;
        cout << "-----------------------------------------------------------\n";

        cout << "TESTING MOVIEDATABASE [] OPERATOR:\n";
        cout << * movieDatabase1[3] << endl;
        cout << "-----------------------------------------------------------\n";

        cout << "TESTING sort():\n";
        movieDatabase1.sort();
        cout << movieDatabase1;
        cout << "-----------------------------------------------------------\n";

        cout << "TESTING sortByTitle():\n";
        movieDatabase1.sortByTitle(true);
        cout << movieDatabase1;
        cout << "-----------------------------------------------------------\n";

        cout << "TESTING sortByTitleLength():\n";
        movieDatabase1.sortByTitleLength(true);
        cout << movieDatabase1;
        cout << "-----------------------------------------------------------\n";

        cout << "TESTING sortByYear():\n";
        movieDatabase1.sortByYear(true);
        cout << movieDatabase1;
        cout << "-----------------------------------------------------------\n";

        cout << "TESTING sortByCertificate():\n";
        movieDatabase1.sortByCertificate(true);
        cout << movieDatabase1;
        cout << "-----------------------------------------------------------\n";

        cout << "TESTING sortByDuration():\n";
        movieDatabase1.sortByDuration(true);
        cout << movieDatabase1;
        cout << "-----------------------------------------------------------\n";

        cout << "TESTING sortByRating():\n";
        movieDatabase1.sortByRating(true);
        cout << movieDatabase1;
        cout << "-----------------------------------------------------------\n";

        cout << "TESTING deleteAllMovies():\n";
        movieDatabase3.addMoviesToDatabase(&movieDatabase1);
        cout << movieDatabase3 << endl;
        movieDatabase3.deleteAllMovies();
        cout << movieDatabase3;
        cout << "-----------------------------------------------------------\n";

        cout << "TESTING filterByPredicate():\n";
        MovieDatabase filteredDatabase;
        filteredDatabase = movieDatabase1.filterByPredicate
        (Filter::CERTIFICATE, "PG-13");
        cout << filteredDatabase << endl;
        cout << * movieDatabase1.filterByPredicate
        (Filter::TITLE, "The Help")[0] << endl << endl;
        cout << * movieDatabase1.filterByPredicate
        (Filter::TITLE, "inception")[2] << endl;
    }
};

#endif //CPP_COURSEWORK_MOVIEDATABASE_HPP