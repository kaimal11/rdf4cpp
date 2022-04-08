
/**
 * @file Registers xsd:gYearMonth with DatatypeRegistry
 */

#ifndef RDF4CPP_XSD_GYEARMONTH_HPP
#define RDF4CPP_XSD_GYEARMONTH_HPP

#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>
#include <regex>
#include <vector>
#include <sstream>

namespace rdf4cpp::rdf::datatypes::xsd {
using GYearMonth = time_t;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#gYearMonth">xsd:gYearMonth</a>
}

namespace rdf4cpp::rdf::datatypes {
constexpr const char xsd_gYearMonth[] = "http://www.w3.org/2001/XMLSchema#gYearMonth";

template<>
inline std::string RegisteredDatatype<xsd::GYearMonth , xsd_gYearMonth>::datatype_iri() noexcept { return "http://www.w3.org/2001/XMLSchema#gYearMonth"; }

template<>
inline xsd::GYearMonth RegisteredDatatype<xsd::GYearMonth , xsd_gYearMonth>::from_string(std::string_view s) {
    const std::regex gYearMonth_regex("-?([1-9][0-9]{3,}|0[0-9]{3})-(0[1-9]|1[0-2])(Z|(\\+|-)((0[0-9]|1[0-3]):[0-5][0-9]|14:00))?");
    if (std::regex_match(s.data(), gYearMonth_regex)) {

        tm tm{};
        strptime(s.data(), "%Y-%M", &tm);

        return mktime(&tm);

    } else {
        throw std::runtime_error("XSD Parsing Error");
    }
}
}  // namespace rdf4cpp::rdf::datatypes


#endif  //RDF4CPP_XSD_GYEARMONTH_HPP
