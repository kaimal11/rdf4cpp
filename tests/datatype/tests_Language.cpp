#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype Language") {

    std::string value = "en";
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::Language, xsd_language>(value);
    CHECK(lit1.value<xsd::Language, xsd_language>() == value);
    CHECK(lit1.lexical_form() == value);

    value = "de";
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::Language, xsd_language>(value);
    CHECK(lit2.value<xsd::Language, xsd_language>() == value);
    CHECK(lit2.lexical_form() == value);

    value = "xx";
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::Language, xsd_language>(value);
    CHECK(lit3.value<xsd::Language, xsd_language>() == value);
    CHECK(lit3.lexical_form() == value);

    value = "en";
    auto lit4 = rdf4cpp::rdf::Literal{value, "http://www.w3.org/2001/XMLSchema#language"};
    CHECK(lit4.value<xsd::Language, xsd_language>() == value);

    value = "de";
    auto lit5 = rdf4cpp::rdf::Literal{value, "http://www.w3.org/2001/XMLSchema#language"};
    CHECK(lit5.value<xsd::Language, xsd_language>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);
    CHECK(lit1 == lit4);
    CHECK(lit2 == lit5);

/*    auto lit7 = rdf4cpp::rdf::Literal{"sdfsdf\n", "http://www.w3.org/2001/XMLSchema#int"};
    CHECK_THROWS_WITH_AS(lit7.value(), "XSD Parsing Error", std::runtime_error);*/
}

