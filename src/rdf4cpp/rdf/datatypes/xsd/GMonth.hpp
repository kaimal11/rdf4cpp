
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
    auto gMonth_l = std::strtol(s.data(), nullptr, 10);

    char str[32];
    std::strftime(str, 32, "%m", std::localtime(&gMonth_l));
    std::string value(str);
    value.insert(0, "--");

    if (std::regex_match(value, gMonth_regex)) {
        return gMonth_l;
    } else {
        throw std::runtime_error("XSD Parsing Error");
    }
}
}  // namespace rdf4cpp::rdf::datatypes

#endif  //RDF4CPP_XSD_GMONTH_HPP
