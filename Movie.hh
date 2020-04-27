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