
/**
 * @file Registers xsd:nonPositiveInteger with DatatypeRegistry
 */

#ifndef RDF4CPP_XSD_NONPOSITIVEINTEGER_HPP
#define RDF4CPP_XSD_NONPOSITIVEINTEGER_HPP

#include "Integer.hpp"
#include <cstdint>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>
#include <regex>

namespace rdf4cpp::rdf::datatypes::xsd {
using NonPositiveInteger = xsd::Integer;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#nonPositiveInteger">xsd:nonPositiveInteger</a>
}

namespace rdf4cpp::rdf::datatypes {
constexpr const char xsd_nonPositiveInteger[] = "http://www.w3.org/2001/XMLSchema#nonPositiveInteger";

template<>
inline std::string RegisteredDatatype<xsd::NonPositiveInteger, xsd_nonPositiveInteger>::datatype_iri() noexcept { return "http://www.w3.org/2001/XMLSchema#nonPositiveInteger"; }

template<>
inline xsd::NonPositiveInteger RegisteredDatatype<xsd::NonPositiveInteger, xsd_nonPositiveInteger>::from_string(const std::string &s) {

    const std::regex npInteger_regex("[\\-]?[0-9]+");

    if (std::regex_match(s, npInteger_regex)) {
        xsd::NonPositiveInteger val =  std::stod(s);

        if(val <= 0) {
            return  val;
        }else{
            throw std::runtime_error("XSD Parsing Error");
        }
    } else {
        throw std::runtime_error("XSD Parsing Error");
    }
}
}  // namespace rdf4cpp::rdf::datatypes

#endif  //RDF4CPP_XSD_NONPOSITIVEINTEGER_HPP
