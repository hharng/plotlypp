// Copyright (c) 2025-2026 Jimmy O'Rourke
// Licensed under and subject to the terms of the LICENSE file accompanying this distribution.
// Official repository: https://github.com/jimmyorourke/plotlypp

#pragma once

#include <plotlypp/figure.hpp>

namespace plotlypp {

// Based on examples from https://plotly.com/javascript/3d-surface-plots/

Figure multiple3DSurfacePlots();

Figure gen3dSurfaceContours();

Figure gen3dSurfaceTorus();

// Based on examples from https://plotly.com/javascript/3d-mesh/ and https://plotly.com/python/3d-mesh/

Figure meshCube();

// Based on examples from https://plotly.com/javascript/3d-line-plots/

Figure gen3dLineSpiral();

// Based on examples from https://plotly.com/python/3d-scatter-plots/

Figure gen3dScatterWithColorscalingAndMarkerStyling();

// Based on examples from https://plotly.com/python/3d-volume-plots/

Figure simpleVolumePlot();

// Based on examples from https://plotly.com/python/3d-isosurface-plots/

Figure multiple3dIsosurfaces();

// Based on examples from https://plotly.com/python/3d-bubble-charts/

plotlypp::Figure bubbleChartSizedByVariable();

} // namespace plotlypp
