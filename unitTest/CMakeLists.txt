cmake_minimum_required(VERSION 3.13)

enable_testing()

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(RatioSimpleUnitTests src/simpleTests.cpp)
target_link_libraries(RatioSimpleUnitTests PUBLIC Ratio GTest::GTest GTest::Main)
target_compile_features(RatioSimpleUnitTests PRIVATE cxx_std_17)

add_executable(RatioIntermediateUnitTests src/intermediateTests.cpp)
target_link_libraries(RatioIntermediateUnitTests PUBLIC Ratio GTest::GTest GTest::Main)
target_compile_features(RatioIntermediateUnitTests PRIVATE cxx_std_17)

add_executable(RatioComplexUnitTests src/complexTests.cpp)
target_link_libraries(RatioComplexUnitTests PUBLIC Ratio GTest::GTest GTest::Main)
target_compile_features(RatioComplexUnitTests PRIVATE cxx_std_17)

gtest_discover_tests(RatioSimpleUnitTests RatioIntermediateUnitTests RatioComplexUnitTests)
