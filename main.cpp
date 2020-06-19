/*******************************************************************************
 File        : main.cpp

 Include     : Movie.h, MovieDatabase.h

 Description : The class contains a main method which will be used for running
               the functionality of the classes @Movie and @MovieDatabase.
               The class reads data from a file and populates a MovieDatabase
               object with a series of 'Films'. Then methods from MovieDatabase
               are used to answer specific queries. The main method also
               initialise two unions that display the test harness for Movie
               and MovieDatabase.

 Author      : Dovydas Novikovas

 Date        : Wednesday 6th May 2020
*******************************************************************************/

#include <iostream>
#include <fstream>
#include "Movie.h"
#include "MovieDatabase.h"

using namespace std;

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
    cout << movieDatabase;

    //  3. Displaying the third longest 'Film-Noir'
    cout << "\nTHIRD LONGEST FILM-NOIR:" << endl;
    movieDatabase.sortByDuration(false);
    cout << * movieDatabase.filterByPredicate(Filter::GENRE ,"Film-Noir")[2] << endl;

    //  4. Displaying the eight most recent UNRATED film
    cout << "\nEIGHT MOST RECENT UNRATED FILM:" << endl;
    movieDatabase.sortByYear(false);
    cout << * movieDatabase.filterByPredicate(Filter::CERTIFICATE, "UNRATED")[7] << endl;

    //  5. Displaying the film with the longest title
    cout << "\nFILM WITH LONGEST TITLE:" << endl;
    movieDatabase.sortByTitleLength(false);
    cout << * movieDatabase[0] << endl;

    // Test harness for Movie class
    RunMovieTestHarness();

    // Test harness for MovieDatabase class
    RunMovieDatabaseTestHarness();

    return 0;
}