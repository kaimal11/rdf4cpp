
/**
 * @file Registers xsd:yearMonthDuration with DatatypeRegistry
 */

#ifndef RDF4CPP_XSD_YEARMONTHDURATION_HPP
#define RDF4CPP_XSD_YEARMONTHDURATION_HPP

#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>
#include <regex>
#include <sstream>
#include <vector>

namespace rdf4cpp::rdf::datatypes::xsd {
using YearMonthDuration = int *;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#yearMonthDuration">xsd:yearMonthDuration</a>
}

namespace rdf4cpp::rdf::datatypes {
constexpr const char xsd_yearMonthDuration[] = "http://www.w3.org/2001/XMLSchema#yearMonthDuration";

template<>
inline std::string RegisteredDatatype<xsd::YearMonthDuration, xsd_yearMonthDuration>::datatype_iri() noexcept { return "http://www.w3.org/2001/XMLSchema#yearMonthDuration"; }

template<>
inline xsd::YearMonthDuration RegisteredDatatype<xsd::YearMonthDuration, xsd_yearMonthDuration>::from_string(const std::string &s) {
    int Y = 0, m = 1, d = 2, max = 3;
    int *duration = new int[6];
    for (int i = 0; i < max; i++) {
        duration[i] = 0;
    }
    const std::regex duration_regex("-?P((([0-9]+Y)([0-9]+M)?)|([0-9]+M))");
    if (std::regex_match(s, duration_regex)) {

        ulong start = 0, end;
        start = s.find('P');
        end = s.find('Y');
        if (end != std::string::npos) {
            start++;
            duration[Y] = std::stoi(s.substr(start, end - 1));
            start = end;
        }
        end = s.find('M');
        if (end != std::string::npos) {
            start++;
            duration[m] = std::stoi(s.substr(start, end - 1));
            start = end;
        }

        return duration;

    } else {
        throw std::runtime_error("XSD Parsing Error");
    }
}
}  // namespace rdf4cpp::rdf::datatypes

#endif  //RDF4CPP_XSD_YEARMONTHDURATION_HPP
