
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
inline xsd::GDay RegisteredDatatype<xsd::GDay , xsd_gDay>::from_string(const std::string &s) {
    const std::regex gDay_regex("---(0[1-9]|[12][0-9]|3[01])(Z|(\\+|-)((0[0-9]|1[0-3]):[0-5][0-9]|14:00))?");
    if (std::regex_match(s, gDay_regex)) {

        tm tm{};
        strptime(s.c_str(), "%D", &tm);

        return mktime(&tm);

    } else {
        throw std::runtime_error("XSD Parsing Error");
    }
}
}  // namespace rdf4cpp::rdf::datatypes

#endif  //RDF4CPP_XSD_GDAY_HPP
