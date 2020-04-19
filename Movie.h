/*******************************************************************************
 File        : Movie.h

 Description :

 Author      : Dovydas Novikovas

 Date        :
*******************************************************************************/

#ifndef CPP_COURSEWORK_MOVIE_H
#define CPP_COURSEWORK_MOVIE_H

#include <string>
#include <iostream>

using namespace std;

enum class Certificate
{
    NOT_RATED ,UNRATED ,G ,PG ,PG_13 ,R, APPROVED, PASSED, N_A, TV_14, M, X
};

class Movie
{
private :

    string title;
    int    year;
    string genre;
    //set<Genre> genreSet;
    //bitfields for genre
    int    duration;
    double rating;
    Certificate c;

public :

    Movie(string title   = " *** EMPTY MOVIE *** " , int    year   = 0 ,
          Certificate cl = Certificate::NOT_RATED  , string genre  = "",
          int duration   = 0                       , double rating = 0 )
    {
        this->title    = title;
        this->year     = year;
        this->c        = cl;
        this->genre    = genre;
        this->duration = duration;
        this->rating   = rating;
    }

    inline string getTitle() const
    {
        return title;
    }

    inline int getYear() const
    {
        return year;
    }

    inline Certificate getCertificate() const
    {
        return c;
    }

    inline string getGenre() const
    {
        return genre;
    }

    inline int getDuration() const
    {
        return duration;
    }

    inline int getRating() const
    {
        return rating;
    }

    ~Movie()
    = default;

    friend bool operator==(const Movie& movie1, const Movie& movie2);

    friend bool operator!=(const Movie& movie1, const Movie& movie2);

    friend inline bool operator>(const Movie& movie1, const Movie& movie2);

    friend inline bool operator<(const Movie& movie1, const Movie& movie2);

    // overload printing out a movie (toString)


    // << overload to print string format of enum value

};

ostream& operator<<(ostream& str, const Movie& movie);

ostream& operator<<(ostream& os, const Certificate& cl);

istream& operator>>(istream& is, Movie& movie);

istream& operator>>(istream& is, Certificate& cert);

#endif //CPP_COURSEWORK_MOVIE_H
