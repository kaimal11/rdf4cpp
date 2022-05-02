
/**
 * @file Registers xsd:gYear with DatatypeRegistry
 */

#ifndef RDF4CPP_XSD_GYEAR_HPP
#define RDF4CPP_XSD_GYEAR_HPP

#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>
#include <regex>
#include <sstream>
#include <vector>

namespace rdf4cpp::rdf::datatypes::xsd {
using GYear = time_t;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#gYear">xsd:gYear</a>
}

namespace rdf4cpp::rdf::datatypes {
constexpr const char xsd_gYear[] = "http://www.w3.org/2001/XMLSchema#gYear";

template<>
inline std::string RegisteredDatatype<xsd::GYear, xsd_gYear>::datatype_iri() noexcept { return "http://www.w3.org/2001/XMLSchema#gYear"; }

template<>
inline xsd::GYear RegisteredDatatype<xsd::GYear, xsd_gYear>::from_string(std::string_view s) {
    const std::regex gYear_regex("-?([1-9][0-9]{3,}|0[0-9]{3})(Z|(\\+|-)((0[0-9]|1[0-3]):[0-5][0-9]|14:00))?");

    if (std::regex_match(s.data(), gYear_regex)) {

        struct tm tm{};
        strptime(s.data(), "-%Y", &tm);

        //default values
        tm.tm_sec = 0; // seconds of minutes from 0 to 61
        tm.tm_min = 0; // minutes of hour from 0 to 59
        tm.tm_hour = 0; // hours of day from 0 to 24
        tm.tm_mon = 0; // month of year from 0 to 11
        tm.tm_mday = 1; // date of the month
        tm.tm_isdst = -1; // value should be set even if not used

        return mktime(&tm);
    } else {
        throw std::runtime_error("XSD Parsing Error");
    }
}

template<>
inline std::string RegisteredDatatype<xsd::GYear, xsd_gYear>::to_string(const xsd::GYear &value) {

    char str[32];
    std::strftime(str, 32,"-%Y", std::localtime(&value));

    return std::string{str};
}
}  // namespace rdf4cpp::rdf::datatypes

#endif  //RDF4CPP_XSD_GYEAR_HPP
