// Copyright (c) 2025-2026 Jimmy O'Rourke
// Licensed under and subject to the terms of the LICENSE file accompanying this distribution.
// Official repository: https://github.com/jimmyorourke/plotlypp

#pragma once

#include <utility>
#include <vector>

namespace math_utils {

std::vector<double> linspace(double start, double stop, int points);

std::pair<std::vector<std::vector<double>>, std::vector<std::vector<double>>> meshgrid(const std::vector<double>& x,
                                                                                       const std::vector<double>& y);

} // namespace math_utils
