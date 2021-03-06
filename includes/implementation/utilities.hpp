#ifndef HDFPP_IMPLEMENTATION_UTILITIES_HPP
#define HDFPP_IMPLEMENTATION_UTILITIES_HPP

// Includes {{{
#include <boost/range/algorithm/copy.hpp>
#include <boost/scoped_array.hpp>
#include <boost/tokenizer.hpp>
// Includes }}}

namespace HDF {

// Classes {{{
template<typename T> struct TemporaryArray { // {{{
    unsigned int size;
    boost::scoped_array<T> data;

    template<typename Range> TemporaryArray(Range range)
      : size(range.size())
      , data(new T[size])
    { boost::copy(range,data.get()); }

    operator T const*() { return data.get(); }
}; // }}}

typedef TemporaryArray<hsize_t> HSizeArray;

struct SlashTokenizer : public boost::tokenizer<boost::char_separator<char> > { // {{{

    SlashTokenizer(std::string const& location) : boost::tokenizer<boost::char_separator<char> >(location,boost::char_separator<char>("/")) {}

}; // }}}
// Classes }}}

// Functions {{{
inline bool isSlash(char c) { return c == '/'; }
inline bool isDot(char c) { return c == '.'; }
inline bool isSlashOrDot(char c) { return isSlash(c) || isDot(c); }
// Functions }}}

// Macros {{{
#define GET_OPTIONAL_OR(optional,alternative) (optional ? (*optional) : alternative)
// Macros }}}

}

#endif
