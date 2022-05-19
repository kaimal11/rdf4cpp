
/**
 * @file Registers xsd:Name with DatatypeRegistry
 */

#ifndef RDF4CPP_XSD_NAME_HPP
#define RDF4CPP_XSD_NAME_HPP

#include <cstdint>
#include <ostream>
#include <regex>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>

namespace rdf4cpp::rdf::datatypes::xsd {
using Name = std::string;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#name">xsd:Name</a>
}

namespace rdf4cpp::rdf::datatypes {
constexpr const char xsd_Name[] = "http://www.w3.org/2001/XMLSchema#name";

template<>
inline std::string RegisteredDatatype<xsd::Name, xsd_Name>::datatype_iri() noexcept { return "http://www.w3.org/2001/XMLSchema#name"; }

template<>
inline xsd::Name RegisteredDatatype<xsd::Name, xsd_Name>::from_string(std::string_view s) {
    const std::regex name_regex("(.*\\n)|(.*\\t)|(.*\\r)");
    if (std::regex_match(s.data(), name_regex)) {
        throw std::runtime_error("XSD Parsing Error");
    } else {
        return s.data();
    }
}
}  // namespace rdf4cpp::rdf::datatypes

#endif  //RDF4CPP_XSD_NAME_HPP
