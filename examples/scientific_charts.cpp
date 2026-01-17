// Copyright (c) 2025-2026 Jimmy O'Rourke
// Licensed under and subject to the terms of the LICENSE file accompanying this distribution.
// Official repository: https://github.com/jimmyorourke/plotlypp

#include "scientific_charts.hpp"

#include <string>
#include <utility>
#include <vector>

#include <plotlypp/figure.hpp>
#include <plotlypp/layout/layout.hpp>
#include <plotlypp/trace.hpp>
#include <plotlypp/traces/carpet.hpp>
#include <plotlypp/traces/contour.hpp>
#include <plotlypp/traces/scattercarpet.hpp>
#include <plotlypp/traces/scatterpolar.hpp>
#include <plotlypp/traces/scattersmith.hpp>

namespace plotlypp {

// Based on examples from https://plotly.com/javascript/polar-chart/ and https://plotly.com/javascript/radar-chart/

// LOL this is the matplotlib logo!
Figure areaPolarChart() {
    auto trace1 = Scatterpolar()
                      .mode({Scatterpolar::Mode::Lines})
                      .r(std::vector<double>{0, 1.5, 1.5, 0, 2.5, 2.5, 0})
                      .theta(std::vector{0, 10, 25, 0, 205, 215, 0})
                      .fill(Scatterpolar::Fill::Toself)
                      .fillcolor("#709BFF")
                      .line(Scatterpolar::Line().color("black"));
    auto trace2 = Scatterpolar()
                      .mode({Scatterpolar::Mode::Lines})
                      .r(std::vector<double>{0, 3.5, 3.5, 0})
                      .theta(std::vector{0, 55, 75, 0})
                      .fill(Scatterpolar::Fill::Toself)
                      .fillcolor("#E4FF87")
                      .line(Scatterpolar::Line().color("black"));
    auto trace3 = Scatterpolar()
                      .mode({Scatterpolar::Mode::Lines})
                      .r(std::vector<double>{0, 4.5, 4.5, 0, 4.5, 4.5, 0})
                      .theta(std::vector{0, 100, 120, 0, 305, 320, 0})
                      .fill(Scatterpolar::Fill::Toself)
                      .fillcolor("#FFAA70")
                      .line(Scatterpolar::Line().color("black"));
    auto trace4 = Scatterpolar()
                      .mode({Scatterpolar::Mode::Lines})
                      .r(std::vector{0, 4, 4, 0})
                      .theta(std::vector{0, 165, 195, 0})
                      .fill(Scatterpolar::Fill::Toself)
                      .fillcolor("#FFDF70")
                      .line(Scatterpolar::Line().color("black"));
    auto trace5 = Scatterpolar()
                      .mode({Scatterpolar::Mode::Lines})
                      .r(std::vector{0, 3, 3, 0})
                      .theta(std::vector<double>{0, 262.5, 277.5, 0})
                      .fill(Scatterpolar::Fill::Toself)
                      .fillcolor("#B6FFB4")
                      .line(Scatterpolar::Line().color("black"));

    Layout layout = Layout()
                        .polar(Layout::Polar().radialaxis(Layout::Polar::Radialaxis().visible(true).range({0, 5})))
                        .showlegend(false);

    return Figure()
        .addTraces(std::vector<Trace>{std::move(trace1), std::move(trace2), std::move(trace3), std::move(trace4),
                                      std::move(trace5)})
        .setLayout(std::move(layout));
}

Figure multipleTraceRadarChart() {
    auto trace1 = Scatterpolar()
                      .r(std::vector<double>{39, 28, 8, 7, 28, 39})
                      .theta(std::vector{"A", "B", "C", "D", "E", "A"})
                      .fill(Scatterpolar::Fill::Toself)
                      .name("Group A");
    auto trace2 = Scatterpolar()
                      .r(std::vector<double>{1.5, 10, 39, 31, 15, 1.5})
                      .theta(std::vector{"A", "B", "C", "D", "E", "A"})
                      .fill(Scatterpolar::Fill::Toself)
                      .name("Group B");
    return Figure()
        .addTraces(std::vector<Trace>{std::move(trace1), std::move(trace2)})
        .setLayout(
            Layout().polar(Layout::Polar().radialaxis(Layout::Polar::Radialaxis().visible(true).range({0, 50}))));
}

// Based on examples from https://plotly.com/javascript/carpet-scatter/

Figure carpetWithScatterTrace() {
    auto trace1 = Carpet()
                      .a(std::vector{4e-6, 4e-6, 4e-6, 4.5e-6, 4.5e-6, 4.5e-6, 5e-6, 5e-6, 5e-6, 6e-6, 6e-6, 6e-6})
                      .b(std::vector{1e6, 2e6, 3e6, 1e6, 2e6, 3e6, 1e6, 2e6, 3e6, 1e6, 2e6, 3e6})
                      .y(std::vector<double>{2, 3.5, 4, 3, 4.5, 5, 5.5, 6.5, 7.5, 8, 8.5, 10})
                      .aaxis(Carpet::Aaxis().tickprefix("a = ").ticksuffix("m").smoothing(1).minorgridcount(9))
                      .baxis(Carpet::Baxis().tickprefix("b = ").ticksuffix("Pa").smoothing(1).minorgridcount(9));
    auto trace2 = Scattercarpet()
                      .a(std::vector{4e-6, 4.5e-6, 5e-6, 6e-6})
                      .b(std::vector{1.5e6, 2.5e6, 1.5e6, 2.5e6})
                      .line(Scattercarpet::Line().shape(Scattercarpet::Line::Shape::Spline).smoothing(1));
    return Figure().addTraces(std::vector<Trace>{std::move(trace1), std::move(trace2)});
}

// Based on examples from https://plotly.com/javascript/contour-plots/

Figure colorscaleForContourPlot() {
    auto trace = Contour()
                     .z(std::vector<std::vector<double>>{{10, 10.625, 12.5, 15.625, 20},
                                                         {5.625, 6.25, 8.125, 11.25, 15.625},
                                                         {2.5, 3.125, 5., 8.125, 12.5},
                                                         {0.625, 1.25, 3.125, 6.25, 10.625},
                                                         {0, 0.625, 2.5, 5.625, 10}})
                     .colorscale("Jet");
    return Figure().addTrace(std::move(trace)).setLayout(Layout().title([](auto& t) {
        t.text("Colorscale for Contour Plot");
    }));
}

// Based on examples from https://plotly.com/python/smith-charts/

Figure smithChartSubplotsWithStlying() {
    auto smith1 = Scattersmith()
                      .imag(std::vector{1})
                      .real(std::vector{1})
                      .marker([](auto& m) { m.symbol(Scattersmith::Marker::Symbol::X).size(30).color("pink"); })
                      .subplot("smith1");
    auto smith2 = Scattersmith()
                      .imag(std::vector{1})
                      .real(std::vector{1})
                      .marker(Scattersmith::Marker().symbol(Scattersmith::Marker::Symbol::X).size(30).color("green"))
                      .subplot("smith2");

    auto layout = Layout()
                      .smith(Layout::Smith()
                                 .realaxis(Layout::Smith::Realaxis().gridcolor("red"))
                                 .imaginaryaxis(Layout::Smith::Imaginaryaxis().gridcolor("blue"))
                                 .bgcolor("lightgrey")
                                 .domain(Layout::Smith::Domain().x(std::vector{0., 0.45})))
                      .smith(2, Layout::Smith()
                                    .realaxis([](auto& r) { r.gridcolor("blue"); })
                                    .imaginaryaxis([](auto& i) { i.gridcolor("red"); })
                                    .bgcolor("lightgrey")
                                    .domain([](auto& d) { d.x(std::vector{0.55, 1.}); }));

    return Figure().addTrace(std::move(smith1)).addTrace(std::move(smith2)).setLayout(std::move(layout));
}

} // namespace plotlypp
