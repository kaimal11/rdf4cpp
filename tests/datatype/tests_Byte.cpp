#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype Byte") {

    auto value = 1;
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::Byte, xsd_byte>(value);
    CHECK(lit1.value<xsd::Byte, xsd_byte>() == value);

    value = -128;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::Byte, xsd_byte>(value);
    CHECK(lit2.value<xsd::Byte, xsd_byte>() == value);

    value = 127;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::Byte, xsd_byte>(value);
    CHECK(lit3.value<xsd::Byte, xsd_byte>() == value);

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::Byte, xsd_byte>(value);
    CHECK(lit4.value<xsd::Byte, xsd_byte>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);

    if (lit1 == lit2) CHECK(false);
    else
        CHECK(true);

    if (lit1 == lit4) CHECK(true);
    else
        CHECK(false);

    /*    value = 129;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::Byte, xsd_byte>(value);
    CHECK_THROWS_WITH_AS(lit4, "XSD Parsing Error", std::runtime_error);
    CHECK(lit4.value<xsd::Byte,xsd_byte>() == value);

    value = -130;
    auto lit5 = rdf4cpp::rdf::Literal::make<xsd::Byte, xsd_byte>(value);
    CHECK_THROWS_WITH_AS(lit5, "XSD Parsing Error", std::runtime_error);
    CHECK(lit5.value<xsd::Byte,xsd_byte>() == value);*/
}
