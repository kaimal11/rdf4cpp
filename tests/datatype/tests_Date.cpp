#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype Date") {

    time_t value;
    struct tm tm{};

    // Fill in values for Date
    tm.tm_year = 2022 - 1900; // year since 1900
    tm.tm_mon = 4 - 1; // month of year from 0 to 11
    tm.tm_mday = 22;
    value = mktime(&tm);

    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::Date, xsd_date>(value);
    CHECK(lit1.value<xsd::Date, xsd_date>() == value);

    // Fill in values for Date
    tm.tm_year = 2022 - 1900; // year since 1900
    tm.tm_mon = 5 - 1; // month of year from 0 to 11
    tm.tm_mday = 21;
    value = mktime(&tm);

    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::Date, xsd_date>(value);
    CHECK(lit2.value<xsd::Date, xsd_date>() == value);

    // Fill in values for Date
    tm.tm_year = 2022 - 1900; // year since 1900
    tm.tm_mon = 4 - 1; // month of year from 0 to 11
    tm.tm_mday = 22;
    value = mktime(&tm);

    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::Date, xsd_date>(value);
    CHECK(lit3.value<xsd::Date, xsd_date>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);
    CHECK(lit1 == lit3);

}