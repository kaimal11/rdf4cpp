#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype NonPositiveInteger") {

    auto value = -1;
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::NonPositiveInteger, xsd_nonPositiveInteger>(value);
    CHECK(lit1.value<xsd::NonPositiveInteger, xsd_nonPositiveInteger>() == value);

    value = -18446744073709;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::NonPositiveInteger, xsd_nonPositiveInteger>(value);
    CHECK(lit2.value<xsd::NonPositiveInteger, xsd_nonPositiveInteger>() == value);

    value = 0;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::NonPositiveInteger, xsd_nonPositiveInteger>(value);
    CHECK(lit3.value<xsd::NonPositiveInteger, xsd_nonPositiveInteger>() == value);

    value = -1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::NonPositiveInteger, xsd_nonPositiveInteger>(value);
    CHECK(lit4.value<xsd::NonPositiveInteger, xsd_nonPositiveInteger>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);

    if (lit1 == lit2) CHECK(false);
    else
        CHECK(true);

    if (lit1 == lit4) CHECK(true);
    else
        CHECK(false);

    /*    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::NonPositiveInteger, xsd_nonPositiveInteger>(value);
    CHECK_THROWS_WITH_AS(lit4, "XSD Parsing Error", std::runtime_error);
    CHECK(lit4.value<xsd::NonPositiveInteger,xsd_nonPositiveInteger>() == value);

    value = -12.0555;
    auto lit5 = rdf4cpp::rdf::Literal::make<xsd::NonPositiveInteger, xsd_nonPositiveInteger>(value);
    CHECK_THROWS_WITH_AS(lit5, "XSD Parsing Error", std::runtime_error);
    CHECK(lit5.value<xsd::NonPositiveInteger,xsd_nonPositiveInteger>() == value);*/
}
