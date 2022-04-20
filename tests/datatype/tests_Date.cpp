#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype Date") {

    auto input = "2021-12-23";
    auto output = RegisteredDatatype<xsd::Date, xsd_date>::from_string(input);

    char str[32];
    std::strftime(str, 32, "%Y-%m-%d", std::localtime(&output));
    std::string value(str);

    CHECK(value == input);
    CHECK(RegisteredDatatype<xsd::Date, xsd_date>::datatype_iri() == xsd_date);

    auto lit1 = rdf4cpp::rdf::Literal{"2021-01-01", rdf4cpp::rdf::IRI{RegisteredDatatype<xsd::Date, xsd_date>::datatype_iri()}};
    auto lit2 = rdf4cpp::rdf::Literal{"2021-01-01", rdf4cpp::rdf::IRI{RegisteredDatatype<xsd::Date, xsd_date>::datatype_iri()}};
    auto lit3 = rdf4cpp::rdf::Literal{"2021-01-11", rdf4cpp::rdf::IRI{RegisteredDatatype<xsd::Date, xsd_date>::datatype_iri()}};

    CHECK(lit1 != lit3);
    CHECK(lit1 == lit2);

}