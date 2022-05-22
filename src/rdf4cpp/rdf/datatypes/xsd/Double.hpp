
/**
 * @file Registers xsd:double with DatatypeRegistry
 */

#ifndef RDF4CPP_XSD_DOUBLE_HPP
#define RDF4CPP_XSD_DOUBLE_HPP

#include <math.h>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>

namespace rdf4cpp::rdf::datatypes::xsd {
using Double = double;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#double">xsd:double</a>
}

namespace rdf4cpp::rdf::datatypes {
constexpr const char xsd_double[] = "http://www.w3.org/2001/XMLSchema#double";

template<>
inline std::string RegisteredDatatype<xsd::Double, xsd_double>::datatype_iri() noexcept { return "http://www.w3.org/2001/XMLSchema#double"; }

template<>
inline double RegisteredDatatype<xsd::Double, xsd_double>::from_string(std::string_view s) {
    const std::regex double_regex("(\\+|-)?([0-9]+(\\.[0-9]*)?|\\.[0-9]+)|([Ee](\\+|-)?[0-9]+)? |(\\+|-)?INF|NaN");

    if (std::regex_match(s.data(), double_regex)) {
        auto ret = std::strtod(s.data(), nullptr);
        return ret;
    } else {
        throw std::runtime_error("XSD Parsing Error");
    }
}
template<>
inline std::string RegisteredDatatype<xsd::Double, xsd_double>::to_string(const xsd::Double &value) {

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
}  // namespace rdf4cpp::rdf::datatypes
#endif  //RDF4CPP_DOUBLE_HPP
