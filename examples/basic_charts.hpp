// Copyright (c) 2025-2026 Jimmy O'Rourke
// Licensed under and subject to the terms of the LICENSE file accompanying this distribution.
// Official repository: https://github.com/jimmyorourke/plotlypp

#pragma once

#include <plotlypp/figure.hpp>

namespace plotlypp {

// Based on examples from https://plotly.com/javascript/line-and-scatter/ and https://plotly.com/javascript/line-charts/

Figure lineAndScatterWithNamesAxesTitle();

Figure dataLabelsOnPlot();

Figure scatterWithColorDimension();

Figure groupedScatter();

Figure lineDashes();

// Based on examples from https://plotly.com/javascript/bar-charts/

Figure groupedBar();

// Based on examples from https://plotly.com/javascript/pie-charts/

Figure basicPie();

Figure donut();

// Based on examples from https://plotly.com/javascript/bubble-charts/

Figure bubbleWithMarkerSizeAndColor();

// Based on examples from https://plotly.com/javascript/dot-plots/

Figure categoricalDotPlot();

// Based on examples from https://plotly.com/javascript/filled-area-plots/

Figure basicOverlaidArea();

// Based on examples from https://plotly.com/javascript/horizontal-bar-charts/

Figure horizontalBar();

} // namespace plotlypp
