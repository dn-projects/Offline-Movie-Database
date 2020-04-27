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
    MovieDatabase movieDatabase;

    string line;
    ifstream ifs("/Users/David/Offline-Movie-Database/films.txt");
    if (ifs.is_open())
    {
        while (getline(ifs, line))
        {
            stringstream ss;
            ss << line;
            ss >> movieDatabase;
        }
        ifs.close();
    }
    else
    {
        cout << "Unable to open file!";
    }

    cout << movieDatabase << endl << endl;

    movieDatabase.sort();

    cout << movieDatabase << endl << endl;

    movieDatabase.sort([](Movie& movie1, Movie& movie2) -> bool
    {
        return movie1.getYear() < movie2.getYear();
    });

    cout << movieDatabase << endl << endl;

    movieDatabase.filter([](Movie &movie) -> bool {
        return movie.getGenre() == "Film-Noir";
    });

    return 0;
}