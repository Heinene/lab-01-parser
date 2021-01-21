cmake_minimum_required(VERSION 3.4)
 	 
 	set(CMAKE_CXX_STANDARD 17)
 	set(CMAKE_CXX_STANDARD_REQUIRED ON)
 	 
 	option(BUILD_COVERAGE "Build coverage" OFF)
 	 
 	set(
 	HUNTER_CACHE_SERVERS
 	"https://github.com/bmstu-iu8-cpp-sem-3/hunter-cache"
 	CACHE STRING "Default cache server"
 	)
 	 
 	include("tools/gate/cmake/HunterGate.cmake")
 	 
 	HunterGate(
 	URL "https://github.com/cpp-pm/hunter/archive/v0.23.218.tar.gz"
 	SHA1 "9a3594a61227967fb92159339ba326701b287b19"
 	)
 	 
 	 
 	# TODO: rename project and delete this comment
 	project(lab-01-parser-Heinene)
 	 
 	hunter_add_package(GTest)
 	hunter_add_package(nlohmann_json)
 	find_package(GTest CONFIG REQUIRED)
 	find_package(nlohmann_json 3.2.0 REQUIRED)
 	 
 	# TODO: change template word to project name and delete this comment
 	add_library(lab-01-parser-Heinene STATIC
 	# enum your files and delete this comment
 	${CMAKE_CURRENT_SOURCE_DIR}/sources/source.cpp
 	)
 	add_executable(tests
 	# TODO: enum your files and delete this comment
 	${CMAKE_CURRENT_SOURCE_DIR}/tests/test.cpp
 	)
 	 
 	# TODO: change template word to project name and delete this comment
 	target_include_directories(lab-01-parser-Heinene
 	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
 	)
 	target_include_directories(tests
 	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
 	)
 	# TODO: change template word to project name and delete this comment
 	target_link_libraries(lab-01-parser-Heinene nlohmann_json::nlohmann_json)
 	target_link_libraries(tests GTest::main lab-01-parser-Heinene nlohmann_json::nlohmann_json)
 	 
 	enable_testing()
 	add_test(NAME unit_tests COMMAND tests)
 	 
 	if(BUILD_COVERAGE)
 	set(ENABLE_COVERAGE ON CACHE BOOL "Enable coverage build." FORCE)
 	list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
 	find_package(codecov)
 	# TODO: change template word to project name and delete this comment
 	add_coverage(lab-01-parser-Heinene)
 	add_coverage(tests)
 	list(APPEND LCOV_REMOVE_PATTERNS "'${PROJECT_SOURCE_DIR}/tests/*'")
 	coverage_evaluate()
 	endif()
