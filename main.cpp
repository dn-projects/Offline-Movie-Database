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
    Movie m1;

    string line;
    ifstream ifs("/Users/David/Offline-Movie-Database/oneFilm.txt");
    if (ifs.is_open())
    {
        while (getline(ifs, line))
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

    cout << mdb;

    return 0;
}


