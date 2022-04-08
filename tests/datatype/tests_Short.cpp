#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype Short") {

    auto value = 1;
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::Short, xsd_short>(value);
    CHECK(lit1.value<xsd::Short, xsd_short>() == value);

    value = -32768;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::Short, xsd_short>(value);
    CHECK(lit2.value<xsd::Short, xsd_short>() == value);

    value = 32767;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::Short, xsd_short>(value);
    CHECK(lit3.value<xsd::Short, xsd_short>() == value);

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::Short, xsd_short>(value);
    CHECK(lit4.value<xsd::Short, xsd_short>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);

    if (lit1 == lit2) CHECK(false);
    else
        CHECK(true);

    if (lit1 == lit4) CHECK(true);
    else
        CHECK(false);

    /*    value = 32768;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::Short, xsd_short>(value);
    CHECK_THROWS_WITH_AS(lit4, "XSD Parsing Error", std::runtime_error);
    CHECK(lit4.value<xsd::Short,xsd_short>() == value);

    value = -32769;
    auto lit5 = rdf4cpp::rdf::Literal::make<xsd::Short, xsd_short>(value);
    CHECK_THROWS_WITH_AS(lit5, "XSD Parsing Error", std::runtime_error);
    CHECK(lit5.value<xsd::Short,xsd_short>() == value);*/
}
