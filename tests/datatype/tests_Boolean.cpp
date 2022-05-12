#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype Boolean") {

    bool value = true;
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::Boolean, xsd_boolean>(value);
    CHECK(lit1.value<xsd::Boolean, xsd_boolean>() == value);
    CHECK(lit1.lexical_form() == std::to_string(value));

    value = false;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::Boolean, xsd_boolean>(value);
    CHECK(lit2.value<xsd::Boolean, xsd_boolean>() == value);
    CHECK(lit2.lexical_form() == std::to_string(value));

    value = 1;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::Boolean, xsd_boolean>(value);
    CHECK(lit3.value<xsd::Boolean, xsd_boolean>() == value);
    CHECK(lit3.lexical_form() == std::to_string(value));

    value = 0;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::Boolean, xsd_boolean>(value);
    CHECK(lit4.value<xsd::Boolean, xsd_boolean>() == value);

    value = true;
    auto lit5 = rdf4cpp::rdf::Literal{std::to_string(value), "http://www.w3.org/2001/XMLSchema#boolean"};
    CHECK(lit5.value<xsd::Boolean, xsd_boolean>() == value);

    value = false;
    auto lit6 = rdf4cpp::rdf::Literal{std::to_string(value), "http://www.w3.org/2001/XMLSchema#boolean"};
    CHECK(lit6.value<xsd::Boolean, xsd_boolean>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);
    CHECK(lit1 == lit3);
    CHECK(lit2 == lit4);
    CHECK(lit1 == lit5);
    CHECK(lit2 == lit6);
    CHECK(lit3 == lit5);
    CHECK(lit4 == lit6);

/*    auto er_value = 22;
    auto lit5 = rdf4cpp::rdf::Literal::make<xsd::Boolean, xsd_boolean>(er_value);
    //CHECK_THROWS_WITH_AS(lit5, "XSD Parsing Error", std::runtime_error);
    CHECK(lit5.value<xsd::Boolean,xsd_boolean>() == er_value);

    er_value = -1;
    auto lit6 = rdf4cpp::rdf::Literal::make<xsd::Boolean, xsd_boolean>(er_value);
    //CHECK_THROWS_WITH_AS(lit6, "XSD Parsing Error", std::runtime_error);
    CHECK(lit6.value<xsd::Boolean,xsd_boolean>() == er_value);*/
}