#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype Int") {

    auto value = 1;
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::Int, xsd_int>(value);
    CHECK(lit1.value<xsd::Int, xsd_int>() == value);
    CHECK(lit1.lexical_form() == std::to_string(value));

    value = -2147483648;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::Int, xsd_int>(value);
    CHECK(lit2.value<xsd::Int, xsd_int>() == value);
    CHECK(lit2.lexical_form() == std::to_string(value));

    value = 2147483647;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::Int, xsd_int>(value);
    CHECK(lit3.value<xsd::Int, xsd_int>() == value);
    CHECK(lit3.lexical_form() == std::to_string(value));

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal{std::to_string(value), "http://www.w3.org/2001/XMLSchema#int"};
    CHECK(lit4.value<xsd::Int, xsd_int>() == value);

    value = 2147483647;
    auto lit5 = rdf4cpp::rdf::Literal{std::to_string(value), "http://www.w3.org/2001/XMLSchema#int"};
    CHECK(lit5.value<xsd::Int, xsd_int>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);
    CHECK(lit1 == lit4);
    CHECK(lit3 == lit5);

/*    auto lit7 = rdf4cpp::rdf::Literal{"2147483649", "http://www.w3.org/2001/XMLSchema#int"};
    CHECK_THROWS_WITH_AS(lit7.value(), "XSD Parsing Error", std::runtime_error);*/
}
