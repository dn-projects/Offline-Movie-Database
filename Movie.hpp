/*******************************************************************************
 File        : Movie.hpp

 Description : A class that stores the information about a film (Title, Year,
               Certificate, Genre, Duration and Rating) The class acts as a
               template to allow an object to be generated for a film.
               This object can then be used in the MovieDatabase class to add
               an entry (a film object) to the database. The class allows for
               comparisons to be made between different Movie objects.

 Author      : Dovydas Novikovas

 Date        : Wednesday 6th May 2020
*******************************************************************************/

#ifndef CPP_COURSEWORK_MOVIE_HPP
#define CPP_COURSEWORK_MOVIE_HPP

using namespace std;

/**
 * Enum class used to store specific types of Certificates attached to a film
 */
enum class Certificate
{
    NOT_RATED, UNRATED, G, PG, PG_13, R, APPROVED, PASSED, N_A, TV_14, M, X
};

class Movie
{
private :

    string title;
    int year;
    string genre;
    //TODO set<Genre> genreSet;?   //bitfields for genre?
    int duration;
    double rating;
    Certificate certificate;

public :

    Movie(string title = " *** EMPTY MOVIE *** ", int year = 0,
          Certificate cl = Certificate::NOT_RATED, string genre = "",
          int duration = 0, double rating = 0)
    {
        this->title = title;
        this->year = year;
        this->certificate = cl;
        this->genre = genre;
        this->duration = duration;
        this->rating = rating;
    }

    /**
     * an inline method to return the title of a 'movie'
     *
     * @return string representation of the movie title
     */
    inline string getTitle() const
    {
        return title;
    }

    /**
     * an inline method to return the year a 'movie' was made in
     *
     * @return int representing the year a movie was made in
     */
    inline int getYear() const
    {
        return year;
    }

    /**
     * an inline method to return the certificate of a 'movie'
     *
     * @return certificate belonging to a movie
     */
    inline Certificate getCertificate() const
    {
        return certificate;
    }

    /**
     * an inline method to return the genre of a 'movie'
     *
     * @return string representation of a movie genre
     */
    inline string getGenre() const
    {
        return genre;
    }

    /**
     * an inline method to return the duration of a 'movie'
     *
     * @return int representing the duration of a movie
     */
    inline int getDuration() const
    {
        return duration;
    }

    /**
     * an inline method to return the rating of a 'movie'
     *
     * @return int representing the rating of a movie
     */
    inline int getRating() const
    {
        return rating;
    }

    //TODO check how to implement garbage collection
    ~Movie()
    = default;

};

/**
 * Overloading the greater than relational operator to compare movie years when
 * comparing two movies objects with the greater than operator
 *
 * @param movie1 - Movie object to make comparison on
 * @param movie2 - Movie object to make comparison on
 * @return true if the int representation of the year of movie2 is greater than
 * the year of movie1; false otherwise
 */
inline bool operator<(const Movie &movie1, const Movie &movie2)
{
    return movie1.getYear() < movie2.getYear();
}

/**
 * Overloading the less than relational operator to compare movie years when
 * comparing two movies objects with the less than operator
 *
 * @param movie1 - Movie object to make comparison on
 * @param movie2 - Movie object to make comparison on
 * @return true if the int representation of the year of movie1 is less than
 * the year of movie2; false otherwise
 */
inline bool operator>(const Movie& movie1, const Movie& movie2)
{
    return movie1.getYear() > movie2.getYear();
}

/**
 * Overloading the equals relational operator to compare two movie titles when
 * comparing two movie objects with the equals operator
 *
 * @param movie1 - Movie object to make comparison on
 * @param movie2 - Movie object to make comparison on
 * @return true if both movie object titles are identical; false otherwise
 */
inline bool operator==(const Movie& movie1, const Movie& movie2)
{
    return (movie1.getTitle() == movie2.getTitle());
}

/**
 * Overloading the not equals relational operator to make a call to the
 * overloaded equals operator checking if return is not true
 *
 * @param movie1 - Movie object to make comparison on
 * @param movie2 - Movie object to make comparison on
 * @return true if both movie object titles are not identical; false otherwise
 */
inline bool operator!=(const Movie& movie1, const Movie& movie2)
{
    return !(movie1 == movie2);
}

/**
 * Overloading the input operator to read a string in a specific format. If the
 * string passed into the input stream does not match the format required then
 * the input operation failed flag is set. An overloaded input operator for
 * input stream and certificate are used to convert string to certificate.
 *
 * @param is    - an input stream
 * @param movie - movie object to instantiate
 * @return returns the input stream
 */
istream &operator>>(istream &is, Movie &movie);

/**
 * Overloading the output operator to format a Movie object being sent passed
 * in an output stream to print out on a single line with each 'information'
 * about a film separated by a comma.
 *
 * @param os    - output stream
 * @param movie - movie object to print out
 * @return the formatted output stream
 */
ostream &operator<<(ostream &str, const Movie &movie);

/**
 * Overloading the input operator for input stream and Certificate, converts
 * string into Certificate. If string does not equal Certificate error message
 * is printed. (uses maps in @Movie.hh)
 *
 * @param is          - an input stream
 * @param certificate - Certificate to instate with the relevant certificate
 * @return input stream after a converted string into a Certificate
 */
istream &operator>>(istream &is, Certificate &certificate);

/**
 * Overloading the output operator to print out a certificate to a string
 *
 * @param os          - output stream
 * @param certificate - Certificate object being passed to output stream
 * @return output stream loaded with relevant Certificate from map
 */
ostream &operator<<(ostream &os, Certificate certificate);

#endif //CPP_COURSEWORK_MOVIE_HPP