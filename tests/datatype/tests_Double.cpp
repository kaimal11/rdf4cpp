#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype Double") {

    auto iri = rdf4cpp::rdf::IRI(RegisteredDatatype<xsd::Double, xsd_double>::datatype_iri());

    auto iri_str = rdf4cpp::rdf::IRI("http://www.w3.org/2001/XMLSchema#double");

    CHECK(iri == iri_str);

    double value = 1.00;
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::Double, xsd_double>(value);
    CHECK(lit1.value<xsd::Double, xsd_double>() == value);
    CHECK(lit1.lexical_form() == std::to_string(value));

    value = 987456321123456.123586987;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::Double, xsd_double>(value);
    CHECK(lit2.value<xsd::Double, xsd_double>() == value);
    CHECK(lit2.lexical_form() == std::to_string(value));

    value = -64545352389.2352345670;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::Double, xsd_double>(value);
    CHECK(lit3.value<xsd::Double, xsd_double>() == value);
    CHECK(lit3.lexical_form() == std::to_string(value));

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::Double, xsd_double>(value);
    CHECK(lit4.value<xsd::Double, xsd_double>() == value);
    CHECK(lit4.lexical_form() == std::to_string(value));

    value = std::numeric_limits<double>::min();
    auto lit5 = rdf4cpp::rdf::Literal::make<xsd::Double, xsd_double>(value);
    CHECK(lit5.value<xsd::Double, xsd_double>() == value);
    CHECK(lit5.lexical_form() == std::to_string(value));

    value = std::numeric_limits<double>::max();;
    auto lit6 = rdf4cpp::rdf::Literal::make<xsd::Double, xsd_double>(value);
    CHECK(lit6.value<xsd::Double, xsd_double>() == value);
    CHECK(lit6.lexical_form() == std::to_string(value));

    value = 1;
    auto lit7 = rdf4cpp::rdf::Literal{std::to_string(value), iri};
    CHECK(lit7.value<xsd::Double, xsd_double>() == value);

    value = 987456321123456.123586987;
    auto lit8 = rdf4cpp::rdf::Literal{std::to_string(value), iri};
    CHECK(lit8.value<xsd::Double, xsd_double>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);
    CHECK(lit1 == lit4);
    CHECK(lit1 == lit7);
    CHECK(lit2 == lit8);
}