#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype GMonthDay") {

    time_t value;
    struct tm tm{};

    // Fill in values for GMonthDay
    tm.tm_sec = 0; // seconds of minutes from 0 to 61
    tm.tm_min = 0; // minutes of hour from 0 to 59
    tm.tm_hour = 0; // hours of day from 0 to 24
    tm.tm_year = 1900; // year since 1900
    tm.tm_mon = 5 - 1; // month of year from 0 to 11
    tm.tm_mday = 1; // date of the month
    tm.tm_isdst = -1; // value should be set even if not used
    value = mktime(&tm);

    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::GMonthDay, xsd_gMonthDay>(value);
    CHECK(lit1.value<xsd::GMonthDay, xsd_gMonthDay>() == value);

    // Fill in values for GMonthDay
    tm.tm_sec = 0; // seconds of minutes from 0 to 61
    tm.tm_min = 0; // minutes of hour from 0 to 59
    tm.tm_hour = 0; // hours of day from 0 to 24
    tm.tm_year = 1900; // year since 1900
    tm.tm_mon = 5 - 1; // month of year from 0 to 11
    tm.tm_mday = 31; // date of the month
    tm.tm_isdst = -1; // value should be set even if not used
    value = mktime(&tm);

    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::GMonthDay, xsd_gMonthDay>(value);
    CHECK(lit2.value<xsd::GMonthDay, xsd_gMonthDay>() == value);

    // Fill in values for GMonthDay
    tm.tm_sec = 0; // seconds of minutes from 0 to 61
    tm.tm_min = 0; // minutes of hour from 0 to 59
    tm.tm_hour = 0; // hours of day from 0 to 24
    tm.tm_year = 1900; // year since 1900
    tm.tm_mon = 5 - 1; // month of year from 0 to 11
    tm.tm_mday = 1; // date of the month
    tm.tm_isdst = -1; // value should be set even if not used
    value = mktime(&tm);

    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::GMonthDay, xsd_gMonthDay>(value);
    CHECK(lit3.value<xsd::GMonthDay, xsd_gMonthDay>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);
    CHECK(lit1 == lit3);

}