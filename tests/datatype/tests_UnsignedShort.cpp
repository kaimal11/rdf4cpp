#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype UnsignedShort") {

    uint16_t value = 1;
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::UnsignedShort, xsd_ushort>(value);
    CHECK(lit1.value<xsd::UnsignedShort, xsd_ushort>() == value);

    value = 0;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::UnsignedShort, xsd_ushort>(value);
    CHECK(lit2.value<xsd::UnsignedShort, xsd_ushort>() == value);

    value = 65535;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::UnsignedShort, xsd_ushort>(value);
    CHECK(lit3.value<xsd::UnsignedShort, xsd_ushort>() == value);

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::UnsignedShort, xsd_ushort>(value);
    CHECK(lit4.value<xsd::UnsignedShort, xsd_ushort>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);
    CHECK(lit1 == lit4);

    /*    value = 65536;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::UnsignedShort, xsd_ushort>(value);
    CHECK_THROWS_WITH_AS(lit4, "XSD Parsing Error", std::runtime_error);
    CHECK(lit4.value<xsd::UnsignedShort,xsd_ushort>() == value);

    value = -1;
    auto lit5 = rdf4cpp::rdf::Literal::make<xsd::UnsignedShort, xsd_ushort>(value);
    CHECK_THROWS_WITH_AS(lit5, "XSD Parsing Error", std::runtime_error);
    CHECK(lit5.value<xsd::UnsignedShort,xsd_ushort>() == value);*/
}
