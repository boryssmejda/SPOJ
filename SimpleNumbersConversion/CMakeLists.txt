cmake_minimum_required(VERSION 3.11)

set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

project(Small_number_conversion)

message("C++ compiler flags: ${CMAKE_CXX_FLAGS}")

list(APPEND flags "-fPIC")
if(NOT WIN32)
  list(APPEND flags "-Wextra" "-Wpedantic")
endif()

set(
	HEADERS
	include/number_converter.hpp
)

set (
	SOURCES
	src/main.cpp
	src/number_converter.cpp
)


add_executable(number_converter ${SOURCES} ${HEADERS})

set_target_properties(number_converter
  PROPERTIES
    CXX_STANDARD 14
    CXX_EXTENSIONS OFF
    CXX_STANDARD_REQUIRED ON
  )
  
 target_include_directories(number_converter PRIVATE include) 
  
  
 target_compile_options(number_converter
  PRIVATE
    ${flags}
  )