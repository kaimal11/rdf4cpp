#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

TEST_CASE("Datatype Integer") {

    auto int_iri = "http://www.w3.org/2001/XMLSchema#int";
    auto input = "2147483647";
    auto output = RegisteredDatatype<xsd::Int, xsd_int>::from_string(input);
    CHECK(output == 2147483647);
    CHECK(RegisteredDatatype<xsd::Int, xsd_int>::datatype_iri() == int_iri);

    input = "-2147483648";
    output = RegisteredDatatype<xsd::Int, xsd_int>::from_string(input);
    CHECK(output == -2147483648);
    CHECK(RegisteredDatatype<xsd::Int, xsd_int>::datatype_iri() == int_iri);
}

TEST_CASE("Datatype Short") {

    auto short_iri = "http://www.w3.org/2001/XMLSchema#short";
    auto input = "32767";
    auto output = RegisteredDatatype<xsd::Short, xsd_short>::from_string(input);
    CHECK(output == 32767);
    CHECK(RegisteredDatatype<xsd::Short, xsd_short>::datatype_iri() == short_iri);

    input = "-32768";
    output = RegisteredDatatype<xsd::Short, xsd_short>::from_string(input);
    CHECK(output == -32768);
    CHECK(RegisteredDatatype<xsd::Short, xsd_short>::datatype_iri() == short_iri);

/*    input = "-32769";
    CHECK_THROWS_WITH_AS(output = RegisteredDatatype<xsd::Short, xsd_short>::from_string(input), "XSD Parsing Error", std::runtime_error);*/
}

TEST_CASE("Datatype Byte") {

    auto byte_iri = "http://www.w3.org/2001/XMLSchema#byte";
    auto input = "127";
    auto output = RegisteredDatatype<xsd::Byte, xsd_byte>::from_string(input);
    CHECK(output == 127);
    CHECK(RegisteredDatatype<xsd::Byte, xsd_byte>::datatype_iri() == byte_iri);

    input = "-128";
    output = RegisteredDatatype<xsd::Byte, xsd_byte>::from_string(input);
    CHECK(output == -128);
    CHECK(RegisteredDatatype<xsd::Byte, xsd_byte>::datatype_iri() == byte_iri);

/*    input = "-129";
    CHECK_THROWS_WITH_AS(output = RegisteredDatatype<xsd::Byte, xsd_byte>::from_string(input), "XSD Parsing Error", std::runtime_error);*/
}

TEST_CASE("Datatype UnsignedInt") {

    auto uInt_iri = "http://www.w3.org/2001/XMLSchema#unsignedInt";
    auto input = "0";
    auto output = RegisteredDatatype<xsd::UnsignedInt, xsd_uint>::from_string(input);
    CHECK(output == 0);
    CHECK(RegisteredDatatype<xsd::UnsignedInt, xsd_uint>::datatype_iri() == uInt_iri);

    input = "4294967295";
    output = RegisteredDatatype<xsd::UnsignedInt, xsd_uint>::from_string(input);
    CHECK(output == 4294967295);
    CHECK(RegisteredDatatype<xsd::UnsignedInt, xsd_uint>::datatype_iri() == uInt_iri);

/*    input = "4294967296";
    CHECK_THROWS_WITH_AS(output = RegisteredDatatype<xsd::UnsignedInt, xsd_uint>::from_string(input), "XSD Parsing Error", std::runtime_error);*/
}

TEST_CASE("Datatype UnsignedShort") {

    auto uShort_iri = "http://www.w3.org/2001/XMLSchema#unsignedShort";
    auto input = "0";
    auto output = RegisteredDatatype<xsd::UnsignedShort, xsd_ushort>::from_string(input);
    CHECK(output == 0);
    CHECK(RegisteredDatatype<xsd::UnsignedShort, xsd_ushort>::datatype_iri() == uShort_iri);

    input = "65535";
    output = RegisteredDatatype<xsd::UnsignedShort, xsd_ushort>::from_string(input);
    CHECK(output == 65535);
    CHECK(RegisteredDatatype<xsd::UnsignedShort, xsd_ushort>::datatype_iri() == uShort_iri);

/*    input = "-1";
    CHECK_THROWS_WITH_AS(output = RegisteredDatatype<xsd::UnsignedShort, xsd_ushort>::from_string(input), "XSD Parsing Error", std::runtime_error);*/
}

TEST_CASE("Datatype UnsignedByte") {

    auto uByte_iri = "http://www.w3.org/2001/XMLSchema#unsignedByte";
    auto input = "0";
    auto output = RegisteredDatatype<xsd::UnsignedByte, xsd_ubyte>::from_string(input);
    CHECK(output == 0);
    CHECK(RegisteredDatatype<xsd::UnsignedByte, xsd_ubyte>::datatype_iri() == uByte_iri);

    input = "255";
    output = RegisteredDatatype<xsd::UnsignedByte, xsd_ubyte>::from_string(input);
    CHECK(output == 255);
    CHECK(RegisteredDatatype<xsd::UnsignedByte, xsd_ubyte>::datatype_iri() == uByte_iri);

/*    input = "-1";
    CHECK_THROWS_WITH_AS(output = RegisteredDatatype<xsd::UnsignedByte, xsd_ubyte>::from_string(input), "XSD Parsing Error", std::runtime_error);*/
}

TEST_CASE("Datatype Float") {

    auto Float_iri = "http://www.w3.org/2001/XMLSchema#float";
    auto input = "1.0";
    auto output = RegisteredDatatype<xsd::Float, xsd_float>::from_string(input);
    CHECK(output == 1.0);
    CHECK(RegisteredDatatype<xsd::Float, xsd_float>::datatype_iri() == Float_iri);

    input = "222.00";
    output = RegisteredDatatype<xsd::Float, xsd_float>::from_string(input);
    CHECK(output == 222.00);
    CHECK(RegisteredDatatype<xsd::Float, xsd_float>::datatype_iri() == Float_iri);


/*    input = "4294967296";
    CHECK_THROWS_WITH_AS(output = RegisteredDatatype<xsd::Float, xsd_float>::from_string(input), "XSD Parsing Error", std::runtime_error);*/

}

TEST_CASE("Datatype Double") {

    auto Double_iri = "http://www.w3.org/2001/XMLSchema#double";
    auto input = "1.0";
    auto output = RegisteredDatatype<xsd::Double, xsd_double>::from_string(input);
    CHECK(output == 1.0);
    CHECK(RegisteredDatatype<xsd::Double, xsd_double>::datatype_iri() == Double_iri);

    input = "222.00";
    output = RegisteredDatatype<xsd::Double, xsd_double>::from_string(input);
    CHECK(output == 222.00);
    CHECK(RegisteredDatatype<xsd::Double, xsd_double>::datatype_iri() == Double_iri);


/*    input = "4294967296";
    CHECK_THROWS_WITH_AS(output = RegisteredDatatype<xsd::Double, xsd_double>::from_string(input), "XSD Parsing Error", std::runtime_error);*/

}

TEST_CASE("Datatype Boolean") {

    auto Boolean_iri = "http://www.w3.org/2001/XMLSchema#boolean";
    auto input = "1";
    auto output = RegisteredDatatype<xsd::Boolean, xsd_boolean>::from_string(input);
    CHECK(output == true);
    CHECK(RegisteredDatatype<xsd::Boolean, xsd_boolean>::datatype_iri() == Boolean_iri);

    input = "0";
    output = RegisteredDatatype<xsd::Boolean, xsd_boolean>::from_string(input);
    CHECK(output == false);
    CHECK(RegisteredDatatype<xsd::Boolean, xsd_boolean>::datatype_iri() == Boolean_iri);

    input = "true";
    output = RegisteredDatatype<xsd::Boolean, xsd_boolean>::from_string(input);
    CHECK(output == true);
    CHECK(RegisteredDatatype<xsd::Boolean, xsd_boolean>::datatype_iri() == Boolean_iri);

    input = "false";
    output = RegisteredDatatype<xsd::Boolean, xsd_boolean>::from_string(input);
    CHECK(output == false);
    CHECK(RegisteredDatatype<xsd::Boolean, xsd_boolean>::datatype_iri() == Boolean_iri);

/*    input = "22";
    CHECK_THROWS_WITH_AS(output = RegisteredDatatype<xsd::Boolean, xsd_boolean>::from_string(input), "XSD Parsing Error", std::runtime_error);*/
}

TEST_CASE("Datatype Long") {

    auto Long_iri = "http://www.w3.org/2001/XMLSchema#long";
    auto input = "9223372036854775807";
    auto output = RegisteredDatatype<xsd::Long, xsd_long>::from_string(input);
    CHECK(output == 9223372036854775807);
    CHECK(RegisteredDatatype<xsd::Long, xsd_long>::datatype_iri() == Long_iri);

    input = "-9223372036854775808";
    output = RegisteredDatatype<xsd::Long, xsd_long>::from_string(input);
    CHECK(output == -9223372036854775808);
    CHECK(RegisteredDatatype<xsd::Long, xsd_long>::datatype_iri() == Long_iri);


/*    input = "-9223372036854775809";
    CHECK_THROWS_WITH_AS(output = RegisteredDatatype<xsd::Long, xsd_long>::from_string(input), "XSD Parsing Error", std::runtime_error);*/

}

TEST_CASE("Datatype UnsignedLong") {

    auto UnsignedLong_iri = "http://www.w3.org/2001/XMLSchema#unsignedLong";
    auto input = "18446744073709551615";
    auto output = RegisteredDatatype<xsd::UnsignedLong, xsd_ulong>::from_string(input);
    CHECK(output == 18446744073709551615);
    CHECK(RegisteredDatatype<xsd::UnsignedLong, xsd_ulong>::datatype_iri() == UnsignedLong_iri);

    input = "0";
    output = RegisteredDatatype<xsd::UnsignedLong, xsd_ulong>::from_string(input);
    CHECK(output == 0);
    CHECK(RegisteredDatatype<xsd::UnsignedLong, xsd_ulong>::datatype_iri() == UnsignedLong_iri);


/*    input = "-1";
    CHECK_THROWS_WITH_AS(output = RegisteredDatatype<xsd::UnsignedLong>::from_string(input), "XSD Parsing Error", std::runtime_error);*/

}

TEST_CASE("Datatype Time") {
    auto Time_iri = "http://www.w3.org/2001/XMLSchema#time";
    auto input = "19:32:00";
    // we can use the predefined constexpr c string
    auto output = RegisteredDatatype<xsd::Time, xsd_time>::from_string(input);

    char str[32];
    std::strftime(str, 32, "%H:%M:%S", std::localtime(&output));
    std::string time_str(str);

    CHECK(time_str == input);
    CHECK(RegisteredDatatype<xsd::Time, xsd_time>::datatype_iri() == Time_iri);
}

TEST_CASE("Datatype Date") {
    auto Date_iri = "http://www.w3.org/2001/XMLSchema#date";
    auto input = "2021-12-23";
    // we can use the predefined constexpr c string
    auto output = RegisteredDatatype<xsd::Date, xsd_date>::from_string(input);

    char str[32];
    std::strftime(str, 32, "%Y-%m-%d", std::localtime(&output));
    std::string time_str(str);

    CHECK(time_str == "2021-12-23");
    CHECK(RegisteredDatatype<xsd::Date, xsd_date>::datatype_iri() == Date_iri);
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
    auto dateTime_iri = "http://www.w3.org/2001/XMLSchema#duration";
    auto input = "P15D";
    // we can use the predefined constexpr c string
    auto output = RegisteredDatatype<xsd::DateTime, xsd_dateTime>::from_string(input);

    char str[32];
    std::strftime(str, 32, "P%dD", std::localtime(&output));
    std::string time_str(str);

    CHECK(time_str == input);
    CHECK(RegisteredDatatype<xsd::DateTime, xsd_dateTime>::datatype_iri() == dateTime_iri);
}

/*
TEST_CASE("Compare Literals"){
    auto lit1 = rdf4cpp::rdf::Literal{"0", rdf4cpp::rdf::IRI{RegisteredDatatype<xsd::Boolean>::datatype_iri()}};
    auto lit2 = rdf4cpp::rdf::Literal{"1", rdf4cpp::rdf::IRI{RegisteredDatatype<xsd::Boolean>::datatype_iri()}};

    if(lit1 == lit2) std::cout << "True" << std::endl;
    else std::cout << "False" << std::endl;
}*/
