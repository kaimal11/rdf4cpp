#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf;

TEST_CASE("Datatype Int") {

    constexpr auto correct_type_iri_cstr = "http://www.w3.org/2001/XMLSchema#int";

    CHECK(std::string(datatypes::xsd::Int::identifier) == correct_type_iri_cstr);

    auto type_iri = IRI(datatypes::xsd::Int::identifier);
    CHECK(type_iri.identifier() == correct_type_iri_cstr);

    using type = datatypes::xsd::Int::cpp_type;

    CHECK(std::is_same_v<type, int32_t>);

    auto value = 1;
    auto lit1 = Literal::make<datatypes::xsd::Int>(value);
    CHECK(lit1.value<datatypes::xsd::Int>() == value);
    CHECK(lit1.lexical_form() == std::to_string(value));

    value = -2147483648;
    auto lit2 = Literal::make<datatypes::xsd::Int>(value);
    CHECK(lit2.value<datatypes::xsd::Int>() == value);
    CHECK(lit2.lexical_form() == std::to_string(value));

    value = 2147483647;
    auto lit3 = Literal::make<datatypes::xsd::Int>(value);
    CHECK(lit3.value<datatypes::xsd::Int>() == value);
    CHECK(lit3.lexical_form() == std::to_string(value));

    value = 1;
    auto lit4 = Literal{std::to_string(value), type_iri};
    CHECK(lit4.value<datatypes::xsd::Int>() == value);

    value = 2147483647;
    auto lit5 = Literal{std::to_string(value), type_iri};
    CHECK(lit5.value<datatypes::xsd::Int>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);
    CHECK(lit1 == lit4);
    CHECK(lit3 == lit5);

    // suppress warnings regarding attribute ‘nodiscard’
    Literal no_discard_dummy;

    CHECK_THROWS_WITH_AS(no_discard_dummy = Literal("2147483649", type_iri), "XSD Parsing Error", std::runtime_error);

    CHECK_THROWS_WITH_AS(no_discard_dummy = Literal("-2147483650", type_iri), "XSD Parsing Error", std::runtime_error);

}
