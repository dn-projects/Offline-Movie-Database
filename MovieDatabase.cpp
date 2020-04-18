/*******************************************************************************
 File        : MovieDatabase.cpp

 Description :

 Author      : Dovydas Novikovas

 Date        :
*******************************************************************************/

#include <vector>
#include <string>
#include <iostream>
#include "MovieDatabase.h"
#include "Movie.h"

using namespace std;

//TODO use lambda ?

istream& operator>>(istream& is, const MovieDatabase& mdb)
{
    Movie mov;

    is >> mov;

    //push movie onto list of movie

    cout << "The Movie: \n" << mov;

    return is;
}