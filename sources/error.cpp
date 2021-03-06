// Includes {{{
#include "implementation/error.hpp"

#include <boost/foreach.hpp>
#include <boost/scoped_array.hpp>
#include <iomanip>
#include <sstream>
// Includes }}}

// Usings {{{
using boost::scoped_array;

using std::endl;
using std::ostringstream;
using std::setw;
using std::string;
using std::vector;
// Usings }}}

namespace HDF {

// Classes {{{
// Error {{{
Error::Error(string const& description) {
    H5Ewalk2(H5E_DEFAULT,H5E_WALK_UPWARD,&ErrorStackFrame::constructAndPush,&error_stack);

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

H5E_auto2_t Error::hdf_func = NULL;
void* Error::hdf_client_data = NULL;

void Error::disableHDFErrorReporting() {
    H5Eset_auto2(H5E_DEFAULT,NULL,NULL);
}

void Error::enableHDFErrorReporting() {
    H5Eset_auto2(H5E_DEFAULT,hdf_func,hdf_client_data);
}

Error::AutomaticDisabler::AutomaticDisabler() {
    H5Eget_auto2(H5E_DEFAULT,&hdf_func,&hdf_client_data);
    disableHDFErrorReporting();
}

Error::AutomaticDisabler Error::automatic_disabler;
// Error }}}
// ErrorStackFrame {{{
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
// ErrorStackFrame }}}
// Exception {{{
Exception::Exception() {}

Exception::Exception(string const& message) : message(message) { }

const char* Exception::what() const throw() { return message.c_str(); }

Exception::~Exception() throw() { }
// Exception }}}
// Classes }}}

}
