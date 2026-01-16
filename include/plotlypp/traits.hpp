// Copyright (c) 2025-2026 Jimmy O'Rourke
// Licensed under and subject to the terms of the LICENSE file accompanying this distribution.
// Official repository: https://github.com/jimmyorourke/plotlypp

#pragma once

#include <array>
#include <cstddef>
#include <string>
#include <type_traits>
#include <vector>

// Feature-test macros were only introduced in C++20, se we can't use
// `__cpp_lib_span`.
#if __cplusplus >= 202002L
#include <span>
#endif

namespace plotlypp {
namespace detail {

template <typename T>
struct is_vector_or_array : std::false_type {};
template <typename T, typename A>
struct is_vector_or_array<std::vector<T, A>> : std::true_type {};
template <typename T, size_t N>
struct is_vector_or_array<std::array<T, N>> : std::true_type {};
template <typename T>
constexpr bool is_vector_or_array_v = is_vector_or_array<std::decay_t<T>>::value;

template <typename T>
struct range_element_type {};
template <typename T, typename A>
struct range_element_type<std::vector<T, A>> {
    using type = T;
};
template <typename T, size_t N>
struct range_element_type<std::array<T, N>> {
    using type = T;
};

#if __cplusplus >= 202002L

template <typename T>
struct is_span : std::false_type {};
template <typename T, size_t E>
struct is_span<std::span<T, E>> : std::true_type {};
template <typename T>
constexpr bool is_span_v = is_span<std::decay_t<T>>::value;

template <typename T, size_t E>
struct range_element_type<std::span<T, E>> {
    using type = T;
};

// Post C++20, allow std::span or std::vector.
template <typename T>
constexpr bool is_data_array_range_v = detail::is_span_v<T> || detail::is_vector_or_array_v<T>;

#else
// Pre-C++20, allow only std::vector.
template <typename T>
constexpr bool is_data_array_range_v = detail::is_vector_or_array_v<T>;

#endif

template <typename R>
using range_element_type_t = typename range_element_type<std::decay_t<R>>::type;

} // namespace detail

// A data array is either a std::vector (or std::array) or std::span of arithmetic types or string, or a nested vector
// (depth currently unbounded) of same. For pre-C++20, a data array is a std::vector or std::array. We use these
// template shenanigans to support vector, array, and span types, and appropriately handle type deduction. A more
// simplistic alias to either `const std::vector<T>&` or `std::span<const T>` cannot handle implicit type deduction when
// passing in a non-const vector to a `std::span<const T>`. Even wrapping in a `std::span()` CTAD constructor is not
// sufficient. Arbitrary ranges are not supported as they might not serialize correctly, eg Eigen column-major matrices,
// and similarly this is why explicit std::span construction is required, rather than just convertibility or
// constructibility.

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

template <typename T, typename = void>
struct is_data_array : std::false_type {};

template <typename T>
struct is_data_array<T, std::enable_if_t<detail::is_data_array_range_v<T>>>
: std::bool_constant<is_data_array_element_v<detail::range_element_type_t<T>>> {};

template <typename T>
inline constexpr bool is_data_array_v = is_data_array<T>::value;

} // namespace plotlypp
