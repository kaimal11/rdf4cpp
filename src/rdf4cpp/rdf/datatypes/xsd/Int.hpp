
/**
 * @file Registers xsd:int with DatatypeRegistry
 */

#ifndef RDF4CPP_XSD_INT_HPP
#define RDF4CPP_XSD_INT_HPP

#include <cstdint>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>

namespace rdf4cpp::rdf::datatypes::xsd {
using Int = int32_t;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#int">xsd:int</a>
}

namespace rdf4cpp::rdf::datatypes {
constexpr const char xsd_int[] = "http://www.w3.org/2001/XMLSchema#int";

template<>
inline std::string RegisteredDatatype<xsd::Int, xsd_int>::datatype_iri() noexcept { return "http://www.w3.org/2001/XMLSchema#int"; }

template<>
inline xsd::Int RegisteredDatatype<xsd::Int, xsd_int>::from_string(std::string_view s) {
    auto int32_val = std::strtol(s.data(), nullptr, 10);
    if (int32_val < -2147483648 || int32_val > 2147483647) throw std::runtime_error("XSD Parsing Error");
    return int32_val;
}
}  // namespace rdf4cpp::rdf::datatypes
#endif  //RDF4CPP_XSD_INT_HPP
