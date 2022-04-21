#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype HexBinary") {

    /*std::vector<std::byte> value = {std::byte{0x36}, std::byte{0xd0}};
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::HexBinary, xsd_integer>(value);
    CHECK(lit1.value<xsd::Integer, xsd_integer>() == value);

    value = -2147483648;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::Integer, xsd_integer>(value);
    CHECK(lit2.value<xsd::Integer, xsd_integer>() == value);

    value = 2147483647;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::Integer, xsd_integer>(value);
    CHECK(lit3.value<xsd::Integer, xsd_integer>() == value);

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::Integer, xsd_integer>(value);
    CHECK(lit4.value<xsd::Integer, xsd_integer>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);
    CHECK(lit1 == lit4);*/

    /*    value = 2147483649;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::Integer, xsd_integer>(value);
    CHECK_THROWS_WITH_AS(lit4, "XSD Parsing Error", std::runtime_error);
    CHECK(lit4.value<xsd::Integer,xsd_integer>() == value);

    value = -2147483649;
    auto lit5 = rdf4cpp::rdf::Literal::make<xsd::Integer, xsd_integer>(value);
    CHECK_THROWS_WITH_AS(lit5, "XSD Parsing Error", std::runtime_error);
    CHECK(lit5.value<xsd::Integer,xsd_integer>() == value);*/
}