#ifndef CPP_COURSEWORK_MOVIEDATABASE_HH
#define CPP_COURSEWORK_MOVIEDATABASE_HH

#include <algorithm>
#include <iterator>
#include <vector>
#include "MovieDatabase.hpp"

using namespace std;

class DatabaseRetriever
{
private:

public:

    template<typename V, typename I>
    Movie static returnMovieByIndex(V vector, I index)
    {
        // if index is 0 print first movie
        index = index == 0 ? index+1 : index;
        // if index is greater than last movie index set to last movie index
        index > vector.size() ? index = vector.size() : index;

        auto it = vector.begin();

        std::advance(it, index - 1);

        return *it;
    }

    template<typename V, typename C>
    void static printMovieByCount(V vector, C count)
    {
        // if count is 0 print all movies
        count = count == 0 ? vector.size() : count;
        // if count is greater than
        count > vector.size() ? count = vector.size() : count;

        std::for_each (vector.begin(), std::next(vector.begin(), count),
                       [] (const Movie& x) { cout << x << endl; } );
    }
};








//    template <class InputIterator, class Functor>
//    std::vector<typename std::iterator_traits<InputIterator>::value_type>
//    filter( InputIterator begin, InputIterator end, Functor f )
//    {
//        using ValueType = typename std::iterator_traits<InputIterator>::value_type;
//
//        std::vector<ValueType> result;
//        result.reserve( std::distance( begin, end ) );
//
//        std::copy_if( begin, end,
//                      std::back_inserter( result ),
//                      f );
//
//        return result;
//    }









//TODO get type?
//template <typename I, typename M>
//Movie queryDatabase(I index = '*', int category = 0, M match = "")
//{
//    vector<Movie> movieDatabase;
//
//    for (const Movie& movie : movieList)
//    {
//        if (category == 0) // title
//        {
//
//        }
//        else if (category == 1) // year
//        {
//
//        }
//        else if (category == 2) // certificate
//        {
//
//        }
//        else if (category == 3) // genre
//        {
//            if (movie.getGenre().find(match) != string::npos)
//            {
//                if (index == '*')
//                {
//                    cout << movie << endl;
//                }
//                movieDatabase.push_back(movie);
//            }
//        }
//        else if (category == 4) // duration
//        {
//
//        }
//        else if (category == 5) // rating
//        {
//
//        }
//    }
//    if (index != '*') {
//        return movieDatabase[index];
//    }
//}

#endif //CPP_COURSEWORK_MOVIEDATABASE_HH
