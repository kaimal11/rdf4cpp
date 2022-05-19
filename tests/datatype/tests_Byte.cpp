#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype Byte") {

    auto iri = "http://www.w3.org/2001/XMLSchema#byte";

    auto value = 1;
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::Byte, xsd_byte>(value);
    CHECK(lit1.value<xsd::Byte, xsd_byte>() == value);
    CHECK(lit1.lexical_form() == std::to_string(value));

    value = -128;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::Byte, xsd_byte>(value);
    CHECK(lit2.value<xsd::Byte, xsd_byte>() == value);
    CHECK(lit1.lexical_form() == std::to_string(value));

    value = 127;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::Byte, xsd_byte>(value);
    CHECK(lit3.value<xsd::Byte, xsd_byte>() == value);
    CHECK(lit1.lexical_form() == std::to_string(value));

/*    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::Byte, xsd_byte>(value);
    CHECK(lit4.value<xsd::Byte, xsd_byte>() == value);*/

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal{std::to_string(value), iri};
    CHECK(lit4.value<xsd::Byte, xsd_byte>() == value);

    value = 127;
    auto lit5 = rdf4cpp::rdf::Literal{std::to_string(value), iri};
    CHECK(lit5.value<xsd::Byte, xsd_byte>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);
    CHECK(lit1 == lit4);
    CHECK(lit3 == lit5);

    auto lit6 = rdf4cpp::rdf::Literal{"139", iri};
    CHECK_THROWS_WITH_AS(lit6.value(), "XSD Parsing Error", std::runtime_error);

    auto lit7 = rdf4cpp::rdf::Literal{"-130", iri};
    CHECK_THROWS_WITH_AS(lit7.value(), "XSD Parsing Error", std::runtime_error);
}
