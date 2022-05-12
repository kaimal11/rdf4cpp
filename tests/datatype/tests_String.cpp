#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype String") {

    std::string value = "123";
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::String, xsd_string>(value);
    CHECK(lit1.value<xsd::String, xsd_string>() == value);
    CHECK(lit1.lexical_form() == value);

    value = "a";
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::String, xsd_string>(value);
    CHECK(lit2.value<xsd::String, xsd_string>() == value);
    CHECK(lit2.lexical_form() == value);

    value = "b";
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::String, xsd_string>(value);
    CHECK(lit3.value<xsd::String, xsd_string>() == value);
    CHECK(lit3.lexical_form() == value);

    value = "123";
    auto lit4 = rdf4cpp::rdf::Literal{value, "http://www.w3.org/2001/XMLSchema#string"};
    CHECK(lit4.value<xsd::String, xsd_string>() == value);

    value = "a";
    auto lit5 = rdf4cpp::rdf::Literal{value, "http://www.w3.org/2001/XMLSchema#string"};
    CHECK(lit5.value<xsd::String, xsd_string>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);
    CHECK(lit1 == lit4);
    CHECK(lit2 == lit5);
}

