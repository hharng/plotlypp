# Copyright (c) 2025 Jimmy O'Rourke
# Licensed under and subject to the terms of the LICENSE file accompanying this distribution.
# Official repository: https://github.com/jimmyorourke/plotlypp

add_library(math_utils
    math_utils.cpp
)
target_include_directories(math_utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(math_utils PUBLIC cxx_std_17)


add_executable(example
    example.cpp
    3d_charts.cpp
    basic_charts.cpp
    financial_charts.cpp
    maps.cpp
    scientific_charts.cpp
    statistical_charts.cpp)

target_link_libraries(example
  PRIVATE
    plotlypp
    math_utils
)
