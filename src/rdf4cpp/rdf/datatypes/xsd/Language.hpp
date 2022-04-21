
/**
 * @file Registers xsd:language with DatatypeRegistry
 */

#ifndef RDF4CPP_XSD_LANGUAGE_HPP
#define RDF4CPP_XSD_LANGUAGE_HPP

#include <cstdint>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>

namespace rdf4cpp::rdf::datatypes::xsd {
using Language = std::string;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#language">xsd:language</a>
}

namespace rdf4cpp::rdf::datatypes {
constexpr const char xsd_language[] = "http://www.w3.org/2001/XMLSchema#language";

template<>
inline std::string RegisteredDatatype<xsd::Language, xsd_language>::datatype_iri() noexcept { return "http://www.w3.org/2001/XMLSchema#language"; }

template<>
inline xsd::Language RegisteredDatatype<xsd::Language, xsd_language>::from_string(std::string_view s) {
    return s.data();
}
}  // namespace rdf4cpp::rdf::datatypes

#endif  //RDF4CPP_XSD_LANGUAGE_HPP
