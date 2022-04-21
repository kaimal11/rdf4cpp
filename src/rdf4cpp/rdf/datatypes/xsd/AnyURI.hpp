
/**
 * @file Registers xsd:anyURI with DatatypeRegistry
 */

#ifndef RDF4CPP_XSD_ANYURI_HPP
#define RDF4CPP_XSD_ANYURI_HPP

#include <cstdint>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>

namespace rdf4cpp::rdf::datatypes::xsd {
using AnyURI = std::string;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#anyURI">xsd:anyURI</a>
}

namespace rdf4cpp::rdf::datatypes {
constexpr const char xsd_anyURI[] = "http://www.w3.org/2001/XMLSchema#anyURI";

template<>
inline std::string RegisteredDatatype<xsd::AnyURI, xsd_anyURI>::datatype_iri() noexcept { return "http://www.w3.org/2001/XMLSchema#anyURI"; }

template<>
inline xsd::AnyURI RegisteredDatatype<xsd::AnyURI, xsd_anyURI>::from_string(std::string_view s) {
    return s.data();
}
}  // namespace rdf4cpp::rdf::datatypes

#endif  //RDF4CPP_XSD_ANYURI_HPP
