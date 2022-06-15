
/**
* @file Registers xsd:duration with DatatypeRegistry
*/

#ifndef RDF4CPP_XSD_DURATION_HPP
#define RDF4CPP_XSD_DURATION_HPP

#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>
#include <regex>
#include <vector>
#include <sstream>
#include <chrono>

namespace rdf4cpp::rdf::datatypes::xsd {
using Duration = time_t;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#duration">xsd:duration</a>
}

namespace rdf4cpp::rdf::datatypes {
constexpr const char xsd_duration[] = "http://www.w3.org/2001/XMLSchema#duration";

template<>
inline std::string RegisteredDatatype<xsd::Duration , xsd_duration>::datatype_iri() noexcept { return "http://www.w3.org/2001/XMLSchema#duration"; }

template<>
inline xsd::Duration RegisteredDatatype<xsd::Duration , xsd_duration>::from_string(std::string_view s) {

    int Y = 0, m = 1, d = 2, H = 3, M = 4, S = 5, max = 6;
    int *duration = new int[6];
    for (int i = 0; i < max; i++) {
        duration[i] = 0;
    }
    const std::regex duration_regex("-?P((([0-9]+Y([0-9]+M)?([0-9]+D)?"
                                    "|([0-9]+M)([0-9]+D)?"
                                    "|([0-9]+D))"
                                    "(T(([0-9]+H)([0-9]+M)?([0-9]+(\\.[0-9]+)?S)?"
                                    "|([0-9]+M)([0-9]+(\\.[0-9]+)?S)?"
                                    "|([0-9]+(\\.[0-9]+)?S)))?)"
                                    "|(T(([0-9]+H)([0-9]+M)?([0-9]+(\\.[0-9]+)?S)?"
                                    "|([0-9]+M)([0-9]+(\\.[0-9]+)?S)?"
                                    "|([0-9]+(\\.[0-9]+)?S))))");

    if (std::regex_match(s.data(), duration_regex)) {
        struct tm tm{};
        strptime(s.data(), "%Y-%m-%d", &tm);

        //default values
        tm.tm_sec = 0; // seconds of minutes from 0 to 61
        tm.tm_min = 0; // minutes of hour from 0 to 59
        tm.tm_hour = 0; // hours of day from 0 to 24
        tm.tm_isdst = -1; // daylight saving

        std::string str = s.data();

        ulong start = 0, end = 0;
        start = str.find('P');
        end = str.find('Y');
        if(end != std::string::npos){
            start++;
            tm.tm_year = std::stoi(result[0].substr(start, end-1));
            start = end;
        }
        end = str.find('M');
        if(end != std::string::npos){
            start++;
            tm.tm_ = std::stoi(result[0].substr(start, end-1));
            start = end;
        }
        end = result[0].find('D');
        if(end != std::string::npos){
            start++;
            duration[d] = std::stoi(result[0].substr(start, end-1));
            start = end;
        }

        end = s.find('T');
        if(end != std::string::npos){

            end = result[1].find('H');
            if(end != std::string::npos){
                start++;
                duration[H] = std::stoi(result[1].substr(start, end-1));
                start = end;
            }

            end = result[1].find('M');
            if(end != std::string::npos){
                start++;
                duration[M] = std::stoi(result[1].substr(start, end-1));
                start = end;
            }

            end = result[1].find('S');
            if(end != std::string::npos){
                start++;
                duration[S] = std::stoi(result[1].substr(start, end-1));
                start = end;
            }
        }
        //return duration;

        time_t tm {};
        return tm;



        return mktime(&tm);
    } else {
        throw std::runtime_error("XSD Parsing Error");
    }
}
}  // namespace rdf4cpp::rdf::datatypes

#endif  //RDF4CPP_XSD_DURATION_HPP
