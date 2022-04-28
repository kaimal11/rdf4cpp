#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype YearMonthDuration") {

    time_t value;
    struct tm tm{};

    // Fill in values for YearMonthDuration
    tm.tm_year = 2022 - 1900; // year since 1900
    tm.tm_mon = 4 - 1; // month of year from 0 to 11
    value = mktime(&tm);

    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::YearMonthDuration, xsd_yearMonthDuration>(value);
    CHECK(lit1.value<xsd::YearMonthDuration, xsd_yearMonthDuration>() == value);

    // Fill in values for YearMonthDuration
    tm.tm_year = 2022 - 1900; // year since 1900
    tm.tm_mon = 5 - 1; // month of year from 0 to 11
    value = mktime(&tm);

    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::YearMonthDuration, xsd_yearMonthDuration>(value);
    CHECK(lit2.value<xsd::YearMonthDuration, xsd_yearMonthDuration>() == value);

    // Fill in values for YearMonthDuration
    tm.tm_year = 2022 - 1900; // year since 1900
    tm.tm_mon = 4 - 1; // month of year from 0 to 11
    value = mktime(&tm);

    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::YearMonthDuration, xsd_yearMonthDuration>(value);
    CHECK(lit3.value<xsd::YearMonthDuration, xsd_yearMonthDuration>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);
    CHECK(lit1 == lit3);

}