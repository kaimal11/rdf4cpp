#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype Long") {

    long value = 1;
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::Long, xsd_long>(value);
    CHECK(lit1.value<xsd::Long, xsd_long>() == value);
    CHECK(lit1.lexical_form() == std::to_string(value));

    value = -9223372036854775808;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::Long, xsd_long>(value);
    CHECK(lit2.value<xsd::Long, xsd_long>() == value);
    CHECK(lit2.lexical_form() == std::to_string(value));

    value = 9223372036854775807;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::Long, xsd_long>(value);
    CHECK(lit3.value<xsd::Long, xsd_long>() == value);
    CHECK(lit3.lexical_form() == std::to_string(value));

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal{std::to_string(value), "http://www.w3.org/2001/XMLSchema#long"};
    CHECK(lit4.value<xsd::Long, xsd_long>() == value);

    value = -9223372036854775808;
    auto lit5 = rdf4cpp::rdf::Literal{std::to_string(value), "http://www.w3.org/2001/XMLSchema#long"};
    CHECK(lit5.value<xsd::Long, xsd_long>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);
    CHECK(lit1 == lit4);
    CHECK(lit2 == lit5);
}
