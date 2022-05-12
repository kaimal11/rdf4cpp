#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype PositiveInteger") {

    int64_t value = 1;
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::PositiveInteger, xsd_positiveInteger>(value);
    CHECK(lit1.value<xsd::PositiveInteger, xsd_positiveInteger>() == value);
    CHECK(lit1.lexical_form() == std::to_string(value));

    value = 18446744073709;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::PositiveInteger, xsd_positiveInteger>(value);
    CHECK(lit2.value<xsd::PositiveInteger, xsd_positiveInteger>() == value);
    CHECK(lit2.lexical_form() == std::to_string(value));

    value = 2147483647;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::PositiveInteger, xsd_positiveInteger>(value);
    CHECK(lit3.value<xsd::PositiveInteger, xsd_positiveInteger>() == value);
    CHECK(lit3.lexical_form() == std::to_string(value));

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal{std::to_string(value), "http://www.w3.org/2001/XMLSchema#positiveinteger"};
    CHECK(lit4.value<xsd::PositiveInteger, xsd_positiveInteger>() == value);

    value = 18446744073709;
    auto lit5 = rdf4cpp::rdf::Literal{std::to_string(value), "http://www.w3.org/2001/XMLSchema#positiveinteger"};
    CHECK(lit5.value<xsd::PositiveInteger, xsd_positiveInteger>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);
    CHECK(lit1 == lit4);
    CHECK(lit2 == lit5);
}
