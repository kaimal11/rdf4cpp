
/**
 * @file Registers xsd:token with DatatypeRegistry
 */

#ifndef RDF4CPP_XSD_TOKEN_HPP
#define RDF4CPP_XSD_TOKEN_HPP

#include <cstdint>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>

namespace rdf4cpp::rdf::datatypes::xsd {
using Token = std::string;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#token">xsd:token</a>
}

namespace rdf4cpp::rdf::datatypes {
constexpr const char xsd_token[] = "http://www.w3.org/2001/XMLSchema#token";

template<>
inline std::string RegisteredDatatype<xsd::Token, xsd_token>::datatype_iri() noexcept { return "http://www.w3.org/2001/XMLSchema#token"; }

template<>
inline xsd::Token RegisteredDatatype<xsd::Token, xsd_token>::from_string(std::string_view s) {
    return s.data();
}
}  // namespace rdf4cpp::rdf::datatypes

#endif  //RDF4CPP_XSD_TOKEN_HPP
