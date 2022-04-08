
/**
 * @file Registers xsd:dayTimeDuration with DatatypeRegistry
 */

#ifndef RDF4CPP_XSD_DAYTIMEDURATION_HPP
#define RDF4CPP_XSD_DAYTIMEDURATION_HPP

#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>
#include <regex>
#include <sstream>
#include <vector>

namespace rdf4cpp::rdf::datatypes::xsd {
using DayTimeDuration = int *;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#dayTimeDuration">xsd:dayTimeDuration</a>
}

namespace rdf4cpp::rdf::datatypes {
constexpr const char xsd_dayTimeDuration[] = "http://www.w3.org/2001/XMLSchema#dayTimeDuration";

template<>
inline std::string RegisteredDatatype<xsd::DayTimeDuration, xsd_dayTimeDuration>::datatype_iri() noexcept { return "http://www.w3.org/2001/XMLSchema#dayTimeDuration"; }

template<>
inline xsd::DayTimeDuration RegisteredDatatype<xsd::DayTimeDuration, xsd_dayTimeDuration>::from_string(std::string_view s) {
    int d = 2, H = 3, M = 4, S = 5, max = 6;
    int *duration = new int[6];
    for (int i = 0; i < max; i++) {
        duration[i] = 0;
    }
    const std::regex duration_regex("-?P((([0-9]+D)"
                                    "(T(([0-9]+H)([0-9]+M)?([0-9]+(\\.[0-9]+)?S)?"
                                    "|([0-9]+M)([0-9]+(\\.[0-9]+)?S)?"
                                    "|([0-9]+(\\.[0-9]+)?S)))?)"
                                    "|(T(([0-9]+H)([0-9]+M)?([0-9]+(\\.[0-9]+)?S)?"
                                    "|([0-9]+M)([0-9]+(\\.[0-9]+)?S)?"
                                    "|([0-9]+(\\.[0-9]+)?S))))");

    if (std::regex_match(s.data(), duration_regex)) {

        std::vector<std::string> result;
        std::stringstream ss(s.data());
        std::string item;

        while (getline(ss, item, 'T')) {
            result.push_back(item);
        }

        ulong start = 0, end;
        start = result[0].find('P');
        end = result[0].find('D');
        if (end != std::string::npos) {
            start++;
            duration[d] = std::stoi(result[0].substr(start, end - 1));
            start = end;
        }

        end = s.find('T');
        if (end != std::string::npos) {

            end = result[1].find('H');
            if (end != std::string::npos) {
                start++;
                duration[H] = std::stoi(result[1].substr(start, end - 1));
                start = end;
            }

            end = result[1].find('M');
            if (end != std::string::npos) {
                start++;
                duration[M] = std::stoi(result[1].substr(start, end - 1));
                start = end;
            }

            end = result[1].find('S');
            if (end != std::string::npos) {
                start++;
                duration[S] = std::stoi(result[1].substr(start, end - 1));
                start = end;
            }
        }
        return duration;

    } else {
        throw std::runtime_error("XSD Parsing Error");
    }
}
}  // namespace rdf4cpp::rdf::datatypes

#endif  //RDF4CPP_XSD_DAYTIMEDURATION_HPP
