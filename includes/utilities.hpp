//@+leo-ver=5-thin
//@+node:gcross.20110521115623.4256: * @file utilities.hpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110521115623.4258: ** << License >>
//@+at
// Copyright (c) 2011, Gregory Crosswhite
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
// 
//     * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//@@c
//@-<< License >>

#ifndef HDFPP_UTILITIES_HPP
#define HDFPP_UTILITIES_HPP

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
