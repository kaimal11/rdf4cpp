
/**
 * @file Registers xsd:double with DatatypeRegistry
 */

#ifndef RDF4CPP_XSD_DOUBLE_HPP
#define RDF4CPP_XSD_DOUBLE_HPP

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
inline double RegisteredDatatype<xsd::Double, xsd_double>::from_string(const std::string &s) {
    return std::stod(s);
}
}  // namespace rdf4cpp::rdf::datatypes

#endif  //RDF4CPP_DOUBLE_HPP
