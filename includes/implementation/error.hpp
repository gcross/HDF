//@+leo-ver=5-thin
//@+node:gcross.20110520194631.1420: * @file error.hpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110520194631.1422: ** << License >>
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

#ifndef HDFPP_IMPLEMENTATION_ERROR_HPP
#define HDFPP_IMPLEMENTATION_ERROR_HPP

//@+<< Includes >>
//@+node:gcross.20110520194631.1421: ** << Includes >>
#include <hdf5.h>
#include <string>
#include <vector>
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110520211700.1394: ** Classes
//@+node:gcross.20110521115623.2760: *3* Exception
struct Exception : public std::exception {
    std::string message;
    Exception();
    Exception(std::string const& message);
    virtual char const* what() const throw();
    virtual ~Exception() throw();
};
//@+node:gcross.20110520211700.1395: *3* ErrorStackFrame
struct ErrorStackFrame {
    std::string source_filename;
    unsigned int source_line;
    std::string source_function;
    std::string class_name, major_message, minor_message;

    ErrorStackFrame(H5E_error2_t const& error_descriptor);

    static herr_t constructAndPush(unsigned int n, H5E_error2_t const *err_desc, std::vector<ErrorStackFrame>* stack);
    static herr_t constructAndPush(unsigned int n, H5E_error2_t const *err_desc, void* stack);
};
//@+node:gcross.20110520211700.1393: *3* Error
struct Error : public Exception {
    std::vector<ErrorStackFrame> error_stack;
    Error(std::string const& description);
    virtual ~Error() throw();

    static void disableHDFErrorReporting();
    static void enableHDFErrorReporting();

protected:

    static H5E_auto_t hdf_func;
    static void* hdf_client_data;

    static struct AutomaticDisabler {
        AutomaticDisabler();
    } automatic_disabler;
};
//@+node:gcross.20110520211700.1481: ** Functions
//@+node:gcross.20110520211700.1484: *3* assertSuccess
template<typename T> T assertSuccess(const char* description, T const result) {
    if(result >= 0)
        return result;
    else
        throw Error(description);
}
//@-others

}

#endif
//@-leo
