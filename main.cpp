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

#include <functional>
#include <iostream>
#include <fstream>
#include "Movie.hpp"
#include "MovieDatabase.hpp"

using namespace std;

//TODO comment []
//TODO test harness []
//TODO check things are const []
//TODO maps into static []
//TODO rename variables []
//TODO move things out of header file []

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













//removing movie 
std::shared_ptr<Movie> movie4(new Movie);
 stringstream stream4("\"Casablanca\",1942,\"PG\",\"Drama/Romance/War\",102,0");
 stream4 >> *movie4;
 cout << "Testing removing single movie from database" << endl;
 cout << "Expected output - size = 249" << endl;
 cout << "Size before removing = " << movieDatabase.getMovieList().size() << endl;
 movieDatabase.removeMovieFromDatabase(movie4);
 cout << "Size after removing = " << movieDatabase.getMovieList().size() << endl << endl;


MovieDatabase movieDatabase1;
    cout << "Testing adding single movie to database" << endl;
    cout << "Expected output - size = 250" << endl;
    cout << "Size before add = " << movieDatabase1.getMovieList().size() << endl;
    movieDatabase1.addMovieToDatabase(movie4);
    cout << "Size after adding = " << movieDatabase1.getMovieList().size() << endl << endl;
    std::shared_ptr<Movie> movie5(new Movie);
    stringstream stream2("\"Casablanca\",1942,\"PG\",\"Drama/Romance/War\",102,0");
    stream2 >> *movie5;
    cout << "Expected output - size = 250" << endl;
    cout << "Size before add = " << movieDatabase1.getMovieList().size() << endl;
    movieDatabase1.addMovieToDatabase(movie5);
    cout << "Size after adding = " << movieDatabase1.getMovieList().size() << endl << endl;







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
    //RunMovieTestHarness();

    // Test harness for MovieDatabase class
    //RunMovieDatabaseTestHarness();

    return 0;
}