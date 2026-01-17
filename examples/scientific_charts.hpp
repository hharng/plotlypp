// Copyright (c) 2025-2026 Jimmy O'Rourke
// Licensed under and subject to the terms of the LICENSE file accompanying this distribution.
// Official repository: https://github.com/jimmyorourke/plotlypp

#pragma once

#include <plotlypp/figure.hpp>

namespace plotlypp {

// Based on examples from https://plotly.com/javascript/polar-chart/ and https://plotly.com/javascript/radar-chart/

// LOL this is the matplotlib logo!
Figure areaPolarChart();

Figure multipleTraceRadarChart();

// Based on examples from https://plotly.com/javascript/carpet-scatter/

Figure carpetWithScatterTrace();

// Based on examples from https://plotly.com/javascript/contour-plots/

Figure colorscaleForContourPlot();

// Based on examples from https://plotly.com/python/smith-charts/

Figure smithChartSubplotsWithStlying();

} // namespace plotlypp
