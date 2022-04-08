#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype Duration") {
    auto duration_iri = "http://www.w3.org/2001/XMLSchema#duration";
    auto input = "P1D";
    // we can use the predefined constexpr c string
    auto output = RegisteredDatatype<xsd::Duration, xsd_duration>::from_string(input);

    for (int i = 0; i < 6; i++) {
        std::cout << output[i] << " ";
    }
    CHECK(RegisteredDatatype<xsd::Duration, xsd_duration>::datatype_iri() == duration_iri);
}
