#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype Short") {

    auto iri = rdf4cpp::rdf::IRI(RegisteredDatatype<xsd::Short, xsd_short>::datatype_iri());

    auto iri_str = rdf4cpp::rdf::IRI("http://www.w3.org/2001/XMLSchema#short");

    CHECK(iri == iri_str);

    auto value = 1;
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::Short, xsd_short>(value);
    CHECK(lit1.value<xsd::Short, xsd_short>() == value);
    CHECK(lit1.lexical_form() == std::to_string(value));

    value = -32768;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::Short, xsd_short>(value);
    CHECK(lit2.value<xsd::Short, xsd_short>() == value);
    CHECK(lit2.lexical_form() == std::to_string(value));

    value = 32767;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::Short, xsd_short>(value);
    CHECK(lit3.value<xsd::Short, xsd_short>() == value);
    CHECK(lit3.lexical_form() == std::to_string(value));

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal{std::to_string(value), iri};
    CHECK(lit4.value<xsd::Short, xsd_short>() == value);

    value = -32768;
    auto lit5 = rdf4cpp::rdf::Literal{std::to_string(value), iri};
    CHECK(lit5.value<xsd::Short, xsd_short>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);
    CHECK(lit1 == lit4);
    CHECK(lit2 == lit5);

    auto lit6 = rdf4cpp::rdf::Literal{"32768", iri};
    CHECK_THROWS_WITH_AS(lit6.value(), "XSD Parsing Error", std::runtime_error);

    auto lit7 = rdf4cpp::rdf::Literal{"-32769", iri};
    CHECK_THROWS_WITH_AS(lit7.value(), "XSD Parsing Error", std::runtime_error);
}
