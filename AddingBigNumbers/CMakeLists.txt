cmake_minimum_required(VERSION 3.11)

set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

project(BigInteger LANGUAGES CXX)

list(APPEND flags "-fPIC")
if(MSVC)
	list(APPEND flags "/W4")
else()
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
    CXX_STANDARD 17
    CXX_EXTENSIONS OFF
    CXX_STANDARD_REQUIRED ON
  )
  
 target_include_directories(${PROJECT_NAME} PRIVATE include) 
  
  
 target_compile_options(${PROJECT_NAME}
	PRIVATE
		${flags}
  )
  
  add_subdirectory(test)
  