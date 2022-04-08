
/**
 * @file Registers xsd:unsignedShort with DatatypeRegistry
 */

#ifndef RDF4CPP_XSD_UNSIGNEDSHORT_HPP
#define RDF4CPP_XSD_UNSIGNEDSHORT_HPP

#include <cstdint>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>

namespace rdf4cpp::rdf::datatypes::xsd {
using UnsignedShort = uint16_t;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#unsignedShort">xsd:unsignedShort</a>
}

namespace rdf4cpp::rdf::datatypes {
constexpr const char xsd_ushort[] = "http://www.w3.org/2001/XMLSchema#unsignedShort";

template<>
inline std::string RegisteredDatatype<xsd::UnsignedShort, xsd_ushort>::datatype_iri() noexcept { return "http://www.w3.org/2001/XMLSchema#unsignedShort"; }

template<>
inline xsd::UnsignedShort RegisteredDatatype<xsd::UnsignedShort, xsd_ushort>::from_string(std::string_view s) {
    auto int16_val = std::strtol(s.data(), nullptr, 10);
    if (int16_val < 0 || int16_val > 65535) throw std::runtime_error("XSD Parsing Error");
    return int16_val;
}
}  // namespace rdf4cpp::rdf::datatypes

#endif  //RDF4CPP_XSD_UNSIGNEDSHORT_HPP
