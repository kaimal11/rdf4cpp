
/**
* @file Registers xsd:duration with DatatypeRegistry
*/

#ifndef RDF4CPP_XSD_DURATION_HPP
#define RDF4CPP_XSD_DURATION_HPP

#include <rdf4cpp/rdf/datatypes/registry/DatatypeMapping.hpp>
#include <rdf4cpp/rdf/datatypes/registry/LiteralDatatypeImpl.hpp>

#include <cstdint>
#include <ostream>
#include <regex>
#include <string>
#include <time.h>
namespace rdf4cpp::rdf::datatypes::registry {
/*
 * Name of the datatype. This is kept so that we won't need to type it over and over again.
 */
constexpr static registry::ConstexprString xsd_duration{"http://www.w3.org/2001/XMLSchema#duration"};

/**
 * Defines the mapping between the LiteralDatatype IRI and the C++ datatype.
 */
template<>
struct DatatypeMapping<xsd_duration> {
    using cpp_datatype = time_t;
};

/**
 * Specialisation of from_string template function.
 */
template<>
inline LiteralDatatypeImpl<xsd_duration>::cpp_type LiteralDatatypeImpl<xsd_duration>::from_string(std::string_view s) {

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

        struct tm tm {};

        //default values
        tm.tm_year = 0;    // year since 1900
        tm.tm_mon = 0;     // month of year from 0 to 11
        tm.tm_mday = 0;    // day
        tm.tm_sec = 0;     // seconds of minutes from 0 to 61
        tm.tm_min = 0;     // minutes of hour from 0 to 59
        tm.tm_hour = 0;    // hours of day from 0 to 24
        tm.tm_isdst = -1;  // daylight saving

        std::string str = s.data();

        ulong start = 0, end = 0;
        start = str.find('P');
        end = str.find('Y');
        if (end != std::string::npos) {
            start++;
            tm.tm_year = std::stoi(str.substr(start, end - start));
            start = end;
        }
        end = str.find('M');
        if (end != std::string::npos) {
            start++;
            tm.tm_mon = std::stoi(str.substr(start, end - start));
            start = end;
        }
        end = str.find('D');
        if (end != std::string::npos) {
            start++;
            tm.tm_mday = std::stoi(str.substr(start, end - start));
        }
        end = str.find('T');
        start = end;
        if (end != std::string::npos) {

            end = str.find('H');
            if (end != std::string::npos) {
                start++;
                tm.tm_hour = std::stoi(str.substr(start, end - start));
                start = end;
            }
            end = str.find('M', start);
            if (end != std::string::npos) {
                start++;
                tm.tm_min = std::stoi(str.substr(start, end - start));
                start = end;
            }
            end = str.find('S');
            if (end != std::string::npos) {
                start++;
                tm.tm_sec = std::stoi(str.substr(start, end - start));
            }
        }

        return mktime(&tm);
    } else {
        throw std::runtime_error("XSD Parsing Error");
    }
}

/**
 * Formats Duration based of rdf specification
 */
inline std::string fmt_duration(std::string duration, int value, char tag) {

    if (tag == 'T') duration.push_back(tag);
    if (value != 0) {
        switch (tag) {
            case 'H':
            case 'm':
            case 'S':
                if (duration.find('T') == std::string::npos) duration.push_back('T');
                break;
            default:
                break;
        }
        duration.append(std::to_string(value));  //Adds value to the duration
        duration.push_back(tag);                 //Adds identifier of the value
    }
    return duration;
}

/**
 * Specialisation of to_string template function.
 */
template<>
inline std::string LiteralDatatypeImpl<xsd_duration>::to_string(const cpp_type &value) {

    char ch[100];
    strftime(ch, 100, "P%YY%mM%dDT%HH%MM%SS", localtime(&value));

    std::string str(ch), duration{"P"};

    ulong start = 0, end = 0;
    start = str.find('P');
    end = str.find('Y');
    if (end != std::string::npos) {
        start++;
        duration = fmt_duration(duration, std::stoi(str.substr(start, end - start)) - 1900, 'Y');
        start = end;
    }
    end = str.find('M');
    if (end != std::string::npos) {
        start++;
        duration = fmt_duration(duration, std::stoi(str.substr(start, end - start)) - 1, 'M');
        start = end;
    }
    end = str.find('D');
    if (end != std::string::npos) {
        start++;
        duration = fmt_duration(duration, std::stoi(str.substr(start, end - start)), 'D');
    }
    end = str.find('T');
    if (end != std::string::npos) {
        start = end;
        end = str.find('H');
        if (end != std::string::npos) {
            start++;
            duration = fmt_duration(duration, std::stoi(str.substr(start, end - start)), 'H');
            start = end;
        }
        end = str.find('M', start);
        if (end != std::string::npos) {
            start++;
            duration = fmt_duration(duration, std::stoi(str.substr(start, end - start)), 'm');
            start = end;
        }
        end = str.find('S');
        if (end != std::string::npos) {
            start++;
            std::string text = str.substr(start, end - start);
            duration = fmt_duration(duration, std::stoi(str.substr(start, end - start)), 'S');
        }
    }

    std::transform(duration.begin(), duration.end(), duration.begin(), ::toupper);

    return duration;
}
}  // namespace rdf4cpp::rdf::datatypes::registry

namespace rdf4cpp::rdf::datatypes::xsd {
/**
 * Implementation of xsd::duration
 */
using Duration = registry::LiteralDatatypeImpl<registry::xsd_duration>;
}  // namespace rdf4cpp::rdf::datatypes::xsd

#endif  //RDF4CPP_XSD_DURATION_HPP
