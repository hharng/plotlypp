// Copyright (c) 2025-2026 Jimmy O'Rourke
// Licensed under and subject to the terms of the LICENSE file accompanying this distribution.
// Official repository: https://github.com/jimmyorourke/plotlypp

#include "statistical_charts.hpp"

#include <algorithm>
#include <random>
#include <string>
#include <utility>
#include <vector>

#include <plotlypp/figure.hpp>
#include <plotlypp/trace.hpp>
#include <plotlypp/traces/box.hpp>
#include <plotlypp/traces/histogram.hpp>
#include <plotlypp/traces/histogram2d.hpp>
#include <plotlypp/traces/histogram2dcontour.hpp>
#include <plotlypp/traces/scatter.hpp>
#include <plotlypp/traces/violin.hpp>

namespace plotlypp {

// Based on examples from https://plotly.com/javascript/box-plots/

Figure coloredBoxPlot() {
    auto trace1 = Box()
                      .y(std::vector{1, 2, 3, 4, 4, 4, 8, 9, 10})
                      .marker(Box::Marker().color("rgb(214,12,140)"))
                      .name("Sample A");
    auto trace2 =
        Box().y(std::vector{2, 3, 3, 3, 3, 5, 6, 6, 7}).marker(Box::Marker().color("rgb(0,128,128)")).name("Sample B");
    return Figure()
        .addTraces(std::vector<Trace>{std::move(trace1), std::move(trace2)})
        .setLayout(Layout().title([](auto& t) { t.text("Colored Box Plot"); }));
}

// Based on examples from https://plotly.com/javascript/histograms/

Figure coloredAndStyledHistograms() {
    std::vector<double> x1;
    std::vector<double> x2;
    std::vector<double> y1;
    std::vector<double> y2;
    std::mt19937 gen(1);
    std::uniform_real_distribution<> dis(0.0, 1.0);
    for (int i = 0; i < 499; ++i) {
        double k = dis(gen);
        x1.push_back(k * 5);
        x2.push_back(k * 10);
        y1.push_back(k);
        y2.push_back(k * 2);
    }
    auto trace1 = Histogram()
                      .x(x1)
                      .y(y1)
                      .name("control")
                      .autobinx(false)
                      .histnorm(Histogram::Histnorm::Empty)
                      .marker(Histogram::Marker()
                                  .color("rgba(255, 100, 102, 0.7)")
                                  .line(Histogram::Marker::Line().color("rgba(255, 100, 102, 1)").width(1)))
                      .opacity(0.5)
                      .xbins(Histogram::Xbins().end(2.8).size(0.06).start(0.5));
    auto trace2 = Histogram()
                      .x(x2)
                      .y(y2)
                      .name("experimental")
                      .autobinx(false)
                      .marker(Histogram::Marker()
                                  .color("rgba(100, 200, 102, 0.7)")
                                  .line(Histogram::Marker::Line().color("rgba(100, 200, 102, 1)").width(1)))
                      .opacity(0.75)
                      .xbins(Histogram::Xbins().end(4).size(0.06).start(-3.2));
    return Figure()
        .addTraces(std::vector<Trace>{std::move(trace1), std::move(trace2)})
        .setLayout(Layout()
                       .bargap(0.05)
                       .bargroupgap(0.2)
                       .barmode(Layout::Barmode::Overlay)
                       .title([](auto& t) { t.text("Sampled Results"); })
                       .xaxis(Layout::Xaxis().title([](auto& t) { t.text("Value"); }))
                       .yaxis(Layout::Yaxis().title([](auto& t) { t.text("Count"); })));
}

// Based on examples from https://plotly.com/javascript/continuous-error-bars/

Figure continuousFilledErrorBars() {
    auto trace1 = Scatter()
                      .x(std::vector<double>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1})
                      .y(std::vector<double>{2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0})
                      .fill(Scatter::Fill::Tozerox)
                      .fillcolor("rgba(0,100,80,0.2)")
                      //.line(Scatter::Line().color("transparent"))
                      .line(Scatter::Line().color("rgba(0,0,0,0)"))
                      .name("Fair")
                      .showlegend(false);
    auto trace2 = Scatter()
                      .x(std::vector<double>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1})
                      .y(std::vector<double>{5.5, 3, 5.5, 8, 6, 3, 8, 5, 6, 5.5, 4.75, 5, 4, 7, 2, 4, 7, 4.4, 2, 4.5})
                      .fill(Scatter::Fill::Tozerox)
                      .fillcolor("rgba(0,176,246,0.2)")
                      //.line(Scatter::Line().color("transparent"))
                      .line(Scatter::Line().color("rgba(0,0,0,0)"))
                      .name("Premium")
                      .showlegend(false);
    auto trace3 = Scatter()
                      .x(std::vector<double>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1})
                      .y(std::vector<double>{11, 9, 7, 5, 3, 1, 3, 5, 3, 1, -1, 1, 3, 1, -0.5, 1, 3, 5, 7, 9})
                      .fill(Scatter::Fill::Tozerox)
                      .fillcolor("rgba(231,107,243,0.2)")
                      //.line(Scatter::Line().color("transparent"))
                      .line(Scatter::Line().color("rgba(0,0,0,0)"))
                      .name("Ideal")
                      .showlegend(false);
    auto trace4 = Scatter()
                      .x(std::vector<double>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10})
                      .y(std::vector<double>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10})
                      .line(Scatter::Line().color("rgb(0,100,80)"))
                      .mode({Scatter::Mode::Lines})
                      .name("Fair");
    auto trace5 = Scatter()
                      .x(std::vector<double>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10})
                      .y(std::vector<double>{5, 2.5, 5, 7.5, 5, 2.5, 7.5, 4.5, 5.5, 5})
                      .line(Scatter::Line().color("rgb(0,176,246)"))
                      .mode({Scatter::Mode::Lines})
                      .name("Premium");
    auto trace6 = Scatter()
                      .x(std::vector<double>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10})
                      .y(std::vector<double>{10, 8, 6, 4, 2, 0, 2, 4, 2, 0})
                      .line(Scatter::Line().color("rgb(231,107,243)"))
                      .mode({Scatter::Mode::Lines})
                      .name("Ideal");

    return Figure()
        .addTraces(std::vector<Trace>{std::move(trace1), std::move(trace2), std::move(trace3), std::move(trace4),
                                      std::move(trace5), std::move(trace6)})
        .setLayout(Layout()
                       .paper_bgcolor("rgb(255,255,255)")
                       .plot_bgcolor("rgb(229,229,229)")
                       .xaxis(Layout::Xaxis()
                                  .gridcolor("rgb(255,255,255)")
                                  .range({1, 10})
                                  .showgrid(true)
                                  .showline(false)
                                  .showticklabels(true)
                                  .tickcolor("rgb(127,127,127)")
                                  .ticks(Layout::Xaxis::Ticks::Outside)
                                  .zeroline(false))
                       .yaxis(Layout::Yaxis()
                                  .gridcolor("rgb(255,255,255)")
                                  .showgrid(true)
                                  .showline(false)
                                  .showticklabels(true)
                                  .tickcolor("rgb(127,127,127)")
                                  .ticks(Layout::Yaxis::Ticks::Outside)
                                  .zeroline(false)));
}

// Based on examples from https://plotly.com/javascript/error-bars/

Figure asymmetricErrorBars() {
    return Figure().addTrace(Scatter()
                                 .x(std::vector<double>{1, 2, 3, 4})
                                 .y(std::vector<double>{2, 1, 3, 4})
                                 .error_y(Scatter::Error_Y()
                                              .type(Scatter::Error_Y::Type::Data)
                                              .symmetric(false)
                                              .array(std::vector<double>{0.1, 0.2, 0.1, 0.1})
                                              .arrayminus(std::vector<double>{0.2, 0.4, 1, 0.2})));
}

// Based on examples from https://plotly.com/javascript/2D-Histogram/

Figure gen2DHistogramBivariateNormal() {
    std::mt19937 gen(1);
    std::uniform_real_distribution<> dis(0.0, 1.0);
    std::vector<double> x;
    std::vector<double> y;
    for (int i = 0; i < 499; ++i) {
        x.push_back(dis(gen));
        y.push_back(dis(gen) + 1);
    }
    return Figure().addTrace(Histogram2D().x(x).y(y));
}

// Based on examples from https://plotly.com/javascript/2d-histogram-contour/

Figure gen2DHistogramContour() {
    std::vector<double> x;
    std::vector<double> y;
    std::mt19937 gen(1);
    std::uniform_real_distribution<> dis(0.0, 1.0);
    for (int i = 0; i < 500; ++i) {
        x.push_back(dis(gen));
        y.push_back(dis(gen) + 1);
    }
    return Figure().addTrace(Histogram2Dcontour().x(x).y(y).colorscale("Blues"));
}

// Based on examples from https://plotly.com/javascript/violin/

Figure basicHorizontalViolinPlot() {
    std::vector<double> total_bill_data;
    std::mt19937 gen(1);
    // Bills centered around $40, std dev $10, min $5
    std::normal_distribution<> dis(40.0, 10.0);
    total_bill_data.reserve(100);
    for (int i = 0; i < 100; ++i) {
        total_bill_data.push_back(std::max(5.0, dis(gen)));
    }

    auto trace = Violin()
                     .x(total_bill_data)
                     .points(Violin::Points::False)
                     .box(Violin::Box().visible(true))
                     .line(Violin::Line().color("black"))
                     .fillcolor("#8dd3c7")
                     .opacity(0.6)
                     .meanline(Violin::Meanline().visible(true))
                     .y0("Total Bill");

    return Figure()
        .addTrace(std::move(trace))
        .setLayout(Layout()
                       .title([](auto& t) { t.text("Basic Horizontal Violin Plot"); })
                       .xaxis(Layout::Xaxis().zeroline(false)));
}

} // namespace plotlypp
