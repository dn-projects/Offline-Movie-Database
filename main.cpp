/*******************************************************************************
 File        : main.cpp

 Include     : Movie.hpp, MovieDatabase.hpp

 Description : The class contains a main method which will be used for running
               and testing the classes @Movie.cpp and @MovieDatabase.cpp.
               The class reads data from a file and populates a MovieDatabase
               object(vector of Movie objects) with a series of 'Films'. Then
               methods from MovieDatabase are used to answer specific queries.
               The method also initialise two structs that display the test
               harness for Movie and MovieDatabase.

 Author      : Dovydas Novikovas

 Date        : Wednesday 6th May 2020
*******************************************************************************/

#include <string>
#include <functional>
#include <iostream>
#include <fstream>
#include "Movie.hpp"
#include "MovieDatabase.hpp"

using namespace std;

//TODO comment []
//TODO test harness []


//TODO filter/sort method []
//TODO pointers []
//TODO garbage collection []
//TODO bit fields [x]
//TODO check things are const []

int main()
{
    MovieDatabase movieDatabase;

    //  1. Using "films.txt" to populate movieDatabase with data
    ifstream ifs("films.txt", ifstream::in);
    if(ifs)
    {
        ifs >> movieDatabase;
        ifs.close();
    }
    else
    {
        cerr << "Error: unable to open input file" << endl;
    }

    //  2. Displaying all Movies in chronological order
    cout << "FILMS IN CHRONOLOGICAL ORDER:" << endl;
    //cout << movieDatabase;

    //  3. Displaying the third longest 'Film-Noir'
    cout << "\nTHIRD LONGEST FILM-NOIR:" << endl;



    //cout << movieDatabase << endl;
    //movieDatabase.filterTitleByPredicate("Ikiru");
    //movieDatabase.filterGenreByPredicate("Film-Noir");
    //cout << movieDatabase << endl;
    //cout << *movieDatabase.movieByIndex(1);


    //movieDatabase.filterGenreByPredicate(Genre().Film_Noir);
    //cout << movieDatabase;
    //movieDatabase.filterGenreByPredicate("Film-Noir");
    //cout << movieDatabase;



    //  4. Displaying the eight most recent UNRATED film
    cout << "\nEIGHT MOST RECENT UNRATED FILM:" << endl;


    //  5. Displaying the film with the longest title
    cout << "\nFILM WITH LONGEST TITLE:" << endl;
    //movieDatabase.sortByTitleLength(false);
    //cout << * movieDatabase[0] << endl;

    // Test harness for Movie class
    //RunMovieTestHarness();

    // Test harness for MovieDatabase class
    //RunMovieDatabaseTestHarness();

    return 0;
}