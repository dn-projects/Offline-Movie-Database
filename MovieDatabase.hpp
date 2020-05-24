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

#include "Movie.hpp"

//TODO use functor, lambda, function pointer?

using namespace std;

class MovieDatabase {
private:

    vector<shared_ptr<Movie> > movieList;

public:

    explicit MovieDatabase()
    = default;


    inline vector<shared_ptr<Movie> > getMovieList() const
    {
        return movieList;
    }


    inline void addMovieToDatabase(shared_ptr<Movie> movie)
    {
        movieList.push_back(movie);
    }


    inline shared_ptr<Movie> operator[](const int &index)
    {
        return movieList[index];
    }

    inline void sort()
    {
        std::sort(movieList.begin(), movieList.end(),
                  [](shared_ptr<Movie> pointer1,
                     shared_ptr<Movie> pointer2) -> bool
                     {
                        return *pointer1 < *pointer2;
                     });
    }


    //inline void sortAscending()
    //{
        //TODO not generic
    //    std::sort(movieList.begin(), movieList.end(), [](shared_ptr<Movie> movie1, shared_ptr<Movie> movie2) -> bool {return *movie1 < *movie2;});
    //}

    //inline void sortDescending()
    //{
        //TODO not generic
    //    std::sort(movieList.begin(), movieList.end(), [](shared_ptr<Movie> movie1, shared_ptr<Movie> movie2) -> bool {return *movie1 > *movie2;});
    //}

    template <typename T>
    inline void sort(T compare)
    {
        std::sort(movieList.begin(), movieList.end(), compare);
    }

    void sortByTitle(bool ascending)
    {
        ascending?
        std::sort(movieList.begin(), movieList.end(), [](shared_ptr<Movie> movie1, shared_ptr<Movie> movie2) -> bool
        {
            return movie1->getTitle() < movie2->getTitle();
        })
        :
        std::sort(movieList.begin(), movieList.end(), [](shared_ptr<Movie> movie1, shared_ptr<Movie> movie2) -> bool
        {
            return movie1->getTitle() > movie2->getTitle();
        });
    }

    void sortByYear(bool ascending)
    {
        ascending?
        std::sort(movieList.begin(), movieList.end(), [](shared_ptr<Movie> movie1, shared_ptr<Movie> movie2) -> bool
        {
            return movie1->getYear() < movie2->getYear();
        })
        :
        std::sort(movieList.begin(), movieList.end(), [](shared_ptr<Movie> movie1, shared_ptr<Movie> movie2) -> bool
        {
            return movie1->getYear() > movie2->getYear();
        });
    }

    void sortByCertificate(bool ascending)
    {
        ascending?
        std::sort(movieList.begin(), movieList.end(), [](shared_ptr<Movie> movie1, shared_ptr<Movie> movie2) -> bool
        {
            return movie1->getCertificate() < movie2->getCertificate();
        })
        :
        std::sort(movieList.begin(), movieList.end(), [](shared_ptr<Movie> movie1, shared_ptr<Movie> movie2) -> bool
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
        std::sort(movieList.begin(), movieList.end(), [](shared_ptr<Movie> movie1, shared_ptr<Movie> movie2) -> bool
        {
            return movie1->getDuration() < movie2->getDuration();
        })
                 :
        std::sort(movieList.begin(), movieList.end(), [](shared_ptr<Movie> movie1, shared_ptr<Movie> movie2) -> bool
        {
            return movie1->getDuration() > movie2->getDuration();
        });
    }

    void sortByRating(bool ascending)
    {
        ascending?
        std::sort(movieList.begin(), movieList.end(), [](shared_ptr<Movie> movie1, shared_ptr<Movie> movie2) -> bool
        {
            return movie1->getRating() < movie2->getRating();
        })
                 :
        std::sort(movieList.begin(), movieList.end(), [](shared_ptr<Movie> movie1, shared_ptr<Movie> movie2) -> bool
        {
            return movie1->getRating() > movie2->getRating();
        });
    }




    bool Check(shared_ptr<Movie> mov)
    {
        Genre gen;
        string genre = "Film-Noir";
        string str ;

        istringstream(genre) >> gen;

        ostringstream os;

        os << mov->getGenre();

        str = os.str();

        if(str.find(genre) != string::npos)
        {
            return false;
        }
        return true;
    }

    void filterGenreByPredicate(string genre)
    {
        //Genre gen;
        //string str;

        //istringstream(genre) >> gen;

        remove_if(movieList.begin(), movieList.end(), [&](shared_ptr<Movie> mov){Genre gen;

            string str ;

            istringstream(genre) >> gen;

            ostringstream os;

            os << mov->getGenre();

            str = os.str();

            if(str.find(genre) != string::npos)
            {
                return false;
            }
            return true;});


//        for (shared_ptr<Movie> movie : movieList)
//        {
//            ostringstream os;
//
//            os << movie->getGenre();
//
//            str = os.str();
//
//            if(str.find(genre) != string::npos)
//            {
//                cout << *movie << endl;
//            }
//
//        }
    }




    template <typename T>
    void exchange(T& x, T& y)
    {
        T z = y; y = x; x = z;
    }









    template <typename T>
    struct FilterFunction
    {
        bool operator()(T& check)
        {
            if(check.getGenre().Film_Noir)
            {
                return true;
            }
            return false;
        }
    };

};


template <typename T>
struct Ascending
{
    bool operator()(T& x, T& y)
    {
        return x < y;
    }
};

template <typename T>
struct Descending
{
    bool operator()(T& x, T& y)
    {
        return x > y;
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