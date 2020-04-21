/*******************************************************************************
 File        : MovieDatabase.hh

 Description :

 Author      : Dovydas Novikovas

 Date        :
*******************************************************************************/
#ifndef CPP_COURSEWORK_MOVIE_HH
#define CPP_COURSEWORK_MOVIE_HH

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <map>
#include "Movie.h"

using namespace std;

static const map<string, Certificate> certificateInputMap =
{
    {"PG",        Certificate::PG},
    {"PG-13",     Certificate::PG_13},
    {"APPROVED",  Certificate::APPROVED},
    {"R",         Certificate::R},
    {"NOT RATED", Certificate::NOT_RATED},
    {"G",         Certificate::G},
    {"UNRATED",   Certificate::UNRATED},
    {"PASSED",    Certificate::PASSED},
    {"TV-14",     Certificate::TV_14},
    {"M",         Certificate::M},
    {"X",         Certificate::X},
    {"N/A",       Certificate::N_A}
};

static const map<Certificate, string> certificateOutputMap =
{
    {Certificate::PG,        "PG"},
    {Certificate::PG_13,     "PG-13"},
    {Certificate::APPROVED,  "APPROVED"},
    {Certificate::R,         "R"},
    {Certificate::NOT_RATED, "NOT RATED"},
    {Certificate::G,         "G"},
    {Certificate::UNRATED,   "UNRATED"},
    {Certificate::PASSED,    "PASSED"},
    {Certificate::TV_14,     "TV-14"},
    {Certificate::M,         "M"},
    {Certificate::X,         "X"},
    {Certificate::N_A,       "N/A"}
};

#endif //CPP_COURSEWORK_MOVIE_HH