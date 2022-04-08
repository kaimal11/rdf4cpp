
/**
 * @file Registers xsd:positiveInteger with DatatypeRegistry
 */

#ifndef RDF4CPP_XSD_POSITIVEINTEGER_HPP
#define RDF4CPP_XSD_POSITIVEINTEGER_HPP

#include "Integer.hpp"
#include <cstdint>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>
#include <regex>

namespace rdf4cpp::rdf::datatypes::xsd {
using PositiveInteger = xsd::Integer;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#positiveInteger">xsd:positiveInteger</a>
}

namespace rdf4cpp::rdf::datatypes {
constexpr const char xsd_positiveInteger[] = "http://www.w3.org/2001/XMLSchema#positiveInteger";

template<>
inline std::string RegisteredDatatype<xsd::PositiveInteger, xsd_positiveInteger>::datatype_iri() noexcept { return "http://www.w3.org/2001/XMLSchema#positiveInteger"; }

template<>
inline xsd::Integer RegisteredDatatype<xsd::PositiveInteger, xsd_positiveInteger>::from_string(std::string_view s) {

    const std::regex positiveInteger_regex("[\\+]?[0-9]+");

    if (std::regex_match(s.data(), positiveInteger_regex)) {
        xsd::PositiveInteger val =  std::strtod(s.data(), nullptr);

        if(val > 0) {
            return  val;
        }else{
            throw std::runtime_error("XSD Parsing Error");
        }
    } else {
        throw std::runtime_error("XSD Parsing Error");
    }
}
}  // namespace rdf4cpp::rdf::datatypes

#endif  //RDF4CPP_XSD_POSITIVEINTEGER_HPP
