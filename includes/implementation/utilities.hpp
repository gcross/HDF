//@+leo-ver=5-thin
//@+node:gcross.20110521115623.4256: * @file utilities.hpp
//@@language cplusplus
#ifndef HDFPP_IMPLEMENTATION_UTILITIES_HPP
#define HDFPP_IMPLEMENTATION_UTILITIES_HPP

//@+<< Includes >>
//@+node:gcross.20110521115623.4257: ** << Includes >>
#include <boost/range/algorithm/copy.hpp>
#include <boost/scoped_array.hpp>
#include <boost/tokenizer.hpp>
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110521115623.4260: ** Classes
//@+node:gcross.20110521115623.4259: *3* HSizeArray
template<typename T> struct TemporaryArray {
    unsigned int size;
    boost::scoped_array<T> data;

    template<typename Range> TemporaryArray(Range range)
      : size(range.size())
      , data(new T[size])
    { boost::copy(range,data.get()); }

    operator T const*() { return data.get(); }
};

typedef TemporaryArray<hsize_t> HSizeArray;
//@+node:gcross.20110524225139.1860: *3* LocationSlashTokenizer
struct SlashTokenizer : public boost::tokenizer<boost::char_separator<char> > {

    SlashTokenizer(std::string const& location) : boost::tokenizer<boost::char_separator<char> >(location,boost::char_separator<char>("/")) {}

};
//@+node:gcross.20110524225139.1852: ** Functions
//@+node:gcross.20110524225139.1853: *3* isSlash/Dot
inline bool isSlash(char c) { return c == '/'; }
inline bool isDot(char c) { return c == '.'; }
inline bool isSlashOrDot(char c) { return isSlash(c) || isDot(c); }
//@+node:gcross.20110523113700.2387: ** Macros
#define GET_OPTIONAL_OR(optional,alternative) (optional ? (*optional) : alternative)
//@-others

}

#endif
//@-leo
