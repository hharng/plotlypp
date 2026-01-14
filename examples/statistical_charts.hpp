#pragma once

#include <plotlypp/figure.hpp>

namespace plotlypp {

// https://plotly.com/javascript/box-plots/

Figure coloredBoxPlot();

// https://plotly.com/javascript/histograms/

Figure coloredAndStyledHistograms();

// https://plotly.com/javascript/continuous-error-bars/
Figure continuousFilledErrorBars();

// https://plotly.com/javascript/error-bars/
Figure asymmetricErrorBars();

// https://plotly.com/javascript/2D-Histogram/
Figure gen2DHistogramBivariateNormal();

// https://plotly.com/javascript/2d-histogram-contour/

Figure gen2DHistogramContour();

// https://plotly.com/javascript/violin/
Figure basicHorizontalViolinPlot();

} // namespace plotlypp
