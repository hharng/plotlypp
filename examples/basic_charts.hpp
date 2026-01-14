// Copyright (c) 2025-2026 Jimmy O'Rourke
// Licensed under and subject to the terms of the LICENSE file accompanying this distribution.
// Official repository: https://github.com/jimmyorourke/plotlypp

#pragma once

#include <plotlypp/figure.hpp>

namespace plotlypp {

// scatter, line
// https://plotly.com/javascript/line-and-scatter/
// https://plotly.com/javascript/line-charts/

Figure lineAndScatterWithNamesAxesTitle();

Figure scatterWithColorDimension();

Figure groupedScatter();

Figure lineDashes();

// https://plotly.com/javascript/bar-charts/

Figure groupedBar();

// https://plotly.com/javascript/pie-charts/

Figure basicPie();

Figure donut();

// https://plotly.com/javascript/bubble-charts/

Figure bubbleWithMarkerSizeAndColor();

// https://plotly.com/javascript/dot-plots/

Figure categoricalDotPlot();

// https://plotly.com/javascript/filled-area-plots/

Figure basicOverlaidArea();

// https://plotly.com/javascript/horizontal-bar-charts/

Figure horizontalBar();

} // namespace plotlypp
