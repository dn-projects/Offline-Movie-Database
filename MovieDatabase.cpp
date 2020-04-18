/*******************************************************************************
 File        : MovieDatabase.cpp

 Description :

 Author      : Dovydas Novikovas

 Date        :
*******************************************************************************/

#include <string>
#include <vector>
#include <iostream>
#include "MovieDatabase.h"
#include "Movie.h"

using namespace std;

//TODO use lambda ?

template <typename T>
istream& operator>>(istream& is, const MovieDatabase<T>& mdb)
{
    Movie mov;

    is >> mov;

    //push movie onto list of movie

    cout << "The Movie: \n" << mov;

    return is;
}