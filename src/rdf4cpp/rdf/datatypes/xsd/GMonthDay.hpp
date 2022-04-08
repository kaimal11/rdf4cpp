
/**
 * @file Registers xsd:gMonthDay with DatatypeRegistry
 */

#ifndef RDF4CPP_XSD_GMONTHDAY_HPP
#define RDF4CPP_XSD_GMONTHDAY_HPP

#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>
#include <regex>
#include <vector>
#include <sstream>

namespace rdf4cpp::rdf::datatypes::xsd {
using GMonthDay = time_t;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#gMonthDay">xsd:gMonthDay</a>
}

namespace rdf4cpp::rdf::datatypes {
constexpr const char xsd_gMonthDay[] = "http://www.w3.org/2001/XMLSchema#gMonthDay";

template<>
inline std::string RegisteredDatatype<xsd::GMonthDay, xsd_gMonthDay>::datatype_iri() noexcept { return "http://www.w3.org/2001/XMLSchema#gMonthDay"; }

template<>
inline xsd::GMonthDay RegisteredDatatype<xsd::GMonthDay , xsd_gMonthDay>::from_string(std::string_view s) {
    const std::regex gMonthDay_regex("--(0[1-9]|1[0-2])-(0[1-9]|[12][0-9]|3[01])(Z|(\\+|-)((0[0-9]|1[0-3]):[0-5][0-9]|14:00))?");
    if (std::regex_match(s.data(), gMonthDay_regex)) {

        tm tm{};
        strptime(s.data(), "%M-%D", &tm);

        return mktime(&tm);

    } else {
        throw std::runtime_error("XSD Parsing Error");
    }
}
}  // namespace rdf4cpp::rdf::datatypes

#endif  //RDF4CPP_XSD_GMONTHDAY_H
