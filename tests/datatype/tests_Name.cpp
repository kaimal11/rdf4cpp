#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype Name") {

    auto iri = rdf4cpp::rdf::IRI(RegisteredDatatype<xsd::Name, xsd_Name>::datatype_iri());

    auto iri_str = rdf4cpp::rdf::IRI("http://www.w3.org/2001/XMLSchema#name");

    CHECK(iri == iri_str);

    std::string value = "Bob";
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::Name, xsd_Name>(value);
    CHECK(lit1.value<xsd::Name, xsd_Name>() == value);

    value = "Alice";
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::Name, xsd_Name>(value);
    CHECK(lit2.value<xsd::Name, xsd_Name>() == value);

    value = "Bob";
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::Name, xsd_Name>(value);
    CHECK(lit3.value<xsd::Name, xsd_Name>() == value);

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

