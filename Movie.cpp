/*******************************************************************************
 File        : Movie.cpp

 Description : A class that stores the information about a film (Title, Year,
               Certificate, Genre, Duration and Rating) The class acts as a
               template to allow an object to be generated for a film.
               This object can then be used in the MovieDatabase class to add
               an entry (a film object) to the database.

 Author      : Dovydas Novikovas

 Date        : Wednesday 6th May 2020
*******************************************************************************/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <map>
#include "Movie.h++"
#include "Movie.hh"

using namespace std;

/**
 * Overloading the input operator to convert a string into into a movie object
 *
 * @param is    - an input stream
 * @param movie - movie object to instantiate
 * @return returns the input stream
 */
istream& operator>>(istream& is, Movie& movie)
{
    char c;
    Certificate ce;
    string title, genre, cert;
    int year, dur, rate;

    if (is >> quoted(title) >> c >> year >> c >> quoted(cert)
           >> c >> quoted(genre) >> c >> dur >> c >> rate)
    {
        if(c == ',')
        {
            stringstream ss;

            ss << cert;

            ss >> ce;

            movie = Movie(title, year, ce, genre, dur, rate);
        }
        else
        {
            is.clear(ios_base::failbit);
        }
    }
    return is;
}

/**
 * Overloading the output operator to format a movie object to be printed
 *
 * @param os    - the formatted output stream
 * @param movie - movie object to print out
 * @return the formatted output stream
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
 * Overloading the input operator for a input stream and a Certificate, converts
 * string into Certificate. If no certificate found, error message is printed
 *
 * @param is          - an input stream
 * @param certificate - Certificate to instate with the relevant certificate
 * @return input stream after a converted string into a Certificate
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
        is.clear();
    }
    return is;
}

/**
 * Overloading the output operator to print out a certificate to a string
 *
 * @param os          - the output stream operator
 * @param certificate -
 * @return
 */
ostream &operator<<(ostream& os, Certificate certificate)
{
    return os << certificateOutputMap.at(certificate);
}