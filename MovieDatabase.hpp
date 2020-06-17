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

    inline void addMovieToDatabase(shared_ptr<Movie> movie)
    {
        if(std::find(movieList.begin(), movieList.end(), movie) != movieList.end() == false)
        {
            movieList.push_back(movie);
        }
        else
        {
            cout << "Movie already in database!" << endl;
        }
    }

    inline void addMoviesToDatabase(MovieDatabase *movies)
    {
        for (shared_ptr<Movie> movie: movies->movieList)
        {
            addMovieToDatabase(movie);
        }
    }

    void removeMovieFromDatabase(shared_ptr<Movie> movie)
    {
        movieList.erase(remove_if(movieList.begin(),
         movieList.end(), [movie] (shared_ptr<Movie> mov) { return *movie == *mov; }));
    }

    void removeMoviesFromDatabase(MovieDatabase *movies)
    {
        for (shared_ptr<Movie> movie: movies->movieList)
        {
            removeMovieFromDatabase(movie);
        }
    }


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

    void sortByTitle(bool ascending)
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

    void sortByTitleLength(bool ascending)
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

    void sortByYear(bool ascending)
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

    void sortByCertificate(bool ascending)
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

    //TODO explain why genre sort not implemented
    /*
    void sortByGenre(bool ascending)
    {
        ascending?
        std::sort(movieList.begin(), movieList.end(), [](shared_ptr<Movie> movie1, shared_ptr<Movie> movie2) -> bool
        {
            return movie1->getGenre() < movie2->getGenre();
        })
        :
        std::sort(movieList.begin(), movieList.end(), [](shared_ptr<Movie> movie1, shared_ptr<Movie> movie2) -> bool
        {
            return movie1->getGenre() > movie2->getGenre();
        });
    }
    */

    void sortByDuration(bool ascending)
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

    void sortByRating(bool ascending)
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



    MovieDatabase filterByPredicate(Filter filter, string predicate)
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
    }
};

#endif //CPP_COURSEWORK_MOVIEDATABASE_HPP