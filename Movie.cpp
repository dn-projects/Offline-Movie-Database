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
#include "Movie.h"

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

            ss << quoted(cert);

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

istream& operator>>(istream& is, Certificate& cert)
{
    string input;

    is >> quoted(input);

    string certs[12] = { "NOT RATED", "UNRATED", "G", "PG", "PG-13", "R",
                         "APPROVED", "PASSED", "N/A", "TV-14", "M", "X"};

    for(int i = 0; i < 12; i++)
    {
        if ((strcmp(certs[i].c_str(), input.c_str())) == 0)
        {
            cert = ((Certificate)i);
        }
    }
    return is;
}

ostream& operator<<(ostream& os, const Certificate& cl)
{
    string certs[12] = { "NOT RATED", "UNRATED", "G", "PG", "PG-13", "R",
                         "APPROVED", "PASSED", "N/A", "TV-14", "M", "X"};

    for (int i = 0; i < 12; i++)
    {
        if(cl == (Certificate)i)
        {
            return os << certs[i];
        }
    }
}


