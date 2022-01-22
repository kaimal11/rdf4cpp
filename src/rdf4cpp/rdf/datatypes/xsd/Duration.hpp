
#ifndef RDF4CPP_DURATION_HPP
#define RDF4CPP_DURATION_HPP

#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <ostream>
#include <rdf4cpp/rdf/datatypes/DatatypeRegistry.hpp>
#include <regex>
#include <vector>
#include <sstream>

namespace rdf4cpp::rdf::datatypes::xsd {
using Duration = time_t;  //!< Implements <a href="http://www.w3.org/2001/XMLSchema#duration">xsd:duration</a>
}

namespace rdf4cpp::rdf::datatypes {

constexpr const char xsd_duration[] = "http://www.w3.org/2001/XMLSchema#duration";

template<>
inline xsd::Duration RegisteredDatatype<xsd::Duration , xsd_duration>::from_string(const std::string &s) {
    const std::regex duration_regex("-?P((([0-9]+Y([0-9]+M)?([0-9]+D)?"
                                      "|([0-9]+M)([0-9]+D)?"
                                      "|([0-9]+D))"
                                      "(T(([0-9]+H)([0-9]+M)?([0-9]+(\\.[0-9]+)?S)?"
                                      "|([0-9]+M)([0-9]+(\\.[0-9]+)?S)?"
                                      "|([0-9]+(\\.[0-9]+)?S)))?)"
                                      "|(T(([0-9]+H)([0-9]+M)?([0-9]+(\\.[0-9]+)?S)?"
                                      "|([0-9]+M)([0-9]+(\\.[0-9]+)?S)?"
                                      "|([0-9]+(\\.[0-9]+)?S))))");
    if (std::regex_match(s, duration_regex)) {

        std::vector<std::string> result;
        std::stringstream ss (s);
        std::string item;

        while (getline (ss, item, 'T')) {
            result.push_back (item);
        }

        char *fmt = "P";
        bool first = true;
        if(s.find('Y')){
            first = false;
            strcat(fmt, "%Y");
        }
        if(s.find('M')){
            auto str = "%m";
            if(!first){
                str = "-%m";
            }
            first = false;
            strcat(fmt, str);
        }
        if(s.find('D')){
            auto str = "%d";
            if(!first){
                str = "-%d";
            }
            first = false;
            strcat(fmt, str);
        }

        strcat(fmt, "T");
        first = true;

        if(s.find('H')){
            strcat(fmt, "%H");
        }
        if(s.find('M')){
            auto str = "%M";
            if(!first){
                str = "-%M";
            }
            first = false;
            strcat(fmt, str);
        }
        if(s.find('S')){
            auto str = "%S";
            if(!first){
                str = "-%S";
            }
            first = false;
            strcat(fmt, str);
        }

        tm tm{};
        strptime(s.c_str(), fmt, &tm);

        return mktime(&tm);

    } else {
        throw std::runtime_error("XSD Parsing Error");
    }
}
}  // namespace rdf4cpp::rdf::datatypes

#endif  //RDF4CPP_DURATION_HPP
