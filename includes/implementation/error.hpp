#ifndef HDFPP_IMPLEMENTATION_ERROR_HPP
#define HDFPP_IMPLEMENTATION_ERROR_HPP

// Includes {{{
#include <hdf5.h>
#include <string>
#include <vector>
// Includes }}}

namespace HDF {

// Classes {{{
struct Exception : public std::exception { // {{{
    std::string message;
    Exception();
    Exception(std::string const& message);
    virtual char const* what() const throw();
    virtual ~Exception() throw();
}; // }}}
struct ErrorStackFrame { // {{{
    std::string source_filename;
    unsigned int source_line;
    std::string source_function;
    std::string class_name, major_message, minor_message;

    ErrorStackFrame(H5E_error2_t const& error_descriptor);

    static herr_t constructAndPush(unsigned int n, H5E_error2_t const *err_desc, std::vector<ErrorStackFrame>* stack);
    static herr_t constructAndPush(unsigned int n, H5E_error2_t const *err_desc, void* stack);
}; // }}}
struct Error : public Exception { // {{{
    std::vector<ErrorStackFrame> error_stack;
    Error(std::string const& description);
    virtual ~Error() throw();

    static void disableHDFErrorReporting();
    static void enableHDFErrorReporting();

protected:

    static H5E_auto2_t hdf_func;
    static void* hdf_client_data;

    static struct AutomaticDisabler {
        AutomaticDisabler();
    } automatic_disabler;
}; // }}}
// Classes }}}

// Functions {{{
template<typename T> T assertSuccess(const char* description, T const result) { // {{{
    if(result >= 0)
        return result;
    else
        throw Error(description);
} // }}}
// Functions }}}

}

#endif
