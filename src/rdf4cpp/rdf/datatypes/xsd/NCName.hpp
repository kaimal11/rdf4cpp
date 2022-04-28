
/**
 * @file Registers xsd:NCName with DatatypeRegistry
 */

#ifndef RDF4CPP_XSD_NCNAME_HPP
#define RDF4CPP_XSD_NCNAME_HPP

#include <cstdint>
#include <ostream>
#include <regex>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>

namespace rdf4cpp::rdf::datatypes::xsd {
using NCName = std::string;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#NCName">xsd:NCName</a>
}

namespace rdf4cpp::rdf::datatypes {
constexpr const char xsd_NCName[] = "http://www.w3.org/2001/XMLSchema#NCName";

template<>
inline std::string RegisteredDatatype<xsd::NCName, xsd_NCName>::datatype_iri() noexcept { return "http://www.w3.org/2001/XMLSchema#NCName"; }

template<>
inline xsd::NCName RegisteredDatatype<xsd::NCName, xsd_NCName>::from_string(std::string_view s) {
    const std::regex ncName_regex("\\n|\\s{1,}");
    if (std::regex_match(s.data(), ncName_regex)) {
        throw std::runtime_error("XSD Parsing Error");
    } else {
        return s.data();
    }
}
}  // namespace rdf4cpp::rdf::datatypes

#endif  //RDF4CPP_XSD_NCNAME_HPP
