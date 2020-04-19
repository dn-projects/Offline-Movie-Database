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

//template <typename T>
class MovieDatabase
{
private:

    vector<Movie> movieList;

public:

    explicit MovieDatabase(const Movie mov = Movie())
    {
        movieList.push_back(mov);
        cout << "Another movie added!" << endl;
    }

    inline vector<Movie> getMovieList() const
    {
        return movieList;
    }
};

istream& operator>>(istream& is, MovieDatabase& mdb);

ostream& operator<<(ostream& os, MovieDatabase& mdb);

ostream& operator<<(ostream& os, vector<Movie> vec);

#endif //CPP_COURSEWORK_MOVIEDATABASE_H
