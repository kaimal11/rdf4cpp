#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype GYearMonth") {

    time_t value;
    struct tm tm{};

    // Fill in values for GYearMonth
    tm.tm_year = 2022 - 1900; // year since 1900
    tm.tm_mon = 5 - 1; // month of year from 0 to 11
    value = mktime(&tm);

    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::GYearMonth, xsd_gYearMonth>(value);
    CHECK(lit1.value<xsd::GYearMonth, xsd_gYearMonth>() == value);

    // Fill in values for GYearMonth
    tm.tm_year = 2022 - 1900; // year since 1900
    tm.tm_mon = 4 - 1; // month of year from 0 to 11
    value = mktime(&tm);

    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::GYearMonth, xsd_gYearMonth>(value);
    CHECK(lit2.value<xsd::GYearMonth, xsd_gYearMonth>() == value);

    // Fill in values for GYearMonth
    tm.tm_year = 2022 - 1900; // year since 1900
    tm.tm_mon = 5 - 1; // month of year from 0 to 11
    value = mktime(&tm);

    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::GYearMonth, xsd_gYearMonth>(value);
    CHECK(lit3.value<xsd::GYearMonth, xsd_gYearMonth>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);
    CHECK(lit1 == lit3);

}