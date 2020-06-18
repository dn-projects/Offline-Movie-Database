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
    if(movieDatabase.getMovieList().size() == 0)
    {
        cout << "Database empty!" << endl;
    }
    else
    {
        for (shared_ptr<Movie> movie: movieDatabase.getMovieList())
        {
            os << *movie << endl;
        }
    }
    return os;
}

void MovieDatabase::sortByTitle(bool ascending)
{
    ascending?
    std::sort(movieList.begin(), movieList.end(),
    [](shared_ptr<Movie> movie1, shared_ptr<Movie> movie2) -> bool
    {
        return movie1->getTitle() < movie2->getTitle();
    })
    :
    std::sort(movieList.begin(), movieList.end(),
    [](shared_ptr<Movie> movie1, shared_ptr<Movie> movie2) -> bool
    {
        return movie1->getTitle() > movie2->getTitle();
    });
}

void MovieDatabase::sortByTitleLength(bool ascending)
{
    ascending?
    std::sort(movieList.begin(), movieList.end(),
    [](shared_ptr<Movie> movie1, shared_ptr<Movie> movie2) -> bool
    {
        return movie1->getTitle().length() < movie2->getTitle().length();
    })
    :
    std::sort(movieList.begin(), movieList.end(),
    [](shared_ptr<Movie> movie1, shared_ptr<Movie> movie2) -> bool
    {
        return movie1->getTitle().length() > movie2->getTitle().length();
    });
}

void MovieDatabase::sortByYear(bool ascending)
{
    ascending?
    std::sort(movieList.begin(), movieList.end(),
    [](shared_ptr<Movie> movie1, shared_ptr<Movie> movie2) -> bool
    {
        return *movie1 < *movie2;
    })
    :
    std::sort(movieList.begin(), movieList.end(),
    [](shared_ptr<Movie> movie1, shared_ptr<Movie> movie2) -> bool
    {
        return *movie1 > *movie2;
    });
}

void MovieDatabase::sortByCertificate(bool ascending)
{
    ascending?
    std::sort(movieList.begin(), movieList.end(),
    [](shared_ptr<Movie> movie1, shared_ptr<Movie> movie2) -> bool
    {
        return movie1->getCertificate() < movie2->getCertificate();
    })
    :
    std::sort(movieList.begin(), movieList.end(),
    [](shared_ptr<Movie> movie1, shared_ptr<Movie> movie2) -> bool
    {
        return movie1->getCertificate() > movie2->getCertificate();
    });
}

void MovieDatabase::sortByDuration(bool ascending)
{
    ascending?
    std::sort(movieList.begin(), movieList.end(),
    [](shared_ptr<Movie> movie1, shared_ptr<Movie> movie2) -> bool
    {
        return movie1->getDuration() < movie2->getDuration();
    })
    :
    std::sort(movieList.begin(), movieList.end(),
    [](shared_ptr<Movie> movie1, shared_ptr<Movie> movie2) -> bool
    {
        return movie1->getDuration() > movie2->getDuration();
    });
}

void MovieDatabase::sortByRating(bool ascending)
{
    ascending?
    std::sort(movieList.begin(), movieList.end(),
    [](shared_ptr<Movie> movie1, shared_ptr<Movie> movie2) -> bool
    {
        return movie1->getRating() < movie2->getRating();
    })
    :
    std::sort(movieList.begin(), movieList.end(),
    [](shared_ptr<Movie> movie1, shared_ptr<Movie> movie2) -> bool
    {
        return movie1->getRating() > movie2->getRating();
    });
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

    copy_if(movieList.begin(),movieList.end(),
            back_inserter(filtered.movieList), filterMap.at(filter));

    return filtered;
}