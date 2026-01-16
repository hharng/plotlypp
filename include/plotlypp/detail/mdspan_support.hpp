// Copyright (c) 2025-2026 Jimmy O'Rourke
// Licensed under and subject to the terms of the LICENSE file accompanying this distribution.
// Official repository: https://github.com/jimmyorourke/plotlypp

#pragma once

// This file should only be included if C++23 is supported!
#include <mdspan>

#include <plotlypp/json.hpp>

namespace plotlypp {
template <typename ET, typename Exts, typename LP, typename Acc>
struct range_element_type<std::mdspan<ET, Exts, LP, Acc>> {
    using type = ET;
};

// Specialize is_plotly_range_extension to opt-in mdspan
template <typename ET, typename Exts, typename LP, typename Acc>
struct is_plotly_data_array_extension<std::mdspan<ET, Exts, LP, Acc>> : std::true_type {};

} // namespace plotlypp

// Specialize nlohmann::json serializer for mdspan
namespace nlohmann {
template <typename ET, typename Exts, typename LP, typename Acc>
struct adl_serializer<std::mdspan<ET, Exts, LP, Acc>> {
    using MDS = std::mdspan<ET, Exts, LP, Acc>;

    static void to_json(json& j, const MDS& md_span) {
        if constexpr (MDS::rank() == 1) {
            j = nlohmann::json::array();
            for (size_t i = 0; i < md_span.extent(0); ++i) {
                j.push_back(md_span[i]);
            }
        } else if constexpr (MDS::rank() == 2) {
            j = nlohmann::json::array();
            for (size_t r = 0; r < md_span.extent(0); ++r) {
                json row_j = nlohmann::json::array();
                for (size_t c = 0; c < md_span.extent(1); ++c) {
                    row_j.push_back(md_span[r, c]); // mdspan operator[] handles layout
                }
                j.push_back(row_j);
            }
        } else {
            static_assert(MDS::rank() <= 2, "plotlypp only supports 1D/2D mdspan serialization");
        }
    }
};
} // namespace nlohmann
