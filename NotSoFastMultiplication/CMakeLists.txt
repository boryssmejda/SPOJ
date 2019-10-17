cmake_minimum_required(VERSION 3.11)

set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

project(NotSoFastMultiplication)

list(APPEND flags "-fPIC")
if(NOT WIN32)
  list(APPEND flags "-Wextra" "-Wpedantic")
endif()

set(
	HEADERS
	include/BigMultiplication.hpp
)

set (
	SOURCES
	src/main.cpp
	src/BigMultiplication.cpp
)



add_library(BigMultiplication src/BigMultiplication.cpp include/BigMultiplication.hpp)
target_include_directories(BigMultiplication PUBLIC include) 
target_compile_features(BigMultiplication PRIVATE cxx_std_17)


add_executable(${PROJECT_NAME} src/main.cpp)
#target_include_directories(${PROJECT_NAME} PRIVATE include) 

target_link_libraries(${PROJECT_NAME} PRIVATE BigMultiplication)
  
  
 target_compile_options(${PROJECT_NAME}
  PRIVATE
    ${flags}
  )
  
  add_subdirectory(test)
  