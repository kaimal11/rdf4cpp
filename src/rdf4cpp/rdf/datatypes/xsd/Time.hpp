
/**
 * @file Registers xsd:time with DatatypeRegistry
 */

#ifndef RDF4CPP_XSD_TIME_HPP
#define RDF4CPP_XSD_TIME_HPP

#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>
#include <regex>

namespace rdf4cpp::rdf::datatypes::xsd {
using Time = time_t;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#time">xsd:time</a>
}

namespace rdf4cpp::rdf::datatypes {
constexpr const char xsd_time[] = "http://www.w3.org/2001/XMLSchema#time";

template<>
inline std::string RegisteredDatatype<xsd::Time, xsd_time>::datatype_iri() noexcept { return "http://www.w3.org/2001/XMLSchema#time"; }

template<>
inline xsd::Time RegisteredDatatype<xsd::Time, xsd_time>::from_string(std::string_view s) {
    const std::regex time_regex(R"((([01][0-9]|2[0-3]):[0-5][0-9]:[0-5][0-9](\.[0-9]+)?|(24:00:00(\.0+)?))(Z|(\+|-)((0[0-9]|1[0-3]):[0-5][0-9]|14:00))?)");
    auto time_l = std::strtol(s.data(), nullptr, 10);

    char str[32];
    std::strftime(str, 32, "%H:%M:%S", std::localtime(&time_l));
    std::string value(str);

    if (std::regex_match(str, time_regex)) {
        return time_l;
    } else {
        throw std::runtime_error("XSD Parsing Error");
    }
}
}  // namespace rdf4cpp::rdf::datatypes

#endif  //RDF4CPP_XSD_TIME_HPP