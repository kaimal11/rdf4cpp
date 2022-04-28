#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype Time") {

    time_t value;
    struct tm tm{};

    // Fill in values for Time
    tm.tm_sec = 1; // seconds of minutes from 0 to 61
    tm.tm_min = 21; // minutes of hour from 0 to 59
    tm.tm_hour = 10; // hours of day from 0 to 24
    value = mktime(&tm);

    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::Time, xsd_time>(value);
    CHECK(lit1.value<xsd::Time, xsd_time>() == value);

    // Fill in values for Time
    tm.tm_sec = 6; // seconds of minutes from 0 to 61
    tm.tm_min = 20; // minutes of hour from 0 to 59
    tm.tm_hour = 10; // hours of day from 0 to 24
    value = mktime(&tm);

    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::Time, xsd_time>(value);
    CHECK(lit2.value<xsd::Date, xsd_time>() == value);

    // Fill in values for Time
    tm.tm_sec = 61; // seconds of minutes from 0 to 61
    tm.tm_min = 20; // minutes of hour from 0 to 59
    tm.tm_hour = 10; // hours of day from 0 to 24
    value = mktime(&tm);

    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::Time, xsd_time>(value);
    CHECK(lit3.value<xsd::Time, xsd_time>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);
    CHECK(lit1 == lit3);

    std::cout<< "lit1:" << lit1 <<"\n";
    std::cout<< "lit2:" << lit3 <<"\n";

}