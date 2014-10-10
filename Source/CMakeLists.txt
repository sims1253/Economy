cmake_minimum_required(VERSION 2.8)

set(CMAKE_COLOR_MAKEFILE ON)
set(CMAKE_VERBOSE_MAKEFILE OFF)

project(Economy)

set(Economy_VERSION_MAJOR 0)
set(Economy_VERSION_MINOR 0)
set(Economy_VERSION_MICRO 1)


# Get the current working branch
execute_process(
  COMMAND git rev-parse --abbrev-ref HEAD
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  OUTPUT_VARIABLE GIT_BRANCH
  OUTPUT_STRIP_TRAILING_WHITESPACE
)


# Get the latest abbreviated commit hash of the working branch
execute_process(
  COMMAND git log -1 --format=%h
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  OUTPUT_VARIABLE GIT_HEAD
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

configure_file(
    "${PROJECT_SOURCE_DIR}/Economy_config.h.in"
    "${PROJECT_SOURCE_DIR}/Economy_config.h"
    )

include_directories("${PROJECT_SOURCE_DIR}/..")

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(WARNINGS "-Wpedantic -Wall -Wextra -Werror")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(WARNINGS "/W4 /WX /EHsc")
endif()

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wmaybe-uninitialized -Wno-pragmas")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${WARNINGS} -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

add_subdirectory("Participants")
add_subdirectory("World")

add_library(Economy SHARED ${SRC})

install(TARGETS Economy LIBRARY DESTINATION lib)

install(DIRECTORY              ${CMAKE_CURRENT_LIST_DIR}/
        DESTINATION            include/Economy
        FILES_MATCHING PATTERN "*.h")

# Documentation
find_package(Doxygen)
if (DOXYGEN_FOUND)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in
    ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
add_custom_target(doc
    ${DOXYGEN_EXECUTABLE}
    ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    WORKING_DIRECTORY
    ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Generating API documentation with Doxygen" VERBATIM
    )
endif (DOXYGEN_FOUND)
