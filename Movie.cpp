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
    if (stringToCertificateMap.count(input) == 1)
    {
        certificate = stringToCertificateMap.at(input);
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
    return os << certificateToStringMap.at(certificate);
}

/**
 *
 */
istream& operator>>(istream& is, Genre& genre)
{
    map<string, function<void()> > stringToGenreMap =
    {
            {"Action",    [&] () { genre.Action = 1; } },
            {"Adventure", [&] () { genre.Adventure = 1; } },
            {"Animation", [&] () { genre.Animation = 1; } },
            {"Biography", [&] () { genre.Biography = 1; } },
            {"Comedy",    [&] () { genre.Comedy = 1; } },
            {"Crime",     [&] () { genre.Crime = 1; } },
            {"Drama",     [&] () { genre.Drama = 1; } },
            {"Family",    [&] () { genre.Family = 1; } },
            {"Fantasy",   [&] () { genre.Fantasy = 1; } },
            {"Film-Noir", [&] () { genre.Film_Noir = 1; } },
            {"History",   [&] () { genre.History = 1; } },
            {"Horror",    [&] () { genre.Horror = 1; } },
            {"Music",     [&] () { genre.Music = 1; } },
            {"Musical",   [&] () { genre.Musical = 1; } },
            {"Mystery",   [&] () { genre.Mystery = 1; } },
            {"Romance",   [&] () { genre.Romance = 1; } },
            {"Sci-Fi",    [&] () { genre.Sci_Fi = 1; } },
            {"Thriller",  [&] () { genre.Thriller = 1; } },
            {"War",       [&] () { genre.War = 1; } },
            {"Western",   [&] () { genre.Western = 1; } },
    };

    string genreString, token;

    is >> quoted(genreString);

    istringstream iss(genreString);
    while(getline(iss, token, '/'))
    {
        if(stringToGenreMap.count(token) == 1)
        {
            invoke(stringToGenreMap.at(token));
        }
        else
        {
            is.clear(ios_base::failbit);
            cerr << "Invalid Genre" << endl;
        }
    };
    return is;
}