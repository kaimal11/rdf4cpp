/**
 * @file Registers xsd:int with DatatypeRegistry
 */

#ifndef RDF4CPP_XSD_INT_HPP
#define RDF4CPP_XSD_INT_HPP

#include <cstdint>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>

namespace rdf4cpp::rdf::datatypes::xsd {
using Int = int32_t;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#int">xsd:int</a>
}

namespace rdf4cpp::rdf::datatypes {
constexpr const char xsd_int[] = "xsd::Int";
template<>
inline std::string RegisteredDatatype<xsd::Int, xsd_int>::datatype_iri() noexcept { return "http://www.w3.org/2001/XMLSchema#int"; }

template<>
inline xsd::Int RegisteredDatatype<xsd::Int, xsd_int>::from_string(const std::string &s) {
    return std::stoi(s);
}
}  // namespace rdf4cpp::rdf::datatypes
#endif  //RDF4CPP_XSD_INT_HPP
