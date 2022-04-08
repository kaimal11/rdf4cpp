
/**
 * @file Registers xsd:gYear with DatatypeRegistry
 */

#ifndef RDF4CPP_XSD_GYEAR_HPP
#define RDF4CPP_XSD_GYEAR_HPP

#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>
#include <regex>
#include <sstream>
#include <vector>

namespace rdf4cpp::rdf::datatypes::xsd {
using GYear = time_t;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#gYear">xsd:gYear</a>
}

namespace rdf4cpp::rdf::datatypes {
constexpr const char xsd_gYear[] = "http://www.w3.org/2001/XMLSchema#gYear";

template<>
inline std::string RegisteredDatatype<xsd::GYear, xsd_gYear>::datatype_iri() noexcept { return "http://www.w3.org/2001/XMLSchema#gYear"; }

template<>
inline xsd::GYear RegisteredDatatype<xsd::GYear, xsd_gYear>::from_string(std::string_view s) {
    const std::regex gYear_regex("-?([1-9][0-9]{3,}|0[0-9]{3})(Z|(\\+|-)((0[0-9]|1[0-3]):[0-5][0-9]|14:00))?");
    if (std::regex_match(s.data(), gYear_regex)) {

        tm tm{};
        strptime(s.data(), "%Y", &tm);

        return mktime(&tm);

    } else {
        throw std::runtime_error("XSD Parsing Error");
    }
}
}  // namespace rdf4cpp::rdf::datatypes

#endif  //RDF4CPP_XSD_GYEAR_HPP
