#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype DateTimeStamp") {

    auto input = "2021-12-23T10:11:12";
    auto output = RegisteredDatatype<xsd::DateTime, xsd_dateTime>::from_string(input);

    char str[32];
    std::strftime(str, 32, "%Y-%m-%dT%H:%M:%S", std::localtime(&output));
    std::string value(str);

    CHECK(value == input);
    CHECK(RegisteredDatatype<xsd::DateTime, xsd_dateTime>::datatype_iri() == xsd_dateTime);
}