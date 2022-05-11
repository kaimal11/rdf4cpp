#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype Float") {

    float value = 1.00;
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::Float, xsd_float>(value);
    CHECK(lit1.value<xsd::Float, xsd_float>() == value);

    value = 32568.2350;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::Float, xsd_float>(value);
    CHECK(lit2.value<xsd::Float, xsd_float>() == value);

    value = -14523.2350;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::Float, xsd_float>(value);
    CHECK(lit3.value<xsd::Float, xsd_float>() == value);

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::Float, xsd_float>(value);
    CHECK(lit4.value<xsd::Float, xsd_float>() == value);

    value = std::numeric_limits<float>::min();
    auto lit5 = rdf4cpp::rdf::Literal::make<xsd::Float, xsd_float>(value);
    CHECK(lit5.value<xsd::Float, xsd_float>() == value);

    value = std::numeric_limits<float>::max();;
    auto lit6 = rdf4cpp::rdf::Literal::make<xsd::Float, xsd_float>(value);
    CHECK(lit6.value<xsd::Float, xsd_float>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);
    CHECK(lit1 == lit4);

    /*    value = 4294967296;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::Float, xsd_float>(value);
    CHECK_THROWS_WITH_AS(lit4, "XSD Parsing Error", std::runtime_error);
    CHECK(lit4.value<xsd::Float,xsd_float>() == value);

    value = -4294967296;
    auto lit5 = rdf4cpp::rdf::Literal::make<xsd::Float, xsd_float>(value);
    CHECK_THROWS_WITH_AS(lit5, "XSD Parsing Error", std::runtime_error);
    CHECK(lit5.value<xsd::Float,xsd_float>() == value);*/
}