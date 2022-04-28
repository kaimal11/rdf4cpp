## C++ language configuration boilerplate

include(FetchContent)

FetchContent_Declare(
        DocTest
        GIT_REPOSITORY "https://github.com/onqtam/doctest"
        GIT_TAG  "2.4.6"
)
FetchContent_MakeAvailable(DocTest)

# add the executable for all tests
add_executable(tests_String datatype/tests_String.cpp)
target_link_libraries(tests_String
        doctest
        rdf4cpp
        )
set_property(TARGET tests_String PROPERTY CXX_STANDARD 20)

add_executable(tests_Boolean datatype/tests_Boolean.cpp)
target_link_libraries(tests_Boolean
        doctest
        rdf4cpp
        )
set_property(TARGET tests_Boolean PROPERTY CXX_STANDARD 20)

add_executable(tests_Decimal datatype/tests_Decimal.cpp)
target_link_libraries(tests_Decimal
        doctest
        rdf4cpp
        )
set_property(TARGET tests_Decimal PROPERTY CXX_STANDARD 20)

add_executable(tests_Integer datatype/tests_Integer.cpp)
target_link_libraries(tests_Integer
        doctest
        rdf4cpp
        )
set_property(TARGET tests_Integer PROPERTY CXX_STANDARD 20)

add_executable(tests_Double datatype/tests_Double.cpp)
target_link_libraries(tests_Double
        doctest
        rdf4cpp
        )
set_property(TARGET tests_Double PROPERTY CXX_STANDARD 20)

add_executable(tests_Float datatype/tests_Float.cpp)
target_link_libraries(tests_Float
        doctest
        rdf4cpp
        )
set_property(TARGET tests_Float PROPERTY CXX_STANDARD 20)

add_executable(tests_Date datatype/tests_Date.cpp)
target_link_libraries(tests_Date
        doctest
        rdf4cpp
        )
set_property(TARGET tests_Date PROPERTY CXX_STANDARD 20)

add_executable(tests_Time datatype/tests_Time.cpp)
target_link_libraries(tests_Time
        doctest
        rdf4cpp
        )
set_property(TARGET tests_Time PROPERTY CXX_STANDARD 20)

add_executable(tests_DateTimeStamp datatype/tests_DateTimeStamp.cpp)
target_link_libraries(tests_DateTimeStamp
        doctest
        rdf4cpp
        )
set_property(TARGET tests_DateTimeStamp PROPERTY CXX_STANDARD 20)

add_executable(tests_DateTime datatype/tests_DateTime.cpp)
target_link_libraries(tests_DateTime
        doctest
        rdf4cpp
        )
set_property(TARGET tests_DateTime PROPERTY CXX_STANDARD 20)

add_executable(tests_Byte datatype/tests_Byte.cpp)
target_link_libraries(tests_Byte
        doctest
        rdf4cpp
        )
set_property(TARGET tests_Byte PROPERTY CXX_STANDARD 20)

add_executable(tests_HexBinary datatype/tests_HexBinary.cpp)
target_link_libraries(tests_HexBinary
        doctest
        rdf4cpp
        )
set_property(TARGET tests_HexBinary PROPERTY CXX_STANDARD 20)

add_executable(tests_Short datatype/tests_Short.cpp)
target_link_libraries(tests_Short
        doctest
        rdf4cpp
        )
set_property(TARGET tests_Short PROPERTY CXX_STANDARD 20)

add_executable(tests_Int datatype/tests_Int.cpp)
target_link_libraries(tests_Int
        doctest
        rdf4cpp
        )
set_property(TARGET tests_Int PROPERTY CXX_STANDARD 20)

add_executable(tests_Long datatype/tests_Long.cpp)
target_link_libraries(tests_Long
        doctest
        rdf4cpp
        )
set_property(TARGET tests_Long PROPERTY CXX_STANDARD 20)

add_executable(tests_UnsignedByte datatype/tests_UnsignedByte.cpp)
target_link_libraries(tests_UnsignedByte
        doctest
        rdf4cpp
        )
set_property(TARGET tests_UnsignedByte PROPERTY CXX_STANDARD 20)

add_executable(tests_UnsignedShort datatype/tests_UnsignedShort.cpp)
target_link_libraries(tests_UnsignedShort
        doctest
        rdf4cpp
        )
set_property(TARGET tests_UnsignedShort PROPERTY CXX_STANDARD 20)

add_executable(tests_UnsignedInt datatype/tests_UnsignedInt.cpp)
target_link_libraries(tests_UnsignedInt
        doctest
        rdf4cpp
        )
set_property(TARGET tests_UnsignedInt PROPERTY CXX_STANDARD 20)

add_executable(tests_UnsignedLong datatype/tests_UnsignedLong.cpp)
target_link_libraries(tests_UnsignedLong
        doctest
        rdf4cpp
        )
set_property(TARGET tests_UnsignedLong PROPERTY CXX_STANDARD 20)

add_executable(tests_PositiveInteger datatype/tests_PositiveInteger.cpp)
target_link_libraries(tests_PositiveInteger
        doctest
        rdf4cpp
        )
set_property(TARGET tests_PositiveInteger PROPERTY CXX_STANDARD 20)

add_executable(tests_NegativeInteger datatype/tests_NegativeInteger.cpp)
target_link_libraries(tests_NegativeInteger
        doctest
        rdf4cpp
        )
set_property(TARGET tests_NegativeInteger PROPERTY CXX_STANDARD 20)

add_executable(tests_NonPositiveInteger datatype/tests_NonPositiveInteger.cpp)
target_link_libraries(tests_NonPositiveInteger
        doctest
        rdf4cpp
        )
set_property(TARGET tests_NonPositiveInteger PROPERTY CXX_STANDARD 20)

add_executable(tests_NonNegativeInteger datatype/tests_NonNegativeInteger.cpp)
target_link_libraries(tests_NonNegativeInteger
        doctest
        rdf4cpp
        )
set_property(TARGET tests_NonNegativeInteger PROPERTY CXX_STANDARD 20)

add_executable(tests_Duration datatype/tests_Duration.cpp)
target_link_libraries(tests_Duration
        doctest
        rdf4cpp
        )
set_property(TARGET tests_Duration PROPERTY CXX_STANDARD 20)

add_executable(tests_GDay datatype/tests_GDay.cpp)
target_link_libraries(tests_GDay
        doctest
        rdf4cpp
        )
set_property(TARGET tests_GDay PROPERTY CXX_STANDARD 20)

add_executable(tests_GMonth datatype/tests_GMonth.cpp)
target_link_libraries(tests_GMonth
        doctest
        rdf4cpp
        )
set_property(TARGET tests_GMonth PROPERTY CXX_STANDARD 20)

add_executable(tests_GYear datatype/tests_GYear.cpp)
target_link_libraries(tests_GYear
        doctest
        rdf4cpp
        )
set_property(TARGET tests_GYear PROPERTY CXX_STANDARD 20)

add_executable(tests_GYearMonth datatype/tests_GYearMonth.cpp)
target_link_libraries(tests_GYearMonth
        doctest
        rdf4cpp
        )
set_property(TARGET tests_GYearMonth PROPERTY CXX_STANDARD 20)

add_executable(tests_GMonthDay datatype/tests_GMonthDay.cpp)
target_link_libraries(tests_GMonthDay
        doctest
        rdf4cpp
        )
set_property(TARGET tests_GMonthDay PROPERTY CXX_STANDARD 20)

add_executable(tests_YearMonthDuration datatype/tests_YearMonthDuration.cpp)
target_link_libraries(tests_YearMonthDuration
        doctest
        rdf4cpp
        )
set_property(TARGET tests_YearMonthDuration PROPERTY CXX_STANDARD 20)

add_executable(tests_DayTimeDuration datatype/tests_DayTimeDuration.cpp)
target_link_libraries(tests_DayTimeDuration
        doctest
        rdf4cpp
        )
set_property(TARGET tests_DayTimeDuration PROPERTY CXX_STANDARD 20)

add_executable(tests_hello_test hello_test/main.cpp)
target_link_libraries(tests_hello_test
        doctest
        rdf4cpp
        )
set_property(TARGET tests_hello_test PROPERTY CXX_STANDARD 20)
add_test(NAME tests_hello_test COMMAND tests_hello_test)


add_executable(tests_Variable query/tests_Variable.cpp)
target_link_libraries(tests_Variable
        doctest
        rdf4cpp
        )
set_property(TARGET tests_Variable PROPERTY CXX_STANDARD 20)
add_test(NAME tests_Variable COMMAND tests_Variable)


add_executable(tests_TriplePattern query/tests_TriplePattern.cpp)
target_link_libraries(tests_TriplePattern
        doctest
        rdf4cpp
        )
set_property(TARGET tests_TriplePattern PROPERTY CXX_STANDARD 20)
add_test(NAME tests_TriplePattern COMMAND tests_TriplePattern)


add_executable(tests_QuadPattern query/tests_QuadPattern.cpp)
target_link_libraries(tests_QuadPattern
        doctest
        rdf4cpp
        )
set_property(TARGET tests_QuadPattern PROPERTY CXX_STANDARD 20)
add_test(NAME tests_QuadPattern COMMAND tests_QuadPattern)


add_executable(tests_Literal nodes/tests_Literal.cpp)
target_link_libraries(tests_Literal
        doctest
        rdf4cpp
        )
set_property(TARGET tests_Literal PROPERTY CXX_STANDARD 20)
add_test(NAME tests_Literal COMMAND tests_Literal)


# include(${doctest_SOURCE_DIR}/scripts/cmake/doctest.cmake)
# doctest_discover_tests(tests_hello_test)

# copy files for testing to the binary folder
# file(COPY foldername DESTINATION ${CMAKE_CURRENT_BINARY_DIR})