#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype NegativeInteger") {

    int64_t value = -1;
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::NegativeInteger, xsd_negativeInteger>(value);
    CHECK(lit1.value<xsd::NegativeInteger, xsd_negativeInteger>() == value);

    value = -18446744073709;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::NegativeInteger, xsd_negativeInteger>(value);
    CHECK(lit2.value<xsd::NegativeInteger, xsd_negativeInteger>() == value);

    value = -2147483647;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::NegativeInteger, xsd_negativeInteger>(value);
    CHECK(lit3.value<xsd::NegativeInteger, xsd_negativeInteger>() == value);

    value = -1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::NegativeInteger, xsd_negativeInteger>(value);
    CHECK(lit4.value<xsd::NegativeInteger, xsd_negativeInteger>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);
    CHECK(lit1 == lit4);

    // testing == of Literals
    if (lit1 == lit4) CHECK(true);

    /*    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::NegativeInteger, xsd_negativeInteger>(value);
    CHECK_THROWS_WITH_AS(lit4, "XSD Parsing Error", std::runtime_error);
    CHECK(lit4.value<xsd::NegativeInteger,xsd_negativeInteger>() == value);

    value = -12.0555;
    auto lit5 = rdf4cpp::rdf::Literal::make<xsd::NegativeInteger, xsd_negativeInteger>(value);
    CHECK_THROWS_WITH_AS(lit5, "XSD Parsing Error", std::runtime_error);
    CHECK(lit5.value<xsd::NegativeInteger,xsd_negativeInteger>() == value);*/
}
