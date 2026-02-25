cmake_minimum_required(VERSION 3.20)
project(MathVier VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

# Biblioteca — só os .cpp de implementação, nunca main.cpp
add_library(MathVier STATIC
    src/matrix.cpp
    src/vector.cpp
)
target_include_directories(MathVier PUBLIC include)

option(MATHVIER_BUILD_TESTS "Build tests" OFF)

if(MATHVIER_BUILD_TESTS)
    add_subdirectory(external/catch2)

    # mudar isso depois
    add_executable(mathvier_tests tests/test_vec.cpp)

    target_link_libraries(mathvier_tests
        PRIVATE
            MathVier
            Catch2::Catch2WithMain
    )
    include(CTest)
    include(Catch)
    catch_discover_tests(mathvier_tests)
endif()