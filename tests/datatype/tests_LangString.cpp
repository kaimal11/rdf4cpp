#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf;

TEST_CASE("Datatype LangString") {

    constexpr auto correct_type_iri_cstr = "http://www.w3.org/1999/02/22-rdf-syntax-ns#langString";

    CHECK(std::string(datatypes::xsd::LangString::identifier) == correct_type_iri_cstr);

    auto type_iri = IRI(datatypes::xsd::LangString::identifier);
    CHECK(type_iri.identifier() == correct_type_iri_cstr);

    using type = datatypes::xsd::LangString::cpp_type;

    CHECK(std::is_same_v<type, std::string>);

    std::string value = "123@en";
    auto lit1 = Literal::make<datatypes::xsd::LangString>(value);
    CHECK(lit1.value<datatypes::xsd::LangString>() == value);
    CHECK(lit1.lexical_form() == value);

    value = "asd@de";
    auto lit2 = Literal::make<datatypes::xsd::LangString>(value);
    CHECK(lit2.value<datatypes::xsd::LangString>() == value);
    CHECK(lit2.lexical_form() == value);

    value = "asd@de";
    auto lit3 = Literal::make<datatypes::xsd::LangString>(value);
    CHECK(lit3.value<datatypes::xsd::LangString>() == value);
    CHECK(lit3.lexical_form() == value);

    value = "asd@en";
    auto lit4 = Literal::make<datatypes::xsd::LangString>(value);
    CHECK(lit4.value<datatypes::xsd::LangString>() == value);
    CHECK(lit4.lexical_form() == value);

    value = "\n@en";
    auto lit5 = Literal::make<datatypes::xsd::LangString>(value);
    CHECK(lit5.value<datatypes::xsd::LangString>() == value);
    CHECK(lit5.lexical_form() == value);

    value = "\t@en";
    auto lit6 = Literal::make<datatypes::xsd::LangString>(value);
    CHECK(lit6.value<datatypes::xsd::LangString>() == value);
    CHECK(lit6.lexical_form() == value);

    value = "\r@en";
    auto lit7 = Literal::make<datatypes::xsd::LangString>(value);
    CHECK(lit7.value<datatypes::xsd::LangString>() == value);
    CHECK(lit7.lexical_form() == value);

    value = "\\@en";
    auto lit8 = Literal::make<datatypes::xsd::LangString>(value);
    CHECK(lit8.value<datatypes::xsd::LangString>() == value);
    CHECK(lit8.lexical_form() == value);

    value = "\"@en";
    auto lit9 = Literal::make<datatypes::xsd::LangString>(value);
    CHECK(lit9.value<datatypes::xsd::LangString>() == value);
    CHECK(lit9.lexical_form() == value);

    value = "Bugs Bunny@de";
    auto lit10 = Literal{"Bugs Bunny", "de"};
    CHECK(lit10.value<datatypes::xsd::LangString>() == value);
    CHECK(lit10.lexical_form() == value);

    std::cout<<lit4<<std::endl;
    std::cout<<lit10<<std::endl;

    value = "Bugs Bunny@en";
    auto lit11 = Literal{"Bugs Bunny", "en"};
    CHECK(lit11.value<datatypes::xsd::LangString>() == value);
    CHECK(lit11.lexical_form() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 == lit3);
    CHECK(lit2 != lit4);

    // suppress warnings regarding attribute ‘nodiscard’
    std::any no_discard_dummy = false;

    CHECK_THROWS_WITH_AS(no_discard_dummy = Literal("qwerty", type_iri), "XSD Parsing Error", std::runtime_error);

    CHECK_THROWS_WITH_AS(no_discard_dummy = Literal("a@\n", type_iri), "XSD Parsing Error", std::runtime_error);

    CHECK_THROWS_WITH_AS(no_discard_dummy = Literal("b@\r", type_iri), "XSD Parsing Error", std::runtime_error);

    CHECK_THROWS_WITH_AS(no_discard_dummy = Literal("c@\t", type_iri), "XSD Parsing Error", std::runtime_error);
}
