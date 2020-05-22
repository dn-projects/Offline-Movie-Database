/*******************************************************************************
 File        : MovieDatabase.hh

 Description : A hidden header file used to store two maps to allow for the
               conversions between strings and Certificates.

 Author      : Dovydas Novikovas

 Date        : Wednesday 6th May 2020
*******************************************************************************/

#ifndef CPP_COURSEWORK_MOVIE_HH
#define CPP_COURSEWORK_MOVIE_HH

#include <functional>

using namespace std;

/**
 * Map used to store the string to Certificate conversion with strings as keys
 * and the Certificates as values
 */
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

/**
 * Map used to store the Certificate to string conversion with Certificates as
 * keys and the strings as values
 */
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

ostream& operator<<(ostream& os, const Genre& genre)
{
    string returnString;

    if(genre.Adventure == 1)
    {
        returnString += "Action/";
    }
    if(genre.Animation == 1)
    {
        returnString += "Animation/";
    }
    if(genre.Biography == 1)
    {
        returnString += "Biography/";
    }
    if(genre.Comedy == 1)
    {
        returnString += "Comedy/";
    }
    if(genre.Crime == 1)
    {
        returnString += "Crime/";
    }
    if(genre.Drama == 1)
    {
        returnString += "Drama/";
    }
    if(genre.Family == 1)
    {
        returnString += "Family/";
    }
    if(genre.Fantasy == 1)
    {
        returnString += "Fantasy/";
    }
    if(genre.Film_Noir == 1)
    {
        returnString += "Film-Noir/";
    }
    if(genre.History == 1)
    {
        returnString += "History/";
    }
    if(genre.Horror == 1)
    {
        returnString += "Horror/";
    }
    if(genre.Music == 1)
    {
        returnString += "Music/";
    }
    if(genre.Musical == 1)
    {
        returnString += "Musical/";
    }
    if(genre.Mystery == 1)
    {
        returnString += "Mystery/";
    }
    if(genre.Romance == 1)
    {
        returnString += "Romance/";
    }
    if(genre.Sci_Fi == 1)
    {
        returnString += "Sci-Fi/";
    }
    if(genre.Thriller == 1)
    {
        returnString += "Thriller/";
    }
    if(genre.War == 1)
    {
        returnString += "War/";
    }
    if(genre.Western == 1)
    {
        returnString += "Western/";
    }

    returnString.pop_back();

    return os << returnString;
}

#endif //CPP_COURSEWORK_MOVIE_HH