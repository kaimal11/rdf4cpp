#include <rdf4cpp/rdf.hpp>


#include <iostream>

int main() {
    using namespace rdf4cpp::rdf;

    //xsd::Float
    constexpr const char xsd_float[] = "http://www.w3.org/2001/XMLSchema#float";
    Literal float_1_1("1.1", IRI{xsd_float});

    std::cout << float_1_1 << std::endl;
    std::any any_float_ = float_1_1.value();
    std::cout << any_cast<float>(any_float_) << std::endl;
    auto float_ = float_1_1.value<float, xsd_float>();  // we know the type at compile time
    //[[maybe_unused]] auto int_ = float_1_1.value<int, xsd_float>();
    std::cout << float_ << std::endl;

    // update value
    float_ *= any_cast<datatypes::xsd::Float>(any_float_) * 3;
    // datatypes::xsd::Float is an alias for the built-in type float
    std::cout << float_ << std::endl;
    // make a new literal with new value
    Literal updated_float = Literal::make<datatypes::xsd::Float, xsd_float>(float_);
    std::cout << updated_float << std::endl;

    //xsd::Int
    constexpr const char xsd_int[] = "http://www.w3.org/2001/XMLSchema#int";
    Literal int_2("1", IRI{xsd_int});

    std::cout << int_2 << std::endl;
    std::any any_int_ = int_2.value();
    std::cout << any_cast<int>(any_int_) << std::endl;
    auto int_ = int_2.value<int32_t, xsd_int>();  // we know the type at compile time
    //[[maybe_unused]] auto int_ = float_1_1.value<int, xsd_float>();
    std::cout << int_ << std::endl;

    // update value
    int_ *= any_cast<datatypes::xsd::Int>(any_int_) * 3;
    // datatypes::xsd::Int is an alias for the built-in type int64_t
    std::cout << int_ << std::endl;
    // make a new literal with new value
    Literal updated_int = Literal::make<datatypes::xsd::Int, xsd_int>(int_);
    std::cout << updated_int << std::endl;

    //xsd::Decimal
    constexpr const char xsd_decimal[] = "http://www.w3.org/2001/XMLSchema#decimal";
    Literal decimal_2_1("2.1", IRI{xsd_decimal});

    std::cout << decimal_2_1 << std::endl;
    std::any any_decimal_ = decimal_2_1.value();
    std::cout << any_cast<double>(any_decimal_) << std::endl;
    auto decimal_ = decimal_2_1.value<double, xsd_decimal>();  // we know the type at compile time
    //[[maybe_unused]] auto int_ = float_1_1.value<int, xsd_float>();
    std::cout << decimal_ << std::endl;

    // update value
    decimal_ *= any_cast<datatypes::xsd::Decimal>(any_decimal_) * 3;
    // datatypes::xsd::Decimal is an alias for the built-in type double
    std::cout << decimal_ << std::endl;
    // make a new literal with new value
    Literal updated_decimal = Literal::make<datatypes::xsd::Decimal, xsd_decimal>(decimal_);
    std::cout << updated_decimal << std::endl;

    //xsd::PositiveInteger
    constexpr const char xsd_positiveInteger[] = "http://www.w3.org/2001/XMLSchema#positiveInteger";
    Literal pInteger_1("1", IRI{xsd_positiveInteger});

    std::cout << pInteger_1 << std::endl;
    std::any any_pInteger_ = pInteger_1.value();
    std::cout << any_cast<double>(any_pInteger_) << std::endl;
    auto pInteger_ = pInteger_1.value<double, xsd_positiveInteger>();  // we know the type at compile time
    //[[maybe_unused]] auto int_ = float_1_1.value<int, xsd_float>();
    std::cout << pInteger_ << std::endl;

    // update value
    pInteger_ *= any_cast<datatypes::xsd::PositiveInteger>(any_pInteger_) * 3;
    // datatypes::xsd::PositiveInteger is an alias for the built-in type double
    std::cout << pInteger_ << std::endl;
    // make a new literal with new value
    Literal updated_pInteger = Literal::make<datatypes::xsd::PositiveInteger, xsd_positiveInteger>(pInteger_);
    std::cout << updated_pInteger << std::endl;

    //xsd::NegativeInteger
    constexpr const char xsd_negativeInteger[] = "http://www.w3.org/2001/XMLSchema#negativeInteger";
    Literal nInteger_m1("-1", IRI{xsd_negativeInteger});

    std::cout << nInteger_m1 << std::endl;
    std::any any_nInteger_ = nInteger_m1.value();
    std::cout << any_cast<double>(any_nInteger_) << std::endl;
    auto nInteger_ = nInteger_m1.value<double, xsd_negativeInteger>();  // we know the type at compile time
    //[[maybe_unused]] auto int_ = float_1_1.value<int, xsd_float>();
    std::cout << nInteger_ << std::endl;

    // update value
    nInteger_ *= any_cast<datatypes::xsd::NegativeInteger>(any_nInteger_) * 3;
    // datatypes::xsd::NegativeInteger is an alias for the built-in type double
    std::cout << nInteger_ << std::endl;
    // make a new literal with new value
    Literal updated_nInteger = Literal::make<datatypes::xsd::NegativeInteger, xsd_negativeInteger>(nInteger_);
    std::cout << updated_nInteger << std::endl;

    //xsd::Boolean
    constexpr const char xsd_boolean[] = "http://www.w3.org/2001/XMLSchema#boolean";
    Literal boolean_true("false", IRI{xsd_boolean});

    std::cout << boolean_true << std::endl;
    std::any any_boolean_ = boolean_true.value();
    std::cout << any_cast<bool>(any_boolean_) << std::endl;
    auto boolean_ = boolean_true.value<bool, xsd_boolean>();  // we know the type at compile time
    //[[maybe_unused]] auto int_ = float_1_1.value<int, xsd_float>();
    std::cout << boolean_ << std::endl;

    // update value
    boolean_ = !any_cast<datatypes::xsd::Boolean>(any_boolean_);
    // datatypes::xsd::Boolean is an alias for the built-in type bool
    std::cout << boolean_ << std::endl;
    // make a new literal with new value
    Literal updated_boolean = Literal::make<datatypes::xsd::Boolean, xsd_boolean>(boolean_);
    std::cout << updated_boolean << std::endl;
}