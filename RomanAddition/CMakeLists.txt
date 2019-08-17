cmake_minimum_required(VERSION 3.11)

set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

project(RomanAddition)

message("C++ compiler flags: ${CMAKE_CXX_FLAGS}")

list(APPEND flags "-fPIC")
if(NOT WIN32)
  list(APPEND flags "-Wextra" "-Wpedantic")
endif()

set(
	HEADERS
	include/${PROJECT_NAME}.hpp
)

set (
	SOURCES
	src/main.cpp
	src/${PROJECT_NAME}.cpp
)


add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

set_target_properties(${PROJECT_NAME}
  PROPERTIES
    CXX_STANDARD 14
    CXX_EXTENSIONS OFF
    CXX_STANDARD_REQUIRED ON
  )
  
 target_include_directories(${PROJECT_NAME} PRIVATE include) 
  
  
 target_compile_options(${PROJECT_NAME}
  PRIVATE
    ${flags}
  )
  
  add_subdirectory(test)
  