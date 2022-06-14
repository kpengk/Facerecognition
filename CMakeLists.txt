cmake_minimum_required(VERSION 3.17)

project(Facerecognition VERSION 2.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options("/utf-8")
endif()
if((NOT (CMAKE_BUILD_TYPE STREQUAL "Debug")) AND (NOT (CMAKE_BUILD_TYPE STREQUAL "Release")))
    set(CMAKE_BUILD_TYPE "Release")
endif()
message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
message(STATUS "CMAKE_SYSTEM_NAME: ${CMAKE_SYSTEM_NAME}")
message(STATUS "CMAKE_CXX_COMPILER_ID: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")

add_subdirectory(src)
