
/**
 * @file Registers xsd:dateTimeStamp with DatatypeRegistry
 */

#ifndef RDF4CPP_XSD_DATETIMESTAMP_HPP
#define RDF4CPP_XSD_DATETIMESTAMP_HPP

#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>
#include <regex>
#include <sstream>
#include <vector>
#include "DateTime.hpp"

namespace rdf4cpp::rdf::datatypes::xsd {
using DateTimeStamp = xsd::DateTime;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#dateTimeStamp">xsd:dateTimeStamp</a>
}

namespace rdf4cpp::rdf::datatypes {
constexpr const char xsd_dateTimeStamp[] = "http://www.w3.org/2001/XMLSchema#dateTimeStamp";

template<>
inline std::string RegisteredDatatype<xsd::DateTimeStamp, xsd_dateTimeStamp>::datatype_iri() noexcept { return "http://www.w3.org/2001/XMLSchema#dateTimeStamp"; }

template<>
inline xsd::DateTimeStamp RegisteredDatatype<xsd::DateTimeStamp, xsd_dateTimeStamp>::from_string(std::string_view s) {
    const std::regex dateTimeStamp_regex("(-?([1-9][0-9]{3,}|0[0-9]{3})-(0[1-9]|1[0-2])-(0[1-9]|[12][0-9]|3[01])"
                                    "T(([01][0-9]|2[0-3]):[0-5][0-9]:[0-5][0-9](\\.[0-9]+)?|(24:00:00(\\.0+)?))(Z|(\\+|-)((0[0-9]|1[0-3]):[0-5][0-9]|14:00))?)");
    auto dateTimeStamp_l = std::strtol(s.data(), nullptr, 10);

    char str[32];
    std::strftime(str, 32, "%Y-%m-%dT%H:%M:%SZ", std::localtime(&dateTimeStamp_l));
    std::string value(str);

/*    if (std::regex_match(s.data(), dateTimeStamp_regex)) {

        tm tm{};
        if(s.find('Z') != std::string::npos)
        {
            strptime(s.data(), "%Y-%m-%dT%H:%M:%SZ", &tm);
            return mktime(&tm);
        }else if (s.find('+') || s.find('-')){
            strptime(s.data(), "%Y-%m-%dT%H:%M:%S %z", &tm);
            return mktime(&tm);
        }else{
            throw std::runtime_error("XSD Parsing Error");
        }

    } else {
        throw std::runtime_error("XSD Parsing Error");
    }*/


    if (std::regex_match(str, dateTimeStamp_regex)) {
        return dateTimeStamp_l;
    } else {
        throw std::runtime_error("XSD Parsing Error");
    }
}
}  // namespace rdf4cpp::rdf::datatypes

#endif  //RDF4CPP_XSD_ATETIMESTAMP_HPP
