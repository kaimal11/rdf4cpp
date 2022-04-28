#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype Int") {

    auto value = 1;
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::Int, xsd_int>(value);
    CHECK(lit1.value<xsd::Int, xsd_int>() == value);

    value = -2147483648;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::Int, xsd_int>(value);
    CHECK(lit2.value<xsd::Int, xsd_int>() == value);

    value = 2147483647;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::Int, xsd_int>(value);
    CHECK(lit3.value<xsd::Int, xsd_int>() == value);

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::Int, xsd_int>(value);
    CHECK(lit4.value<xsd::Int, xsd_int>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);
    CHECK(lit1 == lit4);

    auto er_value = 2147483649;
    auto lit5 = rdf4cpp::rdf::Literal::make<xsd::Int, xsd_int>(er_value);
    //CHECK_THROWS_WITH_AS(auto x = lit5.value<xsd::Int,xsd_int>(), "XSD Parsing Error", std::runtime_error);
    CHECK(lit5.value<xsd::Int,xsd_int>() == er_value);

    er_value = -2147483649;
    auto lit6 = rdf4cpp::rdf::Literal::make<xsd::Int, xsd_int>(er_value);
    //CHECK_THROWS_WITH_AS(lit6, "XSD Parsing Error", std::runtime_error);
    CHECK(lit6.value<xsd::Int,xsd_int>() == er_value);
}
