#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype Token") {

    auto iri = rdf4cpp::rdf::IRI(RegisteredDatatype<xsd::Token, xsd_token>::datatype_iri());

    auto iri_str = rdf4cpp::rdf::IRI("http://www.w3.org/2001/XMLSchema#token");

    CHECK(iri == iri_str);

    std::string value = "12sdfs2df";
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::Token, xsd_token>(value);
    CHECK(lit1.value<xsd::Token, xsd_token>() == value);

    value = "sdfsdfwer56";
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::Token, xsd_token>(value);
    CHECK(lit2.value<xsd::Token, xsd_token>() == value);

    value = "12sdfs2df";
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::Token, xsd_token>(value);
    CHECK(lit3.value<xsd::Token, xsd_token>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);
    CHECK(lit1 == lit3);

    auto lit6 = rdf4cpp::rdf::Literal{"sdfsdf\n", iri};
    CHECK_THROWS_WITH_AS(lit6.value(), "XSD Parsing Error", std::runtime_error);

    auto lit7 = rdf4cpp::rdf::Literal{"sdfsdf\t", iri};
    CHECK_THROWS_WITH_AS(lit7.value(), "XSD Parsing Error", std::runtime_error);

    auto lit8 = rdf4cpp::rdf::Literal{"sdfsdf\r", iri};
    CHECK_THROWS_WITH_AS(lit8.value(), "XSD Parsing Error", std::runtime_error);
}

