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
#include "Movie.h"

using namespace std;

//TODO use lambda ?

//template <typename T>
class MovieDatabase
{
private:

    //vector<T> movieList;

public:

    friend istream& operator>>(istream& is, const MovieDatabase& mdb);

};

#endif //CPP_COURSEWORK_MOVIEDATABASE_H
