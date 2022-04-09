
/**
* @file Registers xsd:nonNegativeInteger with DatatypeRegistry
*/

#ifndef RDF4CPP_XSD_NONNEGATIVEINTEGER_HPP
#define RDF4CPP_XSD_NONNEGATIVEINTEGER_HPP

#include "Integer.hpp"
#include <cstdint>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>
#include <regex>

namespace rdf4cpp::rdf::datatypes::xsd {
using NonNegativeInteger = xsd::Integer;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#nonNegativeInteger">xsd:nonNegativeInteger</a>
}

namespace rdf4cpp::rdf::datatypes {
constexpr const char xsd_nonNegativeInteger[] = "http://www.w3.org/2001/XMLSchema#nonNegativeInteger";

template<>
inline std::string RegisteredDatatype<xsd::NonNegativeInteger, xsd_nonNegativeInteger>::datatype_iri() noexcept { return "http://www.w3.org/2001/XMLSchema#nonNegativeInteger"; }

template<>
inline xsd::NonNegativeInteger RegisteredDatatype<xsd::NonNegativeInteger, xsd_nonNegativeInteger>::from_string(std::string_view s) {

    const std::regex nnInteger_regex("[\\+]?[0-9]+");

    if (std::regex_match(s.data(), nnInteger_regex)) {
        xsd::NonNegativeInteger val =  std::strtol(s.data(), nullptr, 10);

        if(val >= 0) {
            return  val;
        }else{
            throw std::runtime_error("XSD Parsing Error");
        }
    } else {
        throw std::runtime_error("XSD Parsing Error");
    }
}
}  // namespace rdf4cpp::rdf::datatypes

#endif  //RDF4CPP_XSD_NONNEGATIVEINTEGER_HPP
