/*******************************************************************************
 File        : Movie.cpp

 Description :

 Author      : Dovydas Novikovas

 Date        :
*******************************************************************************/

#include <string>
#include <iostream>
#include <iomanip>
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
    string title, cert, genre;
    int year, dur, rate;

    if (is >> quoted(title) >> c >> year >> c >> quoted(cert)
           >> c >> quoted(genre) >> c >> dur >> c >> rate)
    {
        if(c == ',')
        {
            Certificate c = Movie::stringToEnum(cert);

            movie = Movie(title, year, c, genre, dur, rate);
        }
        else
        {
            is.clear(ios_base::failbit);
        }
    }
    return is;
}

Certificate Movie::stringToEnum(string str)
{
    if(str == "NOT RATED")     { return Certificate::NOT_RATED; }
    else if(str == "UNRATED")  { return Certificate::UNRATED; }
    else if(str == "PG-13")    { return Certificate::PG_13; }
    else if(str == "G")        { return Certificate::G; }
    else if(str == "PG")       { return Certificate::PG; }
    else if(str == "R")        { return Certificate::R; }
    else if(str == "PASSED")   { return Certificate::PASSED; }
    else if(str == "APPROVED") { return Certificate::APPROVED; }
    else if(str == "N/A")      { return Certificate::N_A; }
    else if(str == "TV-14")    { return Certificate::TV_14; }
    else if(str == "M")        { return Certificate::M; }
    else if(str == "X")        { return Certificate::X; }
}

//istream& operator>>(istream& is, const Certificate& cl)
//{
//    string str;
//
//    is >> str;
//
//    if(str == "G")
//    {
//        //str = Certificate::G;
//    }
//
//    return is;
//}

ostream& operator<<(ostream& os, const Certificate& cl)
{
    switch (cl)
    {
        case Certificate::NOT_RATED :
            return os << "NOT_RATED";
        case Certificate::UNRATED :
            return os << "UNRATED";
        case Certificate::G :
            return os << "G";
        case Certificate::PG :
            return os << "PG";
        case Certificate::PG_13 :
            return os << "PG_13";
        case Certificate::R :
            return os << "R";
        case Certificate::APPROVED :
            return os << "APPROVED";
        case Certificate::PASSED :
            return os << "PASSED";
        case Certificate::N_A :
            return os << "N/A";
        case Certificate::TV_14 :
            return os << "TV-14";
        case Certificate::M :
            return os << "M";
        case Certificate::X :
            return os << "X";
        default:
            return os;
    }
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


