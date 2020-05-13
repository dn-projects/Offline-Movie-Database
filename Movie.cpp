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
    Certificate certificate;
    string title, genre, cert;
    int year, dur, rate;

    if (is >> quoted(title) >> c >> year >> c >> quoted(cert)
           >> c >> quoted(genre) >> c >> dur >> c >> rate)
    {
        if(c == ',')
        {
            // uses overloaded operator >>(input stream, Certificate)
            stringstream ss(cert);
            ss >> certificate;

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
    string input;
    getline(is, input);
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