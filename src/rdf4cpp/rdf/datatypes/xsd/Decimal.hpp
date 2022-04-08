
/**
* @file Registers xsd:float with DatatypeRegistry
*/

#ifndef RDF4CPP_DECIMAL_HPP
#define RDF4CPP_DECIMAL_HPP

#include <cstdint>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>

namespace rdf4cpp::rdf::datatypes::xsd {
using Decimal = double;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#decimal">xsd:decimal</a>
}

namespace rdf4cpp::rdf::datatypes {
constexpr const char xsd_decimal[] = "http://www.w3.org/2001/XMLSchema#decimal";

template<>
inline std::string RegisteredDatatype<xsd::Decimal, xsd_decimal>::datatype_iri() noexcept { return "http://www.w3.org/2001/XMLSchema#decimal"; }

template<>
inline xsd::Decimal RegisteredDatatype<xsd::Decimal, xsd_decimal>::from_string(std::string_view s) {
    return std::strtod(s.data(), nullptr);
}
}  // namespace rdf4cpp::rdf::datatypes
#endif  //RDF4CPP_DECIMAL_HPP
