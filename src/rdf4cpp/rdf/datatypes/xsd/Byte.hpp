
/**
 * @file Registers xsd:byte with DatatypeRegistry
 */

#ifndef RDF4CPP_XSD_BYTE_HPP
#define RDF4CPP_XSD_BYTE_HPP

#include <cstdint>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>

namespace rdf4cpp::rdf::datatypes::xsd {
using Byte = int8_t;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#byte">xsd:byte</a>
}

namespace rdf4cpp::rdf::datatypes {
constexpr const char xsd_byte[] = "http://www.w3.org/2001/XMLSchema#byte";

template<>
inline std::string RegisteredDatatype<xsd::Byte, xsd_byte>::datatype_iri() noexcept { return "http://www.w3.org/2001/XMLSchema#byte"; }

template<>
inline xsd::Byte RegisteredDatatype<xsd::Byte, xsd_byte>::from_string(const std::string &s) {
    auto int8_val = std::stoi(s.c_str());
    if (int8_val < -128 || int8_val > 127) throw std::runtime_error("XSD Parsing Error");
    return int8_val;
}
}  // namespace rdf4cpp::rdf::datatypes

#endif  //RDF4CPP_XSD_BYTE_HPP