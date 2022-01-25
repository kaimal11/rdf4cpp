#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype Byte") {

    auto value = 1;
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::Byte, xsd_byte>(value);
    CHECK(lit1.value<xsd::Byte,xsd_byte>() == value);

    value = -128;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::Byte, xsd_byte>(value);
    CHECK(lit2.value<xsd::Byte,xsd_byte>() == value);

    value = 127;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::Byte, xsd_byte>(value);
    CHECK(lit3.value<xsd::Byte,xsd_byte>() == value);

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::Byte, xsd_byte>(value);
    CHECK(lit4.value<xsd::Byte,xsd_byte>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);

    if(lit1 == lit2) CHECK(false);
    else CHECK(true);

    if(lit1 == lit4) CHECK(true);
    else CHECK(false);

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
    CHECK(lit1.value<xsd::Short,xsd_short>() == value);

    value = -32768;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::Short, xsd_short>(value);
    CHECK(lit2.value<xsd::Short,xsd_short>() == value);

    value = 32767;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::Short, xsd_short>(value);
    CHECK(lit3.value<xsd::Short,xsd_short>() == value);

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::Short, xsd_short>(value);
    CHECK(lit4.value<xsd::Short,xsd_short>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);

    if(lit1 == lit2) CHECK(false);
    else CHECK(true);

    if(lit1 == lit4) CHECK(true);
    else CHECK(false);

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
    CHECK(lit1.value<xsd::Int,xsd_int>() == value);

    value = -2147483648;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::Int, xsd_int>(value);
    CHECK(lit2.value<xsd::Int,xsd_int>() == value);

    value = 2147483647;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::Int, xsd_int>(value);
    CHECK(lit3.value<xsd::Int,xsd_int>() == value);

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::Int, xsd_int>(value);
    CHECK(lit4.value<xsd::Int,xsd_int>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);

    if(lit1 == lit2) CHECK(false);
    else CHECK(true);

    if(lit1 == lit4) CHECK(true);
    else CHECK(false);

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
    CHECK(lit1.value<xsd::Long,xsd_long>() == value);

    value = -9223372036854775808;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::Long, xsd_long>(value);
    CHECK(lit2.value<xsd::Long,xsd_long>() == value);

    value = 9223372036854775807;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::Long, xsd_long>(value);
    CHECK(lit3.value<xsd::Long,xsd_long>() == value);

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::Long, xsd_long>(value);
    CHECK(lit4.value<xsd::Long,xsd_long>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);

    if(lit1 == lit2) CHECK(false);
    else CHECK(true);

    if(lit1 == lit4) CHECK(true);
    else CHECK(false);

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
    std::cout << lit1.value<xsd::UnsignedByte,xsd_ubyte>() << std::endl;
    CHECK(lit1.value<xsd::UnsignedByte,xsd_ubyte>() == value);

    value = 0;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::UnsignedByte, xsd_ubyte>(value);
    CHECK(lit2.value<xsd::UnsignedByte,xsd_ubyte>() == value);

    value = 255;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::UnsignedByte, xsd_ubyte>(value);
    CHECK(lit3.value<xsd::UnsignedByte,xsd_ubyte>() == value);

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::UnsignedByte, xsd_ubyte>(value);
    CHECK(lit4.value<xsd::UnsignedByte,xsd_ubyte>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);

    if(lit1 == lit2) CHECK(false);
    else CHECK(true);

    if(lit1 == lit4) CHECK(true);
    else CHECK(false);

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
    CHECK(lit1.value<xsd::UnsignedShort,xsd_ushort>() == value);

    value = 0;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::UnsignedShort, xsd_ushort>(value);
    CHECK(lit2.value<xsd::UnsignedShort,xsd_ushort>() == value);

    value = 65535;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::UnsignedShort, xsd_ushort>(value);
    CHECK(lit3.value<xsd::UnsignedShort,xsd_ushort>() == value);

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::UnsignedShort, xsd_ushort>(value);
    CHECK(lit4.value<xsd::UnsignedShort,xsd_ushort>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);

    if(lit1 == lit2) CHECK(false);
    else CHECK(true);

    if(lit1 == lit4) CHECK(true);
    else CHECK(false);

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
    CHECK(lit1.value<xsd::UnsignedInt,xsd_uint>() == value);

    value = 0;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::UnsignedInt, xsd_uint>(value);
    CHECK(lit2.value<xsd::UnsignedInt,xsd_uint>() == value);

    value = 4294967295;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::UnsignedInt, xsd_uint>(value);
    CHECK(lit3.value<xsd::UnsignedInt,xsd_uint>() == value);

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::UnsignedInt, xsd_uint>(value);
    CHECK(lit4.value<xsd::UnsignedInt,xsd_uint>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);

    if(lit1 == lit2) CHECK(false);
    else CHECK(true);

    if(lit1 == lit4) CHECK(true);
    else CHECK(false);

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
    CHECK(lit1.value<xsd::UnsignedLong,xsd_ulong>() == value);

    value = 0;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::UnsignedLong, xsd_ulong>(value);
    CHECK(lit2.value<xsd::UnsignedLong,xsd_ulong>() == value);

    value = 18446744073709551615;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::UnsignedLong, xsd_ulong>(value);
    CHECK(lit3.value<xsd::UnsignedLong,xsd_ulong>() == value);

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::UnsignedLong, xsd_ulong>(value);
    CHECK(lit4.value<xsd::UnsignedLong,xsd_ulong>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);

    if(lit1 == lit2) CHECK(false);
    else CHECK(true);

    if(lit1 == lit4) CHECK(true);
    else CHECK(false);

    /*    value = 18446744073709551616;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::UnsignedLong, xsd_ulong>(value);
    CHECK_THROWS_WITH_AS(lit4, "XSD Parsing Error", std::runtime_error);
    CHECK(lit4.value<xsd::UnsignedLong,xsd_ulong>() == value);

    value = -1;
    auto lit5 = rdf4cpp::rdf::Literal::make<xsd::UnsignedLong, xsd_ulong>(value);
    CHECK_THROWS_WITH_AS(lit5, "XSD Parsing Error", std::runtime_error);
    CHECK(lit5.value<xsd::UnsignedLong,xsd_ulong>() == value);*/

}

TEST_CASE("Datatype Boolean") {

    bool value = true;
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::Boolean, xsd_boolean>(value);
    CHECK(lit1.value<xsd::Boolean,xsd_boolean>() == value);

    value = false;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::Boolean, xsd_boolean>(value);
    CHECK(lit2.value<xsd::Boolean,xsd_boolean>() == value);

    value = 1;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::Boolean, xsd_boolean>(value);
    CHECK(lit3.value<xsd::Boolean,xsd_boolean>() == value);

    value = 0;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::Boolean, xsd_boolean>(value);
    CHECK(lit4.value<xsd::Boolean,xsd_boolean>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);

    if(lit1 == lit3) CHECK(true);
    else CHECK(false);

    if(lit2 == lit4) CHECK(true);
    else CHECK(false);

    /*    value = 22;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::Boolean, xsd_boolean>(value);
    CHECK_THROWS_WITH_AS(lit4, "XSD Parsing Error", std::runtime_error);
    CHECK(lit4.value<xsd::Boolean,xsd_boolean>() == value);

    value = -1;
    auto lit5 = rdf4cpp::rdf::Literal::make<xsd::Boolean, xsd_boolean>(value);
    CHECK_THROWS_WITH_AS(lit5, "XSD Parsing Error", std::runtime_error);
    CHECK(lit5.value<xsd::Boolean,xsd_boolean>() == value);*/
}

TEST_CASE("Datatype Decimal") {

    double value = 1.00;
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::Decimal, xsd_decimal>(value);
    CHECK(lit1.value<xsd::Decimal,xsd_decimal>() == value);

    value = 6458988.2350;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::Decimal, xsd_decimal>(value);
    CHECK(lit2.value<xsd::Decimal,xsd_decimal>() == value);

    value = -6452389.2350;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::Decimal, xsd_decimal>(value);
    CHECK(lit3.value<xsd::Decimal,xsd_decimal>() == value);

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::Decimal, xsd_decimal>(value);
    CHECK(lit4.value<xsd::Decimal,xsd_decimal>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);

    if(lit1 == lit2) CHECK(false);
    else CHECK(true);

    if(lit1 == lit4) CHECK(true);
    else CHECK(false);

    /*    value = 4294967296.2446;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::Decimal, xsd_decimal>(value);
    CHECK_THROWS_WITH_AS(lit4, "XSD Parsing Error", std::runtime_error);
    CHECK(lit4.value<xsd::Decimal,xsd_decimal>() == value);

    value = -4294967296.24886;
    auto lit5 = rdf4cpp::rdf::Literal::make<xsd::Decimal, xsd_decimal>(value);
    CHECK_THROWS_WITH_AS(lit5, "XSD Parsing Error", std::runtime_error);
    CHECK(lit5.value<xsd::Decimal,xsd_decimal>() == value);*/
}

TEST_CASE("Datatype Float") {

    float value = 1.00;
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::Float, xsd_float>(value);
    CHECK(lit1.value<xsd::Float,xsd_float>() == value);

    value = 32568.2350;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::Float, xsd_float>(value);
    CHECK(lit2.value<xsd::Float,xsd_float>() == value);

    value = -14523.2350;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::Float, xsd_float>(value);
    CHECK(lit3.value<xsd::Float,xsd_float>() == value);

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::Float, xsd_float>(value);
    CHECK(lit4.value<xsd::Float,xsd_float>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);

    if(lit1 == lit2) CHECK(false);
    else CHECK(true);

    if(lit1 == lit4) CHECK(true);
    else CHECK(false);

    /*    value = 4294967296;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::Float, xsd_float>(value);
    CHECK_THROWS_WITH_AS(lit4, "XSD Parsing Error", std::runtime_error);
    CHECK(lit4.value<xsd::Float,xsd_float>() == value);

    value = -4294967296;
    auto lit5 = rdf4cpp::rdf::Literal::make<xsd::Float, xsd_float>(value);
    CHECK_THROWS_WITH_AS(lit5, "XSD Parsing Error", std::runtime_error);
    CHECK(lit5.value<xsd::Float,xsd_float>() == value);*/

}

TEST_CASE("Datatype Double") {

    double value = 1.00;
    auto lit1 = rdf4cpp::rdf::Literal::make<xsd::Double, xsd_double>(value);
    CHECK(lit1.value<xsd::Double,xsd_double>() == value);

    value = 6458988.2350;
    auto lit2 = rdf4cpp::rdf::Literal::make<xsd::Double, xsd_double>(value);
    CHECK(lit2.value<xsd::Double,xsd_double>() == value);

    value = -6452389.2350;
    auto lit3 = rdf4cpp::rdf::Literal::make<xsd::Double, xsd_double>(value);
    CHECK(lit3.value<xsd::Double,xsd_double>() == value);

    value = 1;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::Double, xsd_double>(value);
    CHECK(lit4.value<xsd::Double,xsd_double>() == value);

    CHECK(lit1 != lit2);
    CHECK(lit2 != lit3);

    if(lit1 == lit2) CHECK(false);
    else CHECK(true);

    if(lit1 == lit4) CHECK(true);
    else CHECK(false);

    /*    value = 4294967296.2446;
    auto lit4 = rdf4cpp::rdf::Literal::make<xsd::Double, xsd_double>(value);
    CHECK_THROWS_WITH_AS(lit4, "XSD Parsing Error", std::runtime_error);
    CHECK(lit4.value<xsd::Double,xsd_double>() == value);

    value = -4294967296.24886;
    auto lit5 = rdf4cpp::rdf::Literal::make<xsd::Double, xsd_double>(value);
    CHECK_THROWS_WITH_AS(lit5, "XSD Parsing Error", std::runtime_error);
    CHECK(lit5.value<xsd::Double,xsd_double>() == value);*/
}

TEST_CASE("Datatype Date") {
    auto Date_iri = "http://www.w3.org/2001/XMLSchema#date";
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

    if(lit1 == lit2) CHECK(true);
    else CHECK(false);
}

TEST_CASE("Datatype Time") {
    auto Time_iri = "http://www.w3.org/2001/XMLSchema#time";
    auto input = "19:32:00";
    auto output = RegisteredDatatype<xsd::Time, xsd_time>::from_string(input);

    char str[32];
    std::strftime(str, 32, "%H:%M:%S", std::localtime(&output));
    std::string time_str(str);

    CHECK(time_str == input);
    CHECK(RegisteredDatatype<xsd::Time, xsd_time>::datatype_iri() == Time_iri);
}

TEST_CASE("Datatype DateTime") {
    auto dateTime_iri = "http://www.w3.org/2001/XMLSchema#dateTime";
    auto input = "2021-12-23T10:11:12";
    // we can use the predefined constexpr c string
    auto output = RegisteredDatatype<xsd::DateTime, xsd_dateTime>::from_string(input);

    char str[32];
    std::strftime(str, 32, "%Y-%m-%dT%H:%M:%S", std::localtime(&output));
    std::string time_str(str);

    CHECK(time_str == "2021-12-23T10:11:12");
    CHECK(RegisteredDatatype<xsd::DateTime, xsd_dateTime>::datatype_iri() == dateTime_iri);
}

TEST_CASE("Datatype Duration") {
    auto duration_iri = "http://www.w3.org/2001/XMLSchema#duration";
    auto input = "P1D";
    // we can use the predefined constexpr c string
    auto output = RegisteredDatatype<xsd::Duration , xsd_duration>::from_string(input);

    for(int i = 0; i < 6; i++){
        std::cout<<output[i]<<" ";
    }
    CHECK(RegisteredDatatype<xsd::Duration , xsd_duration>::datatype_iri() == duration_iri);
}

/*
TEST_CASE("Compare Literals"){
    auto lit1 = rdf4cpp::rdf::Literal{"0", rdf4cpp::rdf::IRI{RegisteredDatatype<xsd::Boolean>::datatype_iri()}};
    auto lit2 = rdf4cpp::rdf::Literal{"1", rdf4cpp::rdf::IRI{RegisteredDatatype<xsd::Boolean>::datatype_iri()}};

    if(lit1 == lit2) std::cout << "True" << std::endl;
    else std::cout << "False" << std::endl;
}*/
