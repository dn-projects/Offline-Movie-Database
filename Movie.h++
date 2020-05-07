/*******************************************************************************
 File        : Movie.h

 Description : A class that stores the information about a film (Title, Year,
               Certificate, Genre, Duration and Rating) The class acts as a
               template to allow an object to be generated for a film.
               This object can then be used in the MovieDatabase class to add
               an entry (a film object) to the database.

 Author      : Dovydas Novikovas

 Date        : Wednesday 6th May 2020
*******************************************************************************/

#ifndef CPP_COURSEWORK_MOVIE_H
#define CPP_COURSEWORK_MOVIE_H

#include <string>
#include <iostream>

using namespace std;

enum class Certificate
{
    NOT_RATED, UNRATED, G, PG, PG_13, R, APPROVED, PASSED, N_A, TV_14, M, X
};

class Movie {
private :

    string title;
    int year;
    string genre;
    //set<Genre> genreSet;
    //bitfields for genre
    int duration;
    double rating;
    Certificate c;

public :

    Movie(string title = " *** EMPTY MOVIE *** ", int year = 0,
          Certificate cl = Certificate::NOT_RATED, string genre = "",
          int duration = 0, double rating = 0)
    {
        this->title = title;
        this->year = year;
        this->c = cl;
        this->genre = genre;
        this->duration = duration;
        this->rating = rating;
    }

    Movie(const Movie &movie2)
    {
        title    = movie2.title;
        year     = movie2.year;
        c        = movie2.c;
        genre    = movie2.genre;
        duration = movie2.duration;
        rating   = movie2.rating;
    }

    inline string getTitle() const {
        return title;
    }

    inline int getYear() const {
        return year;
    }

    inline Certificate getCertificate() const {
        return c;
    }

    inline string getGenre() const {
        return genre;
    }

    inline int getDuration() const {
        return duration;
    }

    inline int getRating() const {
        return rating;
    }

    friend inline bool operator<(const Movie &movie1, const Movie &movie2);

    friend inline bool operator>(const Movie &movie1, const Movie &movie2);

    friend inline bool operator==(const Movie &movie1, const Movie &movie2);

    friend inline bool operator!=(const Movie &movie1, const Movie &movie2);

    ~Movie()
    = default;

};

//TODO in what order should default list be sorted in

inline bool operator<(const Movie &movie1, const Movie &movie2)
{
    return movie1.getYear() < movie2.getYear();
}

bool operator>(const Movie& movie1, const Movie& movie2)
{
    return movie1.getTitle() > movie2.getTitle();
}

bool inline operator==(const Movie& movie1, const Movie& movie2)
{
    return (movie1.getTitle() == movie2.getTitle());
}

bool inline operator!=(const Movie& movie1, const Movie& movie2)
{
    return !(movie1 == movie2);
}

ostream &operator<<(ostream &str, const Movie &movie);

ostream &operator<<(ostream &os, Certificate certificate);

istream &operator>>(istream &is, Movie &movie);

istream &operator>>(istream &is, Certificate &certificate);

#endif //CPP_COURSEWORK_MOVIE_H