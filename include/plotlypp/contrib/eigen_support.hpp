// Copyright (c) 2025-2026 Jimmy O'Rourke
// Licensed under and subject to the terms of the LICENSE file accompanying this distribution.
// Official repository: https://github.com/jimmyorourke/plotlypp

#pragma once

#include <plotlypp/json.hpp>
#include <plotlypp/traits.hpp>

namespace plotlypp {
// range_element_type specialization to get the scalar type from an Eigen Matrix
template <typename Scalar, int Rows, int Cols, int Options, int MaxRows, int MaxCols>
struct range_element_type<Eigen::Matrix<Scalar, Rows, Cols, Options, MaxRows, MaxCols>> {
    using type = Scalar;
};

// Specialize is_plotly_range_extension to opt-in Eigen matrices
template <typename Scalar, int Rows, int Cols, int Options, int MaxRows, int MaxCols>
struct is_plotly_data_array_extension<Eigen::Matrix<Scalar, Rows, Cols, Options, MaxRows, MaxCols>> : std::true_type {};

} // namespace plotlypp

// Specialize nlohmann::json serializer for Eigen types.
namespace nlohmann {
template <typename Scalar, int Rows, int Cols, int Options, int MaxRows, int MaxCols>
struct adl_serializer<Eigen::Matrix<Scalar, Rows, Cols, Options, MaxRows, MaxCols>> {
    using MatrixType = Eigen::Matrix<Scalar, Rows, Cols, Options, MaxRows, MaxCols>;

    static void to_json(json& j, const MatrixType& matrix) {
        if (matrix.cols() == 1 || matrix.rows() == 1) {
            // If it's a vector or row-vector, serialize as a 1D JSON array [1, 2, 3]
            j = std::vector<Scalar>(matrix.data(), matrix.data() + matrix.size());
        }
        // If it's a 2D Matrix, serialize as nested arrays [[1, 2], [3, 4]]
        else {
            j = json::array();
            for (Eigen::Index r = 0; r < matrix.rows(); ++r) {
                json row_j = json::array();
                for (Eigen::Index c = 0; c < matrix.cols(); ++c) {
                    // Manual indexing is safest across versions
                    row_j.push_back(matrix(r, c));
                }
                j.push_back(std::move(row_j));
            }
        }
    }
};
} // namespace nlohmann
