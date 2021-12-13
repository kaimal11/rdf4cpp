
#ifndef RDF4CPP_XSD_TIME_HPP
#define RDF4CPP_XSD_TIME_HPP

#include <cstdint>
#include <ostream>
#include <algorithm>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>
#include <regex>
#include <iomanip>

namespace rdf4cpp::rdf::datatypes::xsd {
using Time = time_t;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#time">xsd:time</a>
}

namespace rdf4cpp::rdf::datatypes {
template<>
inline std::string RegisteredDatatype<xsd::Time>::datatype_iri() noexcept { return "http://www.w3.org/2001/XMLSchema#time"; }

template<>
inline xsd::Time RegisteredDatatype<xsd::Time>::from_string(const std::string &s) {
    const std::regex time_regex(R"((([01][0-9]|2[0-3]):[0-5][0-9]:[0-5][0-9](\.[0-9]+)?|(24:00:00(\.0+)?))(Z|(\+|-)((0[0-9]|1[0-3]):[0-5][0-9]|14:00))?)");
    if(std::regex_match(s, time_regex)){

        const char *str = s.c_str();
        tm tm{};
        strptime(str, "%H:%M:%S", &tm);

        return mktime(&tm);

    }else{
        throw std::runtime_error("XSD Parsing Error");
    }
}
}  // namespace rdf4cpp::rdf::datatypes

#endif  //RDF4CPP_XSD_TIME_HPP