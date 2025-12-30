// Copyright (c) 2025 Jimmy O'Rourke
// Licensed under and subject to the terms of the LICENSE file accompanying this distribution.
// Official repository: https://github.com/jimmyorourke/plotlypp

#pragma once

#include <type_traits>
#include <vector>

namespace plotlypp {

// A data array is either a vector of arithmetic types, or a nested vector (depth currently unbounded) of arithmetic
// types.

template <typename T>
struct is_data_array_element {
    static constexpr bool value =
        std::is_arithmetic_v<std::decay_t<T>> || std::is_convertible_v<std::decay_t<T>, std::string>;
};

template <typename T>
struct is_data_array_element<std::vector<T>> {
    static constexpr bool value = is_data_array_element<T>::value;
};

template <typename T>
inline constexpr bool is_data_array_element_v = is_data_array_element<T>::value;

} // namespace plotlypp
