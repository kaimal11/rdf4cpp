#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype Decimal") {

    double value = 1.00;
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::Decimal, xsd_decimal>(value);
    CHECK(lit1.value<xsd::Decimal, xsd_decimal>() == value);

    value = 64582165456988.235046;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::Decimal, xsd_decimal>(value);
    CHECK(lit2.value<xsd::Decimal, xsd_decimal>() == value);

    value = -64524654389.2345650;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::Decimal, xsd_decimal>(value);
    CHECK(lit3.value<xsd::Decimal, xsd_decimal>() == value);

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::Decimal, xsd_decimal>(value);
    CHECK(lit4.value<xsd::Decimal, xsd_decimal>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);

    if (lit1 == lit2) CHECK(false);
    else
        CHECK(true);

    if (lit1 == lit4) CHECK(true);
    else
        CHECK(false);

    /*    value = 4294967296.2446;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::Decimal, xsd_decimal>(value);
    CHECK_THROWS_WITH_AS(lit4, "XSD Parsing Error", std::runtime_error);
    CHECK(lit4.value<xsd::Decimal,xsd_decimal>() == value);

    value = -4294967296.24886;
    auto lit5 = rdf4cpp::rdf::Literal::make<xsd::Decimal, xsd_decimal>(value);
    CHECK_THROWS_WITH_AS(lit5, "XSD Parsing Error", std::runtime_error);
    CHECK(lit5.value<xsd::Decimal,xsd_decimal>() == value);*/
}