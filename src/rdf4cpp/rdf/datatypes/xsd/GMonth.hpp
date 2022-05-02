
/**
 * @file Registers xsd:gMonth with DatatypeRegistry
 */

#ifndef RDF4CPP_XSD_GMONTH_HPP
#define RDF4CPP_XSD_GMONTH_HPP

#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>
#include <regex>
#include <sstream>
#include <vector>

namespace rdf4cpp::rdf::datatypes::xsd {
using GMonth = time_t;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#gMonth">xsd:gMonth</a>
}

namespace rdf4cpp::rdf::datatypes {
constexpr const char xsd_gMonth[] = "http://www.w3.org/2001/XMLSchema#gMonth";

template<>
inline std::string RegisteredDatatype<xsd::GMonth, xsd_gMonth>::datatype_iri() noexcept { return "http://www.w3.org/2001/XMLSchema#gMonth"; }

template<>
inline xsd::GMonth RegisteredDatatype<xsd::GMonth, xsd_gMonth>::from_string(std::string_view s) {
    const std::regex gMonth_regex("--(0[1-9]|1[0-2])(Z|(\\+|-)((0[0-9]|1[0-3]):[0-5][0-9]|14:00))?");

    if (std::regex_match(s.data(), gMonth_regex)) {

        struct tm tm{};
        strptime(s.data(), "--%m", &tm);

        //default values
        tm.tm_sec = 0; // seconds of minutes from 0 to 61
        tm.tm_min = 0; // minutes of hour from 0 to 59
        tm.tm_hour = 0; // hours of day from 0 to 24
        tm.tm_year = 1900; // year since 1900
        tm.tm_mday = 1; // month of year from 0 to 11
        tm.tm_isdst = -1; // value should be set even if not used

        return mktime(&tm);
    } else {
        throw std::runtime_error("XSD Parsing Error");
    }
}

template<>
inline std::string RegisteredDatatype<xsd::GMonth, xsd_gMonth>::to_string(const xsd::GMonth &value) {

    char str[32];
    std::strftime(str, 32,"--%m", std::localtime(&value));

    return std::string{str};;
}
}  // namespace rdf4cpp::rdf::datatypes

#endif  //RDF4CPP_XSD_GMONTH_HPP
