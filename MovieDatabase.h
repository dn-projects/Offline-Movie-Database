/*******************************************************************************
 File        : MovieDatabase.h

 Description :

 Author      : Dovydas Novikovas

 Date        :
*******************************************************************************/
#ifndef CPP_COURSEWORK_MOVIEDATABASE_H
#define CPP_COURSEWORK_MOVIEDATABASE_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Movie.h"

using namespace std;

struct movieFilter
{
    string title;
    int year;
    string genre;
    int duration;
    double rating;
    Certificate c;

    movieFilter(string t = "")
    {
        title = t;
    }

    //TODO have a number system to choose what to filter on
};

class MovieDatabase
{
private:

    vector<Movie> movieList;

public:

    explicit MovieDatabase()
    = default;

    inline vector<Movie> getMovieList() const
    {
        return movieList;
    }

    inline void addMovieToDatabase(Movie mov)
    {
        movieList.push_back(mov);
    }

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

    //TODO get type?
    template <typename I, typename M>
    Movie queryDatabase(I index = '*', int category = 0, M match = "")
    {
        vector<Movie> movieDatabase;

        for (const Movie& movie : movieList)
        {
            if (category == 0) // title
            {

            }
            else if (category == 1) // year
            {

            }
            else if (category == 2) // certificate
            {

            }
            else if (category == 3) // genre
            {
                if (movie.getGenre().find(match) != string::npos)
                {
                    if (index == '*')
                    {
                        cout << movie << endl;
                    }
                    movieDatabase.push_back(movie);
                }
            }
            else if (category == 4) // duration
            {

            }
            else if (category == 5) // rating
            {

            }
        }
        if (index != '*') {
            return movieDatabase[index];
        }
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
};

istream& operator>>(istream& is, MovieDatabase& mdb);

ostream& operator<<(ostream& os, MovieDatabase& mdb);

ostream& operator<<(ostream& os, vector<Movie> vec);

#endif //CPP_COURSEWORK_MOVIEDATABASE_H