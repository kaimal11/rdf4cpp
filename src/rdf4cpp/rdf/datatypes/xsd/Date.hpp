
#ifndef RDF4CPP_XSD_DATE_HPP
#define RDF4CPP_XSD_DATE_HPP

#include <cstdint>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>
#include <algorithm>
#include <regex>
#include <iomanip>

namespace rdf4cpp::rdf::datatypes::xsd {
using Date = time_t;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#time">xsd:time</a>
}

namespace rdf4cpp::rdf::datatypes {

constexpr const char xsd_date[] = "http://www.w3.org/2001/XMLSchema#date";

template<>
inline xsd::Date RegisteredDatatype<xsd::Date, xsd_date>::from_string(const std::string &s) {
    const std::regex date_regex(R"(-?([1-9][0-9]{3,}|0[0-9]{3})-(0[1-9]|1[0-2])-(0[1-9]|[12][0-9]|3[01])(Z|(\+|-)((0[0-9]|1[0-3]):[0-5][0-9]|14:00))?)");
    if (std::regex_match(s, date_regex)) {

        const char *str = s.c_str();
        tm tm{};
        strptime(str, "%Y-%m-%d", &tm);

        return mktime(&tm);

    } else {
        throw std::runtime_error("XSD Parsing Error");
    }
}
}  // namespace rdf4cpp::rdf::datatypes

#endif  //RDF4CPP_XSD_DATE_HPP
