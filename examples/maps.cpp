#include "maps.hpp"

#include <string>
#include <utility>
#include <vector>

#include <plotlypp/figure.hpp>
#include <plotlypp/trace.hpp>
#include <plotlypp/traces/choropleth.hpp>
#include <plotlypp/traces/densitymap.hpp>
#include <plotlypp/traces/scattergeo.hpp>
#include <plotlypp/traces/scattermap.hpp>

namespace plotlypp {

// https://plotly.com/javascript/lines-on-maps/

Figure linesOnMaps() {
    auto trace = Scattergeo()
                     .lat(std::vector{40.7127, 51.5072})
                     .lon(std::vector{-74.0059, 0.1275})
                     .mode({Scattergeo::Mode::Lines})
                     .line(Scattergeo::Line().width(2).color("blue"));
    return Figure()
        .addTrace(std::move(trace))
        .setLayout(
            Layout()
                .title([](auto& t) { t.text("London to NYC Great Circle"); })
                .showlegend(false)
                .geo(Layout::Geo()
                         .resolution(Layout::Geo::Resolution::Num_50)
                         .showland(true)
                         .showlakes(true)
                         .landcolor("rgb(204, 204, 204)")
                         .countrycolor("rgb(204, 204, 204)")
                         .lakecolor("rgb(255, 255, 255)")
                         .projection(Layout::Geo::Projection().type(Layout::Geo::Projection::Type::Equirectangular))
                         .coastlinewidth(2)
                         .lataxis(Layout::Geo::Lataxis().range(std::vector<double>{20, 60}).showgrid(true).dtick(10))
                         .lonaxis(
                             Layout::Geo::Lonaxis().range(std::vector<double>{-100, 20}).showgrid(true).dtick(20))));
}

// https://plotly.com/javascript/tile-density-heatmaps/

Figure lightTile() {
    auto trace1 = Densitymap()
                      .lon(std::vector{10, 20, 30})
                      .lat(std::vector{15, 25, 35})
                      .z(std::vector{1, 3, 2})
                      .radius(50)
                      .colorbar(Densitymap::Colorbar().y(1).yanchor(Densitymap::Colorbar::Yanchor::Top).len(0.45));
    auto trace2 = Densitymap()
                      .lon(std::vector{-10, -20, -30})
                      .lat(std::vector{15, 25, 35})
                      .radius(std::vector<double>{50, 100, 10})
                      .colorbar(Densitymap::Colorbar().y(0).yanchor(Densitymap::Colorbar::Yanchor::Bottom).len(0.45));
    return Figure()
        .addTraces(std::vector<Trace>{std::move(trace1), std::move(trace2)})
        .setLayout(
            Layout().map(Layout::Map().style("light").center(Layout::Map::Center().lat(20))).width(600).height(400));
}

// https://plotly.com/javascript/outline-map-locations/

Figure outlineMapLocations() {
    auto trace = Choropleth()
                     .locations(std::vector{"USA", "CAN", "MEX", "BRA", "RUS"})
                     .locationmode(Choropleth::Locationmode::Iso3)
                     .z(std::vector{100, 85, 72, 95, 68})
                     .colorscale("Viridis");
    return Figure()
        .addTrace(std::move(trace))
        .setLayout(Layout()
                       .title([](auto& t) { t.text("Choropleth with ISO-3 Country Codes"); })
                       .geo(Layout::Geo().projection(
                           Layout::Geo::Projection().type(Layout::Geo::Projection::Type::NaturalEarth))));
}

// https://plotly.com/javascript/scatter-tile-maps/

Figure scatterTileMaps() {
    auto trace = Scattermap()
                     .mode({Scattermap::Mode::Markers, Scattermap::Mode::Text, Scattermap::Mode::Lines})
                     .lon(std::vector{-75, -80, -50})
                     .lat(std::vector{45, 20, -20})
                     .marker(Scattermap::Marker().size(20).symbol(std::vector<std::string>{"bus", "harbor", "airport"}))
                     .text(std::vector<std::string>{"Bus", "Harbor", "Airport"})
                     .textposition(Scattermap::Textposition::BottomRight);
    return Figure()
        .addTrace(std::move(trace))
        .setLayout(Layout().map(Layout::Map().style("outdoors").zoom(0.7)).showlegend(false).width(700).height(500));
}

} // namespace plotlypp
