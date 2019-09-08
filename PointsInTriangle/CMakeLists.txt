cmake_minimum_required(VERSION 3.11)

set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

project(PointsInTriangle)



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



add_library(Points src/PointsInTriangle.cpp include/PointsInTriangle.hpp)
target_include_directories(Points PUBLIC include) 
target_compile_features(Points PRIVATE cxx_std_17)


add_executable(${PROJECT_NAME} src/main.cpp)
#target_include_directories(${PROJECT_NAME} PRIVATE include) 

target_link_libraries(${PROJECT_NAME} PRIVATE Points)
  
  
 target_compile_options(${PROJECT_NAME}
  PRIVATE
    ${flags}
  )
  
  add_subdirectory(test)
  