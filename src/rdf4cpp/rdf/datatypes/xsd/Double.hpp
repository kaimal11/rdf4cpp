
/**
 * @file Registers xsd:double with DatatypeRegistry
 */

#ifndef RDF4CPP_XSD_DOUBLE_HPP
#define RDF4CPP_XSD_DOUBLE_HPP

#include <rdf4cpp/rdf/datatypes/registry/DatatypeMapping.hpp>
#include <rdf4cpp/rdf/datatypes/registry/LiteralDatatypeImpl.hpp>

#include <cstdint>
#include <ostream>
#include <regex>
#include <math.h>

namespace rdf4cpp::rdf::datatypes::registry {
/*
 * Name of the datatype. This is kept so that we won't need to type it over and over again.
 */
constexpr static registry::ConstexprString xsd_double{"http://www.w3.org/2001/XMLSchema#double"};

/**
 * Defines the mapping between the LiteralDatatype IRI and the C++ datatype.
 */
template<>
struct DatatypeMapping<xsd_double> {
    using cpp_datatype = double;
};

/**
 * Specialisation of from_string template function.
 */
template<>
inline LiteralDatatypeImpl<xsd_double>::cpp_type LiteralDatatypeImpl<xsd_double>::from_string(std::string_view s) {
    const std::regex double_regex("(\\+|-)?([0-9]+(\\.[0-9]*)?|\\.[0-9]+)([Ee](\\+|-)?[0-9]+)?|(\\+|-)?INF|NaN");

    if (std::regex_match(s.data(), double_regex)) {
        auto ret = std::strtod(s.data(), nullptr);
        return ret;
    } else {
        throw std::runtime_error("XSD Parsing Error");
    }
}

/**
 * Specialisation of to_string template function.
 */
template<>
inline std::string LiteralDatatypeImpl<xsd_double>::to_string(const cpp_type &value) {

    if (isnan(value)) {
        return "NaN";
    } else if (isinf(value)) {
        return "INF";
    } else {
        std::ostringstream str_os;
        // Set Fixed -Point Notation
        str_os << std::fixed;
        str_os << value;
        // Get string from output string stream
        std::string str = str_os.str();
        return str;
    }
}
}  // namespace rdf4cpp::rdf::datatypes::registry
namespace rdf4cpp::rdf::datatypes::xsd {
/**
 * Implementation of xsd::double
 */
using Double = registry::LiteralDatatypeImpl<registry::xsd_double>;
}  // namespace rdf4cpp::rdf::datatypes::xsd
#endif  //RDF4CPP_DOUBLE_HPP
