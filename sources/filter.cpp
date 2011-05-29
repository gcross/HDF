//@+leo-ver=5-thin
//@+node:gcross.20110527192131.2347: * @file filter.cpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110527192131.2348: ** << License >>
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
//@+node:gcross.20110527192131.2349: ** << Includes >>
#include "filter.hpp"

#include <boost/format.hpp>
#include <stdexcept>
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110527192131.2350: ** << Usings >>
using boost::format;
using boost::function;
using boost::none;
using boost::optional;

using std::auto_ptr;
using std::invalid_argument;
using std::make_pair;
using std::map;
using std::vector;
//@-<< Usings >>

//@+others
//@+node:gcross.20110527192131.2375: ** Exceptions
//@+node:gcross.20110527192131.2376: *3* WrongNumberOfParametersForFilterException
WrongNumberOfParametersForFilterException::WrongNumberOfParametersForFilterException(
    char const* filter_name
  , unsigned int expected_number_of_parameters
  , unsigned int actual_number_of_parameters
)
  : Exception(
        (format("Filter '%1%' expected %2% parameters but encountered %3% parameters.")
            % filter_name
            % expected_number_of_parameters
            % actual_number_of_parameters
        ).str()
    )
  , filter_name(filter_name)
  , expected_number_of_parameters(expected_number_of_parameters)
  , actual_number_of_parameters(actual_number_of_parameters)
{}

WrongNumberOfParametersForFilterException::~WrongNumberOfParametersForFilterException() throw() {}
//@+node:gcross.20110528133907.2029: ** Classes
//@+node:gcross.20110527192131.2355: *3* Filter
//@+node:gcross.20110527192131.2356: *4* Constructors / Destructors
Filter::Filter(
    unsigned int number_of_parameters
  , bool optional_flag
)
  : parameters(number_of_parameters)
  , optional_flag(optional_flag)
{}

Filter::Filter(
    vector<unsigned int> const& parameters
  , bool optional_flag
)
  : parameters(parameters)
  , optional_flag(optional_flag)
{}

Filter::~Filter() {}
//@+node:gcross.20110527192131.2357: *4* Fields
size_t Filter::getNumberOfParameters() const { return parameters.size(); }

vector<unsigned int> const& Filter::getParameters() const {
    return parameters;
}

unsigned int const* Filter::getParameterData() const {
    return &parameters.front();
}

unsigned int& Filter::operator[](unsigned int index) {
    return parameters[index];
}

unsigned int const& Filter::operator[](unsigned int index) const {
    return parameters[index];
}

bool Filter::getOptionalFlag() const {
    return optional_flag;
}

void Filter::setOptionalFlag(bool optional_flag) {
    this->optional_flag = optional_flag;
}

unsigned int Filter::getFlags() const {
    return optional_flag ? H5Z_FLAG_OPTIONAL : H5Z_FLAG_MANDATORY;
}
//@+node:gcross.20110527192131.2371: *4* Miscellaneous
void Filter::assertNumberOfParametersIs(unsigned int expected_number_of_parameters) {
    if(expected_number_of_parameters != getNumberOfParameters())
        throw 
            WrongNumberOfParametersForFilterException(
                typeid(this).name(),
                expected_number_of_parameters,
                getNumberOfParameters()
            );
}

bool Filter::checkAvailabilityOf(H5Z_filter_t filter_id) {
    return assertSuccess(
        "checking filter availability",
        H5Zfilter_avail(filter_id)
    ) == 1;
}
//@+node:gcross.20110527192131.2358: *4* Registry
map<H5Z_filter_t,Filter::Factory> Filter::registry;

void Filter::registerFactory(H5Z_filter_t filter_id, Factory const& factory) {
    registry.insert(make_pair(filter_id,factory));
}

optional<Filter::Factory const&> Filter::lookupFactory(H5Z_filter_t filter_id) {
    map<H5Z_filter_t,Filter::Factory>::iterator iter = registry.find(filter_id);
    if(iter == registry.end())
        return none;
    else
        return iter->second;
}

auto_ptr<Filter> Filter::construct(
    H5Z_filter_t filter_id
  , vector<unsigned int> const& parameters
  , bool optional_flag
) {
    optional<Filter::Factory const&> optional_factory = lookupFactory(filter_id);
    if(optional_factory)
        return (*optional_factory)(parameters,optional_flag);
    else
        return auto_ptr<Filter>(new UnknownFilter(filter_id,parameters,optional_flag));
}
//@+node:gcross.20110528133907.2031: *3* UnknownFilter
UnknownFilter::UnknownFilter(
    H5Z_filter_t filter_id
  , std::vector<unsigned int> const& parameters
  , bool optional_flag
)
  : Filter(parameters,optional_flag)
  , filter_id(filter_id)
{}

H5Z_filter_t UnknownFilter::getFilterId() const { return filter_id; }
//@+node:gcross.20110527192131.2364: ** Filters
//@+node:gcross.20110527192131.2386: *3* DeflateCompressionFilter
DeflateCompressionFilter::DeflateCompressionFilter(
    unsigned int compression_level
  , bool optional_flag
)
  : Filter(1,optional_flag)
{ setCompressionLevel(compression_level); }

DeflateCompressionFilter::DeflateCompressionFilter(
    vector<unsigned int> const& parameters
  , bool optional_flag
)
  : Filter(parameters,optional_flag)
{ assertNumberOfParametersIs(1); }

unsigned int DeflateCompressionFilter::getCompressionLevel() const {
    return (*this)[0];
}

void DeflateCompressionFilter::setCompressionLevel(unsigned int compression_level) {
    if(compression_level > 9) throw invalid_argument((format("level = %1%, which is not between 0 and 9 inclusive") % compression_level).str());
    (*this)[0] = compression_level;
}

FILTER_DEFINITION_BOILERPLATE(DeflateCompressionFilter,H5Z_FILTER_DEFLATE);
//@+node:gcross.20110527192131.2365: *3* Fletcher32ChecksumFilter
Fletcher32ChecksumFilter::Fletcher32ChecksumFilter()
  : Filter(0,false)
{}

Fletcher32ChecksumFilter::Fletcher32ChecksumFilter(
    vector<unsigned int> const& parameters
  , bool optional_flag
)
  : Filter(parameters,optional_flag)
{ assertNumberOfParametersIs(0); }

FILTER_DEFINITION_BOILERPLATE(Fletcher32ChecksumFilter,H5Z_FILTER_FLETCHER32);
//@+node:gcross.20110528133907.2043: *3* NBitCompressionFilter
NBitCompressionFilter::NBitCompressionFilter()
  : Filter(0,true)
{}

NBitCompressionFilter::NBitCompressionFilter(
    vector<unsigned int> const& parameters
  , bool optional_flag
)
  : Filter(parameters,optional_flag)
{ assertNumberOfParametersIs(0); }

FILTER_DEFINITION_BOILERPLATE(NBitCompressionFilter,H5Z_FILTER_NBIT);
//@+node:gcross.20110528133907.2022: *3* ScaleOffsetCompressionFilter
ScaleOffsetCompressionFilter::ScaleOffsetCompressionFilter(
    ScaleMethod scale_method
  , unsigned int scale_factor
  , bool optional_flag
)
  : Filter(2,optional_flag)
{
    setScaleMethod(scale_method);
    setScaleFactor(scale_factor);
}

ScaleOffsetCompressionFilter::ScaleOffsetCompressionFilter(
    vector<unsigned int> const& parameters
  , bool optional_flag
)
  : Filter(parameters,optional_flag)
{ assertNumberOfParametersIs(2); }

ScaleMethod ScaleOffsetCompressionFilter::getScaleMethod() const {
    return static_cast<ScaleMethod>((*this)[0]);
}

void ScaleOffsetCompressionFilter::setScaleMethod(ScaleMethod scale_method) {
    (*this)[0] = static_cast<unsigned int>(scale_method);
}

unsigned int ScaleOffsetCompressionFilter::getScaleFactor() const {
    return (*this)[1];
}

void ScaleOffsetCompressionFilter::setScaleFactor(unsigned int scale_factor) {
    (*this)[1] = scale_factor;
}

FILTER_DEFINITION_BOILERPLATE(ScaleOffsetCompressionFilter,H5Z_FILTER_SCALEOFFSET);
//@+node:gcross.20110527192131.2382: *3* ShuffleFilter
ShuffleFilter::ShuffleFilter()
  : Filter(0,false)
{}

ShuffleFilter::ShuffleFilter(
    vector<unsigned int> const& parameters
  , bool optional_flag
)
  : Filter(parameters,optional_flag)
{ assertNumberOfParametersIs(0); }

FILTER_DEFINITION_BOILERPLATE(ShuffleFilter,H5Z_FILTER_SHUFFLE);
//@+node:gcross.20110527192131.2394: *3* SZIPCompressionFilter
SZIPCompressionFilter::SZIPCompressionFilter(
    SZIPCodingMethod coding_method
  , unsigned int pixels_per_block
  , bool optional_flag
)
  : Filter(2,optional_flag)
{
    setCodingMethod(coding_method);
    setPixelsPerBlock(pixels_per_block);
}

SZIPCompressionFilter::SZIPCompressionFilter(
    vector<unsigned int> const& parameters
  , bool optional_flag
)
  : Filter(parameters,optional_flag)
{ assertNumberOfParametersIs(2); }

SZIPCodingMethod SZIPCompressionFilter::getCodingMethod() const {
    return static_cast<SZIPCodingMethod>((*this)[0]);
}

void SZIPCompressionFilter::setCodingMethod(SZIPCodingMethod coding_method) {
    (*this)[0] = static_cast<unsigned int>(coding_method);
}

unsigned int SZIPCompressionFilter::getPixelsPerBlock() const {
    return (*this)[1];
}

void SZIPCompressionFilter::setPixelsPerBlock(unsigned int pixels_per_block) {
    (*this)[1] = pixels_per_block;
}

FILTER_DEFINITION_BOILERPLATE(SZIPCompressionFilter,H5Z_FILTER_SZIP);
//@-others

}
//@-leo
