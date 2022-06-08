
/**
* @file Registers xsd:langString with DatatypeRegistry
*/

#ifndef RDF4CPP_RDFSYNTAX_LANGSTRING_HPP
#define RDF4CPP_RDFSYNTAX_LANGSTRING_HPP

#include <rdf4cpp/rdf/datatypes/registry/DatatypeMapping.hpp>
#include <rdf4cpp/rdf/datatypes/registry/LiteralDatatypeImpl.hpp>

#include <cstdint>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <ranges>

namespace rdf4cpp::rdf::datatypes::registry {
/*
 * Name of the datatype. This is kept so that we won't need to type it over and over again.
 */
constexpr static registry::ConstexprString xsd_langString{"http://www.w3.org/1999/02/22-rdf-syntax-ns#langString"};

/**
 * Defines the mapping between the LiteralDatatype IRI and the C++ datatype.
 */
template<>
struct DatatypeMapping<xsd_langString> {
    using cpp_datatype = std::string;
};

/**
 * Specialisation of from_string template function.
 */
template<>
inline LiteralDatatypeImpl<xsd_langString>::cpp_type LiteralDatatypeImpl<xsd_langString>::from_string(std::string_view s) {
    std::string delimiter = "@";
    const std::regex language_regex("[a-zA-Z]{1,8}(-[a-zA-Z0-9]{1,8})*");
    auto pos = s.find(delimiter);
    if (pos != std::string::npos) {
        std::string_view lang = s.substr(pos + 1);

        if (std::regex_match(lang.data(), language_regex)) {
            return s.data();
        } else {
            throw std::runtime_error("XSD Parsing Error");
        }
    } else {
        throw std::runtime_error("XSD Parsing Error");
    }
}
}  // namespace rdf4cpp::rdf::datatypes::registry
namespace rdf4cpp::rdf::datatypes::xsd {
/**
 * Implementation of xsd::langString
 */
using LangString = registry::LiteralDatatypeImpl<registry::xsd_langString>;
}  // namespace rdf4cpp::rdf::datatypes::xsd
#endif  //RDF4CPP_RDFSYNTAX_LANGSTRING_HPP
