#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype UnsignedLong") {

    u_int64_t value = 1;
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::UnsignedLong, xsd_ulong>(value);
    CHECK(lit1.value<xsd::UnsignedLong, xsd_ulong>() == value);

    value = 0;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::UnsignedLong, xsd_ulong>(value);
    CHECK(lit2.value<xsd::UnsignedLong, xsd_ulong>() == value);

    value = 18446744073709551615;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::UnsignedLong, xsd_ulong>(value);
    CHECK(lit3.value<xsd::UnsignedLong, xsd_ulong>() == value);

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::UnsignedLong, xsd_ulong>(value);
    CHECK(lit4.value<xsd::UnsignedLong, xsd_ulong>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);
    CHECK(lit1 == lit4);

    /*    value = 18446744073709551616;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::UnsignedLong, xsd_ulong>(value);
    CHECK_THROWS_WITH_AS(lit4, "XSD Parsing Error", std::runtime_error);
    CHECK(lit4.value<xsd::UnsignedLong,xsd_ulong>() == value);

    value = -1;
    auto lit5 = rdf4cpp::rdf::Literal::make<xsd::UnsignedLong, xsd_ulong>(value);
    CHECK_THROWS_WITH_AS(lit5, "XSD Parsing Error", std::runtime_error);
    CHECK(lit5.value<xsd::UnsignedLong,xsd_ulong>() == value);*/
}
