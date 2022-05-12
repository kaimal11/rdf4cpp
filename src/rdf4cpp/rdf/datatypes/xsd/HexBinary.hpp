
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

namespace rdf4cpp::rdf::datatypes::xsd {
using HexBinary = std::vector<std::int16_t>;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#hexBinary">xsd:hexBinary</a>
}

namespace rdf4cpp::rdf::datatypes {
constexpr const char xsd_hexBinary[] = "http://www.w3.org/2001/XMLSchema#hexBinary";

template<>
inline std::string RegisteredDatatype<xsd::HexBinary, xsd_hexBinary>::datatype_iri() noexcept { return "http://www.w3.org/2001/XMLSchema#hexBinary"; }

template<>
inline xsd::HexBinary RegisteredDatatype<xsd::HexBinary, xsd_hexBinary>::from_string(std::string_view s) {

    const std::regex integer_regex("([0-9a-fA-F]{2})*");

    if (std::regex_match(s.data(), integer_regex)) {
        /*std::stringstream result;
        std::vector<std::int16_t> octet;

        std::copy(octet.begin(), octet.end(), std::ostream_iterator<int>(result, " "));
        return result.str().c_str();*/
    }else {
        throw std::runtime_error("XSD Parsing Error");
    }
}
template<>
inline std::string RegisteredDatatype<xsd::HexBinary, xsd_hexBinary>::to_string(const xsd::HexBinary &value) {

    std::stringstream result;
    std::vector<std::int16_t> octet;

    std::copy(octet.begin(), octet.end(), std::ostream_iterator<int>(result, " "));
    return result.str();
}
}  // namespace rdf4cpp::rdf::datatypes


#endif  //RDF4CPP_XSD_HEXBINARY_HPP
