#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype Long") {

    long value = 1;
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::Long, xsd_long>(value);
    CHECK(lit1.value<xsd::Long, xsd_long>() == value);

    value = -9223372036854775808;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::Long, xsd_long>(value);
    CHECK(lit2.value<xsd::Long, xsd_long>() == value);

    value = 9223372036854775807;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::Long, xsd_long>(value);
    CHECK(lit3.value<xsd::Long, xsd_long>() == value);

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::Long, xsd_long>(value);
    CHECK(lit4.value<xsd::Long, xsd_long>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);
    CHECK(lit1 == lit4);

    // testing == of Literals
    if (lit1 == lit4) CHECK(true);

    /*    value = 9223372036854775809;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::Long, xsd_long>(value);
    CHECK_THROWS_WITH_AS(lit4, "XSD Parsing Error", std::runtime_error);
    CHECK(lit4.value<xsd::Long,xsd_long>() == value);

    value = -9223372036854775809;
    auto lit5 = rdf4cpp::rdf::Literal::make<xsd::Long, xsd_long>(value);
    CHECK_THROWS_WITH_AS(lit5, "XSD Parsing Error", std::runtime_error);
    CHECK(lit5.value<xsd::Long,xsd_long>() == value);*/
}
