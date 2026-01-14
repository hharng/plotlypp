// Copyright (c) 2025-2026 Jimmy O'Rourke
// Licensed under and subject to the terms of the LICENSE file accompanying this distribution.
// Official repository: https://github.com/jimmyorourke/plotlypp

#pragma once

#include <plotlypp/figure.hpp>

namespace plotlypp {

// https://plotly.com/javascript/polar-chart/
// https://plotly.com/javascript/radar-chart/

// LOL this is the matplotlib logo!
Figure areaPolarChart();

Figure multipleTraceRadarChart();

// https://plotly.com/javascript/carpet-scatter/
Figure carpetWithScatterTrace();

// https://plotly.com/javascript/contour-plots/

Figure colorscaleForContourPlot();

// https://plotly.com/python/smith-charts/

Figure smithChartSubplotsWithStlying();

} // namespace plotlypp
