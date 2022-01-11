//
// Created by kaimal on 07.01.22.
//

#ifndef RDF4CPP_XSD_GMONTHDAY_H
#define RDF4CPP_XSD_GMONTHDAY_H

#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>
#include <regex>
#include <vector>
#include <sstream>

namespace rdf4cpp::rdf::datatypes::xsd {
using GMonthDay = time_t;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#time">xsd:gMonthDay</a>
}

namespace rdf4cpp::rdf::datatypes {

constexpr const char xsd_gMonth[] = "http://www.w3.org/2001/XMLSchema#gMonthDay";

template<>
inline xsd::GMonthDay RegisteredDatatype<xsd::GMonthDay , xsd_gMonth>::from_string(const std::string &s) {
    const std::regex gMonthDay_regex("--(0[1-9]|1[0-2])-(0[1-9]|[12][0-9]|3[01])(Z|(\\+|-)((0[0-9]|1[0-3]):[0-5][0-9]|14:00))?");
    if (std::regex_match(s, gMonthDay_regex)) {

        tm tm{};
        strptime(s.c_str(), "%M-%D", &tm);

        return mktime(&tm);

    } else {
        throw std::runtime_error("XSD Parsing Error");
    }
}
}  // namespace rdf4cpp::rdf::datatypes

#endif  //RDF4CPP_XSD_GMONTHDAY_H
