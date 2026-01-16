// Copyright (c) 2025-2026 Jimmy O'Rourke
// Licensed under and subject to the terms of the LICENSE file accompanying this distribution.
// Official repository: https://github.com/jimmyorourke/plotlypp

#pragma once

#include <Eigen/Core>

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

// Add support for Eigen::Block expressions (returned by .row(), .col(), .block(), etc.)
template <typename PlainObjectType, int BlockRows, int BlockCols, bool InnerPanel>
struct range_element_type<Eigen::Block<PlainObjectType, BlockRows, BlockCols, InnerPanel>> {
    using type = typename PlainObjectType::Scalar;
};

template <typename PlainObjectType, int BlockRows, int BlockCols, bool InnerPanel>
struct is_plotly_data_array_extension<Eigen::Block<PlainObjectType, BlockRows, BlockCols, InnerPanel>>
: std::true_type {};

} // namespace plotlypp

// Specialize nlohmann::json serializer for Eigen types.
namespace nlohmann {

// Helper to serialize Eigen Matrix/Block types to JSON.
// This function iterates using operator() which correctly handles different  memory layouts (e.g., column-major vs
// row-major) and striding (for blocks or rows/columns of matrices). This is safer than using `.data()` which assumes
// contiguous memory, as `.row(i)` of a column-major matrix is not contiguous.
template <typename EigenType>
void serialize_eigen_type(json& j, const EigenType& eigen_obj) {
    if (eigen_obj.cols() == 1 || eigen_obj.rows() == 1) {
        // If it's vector-like (1xN or Nx1), serialize as a 1D JSON array [1, 2, 3].
        // operator(i) works for both vectors and row-vectors regardless of stride.
        j = json::array();
        for (Eigen::Index i = 0; i < eigen_obj.size(); ++i) {
            j.push_back(eigen_obj(i));
        }
    } else {
        // If it's a 2D Matrix, serialize as nested arrays [[1, 2], [3, 4]].
        j = json::array();
        for (Eigen::Index r = 0; r < eigen_obj.rows(); ++r) {
            json row_j = json::array();
            for (Eigen::Index c = 0; c < eigen_obj.cols(); ++c) {
                row_j.push_back(eigen_obj(r, c));
            }
            j.push_back(std::move(row_j));
        }
    }
}

// Specialize nlohmann::json serializer for Eigen::Matrix types.
template <typename Scalar, int Rows, int Cols, int Options, int MaxRows, int MaxCols>
struct adl_serializer<Eigen::Matrix<Scalar, Rows, Cols, Options, MaxRows, MaxCols>> {
    using MatrixType = Eigen::Matrix<Scalar, Rows, Cols, Options, MaxRows, MaxCols>;

    static void to_json(json& j, const MatrixType& matrix) { serialize_eigen_type(j, matrix); }
};

// Specialize nlohmann::json serializer for Eigen::Block types.
template <typename PlainObjectType, int BlockRows, int BlockCols, bool InnerPanel>
struct adl_serializer<Eigen::Block<PlainObjectType, BlockRows, BlockCols, InnerPanel>> {
    using BlockType = Eigen::Block<PlainObjectType, BlockRows, BlockCols, InnerPanel>;
    static void to_json(json& j, const BlockType& block) { serialize_eigen_type(j, block); }
};
} // namespace nlohmann
