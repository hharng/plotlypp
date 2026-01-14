// Copyright (c) 2025-2026 Jimmy O'Rourke
// Licensed under and subject to the terms of the LICENSE file accompanying this distribution.
// Official repository: https://github.com/jimmyorourke/plotlypp

#pragma once

#include <plotlypp/figure.hpp>

namespace plotlypp {

// https://plotly.com/javascript/subplots/

Figure subplotsGridLayout();

Figure subplotsDomainLayout();

Figure multipleSubplotsWithSharedAxes();

// https://plotly.com/python/3d-subplots/
// https://plotly.com/javascript/3d-subplots/

Figure gen3dSubplots();

// https://plotly.com/javascript/insets/

Figure insetGraph();

// https://plotly.com/javascript/mixed-subplots/

Figure mixedSubplots();

} // namespace plotlypp
