#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype Float") {

    constexpr auto correct_type_iri_cstr = "http://www.w3.org/2001/XMLSchema#decimal";

    CHECK(std::string(datatypes::xsd::Decimal::identifier) == correct_type_iri_cstr);

    auto type_iri = IRI(datatypes::xsd::Decimal::identifier);
    CHECK(type_iri.identifier() == correct_type_iri_cstr);

    using type = datatypes::xsd::Decimal::cpp_type;

    CHECK(std::is_same_v<type, double>);

    auto iri = rdf4cpp::rdf::IRI(RegisteredDatatype<xsd::Float, xsd_float>::datatype_iri());

    auto iri_str = rdf4cpp::rdf::IRI("http://www.w3.org/2001/XMLSchema#float");

    CHECK(iri == iri_str);

    float value = 1.00;
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::Float, xsd_float>(value);
    CHECK(lit1.value<xsd::Float, xsd_float>() == value);

    value = 32568.2350;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::Float, xsd_float>(value);
    CHECK(lit2.value<xsd::Float, xsd_float>() == value);

    value = -14523.2350;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::Float, xsd_float>(value);
    CHECK(lit3.value<xsd::Float, xsd_float>() == value);

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::Float, xsd_float>(value);
    CHECK(lit4.value<xsd::Float, xsd_float>() == value);

    value = std::numeric_limits<float>::min();
    auto lit5 = rdf4cpp::rdf::Literal::make<xsd::Float, xsd_float>(value);
    CHECK(lit5.value<xsd::Float, xsd_float>() == value);

    value = std::numeric_limits<float>::max();;
    auto lit6 = rdf4cpp::rdf::Literal::make<xsd::Float, xsd_float>(value);
    CHECK(lit6.value<xsd::Float, xsd_float>() == value);

    value = 1;
    auto lit7 = rdf4cpp::rdf::Literal{std::to_string(value), iri};
    CHECK(lit7.value<xsd::Float, xsd_float>() == value);

    value = 32568.2350;
    auto lit8 = rdf4cpp::rdf::Literal{std::to_string(value), iri};
    CHECK(lit8.value<xsd::Float, xsd_float>() == value);

    auto lit9 = rdf4cpp::rdf::Literal{"NaN", iri};
    CHECK(isnan(lit9.value<xsd::Float, xsd_float>()));

    auto lit10 = rdf4cpp::rdf::Literal{"INF", iri};
    CHECK(isinf(lit10.value<xsd::Float, xsd_float>()));

    value = INFINITY;
    auto lit11 = rdf4cpp::rdf::Literal::make<xsd::Float, xsd_float>(value);
    CHECK(isinf(lit11.value<xsd::Float, xsd_float>()));

    value = NAN;
    auto lit12 = rdf4cpp::rdf::Literal::make<xsd::Float, xsd_float>(value);
    CHECK(isnan(lit12.value<xsd::Float, xsd_float>()));

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);
    CHECK(lit1 == lit4);
    CHECK(lit1 == lit7);
    CHECK(lit2 == lit8);
    CHECK(lit9 == lit12);
    CHECK(lit10 == lit11);

    auto lit13 = rdf4cpp::rdf::Literal{"454sdsd", iri};
    CHECK_THROWS_WITH_AS(lit13.value(), "XSD Parsing Error", std::runtime_error);
}