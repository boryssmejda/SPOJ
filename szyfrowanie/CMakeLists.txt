cmake_minimum_required(VERSION 3.19)

project(szyfrowanie LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE "ON")

include(CTest)
enable_testing()

find_package(GTest REQUIRED)

add_library(szyfrowanie_lib
    SHARED
        szyfrowanie.hpp
        szyfrowanie.cpp
)

add_executable(szyfrowanie_test
    szyfrowanie_test.cpp
)

target_link_libraries(szyfrowanie_test
    PRIVATE
        szyfrowanie_lib
        GTest::Main
        GTest::GTest
)

#add_test(NAME szyfrowanie_test COMMAND szyfrowanie_test)
#add_custom_command(TARGET szyfrowanie_test
#        POST_BUILD
#        COMMAND ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --progress --output-on-failure
#        COMMENT "Running CTest after building tests!"
#)
