
/**
* @file Registers xsd:string with DatatypeRegistry
*/

#ifndef RDF4CPP_RDFSYNTAX_LANGSTRING_HPP
#define RDF4CPP_RDFSYNTAX_LANGSTRING_HPP

#include <cstdint>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>

namespace rdf4cpp::rdf::datatypes::xsd {
using langString = std::string;  //!< Implements <a href="http://www.w3.org/1999/02/22-rdf-syntax-ns#langString">xsd:langString</a>
}

namespace rdf4cpp::rdf::datatypes {
constexpr const char xsd_langString[] = "http://www.w3.org/1999/02/22-rdf-syntax-ns#langString";

template<>
inline std::string RegisteredDatatype<xsd::langString, xsd_langString>::datatype_iri() noexcept { return "http://www.w3.org/1999/02/22-rdf-syntax-ns#langString"; }

template<>
inline xsd::langString RegisteredDatatype<xsd::langString, xsd_langString>::from_string(std::string_view s) {
    return s.data();
}
}  // namespace rdf4cpp::rdf::rdf-syntax

#endif  //RDF4CPP_RDFSYNTAX_LANGSTRING_HPP
