#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype String") {

    std::string value = "123";
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::String, xsd_string>(value);
    CHECK(lit1.value<xsd::String, xsd_string>() == value);

    value = "a";
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::String, xsd_string>(value);
    CHECK(lit2.value<xsd::String, xsd_string>() == value);

    value = "b";
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::String, xsd_string>(value);
    CHECK(lit3.value<xsd::String, xsd_string>() == value);

    value = "123";
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::String, xsd_string>(value);
    CHECK(lit4.value<xsd::String, xsd_string>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);
    CHECK(lit1 == lit4);

    // testing == of Literals
    if (lit1 == lit4) CHECK(true);

    /*    value = 22;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::String, xsd_string>(value);
    CHECK_THROWS_WITH_AS(lit4, "XSD Parsing Error", std::runtime_error);
    CHECK(lit4.value<xsd::String,xsd_string>() == value);

    value = -1;
    auto lit5 = rdf4cpp::rdf::Literal::make<xsd::String, xsd_string>(value);
    CHECK_THROWS_WITH_AS(lit5, "XSD Parsing Error", std::runtime_error);
    CHECK(lit5.value<xsd::String,xsd_string>() == value);*/
}

