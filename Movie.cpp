/*******************************************************************************
 File        : Movie.cpp

 Include     : Movie.hpp

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


using namespace std;

// Map used to store the string to Certificate conversion
// with strings as keys and the Certificates as values
static const map<string, Certificate> stringToCertificateMap =
{
        {"NOT RATED", Certificate::NOT_RATED},
        {"UNRATED",   Certificate::UNRATED},
        {"G",         Certificate::G},
        {"PG",        Certificate::PG},
        {"PG-13",     Certificate::PG_13},
        {"R",         Certificate::R},
        {"APPROVED",  Certificate::APPROVED},
        {"PASSED",    Certificate::PASSED},
        {"N/A",       Certificate::N_A},
        {"TV-14",     Certificate::TV_14},
        {"M",         Certificate::M},
        {"X",         Certificate::X},
};

// Map used to store the Certificate to string conversion
// with Certificates as keys and the strings as values
static const map<Certificate, string> certificateToStringMap =
{
        {Certificate::NOT_RATED, "NOT RATED"},
        {Certificate::UNRATED,   "UNRATED"},
        {Certificate::G,         "G"},
        {Certificate::PG,        "PG"},
        {Certificate::PG_13,     "PG-13"},
        {Certificate::R,         "R"},
        {Certificate::APPROVED,  "APPROVED"},
        {Certificate::PASSED,    "PASSED"},
        {Certificate::N_A,       "N/A"},
        {Certificate::TV_14,     "TV-14"},
        {Certificate::M,         "M"},
        {Certificate::X,         "X"},
};

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
            cerr << "Invalid Movie format" << endl;
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
istream& operator>>(istream& is, Certificate& certificate)
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
ostream& operator<<(ostream& os, const Certificate& certificate)
{
    return os << certificateToStringMap.at(certificate);
}

/**
 * Function body for overloaded input operator for input stream, Genre
 */
istream& operator>>(istream& is, Genre& genre)
{
    const map<string, function<void()> > stringToGenreMap =
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
    }
    return is;
}

/**
 * Function body for overloaded output operator for output stream, Genre
 */
ostream& operator<<(ostream& os, const Genre& genre)
{
    string returnString;

    const map< string, function<bool()> > genreToStringMap =
    {
        { "Action/",   [&] () -> bool { return genre.Action == 1; } },
        {"Adventure/", [&] () -> bool { return genre.Adventure == 1; } },
        {"Animation/", [&] () -> bool { return genre.Animation == 1; } },
        {"Biography/", [&] () -> bool { return genre.Biography == 1; } },
        {"Comedy/",    [&] () -> bool { return genre.Comedy == 1; } },
        {"Crime/",     [&] () -> bool { return genre.Crime == 1; } },
        {"Drama/",     [&] () -> bool { return genre.Drama == 1; } },
        {"Family/",    [&] () -> bool { return genre.Family == 1; } },
        {"Fantasy/",   [&] () -> bool { return genre.Fantasy == 1; } },
        {"Film-Noir/", [&] () -> bool { return genre.Film_Noir == 1; } },
        {"History/",   [&] () -> bool { return genre.History == 1; } },
        {"Horror/",    [&] () -> bool { return genre.Horror == 1; } },
        {"Music/",     [&] () -> bool { return genre.Music == 1; } },
        {"Musical/",   [&] () -> bool { return genre.Musical == 1; } },
        {"Mystery/",   [&] () -> bool { return genre.Mystery == 1; } },
        {"Romance/",   [&] () -> bool { return genre.Romance == 1; } },
        {"Sci-Fi/",    [&] () -> bool { return genre.Sci_Fi == 1; } },
        {"Thriller/",  [&] () -> bool { return genre.Thriller == 1; } },
        {"War/",       [&] () -> bool { return genre.War == 1; } },
        {"Western/",   [&] () -> bool { return genre.Western == 1; } },
    };

    for (auto const& [key, value] : genreToStringMap)
    {
        if(value())
        {
            returnString += key;
        }
    }
    // removes forward slash at the end of the string to format
    returnString.pop_back();

    return os << returnString;
}
