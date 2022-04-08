
/**
 * @file Registers xsd:integer with DatatypeRegistry
 */

#ifndef RDF4CPP_XSD_INTEGER_HPP
#define RDF4CPP_XSD_INTEGER_HPP

#include <cstdint>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>
#include <regex>
#include "Decimal.hpp"

namespace rdf4cpp::rdf::datatypes::xsd {
using Integer = xsd::Decimal;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#integer">xsd:integer</a>
}

namespace rdf4cpp::rdf::datatypes {
constexpr const char xsd_integer[] = "http://www.w3.org/2001/XMLSchema#integer";

template<>
inline std::string RegisteredDatatype<xsd::Integer , xsd_integer>::datatype_iri() noexcept { return "http://www.w3.org/2001/XMLSchema#integer"; }

template<>
inline xsd::Integer RegisteredDatatype<xsd::Integer , xsd_integer>::from_string(std::string_view s) {

    const std::regex integer_regex("[\\-+]?[0-9]+");

    if (std::regex_match(s.data(), integer_regex)) {
        return std::strtod(s.data(), nullptr);
    }else {
        throw std::runtime_error("XSD Parsing Error");
    }
}
}  // namespace rdf4cpp::rdf::datatypes


#endif  //RDF4CPP_XSD_INTEGER_HPP
