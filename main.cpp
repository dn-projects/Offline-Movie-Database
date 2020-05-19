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
//TODO bit fields []

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
    //cout << movieDatabase << endl;

    //  3. Displaying the third longest 'Film-Noir'
    cout << "\nTHIRD LONGEST FILM-NOIR:" << endl;
    cout << movieDatabase << endl;
    cout << endl;
    //Descending<Movie> descending;
    Ascending<Movie> ascending;
    movieDatabase.sortCollection(movieDatabase.getMovieList(), ascending);

    //FilterFunction<Movie> filterFunction;
    //movieDatabase.printResults(movieDatabase.getMovieList(), filterFunction);
    //cout << *movieDatabase.printResult<Movie>() << endl;


    //  4. Displaying the eight most recent UNRATED film
    cout << "\nEIGHT MOST RECENT UNRATED FILM:" << endl;


    //  5. Displaying the film with the longest title
    cout << "\nFILM WITH LONGEST TITLE:" << endl;


    // Test harness for Movie class
    //RunMovieTestHarness();

    // Test harness for MovieDatabase class
    //RunMovieDatabaseTestHarness();

    return 0;
}