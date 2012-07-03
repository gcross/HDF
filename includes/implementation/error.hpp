//@+leo-ver=5-thin
//@+node:gcross.20110520194631.1420: * @file error.hpp
//@@language cplusplus
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

    static H5E_auto2_t hdf_func;
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
