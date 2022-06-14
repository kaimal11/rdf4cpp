set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
        DocTest
        GIT_REPOSITORY "https://github.com/onqtam/doctest"
        GIT_TAG  "v2.4.8"
)
FetchContent_MakeAvailable(DocTest)

# add the executable for all tests
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


add_executable(tests_Node_comparison nodes/tests_Node_comparison.cpp)
target_link_libraries(tests_Node_comparison
        doctest
        rdf4cpp
        )
set_property(TARGET tests_Node_comparison PROPERTY CXX_STANDARD 20)
add_test(NAME tests_Node_comparison COMMAND tests_Node_comparison)

# RDF Core Types
add_executable(tests_String datatype/tests_String.cpp)
target_link_libraries(tests_String
        doctest
        rdf4cpp
        )
set_property(TARGET tests_String PROPERTY CXX_STANDARD 20)
add_test(NAME tests_String COMMAND tests_String)

add_executable(tests_Boolean datatype/tests_Boolean.cpp)
target_link_libraries(tests_Boolean
        doctest
        rdf4cpp
        )
set_property(TARGET tests_Boolean PROPERTY CXX_STANDARD 20)
add_test(NAME tests_Boolean COMMAND tests_Boolean)

add_executable(tests_Decimal datatype/tests_Decimal.cpp)
target_link_libraries(tests_Decimal
        doctest
        rdf4cpp
        )
set_property(TARGET tests_Decimal PROPERTY CXX_STANDARD 20)
add_test(NAME tests_Decimal COMMAND tests_Decimal)

add_executable(tests_Integer datatype/tests_Integer.cpp)
target_link_libraries(tests_Integer
        doctest
        rdf4cpp
        )
set_property(TARGET tests_Integer PROPERTY CXX_STANDARD 20)
add_test(NAME tests_Integer COMMAND tests_Integer)

#IEEE Floating Point Numbers
add_executable(tests_Float datatype/tests_Float.cpp)
target_link_libraries(tests_Float
        doctest
        rdf4cpp
        )
set_property(TARGET tests_Float PROPERTY CXX_STANDARD 20)
add_test(NAME tests_Float COMMAND tests_Float)

add_executable(tests_Double datatype/tests_Double.cpp)
target_link_libraries(tests_Double
        doctest
        rdf4cpp
        )
set_property(TARGET tests_Double PROPERTY CXX_STANDARD 20)
add_test(NAME tests_Double COMMAND tests_Double)

#Limited Range numbers
add_executable(tests_Byte datatype/tests_Byte.cpp)
target_link_libraries(tests_Byte
        doctest
        rdf4cpp
        )
set_property(TARGET tests_Byte PROPERTY CXX_STANDARD 20)
add_test(NAME tests_Byte COMMAND tests_Byte)

add_executable(tests_HexBinary datatype/tests_HexBinary.cpp)
target_link_libraries(tests_HexBinary
        doctest
        rdf4cpp
        )
set_property(TARGET tests_HexBinary PROPERTY CXX_STANDARD 20)
add_test(NAME tests_HexBinary COMMAND tests_HexBinary)

add_executable(tests_LangString datatype/tests_LangString.cpp)
target_link_libraries(tests_LangString
        doctest
        rdf4cpp
        )
set_property(TARGET tests_LangString PROPERTY CXX_STANDARD 20)
add_test(NAME tests_LangString COMMAND tests_LangString)

# include(${doctest_SOURCE_DIR}/scripts/cmake/doctest.cmake)
# doctest_discover_tests(tests_hello_test)

# copy files for testing to the binary folder
# file(COPY foldername DESTINATION ${CMAKE_CURRENT_BINARY_DIR})