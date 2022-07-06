#include <date/date.h>
#include <date/tz.h>
#include <rdf4cpp/rdf.hpp>

#include <iostream>

int main() {
    using namespace rdf4cpp::rdf;

    /*    auto utcTime = std::chrono::system_clock::now();
    std::cout << "Local time" << std::endl;
    auto localTime = date::make_zoned(date::current_zone(), utcTime);
    std::cout << "  " << localTime << std::endl;
    std::cout << "  " << date::floor<std::chrono::seconds>(localTime.get_local_time());*/

    std::cout << "GMonthDay Literal Constructor" << std::endl;
    Literal month_day_05_20("--05-20", IRI{"http://www.w3.org/2001/XMLSchema#gMonthDay"});
    std::cout << month_day_05_20 << std::endl;
    auto month_day_05_20_val = month_day_05_20.value<datatypes::xsd::GMonthDay>();

    std::cout << "GDay Literal Constructor : ";
    Literal day_20("---20", IRI{"http://www.w3.org/2001/XMLSchema#gDay"});
    std::cout << day_20 << "\t";
    auto day_20_val = day_20.value<datatypes::xsd::GDay>();
    std::cout << day_20_val << std::endl;

    std::cout << "GDay from GMonthDay value : ";
    day_20 = Literal::make<datatypes::xsd::GDay>(month_day_05_20_val);
    std::cout << day_20 << "\t";
    day_20_val = day_20.value<datatypes::xsd::GDay>();
    std::cout << day_20_val << std::endl;

    std::cout << "GMonth Literal Constructor : ";
    Literal month_05("--05", IRI{"http://www.w3.org/2001/XMLSchema#gMonth"});
    std::cout << month_05 << "\t";
    auto month_05_val = month_05.value<datatypes::xsd::GMonth>();
    std::cout << month_05_val << std::endl;

    std::cout << "GMonth from GMonthDay value : ";
    month_05 = Literal::make<datatypes::xsd::GMonth>(month_day_05_20_val);
    std::cout << month_05 << "\t";
    month_05_val = month_05.value<datatypes::xsd::GMonth>();
    std::cout << month_05_val << std::endl;
}