#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype GYear") {

    time_t value;
    struct tm tm{};

    // Fill in values for GYear
    tm.tm_year = 2022 - 1900; // year since 1900
    value = mktime(&tm);

    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::GYear, xsd_gYear>(value);
    CHECK(lit1.value<xsd::GYear, xsd_gYear>() == value);

    // Fill in values for GYear
    tm.tm_year = 2021 - 1900; // year since 1900
    value = mktime(&tm);

    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::GYear, xsd_gYear>(value);
    CHECK(lit2.value<xsd::GYear, xsd_gYear>() == value);

    // Fill in values for GYear
    tm.tm_year = 2022 - 1900; // year since 1900
    value = mktime(&tm);

    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::GYear, xsd_gYear>(value);
    CHECK(lit3.value<xsd::GYear, xsd_gYear>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);
    CHECK(lit1 == lit3);

}