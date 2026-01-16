// Copyright (c) 2025-2026 Jimmy O'Rourke
// Licensed under and subject to the terms of the LICENSE file accompanying this distribution.
// Official repository: https://github.com/jimmyorourke/plotlypp

#pragma once

#include <initializer_list>
#include <string>

namespace plotlypp {
namespace detail {

// Joins a flaglist into the "+ string" concatenated form expected by Plotly JS.
template <typename T, typename F>
inline std::string joinFlaglist(std::initializer_list<T> flags, F&& flag_to_string_converter) {
    if (flags.size() == 0) {
        return "none";
    }
    std::string result;
    bool first = true;
    for (const auto& flag : flags) {
        if (!first) {
            result += "+";
        }
        result += std::forward<F>(flag_to_string_converter)(flag);
        first = false;
    }
    return result;
}

} // namespace detail
} // namespace plotlypp
