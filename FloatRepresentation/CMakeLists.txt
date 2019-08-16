cmake_minimum_required(VERSION 3.11)

set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

project(Float_conversion)

message("C++ compiler flags: ${CMAKE_CXX_FLAGS}")

list(APPEND flags "-fPIC")
if(NOT WIN32)
  list(APPEND flags "-Wextra" "-Wpedantic")
endif()

set(
	HEADERS
	include/floatRepresentation.hpp
)

set (
	SOURCES
	src/main.cpp
	src/floatRepresentation.cpp
)


add_executable(float_representation ${SOURCES} ${HEADERS})

set_target_properties(float_representation
  PROPERTIES
    CXX_STANDARD 14
    CXX_EXTENSIONS OFF
    CXX_STANDARD_REQUIRED ON
  )
  
 target_include_directories(float_representation PRIVATE include) 
  
  
 target_compile_options(float_representation
  PRIVATE
    ${flags}
  )
  
  add_subdirectory(test)
  