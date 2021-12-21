
#ifndef RDF4CPP_UNSIGNEDLONG_HPP
#define RDF4CPP_UNSIGNEDLONG_HPP

#include <cstdint>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>

namespace rdf4cpp::rdf::datatypes::xsd {
using UnsignedLong = ulong;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#unsignedLong">xsd:unsignedLong</a>
}

namespace rdf4cpp::rdf::datatypes {
constexpr const char xsd_ulong[] = "xsd::UnsignedLong";
template<>
inline std::string RegisteredDatatype<xsd::UnsignedLong, xsd_ulong>::datatype_iri() noexcept { return "http://www.w3.org/2001/XMLSchema#unsignedLong"; }

template<>
inline xsd::UnsignedLong RegisteredDatatype<xsd::UnsignedLong, xsd_ulong>::from_string(const std::string &s) {
    return std::stoull(s);
}
}  // namespace rdf4cpp::rdf::datatypes

#endif  //RDF4CPP_UNSIGNEDLONG_HPP
