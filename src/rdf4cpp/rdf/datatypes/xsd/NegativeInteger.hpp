
/**
 * @file Registers xsd:negativeInteger with DatatypeRegistry
 */

#ifndef RDF4CPP_XSD_NEGATIVEINTEGER_HPP
#define RDF4CPP_XSD_NEGATIVEINTEGER_HPP

#include "Integer.hpp"
#include <cstdint>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>
#include <regex>

namespace rdf4cpp::rdf::datatypes::xsd {
using NegativeInteger = xsd::Integer;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#negativeInteger">xsd:negativeInteger</a>
}

namespace rdf4cpp::rdf::datatypes {
constexpr const char xsd_negativeInteger[] = "http://www.w3.org/2001/XMLSchema#negativeInteger";

template<>
inline std::string RegisteredDatatype<xsd::NegativeInteger, xsd_negativeInteger>::datatype_iri() noexcept { return "http://www.w3.org/2001/XMLSchema#negativeInteger"; }

template<>
inline xsd::NegativeInteger RegisteredDatatype<xsd::NegativeInteger, xsd_negativeInteger>::from_string(const std::string &s) {

    const std::regex negativeInteger_regex("[\\-][0-9]+");

    if (std::regex_match(s, negativeInteger_regex)) {
        xsd::NegativeInteger val =  std::stod(s);

        if(val < 0) {
            return  val;
        }else{
            throw std::runtime_error("XSD Parsing Error");
        }
    } else {
        throw std::runtime_error("XSD Parsing Error");
    }
}
}  // namespace rdf4cpp::rdf::datatypes

#endif  //RDF4CPP_XSD_NEGATIVEINTEGER_HPP
