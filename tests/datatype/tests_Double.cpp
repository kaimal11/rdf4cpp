#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype Double") {

    double value = 1.00;
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::Double, xsd_double>(value);
    CHECK(lit1.value<xsd::Double, xsd_double>() == value);

    value = 987456321123456.123586987;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::Double, xsd_double>(value);
    CHECK(lit2.value<xsd::Double, xsd_double>() == value);

    value = -64545352389.2352345670;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::Double, xsd_double>(value);
    CHECK(lit3.value<xsd::Double, xsd_double>() == value);

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::Double, xsd_double>(value);
    CHECK(lit4.value<xsd::Double, xsd_double>() == value);

    value = std::numeric_limits<double>::min();
    auto lit5 = rdf4cpp::rdf::Literal::make<xsd::Double, xsd_double>(value);
    CHECK(lit5.value<xsd::Double, xsd_double>() == value);

    value = std::numeric_limits<double>::max();;
    auto lit6 = rdf4cpp::rdf::Literal::make<xsd::Double, xsd_double>(value);
    CHECK(lit6.value<xsd::Double, xsd_double>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);
    CHECK(lit1 == lit4);
}