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

MovieDatabase MovieDatabase::filterByPredicate(Filter filter, string predicate)
{
    const map<Filter, function<bool(shared_ptr<Movie>)> > filterMap =
    {
            { Filter::TITLE, [predicate](shared_ptr<Movie> movie)
                             {
                                 return movie->getTitle() == predicate;
                             } },

            { Filter::YEAR, [predicate](shared_ptr<Movie> movie)
                             {
                                 return movie->getYear() == stoi(predicate);
                             } },

            { Filter::CERTIFICATE, [predicate](shared_ptr<Movie> movie)
                             {
                                 Certificate certificate;
                                 // char added before the predicate because input operator
                                 // removes first character
                                 stringstream ss('"' + predicate);

                                 ss >> certificate;

                                 return movie->getCertificate() == certificate;
                             } },

            { Filter::GENRE, [predicate](shared_ptr<Movie> movie)
                             {
                                 Genre genre;
                                 ostringstream os(predicate);

                                 os << movie->getGenre();

                                 return os.str().find(predicate) != string::npos;
                             } },

            { Filter::DURATION, [predicate](shared_ptr<Movie> movie)
                             {
                                 return movie->getDuration() == stoi(predicate);
                             } },

            { Filter::RATING, [predicate](shared_ptr<Movie> movie)
                             {
                                 return movie->getRating() == stoi(predicate);
                             } },
    };

    MovieDatabase filtered;
    std::copy_if(movieList.begin(),movieList.end(),
                 back_inserter(filtered.movieList),
                 filterMap.at(filter));
    return filtered;
}