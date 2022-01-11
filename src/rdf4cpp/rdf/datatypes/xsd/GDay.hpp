
#ifndef RDF4CPP_XSD_GDAY_HPP
#define RDF4CPP_XSD_GDAY_HPP

#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>
#include <regex>
#include <vector>
#include <sstream>

namespace rdf4cpp::rdf::datatypes::xsd {
using GYear = time_t;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#time">xsd:gDay</a>
}

namespace rdf4cpp::rdf::datatypes {

constexpr const char xsd_gMonth[] = "http://www.w3.org/2001/XMLSchema#gDay";

template<>
inline xsd::GYear RegisteredDatatype<xsd::GYear , xsd_gMonth>::from_string(const std::string &s) {
    const std::regex gDay_regex("---(0[1-9]|[12][0-9]|3[01])(Z|(\\+|-)((0[0-9]|1[0-3]):[0-5][0-9]|14:00))?");
    if (std::regex_match(s, gDay_regex)) {

        tm tm{};
        strptime(s.c_str(), "%D", &tm);

        return mktime(&tm);

    } else {
        throw std::runtime_error("XSD Parsing Error");
    }
}
}  // namespace rdf4cpp::rdf::datatypes

#endif  //RDF4CPP_XSD_GDAY_HPP
