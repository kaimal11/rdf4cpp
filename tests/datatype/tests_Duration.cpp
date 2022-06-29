#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rdf4cpp/rdf.hpp>

using namespace rdf4cpp::rdf;

TEST_CASE("Datatype Duration") {

    constexpr auto correct_type_iri_cstr = "http://www.w3.org/2001/XMLSchema#duration";

    CHECK(std::string(datatypes::xsd::Duration::identifier) == correct_type_iri_cstr);

    auto type_iri = IRI(datatypes::xsd::Duration::identifier);
    CHECK(type_iri.identifier() == correct_type_iri_cstr);

    using type = datatypes::xsd::Duration::cpp_type;

    CHECK(std::is_same_v<type, time_t>);

    struct tm tm{};

    //default values
    tm.tm_year = 1;  // year
    tm.tm_mon = 1;  // month
    tm.tm_mday = 1;  // day
    tm.tm_sec = 1;   // seconds of minutes
    tm.tm_min = 1;   // minutes of hour
    tm.tm_hour = 1; // hours of day
    tm.tm_isdst = -1; // daylight saving

    auto value = mktime(&tm);

    auto lit1 = Literal::make<datatypes::xsd::Duration>(value);
    CHECK(lit1.value<datatypes::xsd::Duration>() == value);

    std::cout<< lit1 <<std::endl;

    //default values
    tm.tm_year = 1;  // year
    tm.tm_mon = 0;  // month
    tm.tm_mday = 0;  // day
    tm.tm_sec = 0;   // seconds of minutes
    tm.tm_min = 0;   // minutes of hour
    tm.tm_hour = 0; // hours of day
    tm.tm_isdst = -1; // daylight saving

    value = mktime(&tm);

    auto lit2 = Literal::make<datatypes::xsd::Duration>(value);
    CHECK(lit2.value<datatypes::xsd::Duration>() == value);

    std::cout<< lit2 <<std::endl;

    //default values
    tm.tm_year = 0;  // year
    tm.tm_mon = 1;  // month
    tm.tm_mday = 0;  // day
    tm.tm_sec = 0;   // seconds of minutes
    tm.tm_min = 0;   // minutes of hour
    tm.tm_hour = 0; // hours of day
    tm.tm_isdst = -1; // daylight saving

    value = mktime(&tm);

    auto lit3 = Literal::make<datatypes::xsd::Duration>(value);
    CHECK(lit3.value<datatypes::xsd::Duration>() == value);

    std::cout<< lit3 <<std::endl;

    //default values
    tm.tm_year = 0;  // year
    tm.tm_mon = 0;  // month
    tm.tm_mday = 1;  // day
    tm.tm_sec = 0;   // seconds of minutes
    tm.tm_min = 0;   // minutes of hour
    tm.tm_hour = 0; // hours of day
    tm.tm_isdst = -1; // daylight saving

    value = mktime(&tm);

    auto lit4 = Literal::make<datatypes::xsd::Duration>(value);
    CHECK(lit4.value<datatypes::xsd::Duration>() == value);

    std::cout<< lit4 <<std::endl;

    //default values
    tm.tm_year = 0;  // year
    tm.tm_mon = 0;  // month
    tm.tm_mday = 0;  // day
    tm.tm_sec = 1;   // seconds of minutes
    tm.tm_min = 0;   // minutes of hour
    tm.tm_hour = 0; // hours of day
    tm.tm_isdst = 0; // daylight saving

    value = mktime(&tm);

    auto lit5 = Literal::make<datatypes::xsd::Duration>(value);
    CHECK(lit5.value<datatypes::xsd::Duration>() == value);

    std::cout<< lit5 <<std::endl;
/*
    //default values
    tm.tm_year = 0;  // year
    tm.tm_mon = 0;  // month
    tm.tm_mday = 0;  // day
    tm.tm_sec = 0;   // seconds of minutes
    tm.tm_min = 1;   // minutes of hour
    tm.tm_hour = 0; // hours of day
    tm.tm_isdst = -1; // daylight saving

    value = mktime(&tm);

    auto lit6 = Literal::make<datatypes::xsd::Duration>(value);
    CHECK(lit6.value<datatypes::xsd::Duration>() == value);

    std::cout<< lit6 <<std::endl;

    //default values
    tm.tm_year = 0;  // year
    tm.tm_mon = 0;  // month
    tm.tm_mday = 0;  // day
    tm.tm_sec = 0;   // seconds of minutes
    tm.tm_min = 0;   // minutes of hour
    tm.tm_hour = 1; // hours of day
    tm.tm_isdst = -1; // daylight saving

    value = mktime(&tm);

    auto lit7 = Literal::make<datatypes::xsd::Duration>(value);
    CHECK(lit7.value<datatypes::xsd::Duration>() == value);

    std::cout<< lit7 <<std::endl;*/

    //default values
    tm.tm_year = 1;  // year
    tm.tm_mon = 1;  // month
    tm.tm_mday = 0;  // day
    tm.tm_sec = 0;   // seconds of minutes
    tm.tm_min = 0;   // minutes of hour
    tm.tm_hour = 0; // hours of day
    tm.tm_isdst = -1; // daylight saving

    value = mktime(&tm);

    auto lit8 = Literal::make<datatypes::xsd::Duration>(value);
    CHECK(lit8.value<datatypes::xsd::Duration>() == value);

    std::cout<< lit8 <<std::endl;

    //default values
    tm.tm_year = 1;  // year
    tm.tm_mon = 0;  // month
    tm.tm_mday = 1;  // day
    tm.tm_sec = 0;   // seconds of minutes
    tm.tm_min = 0;   // minutes of hour
    tm.tm_hour = 0; // hours of day
    tm.tm_isdst = -1; // daylight saving

    value = mktime(&tm);

    auto lit9 = Literal::make<datatypes::xsd::Duration>(value);
    CHECK(lit9.value<datatypes::xsd::Duration>() == value);

    std::cout<< lit9 <<std::endl;

    //default values
    tm.tm_year = 1;  // year
    tm.tm_mon = 0;  // month
    tm.tm_mday = 0;  // day
    tm.tm_sec = 1;   // seconds of minutes
    tm.tm_min = 0;   // minutes of hour
    tm.tm_hour = 0; // hours of day
    tm.tm_isdst = -1; // daylight saving

    value = mktime(&tm);

    auto lit10 = Literal::make<datatypes::xsd::Duration>(value);
    CHECK(lit10.value<datatypes::xsd::Duration>() == value);

    std::cout<< lit10 <<std::endl;

    //default values
    tm.tm_year = 1;  // year
    tm.tm_mon = 0;  // month
    tm.tm_mday = 0;  // day
    tm.tm_sec = 0;   // seconds of minutes
    tm.tm_min = 1;   // minutes of hour
    tm.tm_hour = 0; // hours of day
    tm.tm_isdst = -1; // daylight saving

    value = mktime(&tm);

    auto lit11 = Literal::make<datatypes::xsd::Duration>(value);
    CHECK(lit11.value<datatypes::xsd::Duration>() == value);

    std::cout<< lit11 <<std::endl;

    //default values
    tm.tm_year = 1;  // year
    tm.tm_mon = 0;  // month
    tm.tm_mday = 0;  // day
    tm.tm_sec = 0;   // seconds of minutes
    tm.tm_min = 0;   // minutes of hour
    tm.tm_hour = 1; // hours of day
    tm.tm_isdst = -1; // daylight saving

    value = mktime(&tm);

    auto lit12 = Literal::make<datatypes::xsd::Duration>(value);
    CHECK(lit12.value<datatypes::xsd::Duration>() == value);

    std::cout<< lit12 <<std::endl;


    //auto lit1 = Literal{"P1D", type_iri};
    //CHECK(lit1.value<datatypes::xsd::Duration>() == 1.17e-38);

}
