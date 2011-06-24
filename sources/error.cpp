//@+leo-ver=5-thin
//@+node:gcross.20110520211700.1400: * @file error.cpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110520211700.1401: ** << License >>
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

//@+<< Includes >>
//@+node:gcross.20110520211700.1402: ** << Includes >>
#include "implementation/error.hpp"

#include <boost/foreach.hpp>
#include <boost/scoped_array.hpp>
#include <iomanip>
#include <sstream>
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110520211700.1403: ** << Usings >>
using boost::scoped_array;

using std::endl;
using std::ostringstream;
using std::setw;
using std::string;
using std::vector;
//@-<< Usings >>

//@+others
//@+node:gcross.20110520211700.1407: ** Classes
//@+node:gcross.20110520211700.1409: *3* Error
Error::Error(string const& description) {
    H5Ewalk(H5E_DEFAULT,H5E_WALK_UPWARD,&ErrorStackFrame::constructAndPush,&error_stack);

    ostringstream buffer;
    buffer << "Error occurred while " << description << ":\n";

    unsigned int n = 0;
    BOOST_FOREACH(ErrorStackFrame const& frame, error_stack) {
        buffer << "    " << setw(3) << (++n) << ": " << frame.source_filename << " line " << frame.source_line << " in " << frame.source_function << "()" << endl;
        buffer << "    " << " - class:  " << frame.class_name << endl;
        buffer << "    " << " - major: " << frame.major_message << endl;
        buffer << "    " << " - minor: " << frame.minor_message << endl;
    }

    message = buffer.str();
}

Error::~Error() throw() {}

H5E_auto_t Error::hdf_func = NULL;
void* Error::hdf_client_data = NULL;

void Error::disableHDFErrorReporting() {
    H5Eset_auto(H5E_DEFAULT,NULL,NULL);
}

void Error::enableHDFErrorReporting() {
    H5Eset_auto(H5E_DEFAULT,hdf_func,hdf_client_data);
}

Error::AutomaticDisabler::AutomaticDisabler() {
    H5Eget_auto(H5E_DEFAULT,&hdf_func,&hdf_client_data);
    disableHDFErrorReporting();
}

Error::AutomaticDisabler Error::automatic_disabler;
//@+node:gcross.20110520211700.1408: *3* ErrorStackFrame
ErrorStackFrame::ErrorStackFrame(H5E_error2_t const& error_descriptor)
  : source_filename(error_descriptor.file_name)
  , source_line(error_descriptor.line)
  , source_function(error_descriptor.func_name)
{
    {
        size_t size = H5Eget_class_name(error_descriptor.cls_id,NULL,0);
        scoped_array<char> data(new char[size+1]);
        H5Eget_class_name(error_descriptor.cls_id,data.get(),size+1);
        class_name = data.get();
    }
    {
        size_t size = H5Eget_msg(error_descriptor.maj_num,NULL,NULL,0);
        scoped_array<char> data(new char[size+1]);
        H5Eget_msg(error_descriptor.maj_num,NULL,data.get(),size+1);
        major_message = data.get();
    }
    {
        size_t size = H5Eget_msg(error_descriptor.min_num,NULL,NULL,0);
        scoped_array<char> data(new char[size+1]);
        H5Eget_msg(error_descriptor.min_num,NULL,data.get(),size+1);
        minor_message = data.get();
    }
}

herr_t ErrorStackFrame::constructAndPush(unsigned int n, H5E_error2_t const *err_desc, vector<ErrorStackFrame>* stack) {
    stack->push_back(ErrorStackFrame(*err_desc));
    return 0;
}

herr_t ErrorStackFrame::constructAndPush(unsigned int n, H5E_error2_t const *err_desc, void* stack) {
    return constructAndPush(n,err_desc,static_cast<vector<ErrorStackFrame>*>(stack));
}
//@+node:gcross.20110521115623.2762: *3* Exception
Exception::Exception() {}

Exception::Exception(string const& message) : message(message) { }

const char* Exception::what() const throw() { return message.c_str(); }

Exception::~Exception() throw() { }
//@-others

}
//@-leo
