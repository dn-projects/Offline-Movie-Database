/*******************************************************************************
 File        : MovieDatabase.hh

 Description : A hidden header file used to store two maps to allow for the
               conversions between strings and Certificates.

 Author      : Dovydas Novikovas

 Date        : Wednesday 6th May 2020
*******************************************************************************/
#ifndef CPP_COURSEWORK_MOVIE_HH
#define CPP_COURSEWORK_MOVIE_HH

#include <iomanip>
#include <map>
#include "Movie.hpp"

using namespace std;

/**
 * Map used to store the string to Certificate conversion with strings as keys
 * and the Certificates as values
 */
static const map<string, Certificate> certificateInputMap =
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
static const map<Certificate, string> certificateOutputMap =
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

#endif //CPP_COURSEWORK_MOVIE_HH