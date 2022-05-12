#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype UnsignedLong") {

    u_int64_t value = 1;
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::UnsignedLong, xsd_ulong>(value);
    CHECK(lit1.value<xsd::UnsignedLong, xsd_ulong>() == value);
    CHECK(lit1.lexical_form() == std::to_string(value));

    value = 0;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::UnsignedLong, xsd_ulong>(value);
    CHECK(lit2.value<xsd::UnsignedLong, xsd_ulong>() == value);
    CHECK(lit2.lexical_form() == std::to_string(value));

    value = 18446744073709551615;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::UnsignedLong, xsd_ulong>(value);
    CHECK(lit3.value<xsd::UnsignedLong, xsd_ulong>() == value);
    CHECK(lit3.lexical_form() == std::to_string(value));

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal{std::to_string(value), "http://www.w3.org/2001/XMLSchema#unsignedlong"};
    CHECK(lit4.value<xsd::UnsignedLong, xsd_ulong>() == value);

    value = 0;
    auto lit5 = rdf4cpp::rdf::Literal{std::to_string(value), "http://www.w3.org/2001/XMLSchema#unsignedlong"};
    CHECK(lit5.value<xsd::UnsignedLong, xsd_ulong>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);
    CHECK(lit1 == lit4);
    CHECK(lit2 == lit5);

}
