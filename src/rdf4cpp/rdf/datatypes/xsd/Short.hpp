
/**
 * @file Registers xsd:short with DatatypeRegistry
 */

#ifndef RDF4CPP_XSD_SHORT_HPP
#define RDF4CPP_XSD_SHORT_HPP

#include <cstdint>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>

namespace rdf4cpp::rdf::datatypes::xsd {
using Short = int16_t;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#short">xsd:short</a>
}

namespace rdf4cpp::rdf::datatypes {
constexpr const char xsd_short[] = "http://www.w3.org/2001/XMLSchema#short";

template<>
inline std::string RegisteredDatatype<xsd::Short, xsd_short>::datatype_iri() noexcept { return "http://www.w3.org/2001/XMLSchema#short"; }

template<>
inline xsd::Short RegisteredDatatype<xsd::Short, xsd_short>::from_string(std::string_view s) {
    auto int16_val = std::strtol(s.data(), nullptr, 10);
    if (int16_val < -32768 || int16_val > 32767) throw std::runtime_error("XSD Parsing Error");
    return int16_val;
}
}  // namespace rdf4cpp::rdf::datatypes

#endif  //RDF4CPP_XSD_SHORT_HPP