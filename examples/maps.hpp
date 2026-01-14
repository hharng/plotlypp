// Copyright (c) 2025-2026 Jimmy O'Rourke
// Licensed under and subject to the terms of the LICENSE file accompanying this distribution.
// Official repository: https://github.com/jimmyorourke/plotlypp

#pragma once

#include <string>
#include <utility>
#include <vector>

#include <plotlypp/figure.hpp>

namespace plotlypp {

// https://plotly.com/javascript/lines-on-maps/

Figure linesOnMaps();

// https://plotly.com/javascript/tile-density-heatmaps/

Figure lightTile();

// https://plotly.com/javascript/outline-map-locations/

Figure outlineMapLocations();

// https://plotly.com/javascript/scatter-tile-maps/

Figure scatterTileMaps();

} // namespace plotlypp
