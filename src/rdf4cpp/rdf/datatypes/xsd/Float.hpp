/**
 * @file Registers xsd:float with DatatypeRegistry
 */

#ifndef RDF4CPP_XSD_FLOAT_HPP
#define RDF4CPP_XSD_FLOAT_HPP

#include <ostream>
#include <math.h>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>

namespace rdf4cpp::rdf::datatypes::xsd {
using Float = float;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#float">xsd:float</a>
}


namespace rdf4cpp::rdf::datatypes {
constexpr const char xsd_float[] = "http://www.w3.org/2001/XMLSchema#float";

template<>
inline std::string RegisteredDatatype<xsd::Float, xsd_float>::datatype_iri() noexcept { return "http://www.w3.org/2001/XMLSchema#float"; }

template<>
inline float RegisteredDatatype<xsd::Float, xsd_float>::from_string(std::string_view s) {
    const std::regex float_regex("(\\+|-)?([0-9]+(\\.[0-9]*)?|\\.[0-9]+)|([Ee](\\+|-)?[0-9]+)? |(\\+|-)?INF|NaN");

    if (std::regex_match(s.data(), float_regex)) {
        return std::strtof(s.data(), nullptr);
    }else {
        throw std::runtime_error("XSD Parsing Error");
    }
}
template<>
inline std::string RegisteredDatatype<xsd::Float, xsd_float>::to_string(const xsd::Float &value) {

    if(isnan(value)){
        return "NaN";
    }else if(isinf(value)){
        return "INF";
    }else{
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

#endif  //RDF4CPP_XSD_FLOAT_HPP
