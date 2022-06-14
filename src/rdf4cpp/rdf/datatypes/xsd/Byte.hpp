
/**
 * @file Registers xsd:byte with DatatypeRegistry
 */

#ifndef RDF4CPP_XSD_BYTE_HPP
#define RDF4CPP_XSD_BYTE_HPP

#include <rdf4cpp/rdf/datatypes/registry/DatatypeMapping.hpp>
#include <rdf4cpp/rdf/datatypes/registry/LiteralDatatypeImpl.hpp>

#include <cstdint>
#include <ostream>
#include <regex>

namespace rdf4cpp::rdf::datatypes::registry {
/*
 * Name of the datatype. This is kept so that we won't need to type it over and over again.
 */
constexpr static registry::ConstexprString xsd_byte{"http://www.w3.org/2001/XMLSchema#byte"};

/**
 * Defines the mapping between the LiteralDatatype IRI and the C++ datatype.
 */
template<>
struct DatatypeMapping<xsd_byte> {
    using cpp_datatype = int8_t;
};

/**
 * Specialisation of from_string template function.
 */
template<>
inline LiteralDatatypeImpl<xsd_byte>::cpp_type LiteralDatatypeImpl<xsd_byte>::from_string(std::string_view s) {

    auto int8_val = s[0];
    if (int8_val < -128 || int8_val > 127) throw std::runtime_error("XSD Parsing Error");
    return int8_val;
}
}  // namespace rdf4cpp::rdf::datatypes::registry

namespace rdf4cpp::rdf::datatypes::xsd {
/**
 * Implementation of xsd::decimal
 */
using Byte = registry::LiteralDatatypeImpl<registry::xsd_byte>;
}  // namespace rdf4cpp::rdf::datatypes::xsd

#endif  //RDF4CPP_XSD_BYTE_HPP