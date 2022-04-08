
/**
 * @file Registers xsd:unsignedInt with DatatypeRegistry
 */

#ifndef RDF4CPP_XSD_UNSIGNEDINT_HPP
#define RDF4CPP_XSD_UNSIGNEDINT_HPP

#include <cstdint>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>

namespace rdf4cpp::rdf::datatypes::xsd {
using UnsignedInt = uint32_t;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#unsignedInt">xsd:unsignedInt</a>
}

namespace rdf4cpp::rdf::datatypes {
constexpr const char xsd_uint[] = "http://www.w3.org/2001/XMLSchema#unsignedInt";

template<>
inline std::string RegisteredDatatype<xsd::UnsignedInt, xsd_uint>::datatype_iri() noexcept { return "http://www.w3.org/2001/XMLSchema#unsignedInt"; }

template<>
inline xsd::UnsignedInt RegisteredDatatype<xsd::UnsignedInt, xsd_uint>::from_string(std::string_view s) {
    auto int32_val = std::strtol(s.data(), nullptr, 10);
    if (int32_val < 0 || int32_val > 4294967295) throw std::runtime_error("XSD Parsing Error");
    return int32_val;
}
}  // namespace rdf4cpp::rdf::datatypes

#endif  //RDF4CPP_XSD_UNSIGNEDINT_HPP
