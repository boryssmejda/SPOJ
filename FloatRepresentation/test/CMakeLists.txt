cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(Unit_Testing)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.8.0
)

FetchContent_GetProperties(googletest)

if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)

  # Prevent GoogleTest from overriding our compiler/linker options
  # when building with Visual Studio
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  # Prevent GoogleTest from using PThreads
  set(gtest_disable_pthreads ON CACHE BOOL "" FORCE)

  # adds the targers: gtest, gtest_main, gmock, gmock_main
  add_subdirectory(
    ${googletest_SOURCE_DIR}
    ${googletest_BINARY_DIR}
    )
	
	if(MSVC)
		foreach(_tgt gtest gtest_main gmock gmock_main)
		  target_compile_definitions(${_tgt}
		   PRIVATE
			  "_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING"
			)
		endforeach()
	endif()
endif()

add_executable(float_representation_test "")


target_include_directories(float_representation_test PRIVATE ../include ../src)



target_sources(float_representation_test
  PRIVATE
    float_representation_unittest.cpp
	../src/floatRepresentation.cpp
  )

target_link_libraries(

	float_representation_test
	PRIVATE
	gtest_main
)


enable_testing()

add_test(
  NAME google_test
  COMMAND $<TARGET_FILE:float_representation_test>
  )



