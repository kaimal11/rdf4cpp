#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype UnsignedByte") {

    uint8_t value = 1;
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::UnsignedByte, xsd_ubyte>(value);
    std::cout << lit1.value<xsd::UnsignedByte, xsd_ubyte>() << std::endl;
    CHECK(lit1.value<xsd::UnsignedByte, xsd_ubyte>() == value);

    value = 0;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::UnsignedByte, xsd_ubyte>(value);
    CHECK(lit2.value<xsd::UnsignedByte, xsd_ubyte>() == value);

    value = 255;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::UnsignedByte, xsd_ubyte>(value);
    CHECK(lit3.value<xsd::UnsignedByte, xsd_ubyte>() == value);

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::UnsignedByte, xsd_ubyte>(value);
    CHECK(lit4.value<xsd::UnsignedByte, xsd_ubyte>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);
    CHECK(lit1 == lit4);

    /*    value = 256;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::UnsignedByte, xsd_ubyte>(value);
    CHECK_THROWS_WITH_AS(lit4, "XSD Parsing Error", std::runtime_error);
    CHECK(lit4.value<xsd::UnsignedByte,xsd_ubyte>() == value);

    value = -1;
    auto lit5 = rdf4cpp::rdf::Literal::make<xsd::UnsignedByte, xsd_ubyte>(value);
    CHECK_THROWS_WITH_AS(lit5, "XSD Parsing Error", std::runtime_error);
    CHECK(lit5.value<xsd::UnsignedByte,xsd_ubyte>() == value);*/
}
