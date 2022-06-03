#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf;

TEST_CASE("Datatype LangString") {

    constexpr auto correct_type_iri_cstr = "http://www.w3.org/2001/XMLSchema#langString";

    CHECK(std::string(datatypes::xsd::String::identifier) == correct_type_iri_cstr);

    auto type_iri = IRI(datatypes::xsd::String::identifier);
    CHECK(type_iri.identifier() == correct_type_iri_cstr);

    using type = datatypes::xsd::String::cpp_type;

    CHECK(std::is_same_v<type, std::string>);


    std::string value = "123@en";
    auto lit1 = Literal::make<datatypes::xsd::String>(value);
    CHECK(lit1.value<datatypes::xsd::String>() == value);
    CHECK(lit1.lexical_form() == value);

    value = "asd@de";
    auto lit2 = Literal::make<datatypes::xsd::String>(value);
    CHECK(lit2.value<datatypes::xsd::String>() == value);
    CHECK(lit2.lexical_form() == value);

    value = "asd@de";
    auto lit3 = Literal::make<datatypes::xsd::String>(value);
    CHECK(lit3.value<datatypes::xsd::String>() == value);
    CHECK(lit3.lexical_form() == value);

    value = "asd@en";
    auto lit4 = Literal::make<datatypes::xsd::String>(value);
    CHECK(lit4.value<datatypes::xsd::String>() == value);
    CHECK(lit4.lexical_form() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);
    CHECK(lit2 == lit4);

    // suppress warnings regarding attribute ‘nodiscard’
    std::any no_discard_dummy = false;

    auto lit5 = rdf4cpp::rdf::Literal{"qwerty", type_iri};
    CHECK_THROWS_WITH_AS(no_discard_dummy = lit5.value(), "XSD Parsing Error", std::runtime_error);

    auto lit6 = rdf4cpp::rdf::Literal{"a@\n", type_iri};
    CHECK_THROWS_WITH_AS(no_discard_dummy = lit6.value(), "XSD Parsing Error", std::runtime_error);

    auto lit7 = rdf4cpp::rdf::Literal{"b@\r", type_iri};
    CHECK_THROWS_WITH_AS(no_discard_dummy = lit7.value(), "XSD Parsing Error", std::runtime_error);

    auto lit8 = rdf4cpp::rdf::Literal{"c@\t", type_iri};
    CHECK_THROWS_WITH_AS(no_discard_dummy = lit8.value(), "XSD Parsing Error", std::runtime_error);
}
