/*******************************************************************************
 File        : Movie.cpp

 Description :

 Author      : Dovydas Novikovas

 Date        :
*******************************************************************************/

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <map>
#include "Movie.h"
#include "Movie.hh"

using namespace std;

inline bool operator>(const Movie& movie1, const Movie& movie2)
{
    return movie1.getTitle() > movie2.getTitle();
}

inline bool operator<(const Movie& movie1, const Movie& movie2)
{
    return movie1.getTitle() < movie2.getTitle();
}

bool operator==(const Movie& movie1, const Movie& movie2)
{
    return (movie1.getTitle() == movie2.getTitle());
}

bool operator!=(const Movie& movie1, const Movie& movie2)
{
    return !(movie1 == movie2);
}

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

ostream& operator<<(ostream& os, const Movie& movie)
{
    return os << "\"" << movie.getTitle()       << "\","
                      << movie.getYear()        << ",\""
                      << movie.getCertificate() << "\",\""
                      << movie.getGenre()       << "\","
                      << movie.getDuration()    << ","
                      << movie.getRating();
}

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

ostream &operator<<(ostream& os, Certificate certificate)
{
    return os << certificateOutputMap.at(certificate);
}


