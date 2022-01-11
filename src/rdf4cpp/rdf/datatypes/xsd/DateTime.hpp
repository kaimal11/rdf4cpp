
#ifndef RDF4CPP_XSD_DATETIME_H
#define RDF4CPP_XSD_DATETIME_H

#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>
#include <regex>
#include <vector>
#include <sstream>

namespace rdf4cpp::rdf::datatypes::xsd {
using DateTime = time_t;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#time">xsd:dateTime</a>
}

namespace rdf4cpp::rdf::datatypes {

constexpr const char xsd_dateTime[] = "http://www.w3.org/2001/XMLSchema#dateTime";

template<>
inline xsd::DateTime RegisteredDatatype<xsd::DateTime, xsd_dateTime>::from_string(const std::string &s) {
    const std::regex dateTime_regex("(-?([1-9][0-9]{3,}|0[0-9]{3})-(0[1-9]|1[0-2])-(0[1-9]|[12][0-9]|3[01])"
                                    "T(([01][0-9]|2[0-3]):[0-5][0-9]:[0-5][0-9](\\.[0-9]+)?|(24:00:00(\\.0+)?))(Z|(\\+|-)((0[0-9]|1[0-3]):[0-5][0-9]|14:00))?)");
    if (std::regex_match(s, dateTime_regex)) {

        tm tm{};
        strptime(s.c_str(), "%Y-%m-%dT%H:%M:%S", &tm);

        return mktime(&tm);

    } else {
        throw std::runtime_error("XSD Parsing Error");
    }
}
}  // namespace rdf4cpp::rdf::datatypes

#endif  //RDF4CPP_XSD_DATETIME_H
