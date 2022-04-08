
/**
 * @file Registers xsd:long with DatatypeRegistry
 */

#ifndef RDF4CPP_XSD_LONG_HPP
#define RDF4CPP_XSD_LONG_HPP

#include <cstdint>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>

namespace rdf4cpp::rdf::datatypes::xsd {
using Long = int64_t;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#long">xsd:long</a>
}

namespace rdf4cpp::rdf::datatypes {
constexpr const char xsd_long[] = "http://www.w3.org/2001/XMLSchema#long";

template<>
inline std::string RegisteredDatatype<xsd::Long, xsd_long>::datatype_iri() noexcept { return "http://www.w3.org/2001/XMLSchema#long"; }

template<>
inline xsd::Long RegisteredDatatype<xsd::Long, xsd_long>::from_string(std::string_view s) {
    return std::strtol(s.data(), nullptr, 10);
}
}  // namespace rdf4cpp::rdf::datatypes

#endif  //RDF4CPP_XSD_LONG_HPP
