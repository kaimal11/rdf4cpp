#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype Time") {

    auto input = "19:32:00";
    auto output = RegisteredDatatype<xsd::Time, xsd_time>::from_string(input);

    char str[32];
    std::strftime(str, 32, "%H:%M:%S", std::localtime(&output));
    std::string value(str);

    CHECK(value == input);
    CHECK(RegisteredDatatype<xsd::Time, xsd_time>::datatype_iri() == xsd_time);

    auto lit1 = rdf4cpp::rdf::Literal{"19:32:01", rdf4cpp::rdf::IRI{RegisteredDatatype<xsd::Time, xsd_time>::datatype_iri()}};
    auto lit2 = rdf4cpp::rdf::Literal{"19:32:01", rdf4cpp::rdf::IRI{RegisteredDatatype<xsd::Time, xsd_time>::datatype_iri()}};
    auto lit3 = rdf4cpp::rdf::Literal{"20:21:22", rdf4cpp::rdf::IRI{RegisteredDatatype<xsd::Time, xsd_time>::datatype_iri()}};

    CHECK(lit1 == lit2);
    CHECK(lit2 != lit3);
    CHECK(lit1 != lit3);

    // testing == of Literals
    if (lit1 == lit2) CHECK(true);
}