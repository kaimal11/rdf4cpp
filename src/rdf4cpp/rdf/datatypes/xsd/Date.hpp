
/**
 * @file Registers xsd:date with DatatypeRegistry
 */

#ifndef RDF4CPP_XSD_DATE_HPP
#define RDF4CPP_XSD_DATE_HPP

#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>
#include <regex>
#include <chrono>

namespace rdf4cpp::rdf::datatypes::xsd {
using Date = time_t;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#date">xsd:date</a>
}

namespace rdf4cpp::rdf::datatypes {
constexpr const char xsd_date[] = "http://www.w3.org/2001/XMLSchema#date";

template<>
inline std::string RegisteredDatatype<xsd::Date, xsd_date>::datatype_iri() noexcept { return "http://www.w3.org/2001/XMLSchema#date"; }

template<>
inline xsd::Date RegisteredDatatype<xsd::Date, xsd_date>::from_string(const std::string &s) {
    const std::regex date_regex(R"(-?([1-9][0-9]{3,}|0[0-9]{3})-(0[1-9]|1[0-2])-(0[1-9]|[12][0-9]|3[01])(Z|(\+|-)((0[0-9]|1[0-3]):[0-5][0-9]|14:00))?)");
    if (std::regex_match(s, date_regex)) {

        /*        std::vector<std::string> result;
        std::stringstream ss(s);
        std::string item;

        while (getline(ss, item, '-')) {
            result.push_back(item);
        }

        using namespace std::chrono;

        auto y = std::stoi(result[0]);
        uint8_t m = std::stoi(result[1]);
        uint8_t d = std::stoi(result[2]);

        return year_month_day{year{y}, month{m}, day{d}};*/

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
