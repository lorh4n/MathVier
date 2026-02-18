cmake_minimum_required(VERSION 3.20)
project(MathVier VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

# Biblioteca — só os .cpp de implementação, nunca main.cpp
add_library(MathVier STATIC
    src/matrix.cpp
    src/vector.cpp
)
target_include_directories(MathVier PUBLIC include)

# Testes (opcional, só compila se quiser)
option(MATHVIER_BUILD_TESTS "Build tests" OFF)
if(MATHVIER_BUILD_TESTS)
    find_package(GTest REQUIRED)
    add_executable(mathvier_tests tests/test_vec.cpp)
    target_link_libraries(mathvier_tests PRIVATE MathVier GTest::gtest_main)
endif()