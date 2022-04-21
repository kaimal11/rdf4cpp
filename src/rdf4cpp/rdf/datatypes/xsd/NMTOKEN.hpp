
/**
 * @file Registers xsd:NMTOKEN with DatatypeRegistry
 */

#ifndef RDF4CPP_XSD_NMTOKEN_HPP
#define RDF4CPP_XSD_NMTOKEN_HPP

#include <cstdint>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>

namespace rdf4cpp::rdf::datatypes::xsd {
using NMTOKEN = std::string;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#NMTOKEN">xsd:NMTOKEN</a>
}

namespace rdf4cpp::rdf::datatypes {
constexpr const char xsd_NMTOKEN[] = "http://www.w3.org/2001/XMLSchema#NMTOKEN";

template<>
inline std::string RegisteredDatatype<xsd::NMTOKEN, xsd_NMTOKEN>::datatype_iri() noexcept { return "http://www.w3.org/2001/XMLSchema#NMTOKEN"; }

template<>
inline xsd::NMTOKEN RegisteredDatatype<xsd::NMTOKEN, xsd_NMTOKEN>::from_string(std::string_view s) {
    return s.data();
}
}  // namespace rdf4cpp::rdf::datatypes

#endif  //RDF4CPP_XSD_NMTOKEN_HPP
