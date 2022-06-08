#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf;

TEST_CASE("Datatype Float") {

    constexpr auto correct_type_iri_cstr = "http://www.w3.org/2001/XMLSchema#float";

    CHECK(std::string(datatypes::xsd::Float::identifier) == correct_type_iri_cstr);

    auto type_iri = IRI(datatypes::xsd::Float::identifier);
    CHECK(type_iri.identifier() == correct_type_iri_cstr);

    using type = datatypes::xsd::Float::cpp_type;

    CHECK(std::is_same_v<type, float>);

    float value = 1.00;
    auto lit1 = Literal::make<datatypes::xsd::Float>(value);
    CHECK(lit1.value<datatypes::xsd::Float>() == value);
    CHECK(lit1.lexical_form() == std::to_string(value));

    value = 32568.2350;
    auto lit2 = Literal::make<datatypes::xsd::Float>(value);
    CHECK(lit2.value<datatypes::xsd::Float>() == value);
    CHECK(lit2.lexical_form() == std::to_string(value));

    value = -14523.2350;
    auto lit3 = Literal::make<datatypes::xsd::Float>(value);
    CHECK(lit3.value<datatypes::xsd::Float>() == value);
    CHECK(lit3.lexical_form() == std::to_string(value));

    value = 1;
    auto lit4 = Literal::make<datatypes::xsd::Float>(value);
    CHECK(lit4.value<datatypes::xsd::Float>() == value);
    CHECK(lit4.lexical_form() == std::to_string(value));

    //minimum value for float
    auto lit5 = Literal{"1.17e-38", type_iri};
    CHECK(lit5.value<datatypes::xsd::Float>() == 1.17e-38);

    value = std::numeric_limits<float>::max();;
    auto lit6 = Literal::make<datatypes::xsd::Float>(value);
    CHECK(lit6.value<datatypes::xsd::Float>() == value);
    CHECK(lit6.lexical_form() == std::to_string(value));

    value = 1;
    auto lit7 = Literal{std::to_string(value), type_iri};
    CHECK(lit7.value<datatypes::xsd::Float>() == value);

    value = 32568.2350;
    auto lit8 = Literal{std::to_string(value), type_iri};
    CHECK(lit8.value<datatypes::xsd::Float>() == value);

    auto lit9 = Literal{"NaN", type_iri};
    CHECK(isnan(lit9.value<datatypes::xsd::Float>()));

    auto lit10 = Literal{"INF", type_iri};
    CHECK(isinf(lit10.value<datatypes::xsd::Float>()));

    value = INFINITY;
    auto lit11 = Literal::make<datatypes::xsd::Float>(value);
    CHECK(isinf(lit11.value<datatypes::xsd::Float>()));

    value = NAN;
    auto lit12 = Literal::make<datatypes::xsd::Float>(value);
    CHECK(isnan(lit12.value<datatypes::xsd::Float>()));

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);
    CHECK(lit1 == lit4);
    CHECK(lit1 == lit7);
    CHECK(lit2 == lit8);
    CHECK(lit9 == lit12);
    CHECK(lit10 == lit11);

    // suppress warnings regarding attribute ‘nodiscard’
    std::any no_discard_dummy = false;

    auto lit13 = Literal{"454sdsd", type_iri};
    CHECK_THROWS_WITH_AS(no_discard_dummy = lit13.value(), "XSD Parsing Error", std::runtime_error);
}