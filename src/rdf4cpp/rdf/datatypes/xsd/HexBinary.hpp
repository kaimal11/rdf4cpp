
/**
 * @file Registers xsd:hexBinary with DatatypeRegistry
 */

#ifndef RDF4CPP_XSD_HEXBINARY_HPP
#define RDF4CPP_XSD_HEXBINARY_HPP

#include <cstdint>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>
#include <regex>
#include <sstream>
#include <bitset>

/*
namespace rdf4cpp::rdf::datatypes::xsd {
using HexBinary = std::vector<std::>;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#hexBinary">xsd:hexBinary</a>
}

namespace rdf4cpp::rdf::datatypes {
constexpr const char xsd_hexBinary[] = "http://www.w3.org/2001/XMLSchema#hexBinary";

template<>
inline std::string RegisteredDatatype<xsd::HexBinary, xsd_hexBinary>::datatype_iri() noexcept { return "http://www.w3.org/2001/XMLSchema#hexBinary"; }

template<>
inline xsd::HexBinary RegisteredDatatype<xsd::HexBinary, xsd_hexBinary>::from_string(std::string_view s) {

    const std::regex integer_regex("([0-9a-fA-F]{2})*");

    if (std::regex_match(s.data(), integer_regex)) {
        std::vector<std::byte> bytes;
        bytes.reserve(std::size(s));

        std::transform(std::begin(s), std::end(s), std::back_inserter(bytes), [](char c){
            return std::byte(c);
            });
        return bytes;
    }else {
        throw std::runtime_error("XSD Parsing Error");
    }
}
}  // namespace rdf4cpp::rdf::datatypes
*/

#endif  //RDF4CPP_XSD_HEXBINARY_HPP
