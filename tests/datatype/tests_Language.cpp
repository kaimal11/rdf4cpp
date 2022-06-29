#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf;

TEST_CASE("Datatype Language") {

    constexpr auto correct_type_iri_cstr = "http://www.w3.org/2001/XMLSchema#language";

    CHECK(std::string(datatypes::xsd::Language::identifier) == correct_type_iri_cstr);

    auto type_iri = IRI(datatypes::xsd::Language::identifier);
    CHECK(type_iri.identifier() == correct_type_iri_cstr);

    using type = datatypes::xsd::Language::cpp_type;

    CHECK(std::is_same_v<type, std::string>);

    std::string value = "en";
    auto lit1 = Literal::make<datatypes::xsd::Language>(value);
    CHECK(lit1.value<datatypes::xsd::Language>() == value);
    CHECK(lit1.lexical_form() == value);

    value = "de";
    auto lit2 = Literal::make<datatypes::xsd::Language>(value);
    CHECK(lit2.value<datatypes::xsd::Language>() == value);
    CHECK(lit2.lexical_form() == value);

    value = "xx";
    auto lit3 = Literal::make<datatypes::xsd::Language>(value);
    CHECK(lit3.value<datatypes::xsd::Language>() == value);
    CHECK(lit3.lexical_form() == value);

    value = "en";
    auto lit4 = Literal{value, type_iri};
    CHECK(lit4.value<datatypes::xsd::Language>() == value);
    CHECK(lit4.lexical_form() == value);

    value = "de";
    auto lit5 = Literal{value, type_iri};
    CHECK(lit5.value<datatypes::xsd::Language>() == value);
    CHECK(lit5.lexical_form() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);
    CHECK(lit1 == lit4);
    CHECK(lit2 == lit5);

    // suppress warnings regarding attribute ‘nodiscard’
    Literal no_discard_dummy;

    CHECK_THROWS_WITH_AS(no_discard_dummy = Literal("sdfsdf\n", type_iri), "XSD Parsing Error", std::runtime_error);

    CHECK_THROWS_WITH_AS(no_discard_dummy = Literal("sdfsdf\t", type_iri), "XSD Parsing Error", std::runtime_error);

    CHECK_THROWS_WITH_AS(no_discard_dummy = Literal("sdfsdf\r", type_iri), "XSD Parsing Error", std::runtime_error);
}

