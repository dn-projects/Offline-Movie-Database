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

//TODO use lambda ?

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
};

istream& operator>>(istream& is, MovieDatabase& mdb);

ostream& operator<<(ostream& os, MovieDatabase& mdb);

ostream& operator<<(ostream& os, vector<Movie> vec);

#endif //CPP_COURSEWORK_MOVIEDATABASE_H
