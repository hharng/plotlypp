// Copyright (c) 2025-2026 Jimmy O'Rourke
// Licensed under and subject to the terms of the LICENSE file accompanying this distribution.
// Official repository: https://github.com/jimmyorourke/plotlypp

#pragma once

#include <plotlypp/figure.hpp>

namespace plotlypp {

// Based on examples from https://plotly.com/javascript/box-plots/

Figure coloredBoxPlot();

// Based on examples from https://plotly.com/javascript/histograms/

Figure coloredAndStyledHistograms();

// Based on examples from https://plotly.com/javascript/continuous-error-bars/

Figure continuousFilledErrorBars();

// Based on examples from https://plotly.com/javascript/error-bars/

Figure asymmetricErrorBars();

// Based on examples from https://plotly.com/javascript/2D-Histogram/

Figure gen2DHistogramBivariateNormal();

// Based on examples from https://plotly.com/javascript/2d-histogram-contour/

Figure gen2DHistogramContour();

// Based on examples from https://plotly.com/javascript/violin/

Figure basicHorizontalViolinPlot();

} // namespace plotlypp
