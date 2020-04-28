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
#include <iterator>
#include <vector>
#include "Movie.h++"
#include "MovieDatabase.hh"

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

    template<typename I>
    Movie returnMovieIndex(I index)
    {
        return DatabaseRetriever::returnMovieByIndex(movieList, index);
    }

    template<typename C>
    void printMovieCount(C count)
    {
        return DatabaseRetriever::printMovieByCount(movieList, count);
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

istream& operator>>(istream& is, MovieDatabase& mdb);

ostream& operator<<(ostream& os, MovieDatabase& mdb);

ostream& operator<<(ostream& os, vector<Movie> vec);

#endif //CPP_COURSEWORK_MOVIEDATABASE_H