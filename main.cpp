/*******************************************************************************
 File        : main.cpp

 Description : The class contains a main method which will be used for running
               and testing the classes @Movie.cpp and @MovieDatabase.cpp.
               The class reads data from a file and populates a MovieDatabase
               object(vector of Movie objects) with a series of 'Films'.

 Author      : Dovydas Novikovas

 Date        : Wednesday 6th May 2020
*******************************************************************************/

#include <string>
#include <iostream>
#include "Movie.h++"
#include "MovieDatabase.h++"

using namespace std;

//TODO make test harness function for each class

int main()
{
    Movie movie;



    //MovieDatabase movieDatabase;

    //ifstream ifs("films.txt", ifstream::in);

    //if(ifs)
    //{
    //    ifs >> movieDatabase;
    //    ifs.close();
    //}
    //else
    //{
    //    cerr << "Error: unable to open input file" << endl;
    //}

    //cout << movieDatabase << endl << endl;



    //cout << movieDatabase << endl << endl;

    //movieDatabase.sort([](Movie& movie1, Movie& movie2) -> bool
    //{
    //    return movie1.getYear() < movie2.getYear();
    //});

    //cout << movieDatabase << endl << endl;

    //movieDatabase.filter([](Movie &movie) -> bool
    //{
    //    return movie.getGenre() == "Film-Noir"; //TODO is '==' correct
    //});

//    cout << "printing movie by index: \n";
//    Movie movie1 = movieDatabase.returnMovieIndex(0);
//    cout << movie1 << endl;
//
//    cout << "printing movie by count: \n";
//    movieDatabase.printMovieCount(0);

    //movieDatabase.queryDatabase('*', 0, "");
    //cout << "The movie is: " << endl << endl;
    //cout << movieDatabase.queryDatabase(2, 3, "Film-Noir");

    return 0;
}