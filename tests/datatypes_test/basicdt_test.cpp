#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf::datatypes;

/*TEST_CASE("Datatype Integer") {

    auto int_iri = "http://www.w3.org/2001/XMLSchema#int";
    auto input = "2147483647";
    auto output = RegisteredDatatype<xsd::Int>::from_string(input);
    CHECK(output == 2147483647);
    CHECK(RegisteredDatatype<xsd::Int>::datatype_iri() == int_iri);

    input = "-2147483648";
    output = RegisteredDatatype<xsd::Int>::from_string(input);
    CHECK(output == -2147483648);
    CHECK(RegisteredDatatype<xsd::Int>::datatype_iri() == int_iri);
}

TEST_CASE("Datatype Short") {

    auto short_iri = "http://www.w3.org/2001/XMLSchema#short";
    auto input = "32767";
    auto output = RegisteredDatatype<xsd::Short>::from_string(input);
    CHECK(output == 32767);
    CHECK(RegisteredDatatype<xsd::Short>::datatype_iri() == short_iri);

    input = "-32768";
    output = RegisteredDatatype<xsd::Short>::from_string(input);
    CHECK(output == -32768);
    CHECK(RegisteredDatatype<xsd::Short>::datatype_iri() == short_iri);

    input = "-32769";
    CHECK_THROWS_WITH_AS(output = RegisteredDatatype<xsd::Short>::from_string(input), "XSD Parsing Error", std::runtime_error);
}

TEST_CASE("Datatype Byte") {

    auto byte_iri = "http://www.w3.org/2001/XMLSchema#byte";
    auto input = "127";
    auto output = RegisteredDatatype<xsd::Byte>::from_string(input);
    CHECK(output == 127);
    CHECK(RegisteredDatatype<xsd::Byte>::datatype_iri() == byte_iri);

    input = "-128";
    output = RegisteredDatatype<xsd::Byte>::from_string(input);
    CHECK(output == -128);
    CHECK(RegisteredDatatype<xsd::Byte>::datatype_iri() == byte_iri);

    input = "-129";
    CHECK_THROWS_WITH_AS(output = RegisteredDatatype<xsd::Byte>::from_string(input), "XSD Parsing Error", std::runtime_error);
}

TEST_CASE("Datatype UnsignedInt") {

    auto uInt_iri = "http://www.w3.org/2001/XMLSchema#unsignedInt";
    auto input = "0";
    auto output = RegisteredDatatype<xsd::UnsignedInt>::from_string(input);
    CHECK(output == 0);
    CHECK(RegisteredDatatype<xsd::UnsignedInt>::datatype_iri() == uInt_iri);

    input = "4294967295";
    output = RegisteredDatatype<xsd::UnsignedInt>::from_string(input);
    CHECK(output == 4294967295);
    CHECK(RegisteredDatatype<xsd::UnsignedInt>::datatype_iri() == uInt_iri);

    input = "4294967296";
    CHECK_THROWS_WITH_AS(output = RegisteredDatatype<xsd::UnsignedInt>::from_string(input), "XSD Parsing Error", std::runtime_error);
}

TEST_CASE("Datatype UnsignedShort") {

    auto uShort_iri = "http://www.w3.org/2001/XMLSchema#unsignedShort";
    auto input = "0";
    auto output = RegisteredDatatype<xsd::UnsignedShort>::from_string(input);
    CHECK(output == 0);
    CHECK(RegisteredDatatype<xsd::UnsignedShort>::datatype_iri() == uShort_iri);

    input = "65535";
    output = RegisteredDatatype<xsd::UnsignedShort>::from_string(input);
    CHECK(output == 65535);
    CHECK(RegisteredDatatype<xsd::UnsignedShort>::datatype_iri() == uShort_iri);

    input = "-1";
    CHECK_THROWS_WITH_AS(output = RegisteredDatatype<xsd::UnsignedShort>::from_string(input), "XSD Parsing Error", std::runtime_error);
}

TEST_CASE("Datatype UnsignedByte") {

    auto uByte_iri = "http://www.w3.org/2001/XMLSchema#unsignedByte";
    auto input = "0";
    auto output = RegisteredDatatype<xsd::UnsignedByte>::from_string(input);
    CHECK(output == 0);
    CHECK(RegisteredDatatype<xsd::UnsignedByte>::datatype_iri() == uByte_iri);

    input = "255";
    output = RegisteredDatatype<xsd::UnsignedByte>::from_string(input);
    CHECK(output == 255);
    CHECK(RegisteredDatatype<xsd::UnsignedByte>::datatype_iri() == uByte_iri);

    input = "-1";
    CHECK_THROWS_WITH_AS(output = RegisteredDatatype<xsd::UnsignedByte>::from_string(input), "XSD Parsing Error", std::runtime_error);
}

TEST_CASE("Datatype Float") {

    auto Float_iri = "http://www.w3.org/2001/XMLSchema#float";
    auto input = "1.0";
    auto output = RegisteredDatatype<xsd::Float>::from_string(input);
    CHECK(output == 1.0);
    CHECK(RegisteredDatatype<xsd::Float>::datatype_iri() == Float_iri);

    input = "222.00";
    output = RegisteredDatatype<xsd::Float>::from_string(input);
    CHECK(output == 222.00);
    CHECK(RegisteredDatatype<xsd::Float>::datatype_iri() == Float_iri);

*/
/*    input = "4294967296";
    CHECK_THROWS_WITH_AS(output = RegisteredDatatype<xsd::Float>::from_string(input), "XSD Parsing Error", std::runtime_error);*/
/*
}

TEST_CASE("Datatype Double") {

    auto Double_iri = "http://www.w3.org/2001/XMLSchema#double";
    auto input = "1.0";
    auto output = RegisteredDatatype<xsd::Double>::from_string(input);
    CHECK(output == 1.0);
    CHECK(RegisteredDatatype<xsd::Double>::datatype_iri() == Double_iri);

    input = "222.00";
    output = RegisteredDatatype<xsd::Double>::from_string(input);
    CHECK(output == 222.00);
    CHECK(RegisteredDatatype<xsd::Double>::datatype_iri() == Double_iri);

*/
/*    input = "4294967296";
    CHECK_THROWS_WITH_AS(output = RegisteredDatatype<xsd::Double>::from_string(input), "XSD Parsing Error", std::runtime_error);*/
/*
}

TEST_CASE("Datatype Boolean") {

    auto Boolean_iri = "http://www.w3.org/2001/XMLSchema#boolean";
    auto input = "1";
    auto output = RegisteredDatatype<xsd::Boolean>::from_string(input);
    CHECK(output == true);
    CHECK(RegisteredDatatype<xsd::Boolean>::datatype_iri() == Boolean_iri);

    input = "0";
    output = RegisteredDatatype<xsd::Boolean>::from_string(input);
    CHECK(output == false);
    CHECK(RegisteredDatatype<xsd::Boolean>::datatype_iri() == Boolean_iri);

    input = "true";
    output = RegisteredDatatype<xsd::Boolean>::from_string(input);
    CHECK(output == true);
    CHECK(RegisteredDatatype<xsd::Boolean>::datatype_iri() == Boolean_iri);

    input = "false";
    output = RegisteredDatatype<xsd::Boolean>::from_string(input);
    CHECK(output == false);
    CHECK(RegisteredDatatype<xsd::Boolean>::datatype_iri() == Boolean_iri);

    input = "22";
    CHECK_THROWS_WITH_AS(output = RegisteredDatatype<xsd::Boolean>::from_string(input), "XSD Parsing Error", std::runtime_error);
}

TEST_CASE("Datatype Long") {

    auto Long_iri = "http://www.w3.org/2001/XMLSchema#long";
    auto input = "9223372036854775807";
    auto output = RegisteredDatatype<xsd::Long>::from_string(input);
    CHECK(output == 9223372036854775807);
    CHECK(RegisteredDatatype<xsd::Long>::datatype_iri() == Long_iri);

    input = "-9223372036854775808";
    output = RegisteredDatatype<xsd::Long>::from_string(input);
    CHECK(output == -9223372036854775808);
    CHECK(RegisteredDatatype<xsd::Long>::datatype_iri() == Long_iri);

*/
/*    input = "-9223372036854775809";
    CHECK_THROWS_WITH_AS(output = RegisteredDatatype<xsd::Long>::from_string(input), "XSD Parsing Error", std::runtime_error);*/
/*
}

TEST_CASE("Datatype UnsignedLong") {

    auto UnsignedLong_iri = "http://www.w3.org/2001/XMLSchema#unsignedLong";
    auto input = "18446744073709551615";
    auto output = RegisteredDatatype<xsd::UnsignedLong>::from_string(input);
    CHECK(output == 18446744073709551615);
    CHECK(RegisteredDatatype<xsd::UnsignedLong>::datatype_iri() == UnsignedLong_iri);

    input = "0";
    output = RegisteredDatatype<xsd::UnsignedLong>::from_string(input);
    CHECK(output == 0);
    CHECK(RegisteredDatatype<xsd::UnsignedLong>::datatype_iri() == UnsignedLong_iri);

*/
/*    input = "-1";
    CHECK_THROWS_WITH_AS(output = RegisteredDatatype<xsd::UnsignedLong>::from_string(input), "XSD Parsing Error", std::runtime_error);*/
/*
}*/

TEST_CASE("Datatype Time") {
    auto Time_iri = "http://www.w3.org/2001/XMLSchema#time";
    auto input = "19:32:00";
    // we can use the predefined constexpr c string
    auto output = RegisteredDatatype<xsd::Time, xsd_time>::from_string(input);
    // or use a c string constant in place:
    output = RegisteredDatatype<xsd::Time, "http://www.w3.org/2001/XMLSchema#time">::from_string(input);

    char str[32];
    std::strftime(str, 32, "%H:%M:%S", std::localtime(&output));
    std::string time_str(str);

    CHECK(time_str == "19:32:00");
    CHECK(RegisteredDatatype<xsd::Time, xsd_time>::datatype_iri() == Time_iri);
}

/*
TEST_CASE("Compare Literals"){
    auto lit1 = rdf4cpp::rdf::Literal{"0", rdf4cpp::rdf::IRI{RegisteredDatatype<xsd::Boolean>::datatype_iri()}};
    auto lit2 = rdf4cpp::rdf::Literal{"1", rdf4cpp::rdf::IRI{RegisteredDatatype<xsd::Boolean>::datatype_iri()}};

    if(lit1 == lit2) std::cout << "True" << std::endl;
    else std::cout << "False" << std::endl;
}*/
