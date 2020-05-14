/*******************************************************************************
 File        : Movie.cpp

 Include     : Movie.hpp, Movie.hh

 Description : Contains the implementations for the overloaded input and output
               operators for class Movie.

 Author      : Dovydas Novikovas

 Date        : Wednesday 6th May 2020
*******************************************************************************/

#include <sstream>
#include <iostream>
#include <iomanip>
#include <map>
#include "Movie.hpp"
#include "Movie.hh"

using namespace std;

/**
 * Function body for overloaded input operator for input stream, Movie
 */
istream& operator>>(istream& is, Movie& movie)
{
    char c;
    Genre genre;
    string title;
    int year, dur, rate;
    Certificate certificate;

    if (is >> quoted(title) >> c >> year >> c >> certificate
           >> c >> genre >> c >> dur >> c >> rate)
    {
        if(c == ',')
        {
            movie = Movie(title, year, certificate, genre, dur, rate);
        }
        else
        {
            is.clear(ios_base::failbit);
            cerr << "Failed to generate Movie" << endl;
        }
    }
    return is;
}

/**
 * Function body for overloaded output operator for output stream, Movie
 */
ostream& operator<<(ostream& os, const Movie& movie)
{
    return os << "\"" << movie.getTitle()       << "\","
                      << movie.getYear()        << ",\""
                      << movie.getCertificate() << "\",\""
                      << movie.getGenre()       << "\","
                      << movie.getDuration()    << ","
                      << movie.getRating();
}

/**
 * Function body for overloaded input operator for input stream, Certificate
 */
istream &operator>>(istream& is, Certificate& certificate)
{
    char c;
    string input;

    is >> c;

    getline(is, input, '"');
    if (certificateInputMap.count(input) == 1)
    {
        certificate = certificateInputMap.at(input);
    }
    else
    {
        cerr << "Not a certificate!" << input << endl;
        is.clear(ios_base::failbit);
    }
    return is;
}

/**
 * Function body for overloaded output operator for output stream, Certificate
 */
ostream &operator<<(ostream& os, Certificate certificate)
{
    return os << certificateOutputMap.at(certificate);
}




istream& operator>>(istream& is, Genre& genre)
{
    char c;
    string genreString;

    is >> c;

    if(c == '"')
    {
        while (getline(is, genreString, '"'))
        {
            if(genreString.find("Action") != string::npos)
            {
                genre.Action = 1;
            }
            if(genreString.find("Adventure") != string::npos)
            {
                genre.Adventure = 1;
            }
            if(genreString.find("Animation") != string::npos)
            {
                genre.Animation = 1;
            }
            if(genreString.find("Biography") != string::npos)
            {
                genre.Biography = 1;
            }
            if(genreString.find("Comedy") != string::npos)
            {
                genre.Comedy = 1;
            }
            if(genreString.find("Crime") != string::npos)
            {
                genre.Crime = 1;
            }
            if(genreString.find("Drama") != string::npos)
            {
                genre.Drama = 1;
            }
            if(genreString.find("Family") != string::npos)
            {
                genre.Family = 1;
            }
            if(genreString.find("Fantasy") != string::npos)
            {
                genre.Fantasy = 1;
            }
            if(genreString.find("Film-Noir") != string::npos)
            {
                genre.Film_Noir = 1;
            }
            if(genreString.find("History") != string::npos)
            {
                genre.History = 1;
            }
            if(genreString.find("Horror") != string::npos)
            {
                genre.Horror = 1;
            }
            if(genreString.find("Music") != string::npos)
            {
                genre.Music = 1;
            }
            if(genreString.find("Musical") != string::npos)
            {
                genre.Musical = 1;
            }
            if(genreString.find("Mystery") != string::npos)
            {
                genre.Mystery = 1;
            }
            if(genreString.find("Romance") != string::npos)
            {
                genre.Romance = 1;
            }
            if(genreString.find("Sci-Fi") != string::npos)
            {
                genre.Sci_Fi = 1;
            }
            if(genreString.find("Thriller") != string::npos)
            {
                genre.Thriller = 1;
            }
            if(genreString.find("War") != string::npos)
            {
                genre.War = 1;
            }
            if(genreString.find("Western") != string::npos)
            {
                genre.Western = 1;
            }
        }
    }
    else
    {
        is.clear(ios_base::failbit);
        cerr << "Incorrect Genre" << endl;
    }
    return is;
}

ostream& operator<<(ostream& os, const Genre& genre) {
    os << "Action: " << genre.Action << " Adventure: " << genre.Adventure
       << " Animation: " << genre.Animation << " Biography: " << genre.Biography
       << " Comedy: " << genre.Comedy << " Crime: " << genre.Crime << " Drama: "
       << genre.Drama << " Family: " << genre.Family << " Fantasy: "
       << genre.Fantasy << " Film_Noir: " << genre.Film_Noir << " History: "
       << genre.History << " Horror: " << genre.Horror << " Music: "
       << genre.Music << " Musical: " << genre.Musical << " Mystery: "
       << genre.Mystery << " Romance: " << genre.Romance << " Sci_Fi: "
       << genre.Sci_Fi << " Thriller: " << genre.Thriller << " War: "
       << genre.War << " Western: " << genre.Western;
    return os;
}
