# Copyright (c) 2025-2026 Jimmy O'Rourke
# Licensed under and subject to the terms of the LICENSE file accompanying this distribution.
# Official repository: https://github.com/jimmyorourke/plotlypp

cmake_minimum_required(VERSION 3.13)
project(plotlypp LANGUAGES CXX)

set(MAIN_PROJECT OFF)
if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(MAIN_PROJECT ON)
endif()

option(PLOTLYPP_BUILD_EXAMPLES "Build the examples" ${MAIN_PROJECT})

if(MAIN_PROJECT)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif()

set(PLOTLYPP_FETCH_CONTENT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third_party_fetch_content)

# When part of a larger project, nlohmann_json may be made available by the greater project, and discoverable by
# find_package. This way we impose no requirement on how projects procure their dependencies. If not discoverable, or
# when just building plotlypp (eg the examples), use FetchContent.
find_package(nlohmann_json QUIET)
if(nlohmann_json_FOUND)
    message(STATUS "Found system nlohmann_json")
else()
    message(STATUS "nlohmann_json not found, fetching...")
    # Avoid warning about DOWNLOAD_EXTRACT_TIMESTAMP in CMake 3.24+:
    if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
        cmake_policy(SET CMP0135 NEW)
    endif()
    include(FetchContent)

    set(FETCHCONTENT_BASE_DIR ${PLOTLYPP_FETCH_CONTENT_DIR})
    FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
    FetchContent_MakeAvailable(json)
endif()
set(JSON_TARGET nlohmann_json::nlohmann_json)

add_library(plotlypp INTERFACE)
# Add a namespaced alias
add_library(plotlypp::plotlypp ALIAS plotlypp)
target_link_libraries(plotlypp INTERFACE ${JSON_TARGET})
target_include_directories(plotlypp INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
# Require at least C++17. Depending executables can override with a newer version.
target_compile_features(plotlypp INTERFACE cxx_std_17)


if(PLOTLYPP_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
