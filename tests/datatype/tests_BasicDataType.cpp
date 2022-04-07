#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype Byte") {

    auto value = 1;
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::Byte, xsd_byte>(value);
    CHECK(lit1.value<xsd::Byte, xsd_byte>() == value);

    value = -128;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::Byte, xsd_byte>(value);
    CHECK(lit2.value<xsd::Byte, xsd_byte>() == value);

    value = 127;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::Byte, xsd_byte>(value);
    CHECK(lit3.value<xsd::Byte, xsd_byte>() == value);

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::Byte, xsd_byte>(value);
    CHECK(lit4.value<xsd::Byte, xsd_byte>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);

    if (lit1 == lit2) CHECK(false);
    else
        CHECK(true);

    if (lit1 == lit4) CHECK(true);
    else
        CHECK(false);

    /*    value = 129;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::Byte, xsd_byte>(value);
    CHECK_THROWS_WITH_AS(lit4, "XSD Parsing Error", std::runtime_error);
    CHECK(lit4.value<xsd::Byte,xsd_byte>() == value);

    value = -130;
    auto lit5 = rdf4cpp::rdf::Literal::make<xsd::Byte, xsd_byte>(value);
    CHECK_THROWS_WITH_AS(lit5, "XSD Parsing Error", std::runtime_error);
    CHECK(lit5.value<xsd::Byte,xsd_byte>() == value);*/
}

TEST_CASE("Datatype Short") {

    auto value = 1;
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::Short, xsd_short>(value);
    CHECK(lit1.value<xsd::Short, xsd_short>() == value);

    value = -32768;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::Short, xsd_short>(value);
    CHECK(lit2.value<xsd::Short, xsd_short>() == value);

    value = 32767;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::Short, xsd_short>(value);
    CHECK(lit3.value<xsd::Short, xsd_short>() == value);

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::Short, xsd_short>(value);
    CHECK(lit4.value<xsd::Short, xsd_short>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);

    if (lit1 == lit2) CHECK(false);
    else
        CHECK(true);

    if (lit1 == lit4) CHECK(true);
    else
        CHECK(false);

    /*    value = 32768;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::Short, xsd_short>(value);
    CHECK_THROWS_WITH_AS(lit4, "XSD Parsing Error", std::runtime_error);
    CHECK(lit4.value<xsd::Short,xsd_short>() == value);

    value = -32769;
    auto lit5 = rdf4cpp::rdf::Literal::make<xsd::Short, xsd_short>(value);
    CHECK_THROWS_WITH_AS(lit5, "XSD Parsing Error", std::runtime_error);
    CHECK(lit5.value<xsd::Short,xsd_short>() == value);*/
}

TEST_CASE("Datatype Int") {

    auto value = 1;
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::Int, xsd_int>(value);
    CHECK(lit1.value<xsd::Int, xsd_int>() == value);

    value = -2147483648;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::Int, xsd_int>(value);
    CHECK(lit2.value<xsd::Int, xsd_int>() == value);

    value = 2147483647;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::Int, xsd_int>(value);
    CHECK(lit3.value<xsd::Int, xsd_int>() == value);

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::Int, xsd_int>(value);
    CHECK(lit4.value<xsd::Int, xsd_int>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);

    if (lit1 == lit2) CHECK(false);
    else
        CHECK(true);

    if (lit1 == lit4) CHECK(true);
    else
        CHECK(false);

    /*    value = 2147483649;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::Int, xsd_int>(value);
    CHECK_THROWS_WITH_AS(lit4, "XSD Parsing Error", std::runtime_error);
    CHECK(lit4.value<xsd::Int,xsd_int>() == value);

    value = -2147483649;
    auto lit5 = rdf4cpp::rdf::Literal::make<xsd::Int, xsd_int>(value);
    CHECK_THROWS_WITH_AS(lit5, "XSD Parsing Error", std::runtime_error);
    CHECK(lit5.value<xsd::Int,xsd_int>() == value);*/
}

TEST_CASE("Datatype Long") {

    long value = 1;
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::Long, xsd_long>(value);
    CHECK(lit1.value<xsd::Long, xsd_long>() == value);

    value = -9223372036854775808;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::Long, xsd_long>(value);
    CHECK(lit2.value<xsd::Long, xsd_long>() == value);

    value = 9223372036854775807;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::Long, xsd_long>(value);
    CHECK(lit3.value<xsd::Long, xsd_long>() == value);

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::Long, xsd_long>(value);
    CHECK(lit4.value<xsd::Long, xsd_long>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);

    if (lit1 == lit2) CHECK(false);
    else
        CHECK(true);

    if (lit1 == lit4) CHECK(true);
    else
        CHECK(false);

    /*    value = 9223372036854775809;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::Long, xsd_long>(value);
    CHECK_THROWS_WITH_AS(lit4, "XSD Parsing Error", std::runtime_error);
    CHECK(lit4.value<xsd::Long,xsd_long>() == value);

    value = -9223372036854775809;
    auto lit5 = rdf4cpp::rdf::Literal::make<xsd::Long, xsd_long>(value);
    CHECK_THROWS_WITH_AS(lit5, "XSD Parsing Error", std::runtime_error);
    CHECK(lit5.value<xsd::Long,xsd_long>() == value);*/
}

TEST_CASE("Datatype UnsignedByte") {

    uint8_t value = 1;
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::UnsignedByte, xsd_ubyte>(value);
    std::cout << lit1.value<xsd::UnsignedByte, xsd_ubyte>() << std::endl;
    CHECK(lit1.value<xsd::UnsignedByte, xsd_ubyte>() == value);

    value = 0;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::UnsignedByte, xsd_ubyte>(value);
    CHECK(lit2.value<xsd::UnsignedByte, xsd_ubyte>() == value);

    value = 255;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::UnsignedByte, xsd_ubyte>(value);
    CHECK(lit3.value<xsd::UnsignedByte, xsd_ubyte>() == value);

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::UnsignedByte, xsd_ubyte>(value);
    CHECK(lit4.value<xsd::UnsignedByte, xsd_ubyte>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);

    if (lit1 == lit2) CHECK(false);
    else
        CHECK(true);

    if (lit1 == lit4) CHECK(true);
    else
        CHECK(false);

    /*    value = 256;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::UnsignedByte, xsd_ubyte>(value);
    CHECK_THROWS_WITH_AS(lit4, "XSD Parsing Error", std::runtime_error);
    CHECK(lit4.value<xsd::UnsignedByte,xsd_ubyte>() == value);

    value = -1;
    auto lit5 = rdf4cpp::rdf::Literal::make<xsd::UnsignedByte, xsd_ubyte>(value);
    CHECK_THROWS_WITH_AS(lit5, "XSD Parsing Error", std::runtime_error);
    CHECK(lit5.value<xsd::UnsignedByte,xsd_ubyte>() == value);*/
}

TEST_CASE("Datatype UnsignedShort") {

    uint16_t value = 1;
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::UnsignedShort, xsd_ushort>(value);
    CHECK(lit1.value<xsd::UnsignedShort, xsd_ushort>() == value);

    value = 0;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::UnsignedShort, xsd_ushort>(value);
    CHECK(lit2.value<xsd::UnsignedShort, xsd_ushort>() == value);

    value = 65535;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::UnsignedShort, xsd_ushort>(value);
    CHECK(lit3.value<xsd::UnsignedShort, xsd_ushort>() == value);

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::UnsignedShort, xsd_ushort>(value);
    CHECK(lit4.value<xsd::UnsignedShort, xsd_ushort>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);

    if (lit1 == lit2) CHECK(false);
    else
        CHECK(true);

    if (lit1 == lit4) CHECK(true);
    else
        CHECK(false);

    /*    value = 65536;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::UnsignedShort, xsd_ushort>(value);
    CHECK_THROWS_WITH_AS(lit4, "XSD Parsing Error", std::runtime_error);
    CHECK(lit4.value<xsd::UnsignedShort,xsd_ushort>() == value);

    value = -1;
    auto lit5 = rdf4cpp::rdf::Literal::make<xsd::UnsignedShort, xsd_ushort>(value);
    CHECK_THROWS_WITH_AS(lit5, "XSD Parsing Error", std::runtime_error);
    CHECK(lit5.value<xsd::UnsignedShort,xsd_ushort>() == value);*/
}

TEST_CASE("Datatype UnsignedInt") {

    uint32_t value = 1;
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::UnsignedInt, xsd_uint>(value);
    CHECK(lit1.value<xsd::UnsignedInt, xsd_uint>() == value);

    value = 0;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::UnsignedInt, xsd_uint>(value);
    CHECK(lit2.value<xsd::UnsignedInt, xsd_uint>() == value);

    value = 4294967295;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::UnsignedInt, xsd_uint>(value);
    CHECK(lit3.value<xsd::UnsignedInt, xsd_uint>() == value);

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::UnsignedInt, xsd_uint>(value);
    CHECK(lit4.value<xsd::UnsignedInt, xsd_uint>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);

    if (lit1 == lit2) CHECK(false);
    else
        CHECK(true);

    if (lit1 == lit4) CHECK(true);
    else
        CHECK(false);

    /*    value = 4294967296;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::UnsignedInt, xsd_uint>(value);
    CHECK_THROWS_WITH_AS(lit4, "XSD Parsing Error", std::runtime_error);
    CHECK(lit4.value<xsd::UnsignedInt,xsd_uint>() == value);

    value = -1;
    auto lit5 = rdf4cpp::rdf::Literal::make<xsd::UnsignedInt, xsd_uint>(value);
    CHECK_THROWS_WITH_AS(lit5, "XSD Parsing Error", std::runtime_error);
    CHECK(lit5.value<xsd::UnsignedInt,xsd_uint>() == value);*/
}

TEST_CASE("Datatype UnsignedLong") {

    u_int64_t value = 1;
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::UnsignedLong, xsd_ulong>(value);
    CHECK(lit1.value<xsd::UnsignedLong, xsd_ulong>() == value);

    value = 0;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::UnsignedLong, xsd_ulong>(value);
    CHECK(lit2.value<xsd::UnsignedLong, xsd_ulong>() == value);

    value = 18446744073709551615;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::UnsignedLong, xsd_ulong>(value);
    CHECK(lit3.value<xsd::UnsignedLong, xsd_ulong>() == value);

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::UnsignedLong, xsd_ulong>(value);
    CHECK(lit4.value<xsd::UnsignedLong, xsd_ulong>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);

    if (lit1 == lit2) CHECK(false);
    else
        CHECK(true);

    if (lit1 == lit4) CHECK(true);
    else
        CHECK(false);

    /*    value = 18446744073709551616;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::UnsignedLong, xsd_ulong>(value);
    CHECK_THROWS_WITH_AS(lit4, "XSD Parsing Error", std::runtime_error);
    CHECK(lit4.value<xsd::UnsignedLong,xsd_ulong>() == value);

    value = -1;
    auto lit5 = rdf4cpp::rdf::Literal::make<xsd::UnsignedLong, xsd_ulong>(value);
    CHECK_THROWS_WITH_AS(lit5, "XSD Parsing Error", std::runtime_error);
    CHECK(lit5.value<xsd::UnsignedLong,xsd_ulong>() == value);*/
}

TEST_CASE("Datatype PositiveInteger") {

    auto value = 1;
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::PositiveInteger, xsd_positiveInteger>(value);
    CHECK(lit1.value<xsd::PositiveInteger, xsd_positiveInteger>() == value);

    value = 18446744073709;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::PositiveInteger, xsd_positiveInteger>(value);
    CHECK(lit2.value<xsd::PositiveInteger, xsd_positiveInteger>() == value);

    value = 2147483647;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::PositiveInteger, xsd_positiveInteger>(value);
    CHECK(lit3.value<xsd::PositiveInteger, xsd_positiveInteger>() == value);

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::PositiveInteger, xsd_positiveInteger>(value);
    CHECK(lit4.value<xsd::PositiveInteger, xsd_positiveInteger>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);

    if (lit1 == lit2) CHECK(false);
    else
        CHECK(true);

    if (lit1 == lit4) CHECK(true);
    else
        CHECK(false);

    /*    value = -1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::PositiveInteger, xsd_positiveInteger>(value);
    CHECK_THROWS_WITH_AS(lit4, "XSD Parsing Error", std::runtime_error);
    CHECK(lit4.value<xsd::PositiveInteger,xsd_positiveInteger>() == value);

    value = 12.0555;
    auto lit5 = rdf4cpp::rdf::Literal::make<xsd::PositiveInteger, xsd_positiveInteger>(value);
    CHECK_THROWS_WITH_AS(lit5, "XSD Parsing Error", std::runtime_error);
    CHECK(lit5.value<xsd::PositiveInteger,xsd_positiveInteger>() == value);*/
}

TEST_CASE("Datatype NegativeInteger") {

    auto value = -1;
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::NegativeInteger, xsd_negativeInteger>(value);
    CHECK(lit1.value<xsd::NegativeInteger, xsd_negativeInteger>() == value);

    value = -18446744073709;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::NegativeInteger, xsd_negativeInteger>(value);
    CHECK(lit2.value<xsd::NegativeInteger, xsd_negativeInteger>() == value);

    value = -2147483647;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::NegativeInteger, xsd_negativeInteger>(value);
    CHECK(lit3.value<xsd::NegativeInteger, xsd_negativeInteger>() == value);

    value = -1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::NegativeInteger, xsd_negativeInteger>(value);
    CHECK(lit4.value<xsd::NegativeInteger, xsd_negativeInteger>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);

    if (lit1 == lit2) CHECK(false);
    else
        CHECK(true);

    if (lit1 == lit4) CHECK(true);
    else
        CHECK(false);

    /*    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::NegativeInteger, xsd_negativeInteger>(value);
    CHECK_THROWS_WITH_AS(lit4, "XSD Parsing Error", std::runtime_error);
    CHECK(lit4.value<xsd::NegativeInteger,xsd_negativeInteger>() == value);

    value = -12.0555;
    auto lit5 = rdf4cpp::rdf::Literal::make<xsd::NegativeInteger, xsd_negativeInteger>(value);
    CHECK_THROWS_WITH_AS(lit5, "XSD Parsing Error", std::runtime_error);
    CHECK(lit5.value<xsd::NegativeInteger,xsd_negativeInteger>() == value);*/
}

TEST_CASE("Datatype NonNegativeInteger") {

    auto value = 1;
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::NonNegativeInteger, xsd_nonNegativeInteger>(value);
    CHECK(lit1.value<xsd::NonNegativeInteger, xsd_nonNegativeInteger>() == value);

    value = 18446744073709;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::NonNegativeInteger, xsd_nonNegativeInteger>(value);
    CHECK(lit2.value<xsd::NonNegativeInteger, xsd_nonNegativeInteger>() == value);

    value = 0;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::NonNegativeInteger, xsd_nonNegativeInteger>(value);
    CHECK(lit3.value<xsd::NonNegativeInteger, xsd_nonNegativeInteger>() == value);

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::NonNegativeInteger, xsd_nonNegativeInteger>(value);
    CHECK(lit4.value<xsd::NonNegativeInteger, xsd_nonNegativeInteger>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);

    if (lit1 == lit2) CHECK(false);
    else
        CHECK(true);

    if (lit1 == lit4) CHECK(true);
    else
        CHECK(false);

    /*    value = -1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::NonNegativeInteger, xsd_nonNegativeInteger>(value);
    CHECK_THROWS_WITH_AS(lit4, "XSD Parsing Error", std::runtime_error);
    CHECK(lit4.value<xsd::NonNegativeInteger,xsd_nonNegativeInteger>() == value);

    value = 0.985;
    auto lit5 = rdf4cpp::rdf::Literal::make<xsd::NonNegativeInteger, xsd_nonNegativeInteger>(value);
    CHECK_THROWS_WITH_AS(lit5, "XSD Parsing Error", std::runtime_error);
    CHECK(lit5.value<xsd::NonNegativeInteger,xsd_nonNegativeInteger>() == value);*/
}

TEST_CASE("Datatype NonPositiveInteger") {

    auto value = -1;
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::NonPositiveInteger, xsd_nonPositiveInteger>(value);
    CHECK(lit1.value<xsd::NonPositiveInteger, xsd_nonPositiveInteger>() == value);

    value = -18446744073709;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::NonPositiveInteger, xsd_nonPositiveInteger>(value);
    CHECK(lit2.value<xsd::NonPositiveInteger, xsd_nonPositiveInteger>() == value);

    value = 0;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::NonPositiveInteger, xsd_nonPositiveInteger>(value);
    CHECK(lit3.value<xsd::NonPositiveInteger, xsd_nonPositiveInteger>() == value);

    value = -1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::NonPositiveInteger, xsd_nonPositiveInteger>(value);
    CHECK(lit4.value<xsd::NonPositiveInteger, xsd_nonPositiveInteger>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);

    if (lit1 == lit2) CHECK(false);
    else
        CHECK(true);

    if (lit1 == lit4) CHECK(true);
    else
        CHECK(false);

    /*    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::NonPositiveInteger, xsd_nonPositiveInteger>(value);
    CHECK_THROWS_WITH_AS(lit4, "XSD Parsing Error", std::runtime_error);
    CHECK(lit4.value<xsd::NonPositiveInteger,xsd_nonPositiveInteger>() == value);

    value = -12.0555;
    auto lit5 = rdf4cpp::rdf::Literal::make<xsd::NonPositiveInteger, xsd_nonPositiveInteger>(value);
    CHECK_THROWS_WITH_AS(lit5, "XSD Parsing Error", std::runtime_error);
    CHECK(lit5.value<xsd::NonPositiveInteger,xsd_nonPositiveInteger>() == value);*/
}

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
