#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype Date") {

    auto iri = rdf4cpp::rdf::IRI("http://www.w3.org/2001/XMLSchema#date");

    time_t value;
    struct tm tm{};

    // Fill in values for Date
    tm.tm_sec = 0; // seconds of minutes from 0 to 61
    tm.tm_min = 0; // minutes of hour from 0 to 59
    tm.tm_hour = 0; // hours of day from 0 to 24
    tm.tm_year = 2022 - 1900; // year since 1900
    tm.tm_mon = 4 - 1; // month of year from 0 to 11
    tm.tm_mday = 22;
    tm.tm_isdst = -1; // value should be set even if not used
    value = mktime(&tm);

    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::Date, xsd_date>(value);
    CHECK(lit1.value<xsd::Date, xsd_date>() == value);

    // Fill in values for Date
    tm.tm_sec = 0; // seconds of minutes from 0 to 61
    tm.tm_min = 0; // minutes of hour from 0 to 59
    tm.tm_hour = 0; // hours of day from 0 to 24
    tm.tm_year = 2022 - 1900; // year since 1900
    tm.tm_mon = 5 - 1; // month of year from 0 to 11
    tm.tm_mday = 21;
    tm.tm_isdst = -1; // value should be set even if not used
    value = mktime(&tm);

    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::Date, xsd_date>(value);
    CHECK(lit2.value<xsd::Date, xsd_date>() == value);

    // Fill in values for Date
    tm.tm_sec = 0; // seconds of minutes from 0 to 61
    tm.tm_min = 0; // minutes of hour from 0 to 59
    tm.tm_hour = 0; // hours of day from 0 to 24
    tm.tm_year = 2022 - 1900; // year since 1900
    tm.tm_mon = 4 - 1; // month of year from 0 to 11
    tm.tm_mday = 22;
    tm.tm_isdst = -1; // value should be set even if not used
    value = mktime(&tm);

    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::Date, xsd_date>(value);
    CHECK(lit3.value<xsd::Date, xsd_date>() == value);
    std::cout<< lit3;

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);
    CHECK(lit1 == lit3);

    auto lit4 = rdf4cpp::rdf::Literal{"22-04-2022", iri};
    CHECK_THROWS_WITH_AS(lit4.value(), "XSD Parsing Error", std::runtime_error);
}