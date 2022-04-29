#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype GDay") {

    time_t value;
    struct tm tm{};

    // Fill in values for GDay
    tm.tm_sec = 0; // seconds of minutes from 0 to 61
    tm.tm_min = 0; // minutes of hour from 0 to 59
    tm.tm_hour = 0; // hours of day from 0 to 24
    tm.tm_year = 1900; // year since 1900
    tm.tm_mon = 0; // month of year from 0 to 11
    tm.tm_mday = 22; // date of the month
    tm.tm_isdst = -1; // value should be set even if not used
    value = mktime(&tm);

    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::GDay, xsd_gDay>(value);
    CHECK(lit1.value<xsd::GDay, xsd_gDay>() == value);

    // Fill in values for GDay
    tm.tm_sec = 0; // seconds of minutes from 0 to 61
    tm.tm_min = 0; // minutes of hour from 0 to 59
    tm.tm_hour = 0; // hours of day from 0 to 24
    tm.tm_year = 1900; // year since 1900
    tm.tm_mon = 0; // month of year from 0 to 11
    tm.tm_mday = 21;
    tm.tm_isdst = -1; // value should be set even if not used
    value = mktime(&tm);

    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::GDay, xsd_gDay>(value);
    CHECK(lit2.value<xsd::GDay, xsd_gDay>() == value);

    // Fill in values for GDay
    tm.tm_sec = 0; // seconds of minutes from 0 to 61
    tm.tm_min = 0; // minutes of hour from 0 to 59
    tm.tm_hour = 0; // hours of day from 0 to 24
    tm.tm_year = 1900; // year since 1900
    tm.tm_mon = 0; // month of year from 0 to 11
    tm.tm_mday = 22; //date of the month
    tm.tm_isdst = -1; // value should be set even if not used
    value = mktime(&tm);

    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::GDay, xsd_gDay>(value);
    CHECK(lit3.value<xsd::GDay, xsd_gDay>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);
    CHECK(lit1 == lit3);

}