/*******************************************************************************
 File        : main.cpp

 Description :

 Author      : Dovydas Novikovas

 Date        :
*******************************************************************************/

#include <string>
#include <iostream>
#include <sstream>
#include "Movie.h"
#include "MovieDatabase.h"

using namespace std;

int main()
{
    MovieDatabase mdb;
    Movie mov1;

    string line;
    ifstream ifs("/Users/david/ /Prog2_cpplabs/cpp_coursework/oneFilm.txt");
    if (ifs.is_open())
    {
        while (getline (ifs, line))
        {
            stringstream ss;
            ss << line;
            ss >> mdb;
        }
        ifs.close();
    }
    else
    {
        cout << "Unable to open file!";
    }

    //cout << mov1 << endl;



    //MovieDatabase >> filePath

    // pass a file to MovieDatabase using >> (stream >> string) (stream >> file)
    // in (MovieDatabase >>) call MovieDatabase constructor and pass in file/string to constructor
    // in MovieDatabase constructor split on each line and then call movie >>
    // getLine
    // movie >> getLine

    // pass a string into Movie >>
    // in Movie >> call movie constructor (that accepts a string)
    // in constructor (string) split string into title, year etc
    // in movie constructor that accepts a string call other constructor that accepts title, year etc

    // print out each Movie on a new line
    //cout << mdb << endl;

    return 0;
}