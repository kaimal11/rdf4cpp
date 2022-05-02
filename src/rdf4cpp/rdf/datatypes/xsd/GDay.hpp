
/**
 * @file Registers xsd:gDay with DatatypeRegistry
 */

#ifndef RDF4CPP_XSD_GDAY_HPP
#define RDF4CPP_XSD_GDAY_HPP

#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>
#include <regex>
#include <vector>
#include <sstream>

namespace rdf4cpp::rdf::datatypes::xsd {
using GDay = time_t;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#gDay">xsd:gDay</a>
}

namespace rdf4cpp::rdf::datatypes {
constexpr const char xsd_gDay[] = "http://www.w3.org/2001/XMLSchema#gDay";

template<>
inline std::string RegisteredDatatype<xsd::GDay, xsd_gDay>::datatype_iri() noexcept { return "http://www.w3.org/2001/XMLSchema#gDay"; }

template<>
inline xsd::GDay RegisteredDatatype<xsd::GDay , xsd_gDay>::from_string(std::string_view s) {
    const std::regex gDay_regex("---(0[1-9]|[12][0-9]|3[01])(Z|(\\+|-)((0[0-9]|1[0-3]):[0-5][0-9]|14:00))?");

    if (std::regex_match(s.data(), gDay_regex)) {

        struct tm tm{};
        strptime(s.data(), "---%d", &tm);

        //default values
        tm.tm_sec = 0; // seconds of minutes from 0 to 61
        tm.tm_min = 0; // minutes of hour from 0 to 59
        tm.tm_hour = 0; // hours of day from 0 to 24
        tm.tm_year = 1900; // year since 1900
        tm.tm_mon = 0; // month of year from 0 to 11
        tm.tm_isdst = -1; // value should be set even if not used

        return mktime(&tm);
    } else {
        throw std::runtime_error("XSD Parsing Error");
    }
}

template<>
inline std::string RegisteredDatatype<xsd::GDay, xsd_gDay>::to_string(const xsd::GDay &value) {

    char str[32];
    std::strftime(str, 32,"---%d", std::localtime(&value));

    return std::string{str};

}
}  // namespace rdf4cpp::rdf::datatypes

#endif  //RDF4CPP_XSD_GDAY_HPP
