
/**
 * @file Registers xsd:unsignedByte with DatatypeRegistry
 */

#ifndef RDF4CPP_XSD_UNSIGNEDBYTE_HPP
#define RDF4CPP_XSD_UNSIGNEDBYTE_HPP

#include <cstdint>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>

namespace rdf4cpp::rdf::datatypes::xsd {
using UnsignedByte = uint8_t;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#unsignedByte">xsd:unsignedByte</a>
}

namespace rdf4cpp::rdf::datatypes {
constexpr const char xsd_ubyte[] = "http://www.w3.org/2001/XMLSchema#unsignedByte";

template<>
inline std::string RegisteredDatatype<xsd::UnsignedByte, xsd_ubyte>::datatype_iri() noexcept { return "http://www.w3.org/2001/XMLSchema#unsignedByte"; }

template<>
inline xsd::UnsignedByte RegisteredDatatype<xsd::UnsignedByte, xsd_ubyte>::from_string(std::string_view s) {
    uint8_t int8_val = std::strtol(s.data(), nullptr, 10);
    if (int8_val < 0 || int8_val > 255) throw std::runtime_error("XSD Parsing Error");
    return int8_val;
}
}  // namespace rdf4cpp::rdf::datatypes

#endif  //RDF4CPP_XSD_UNSIGNEDBYTE_HPP
