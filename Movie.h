/*******************************************************************************
 File        : Movie.h

 Description : Movie header file contains a enum class to store certificates, a
               genre struct to set the genres a Movie object has and a Movie
               class that stores the information about a film (Title, Year,
               Certificate, Genre, Duration and Rating) Movie class acts as a
               template to allow an object to be generated for a film.
               This object can then be used in the MovieDatabase class to add
               an entry (a film object) to the database. The class allows for
               comparisons to be made between different Movie objects. The file
               also contains a union that is used as a 'test harness'.

 Author      : Dovydas Novikovas

 Date        : Wednesday 6th May 2020

 Notes       : Movie class does not implement the use of destructors because
               the primitives used as my instance variables use their own
               destructors and the enum class (Certificate) uses ints as the
               underlying data type which uses its default destructor. Movie
               class does not implement copy constructors or copy assignment
               operators because it does not seem fit to be able to copy one
               Movie into another hence 'Rule of three' is not in Movie class.

*******************************************************************************/

#ifndef CPP_COURSEWORK_MOVIE_H
#define CPP_COURSEWORK_MOVIE_H

#include <sstream>
#include <ostream>

using namespace std;

/**
    Enum class used to store specific types of Certificates attached to a film
 */
enum class Certificate
{
    NOT_RATED, UNRATED, G, PG, PG_13, R, APPROVED, PASSED, N_A, TV_14, M, X
};

/**
    Genre struct uses bitfields to help categorise the different genres
    belonging to a Movie object
 */
struct Genre
{

    Genre()
    {
        memset(this,0,sizeof(*this));
    }

    uint8_t Action : 1, Adventure : 1, Animation : 1, Biography : 1,
            Comedy : 1,     Crime : 1,     Drama : 1,    Family : 1,
           Fantasy : 1, Film_Noir : 1,   History : 1,    Horror : 1,
             Music : 1,   Musical : 1,   Mystery : 1,   Romance : 1,
            Sci_Fi : 1,  Thriller : 1,       War : 1,   Western : 1;


};

class Movie
{
private :

    string title;
    int year;
    Genre genre;
    int duration;
    double rating;
    Certificate certificate;

public :

    Movie(string title = " *** EMPTY MOVIE *** ", int year = 0,
          Certificate cl = Certificate::NOT_RATED, Genre genre = Genre(),
          int duration = 0, double rating = 0) :

        title(title),
        year(year),
        certificate(cl),
        genre(genre),
        duration(duration),
        rating(rating){};


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
    inline Genre getGenre() const
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
inline bool operator<(const Movie& movie1, const Movie& movie2)
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
    return  movie1.getTitle() == movie2.getTitle();
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
 * input stream and certificate are used to convert string to certificate as
 * well an overloaded input operator for a string and Genre to set the genres
 * that belong to a Movie object.
 *
 * @param is    - an input stream
 * @param movie - movie object to instantiate
 * @return returns the input stream
 */
istream& operator>>(istream& is, Movie &movie);

/**
 * Overloading the output operator to format a Movie object being sent passed
 * in an output stream to print out on a single line with each 'information'
 * about a film separated by a comma.
 *
 * @param os    - output stream
 * @param movie - movie object to print out
 * @return the formatted output stream
 */
ostream& operator<<(ostream& str, const Movie &movie);

/**
 * Overloading the input operator for input stream and Certificate, converts
 * string into Certificate. If string does not equal Certificate error message
 * is printed.
 *
 * @param is          - an input stream
 * @param certificate - Certificate to instate with the relevant certificate
 * @return input stream after a converted string into a Certificate
 */
istream& operator>>(istream& is, Certificate &certificate);

/**
 * Overloading the output operator to print out a certificate to a string
 *
 * @param os          - output stream
 * @param certificate - Certificate object being passed to output stream
 * @return output stream loaded with relevant Certificate from map
 */
ostream& operator<<(ostream& os, const Certificate& certificate);

/**
 * Overloading the input operator to toggle the corresponding bitfield for each
 * genre found in a string. The function uses a map that detects a specific
 * string as the key and once found invokes the matching value to perform a
 * lambda function to toggle a bitfield in Genre.
 *
 * @param is    - an input stream
 * @param genre - Genre object that has certain bitfields toggled depending on
 *                the genres belonging to a film
 * @return input stream with correct bitfields toggled in Genre
 */
istream& operator>>(istream& is, Genre& genre);

/**
 * Overloaded output operator to loop through a map that checks every toggled
 * bitfields for a Genre passed in the parameter. The map contains lambdas as
 * values and the value checks if a specific bitfield in genre is toggled and
 * if true, the matching key is added to a string which is then returned by
 * the function.
 *
 * @param os    - output stream
 * @param genre - A Genre to loop through and check the bitfields toggled
 * @return String that contains all the toggled genres, with each genre being
 *         separated by comma delimiter
 */
ostream& operator<<(ostream& os, const Genre& genre);

/**
    Union used as test harness to test Movie class functionality
 */
union RunMovieTestHarness
{
    RunMovieTestHarness()
    {
        cout << "-------------------TESTING MOVIE CLASS---------------------\n";

        cout << "DEFAULT MOVIE:\n";
        Movie movie;
        cout << movie << endl;
        cout << "-----------------------------------------------------------\n";

        cout << "TESTING INPUT AND OUTPUT OPERATOR TO GENERATE MOVIE1:\n";
        Movie movie1;
        stringstream ssi
        (R"("The Godfather: Part II",1974,"R","Crime/Drama",202,0")");
        ssi >> movie1;
        cout << movie1 << endl;
        cout << "-----------------------------------------------------------\n";

        cout << "TESTING INPUT AND OUTPUT OPERATOR TO GENERATE MOVIE2:\n";
        Movie movie2;
        stringstream ssii
        (R"("Western",1940,"NOT RATED","Drama/Film-Noir/Mystery",130,0)");
        ssii >> movie2;
        cout << movie2 << endl;
        cout << "-----------------------------------------------------------\n";

        cout << "TESTING '==' OPERATOR:\n";
        cout << "EXPECTED OUTCOME | FALSE |\n";
        cout << "ACTUAL OUTCOME | ";
        if( movie1 == movie2 )
        {
            cout << "TRUE |\n";
        }
        else
        {
            cout << "FALSE |\n";
        }
        cout << "-----------------------------------------------------------\n";

        cout << "TESTING '!=' OPERATOR:\n";
        cout << "EXPECTED OUTCOME | TRUE |\n";
        cout << "ACTUAL OUTCOME | ";
        if( movie1 != movie2 )
        {
            cout << "TRUE |\n";
        }
        else
        {
            cout << "FALSE |\n";
        }
        cout << "-----------------------------------------------------------\n";

        cout << "TESTING '>' OPERATOR:\n";
        cout << "EXPECTED OUTCOME | TRUE |\n";
        cout << "ACTUAL OUTCOME | ";
        if( movie1 > movie2 )
        {
            cout << "TRUE |\n";
        }
        else
        {
            cout << "FALSE |\n";
        }
        cout << "-----------------------------------------------------------\n";

        cout << "TESTING '<' OPERATOR:\n";
        cout << "EXPECTED OUTCOME | FALSE |\n";
        cout << "ACTUAL OUTCOME | ";
        if( movie1 < movie2 )
        {
            cout << "TRUE |\n";
        }
        else
        {
            cout << "FALSE |\n";
        }
        cout << "-----------------------------------------------------------\n";
    }
};

#endif //CPP_COURSEWORK_MOVIE_H