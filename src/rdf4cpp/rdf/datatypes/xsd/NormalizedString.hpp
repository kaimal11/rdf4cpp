
/**
 * @file Registers xsd:normalizedString with DatatypeRegistry
 */

#ifndef RDF4CPP_XSD_NORMALIZEDSTRING_HPP
#define RDF4CPP_XSD_NORMALIZEDSTRING_HPP

#include <cstdint>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>

namespace rdf4cpp::rdf::datatypes::xsd {
using NormalizedString = std::string;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#normalizedString">xsd:normalizedString</a>
}

namespace rdf4cpp::rdf::datatypes {
constexpr const char xsd_normalizedString[] = "http://www.w3.org/2001/XMLSchema#normalizedString";

template<>
inline std::string RegisteredDatatype<xsd::NormalizedString, xsd_normalizedString>::datatype_iri() noexcept { return "http://www.w3.org/2001/XMLSchema#normalizedString"; }

template<>
inline xsd::NormalizedString RegisteredDatatype<xsd::NormalizedString, xsd_normalizedString>::from_string(std::string_view s) {
    return s.data();
}
}  // namespace rdf4cpp::rdf::datatypes

#endif  //RDF4CPP_XSD_NORMALIZEDSTRING_HPP
