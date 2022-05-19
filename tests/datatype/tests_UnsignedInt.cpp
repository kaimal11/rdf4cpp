#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype UnsignedInt") {

    auto iri = rdf4cpp::rdf::IRI("http://www.w3.org/2001/XMLSchema#unsignedint");

    uint32_t value = 1;
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::UnsignedInt, xsd_uint>(value);
    CHECK(lit1.value<xsd::UnsignedInt, xsd_uint>() == value);
    CHECK(lit1.lexical_form() == std::to_string(value));

    value = 0;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::UnsignedInt, xsd_uint>(value);
    CHECK(lit2.value<xsd::UnsignedInt, xsd_uint>() == value);
    CHECK(lit2.lexical_form() == std::to_string(value));

    value = 4294967295;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::UnsignedInt, xsd_uint>(value);
    CHECK(lit3.value<xsd::UnsignedInt, xsd_uint>() == value);
    CHECK(lit3.lexical_form() == std::to_string(value));

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal{std::to_string(value), iri};
    CHECK(lit4.value<xsd::UnsignedInt, xsd_uint>() == value);

    value = 0;
    auto lit5 = rdf4cpp::rdf::Literal{std::to_string(value), iri};
    CHECK(lit5.value<xsd::UnsignedInt, xsd_uint>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);
    CHECK(lit1 == lit4);
    CHECK(lit2 == lit5);

    auto lit6 = rdf4cpp::rdf::Literal{"4294967296", iri};
    CHECK_THROWS_WITH_AS(lit6.value(), "XSD Parsing Error", std::runtime_error);

    auto lit7 = rdf4cpp::rdf::Literal{"-1", iri};
    CHECK_THROWS_WITH_AS(lit7.value(), "XSD Parsing Error", std::runtime_error);
}
