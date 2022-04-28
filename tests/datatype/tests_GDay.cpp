#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype GDay") {

    time_t value;
    struct tm tm{};

    // Fill in values for GDay
    tm.tm_mday = 22;
    value = mktime(&tm);

    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::GDay, xsd_gDay>(value);
    CHECK(lit1.value<xsd::GDay, xsd_gDay>() == value);

    // Fill in values for GDay
    tm.tm_mday = 21;
    value = mktime(&tm);

    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::GDay, xsd_gDay>(value);
    CHECK(lit2.value<xsd::GDay, xsd_gDay>() == value);

    // Fill in values for GDay
    tm.tm_mday = 22;
    value = mktime(&tm);

    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::GDay, xsd_gDay>(value);
    CHECK(lit3.value<xsd::GDay, xsd_gDay>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);
    CHECK(lit1 == lit3);

}