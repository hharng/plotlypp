// Copyright (c) 2025-2026 Jimmy O'Rourke
// Licensed under and subject to the terms of the LICENSE file accompanying this distribution.
// Official repository: https://github.com/jimmyorourke/plotlypp

#include "basic_charts.hpp"

#include <string>
#include <utility>
#include <vector>

#include <plotlypp/figure.hpp>
#include <plotlypp/trace.hpp>
#include <plotlypp/traces/bar.hpp>
#include <plotlypp/traces/pie.hpp>
#include <plotlypp/traces/scatter.hpp>

namespace plotlypp {

// scatter, line
// https://plotly.com/javascript/line-and-scatter/
// https://plotly.com/javascript/line-charts/

Figure lineAndScatterWithNamesAxesTitle() {
    auto scatter = Scatter()
                       .x(std::vector{1, 2, 3, 4})
                       .y(std::vector{10, 15, 13, 17})
                       .mode({Scatter::Mode::Markers})
                       .marker(Scatter::Marker().color("rgb(82, 64, 219)").size(12))
                       .name("Markers");
    auto lines =
        Scatter().x(std::vector{2, 3, 4, 5}).y(std::vector{16, 5, 11, 9}).mode({Scatter::Mode::Lines}).name("Lines");
    auto scatter_and_lines = Scatter()
                                 .x(std::vector{1, 2, 3, 4})
                                 .y(std::vector{12, 9, 15, 12})
                                 .mode({Scatter::Mode::Lines, Scatter::Mode::Markers})
                                 .name("Lines & Markers");

    auto layout = Layout()
                      .title([](auto& t) { t.text("Title of the Graph"); })
                      .xaxis(Layout::Xaxis().title([](auto& t) { t.text("x-axis title"); }))
                      .yaxis(Layout::Yaxis().title(Layout::Yaxis::Title().text("y-axis title")));
    return Figure()
        .addTraces(std::vector<Trace>{std::move(scatter), std::move(lines), std::move(scatter_and_lines)})
        .setLayout(std::move(layout));
}

Figure scatterWithColorDimension() {
    return Figure()
        .addTrace(Scatter()
                      .y(std::vector{5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                                     5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5})
                      .mode({Scatter::Mode::Markers})
                      .marker(Scatter::Marker().size(40).color(std::vector<std::string>{
                          "0",  "1",  "2",  "3",  "4",  "5",  "6",  "7",  "8",  "9",  "10", "11", "12", "13",
                          "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27",
                          "28", "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39"})))
        .setLayout({"{\"title\": {\"text\": \"Scatter Plot with a Color Dimension\"}}"});
}

Figure groupedScatter() {
    auto trace1 = Scatter()
                      .x(std::vector{"South Korea", "China", "Canada"})
                      .y(std::vector{24, 10, 9})
                      .name("Gold")
                      .mode({Scatter::Mode::Markers});
    auto trace2 = Scatter()
                      .x(std::vector{"South Korea", "China", "Canada"})
                      .y(std::vector{13, 15, 12})
                      .name("Silver")
                      .mode({Scatter::Mode::Markers});
    auto trace3 = Scatter()
                      .x(std::vector{"South Korea", "China", "Canada"})
                      .y(std::vector{11, 8, 12})
                      .name("Bronze")
                      .mode({Scatter::Mode::Markers});

    auto layout = Layout()
                      .scattermode(Layout::Scattermode::Group)
                      .title(([](auto& t) { t.text("Grouped by Country"); }))
                      .xaxis(Layout::Xaxis().title([](auto& t) { t.text("Country"); }))
                      .yaxis({"{\"title\": {\"text\": \"Medals\"}}"});

    return Figure()
        .addTraces(std::vector<Trace>{std::move(trace1), std::move(trace2), std::move(trace3)})
        .setLayout(std::move(layout));
}

Figure lineDashes() {
    auto trace1 = Scatter()
                      .x(std::vector{1, 2, 3, 4, 5})
                      .y(std::vector{1, 3, 2, 3, 1})
                      .mode({Scatter::Mode::Lines})
                      .name("Solid")
                      .line(Scatter::Line().dash("solid").width(4));

    auto trace2 = Scatter()
                      .x(std::vector{1, 2, 3, 4, 5})
                      .y(std::vector{6, 8, 7, 8, 6})
                      .mode({Scatter::Mode::Lines})
                      .name("DashDot")
                      .line(Scatter::Line().dash("dashdot").width(4));

    auto trace3 = Scatter()
                      .x(std::vector{1, 2, 3, 4, 5})
                      .y(std::vector{11, 13, 12, 13, 11})
                      .mode({Scatter::Mode::Lines})
                      .name("Solid")
                      .line(Scatter::Line().dash("solid").width(4));

    auto trace4 = Scatter()
                      .x(std::vector{1, 2, 3, 4, 5})
                      .y(std::vector{16, 18, 17, 18, 16})
                      .mode({Scatter::Mode::Lines})
                      .name("Dot")
                      .line(Scatter::Line().dash("dot").width(4));

    auto layout =
        Layout()
            .title([](auto& t) { t.text("Line Dash"); })
            .xaxis(Layout::Xaxis().range({0.75, 5.25}).autorange(Layout::Xaxis::Autorange::False))
            .yaxis(Layout::Yaxis().range({0., 18.5}).autorange(Layout::Yaxis::Autorange::False))
            .legend(Layout::Legend().y(0.5).traceorder({Layout::Legend::Traceorder::Reversed}).font([](auto& f) {
                f.size(16);
            }));

    return Figure()
        .addTraces(std::vector<Trace>{std::move(trace1), std::move(trace2), std::move(trace3), std::move(trace4)})
        .setLayout(std::move(layout));
}

// https://plotly.com/javascript/bar-charts/

Figure groupedBar() {
    auto trace1 = Bar().x(std::vector{"giraffes", "orangutans", "monkeys"}).y(std::vector{20, 14, 23}).name("SF Zoo");
    auto trace2 = Bar().x(std::vector{"giraffes", "orangutans", "monkeys"}).y(std::vector{12, 18, 29}).name("LA Zoo");
    return Figure()
        .addTraces(std::vector<Trace>{std::move(trace1), std::move(trace2)})
        .setLayout(Layout().barmode(Layout::Barmode::Group));
}

// https://plotly.com/javascript/pie-charts/

Figure basicPie() {
    auto trace = Pie().values(std::vector{19, 26, 55}).labels(std::vector{"Residential", "Non-Residential", "Utility"});
    return Figure().addTrace(std::move(trace)).setLayout(Layout().height(400).width(500));
}

Figure donut() {
    auto trace1 = Pie()
                      .values(std::vector{16, 15, 12, 6, 5, 4, 42})
                      .labels(std::vector{"US", "China", "European Union", "Russian Federation", "Brazil", "India",
                                          "Rest of World"})
                      .domain(Pie::Domain().column(0))
                      .name("GHG Emissions")
                      .hoverinfo({Pie::Hoverinfo::Label, Pie::Hoverinfo::Percent, Pie::Hoverinfo::Name})
                      .hole(0.4);
    auto trace2 = Pie()
                      .values(std::vector{27, 11, 25, 8, 1, 3, 25})
                      .labels(std::vector{"US", "China", "European Union", "Russian Federation", "Brazil", "India",
                                          "Rest of World"})
                      .text(std::vector{"CO2"})
                      .textposition(Pie::Textposition::Inside)
                      .domain(Pie::Domain().column(1))
                      .name("CO2 Emissions")
                      .hoverinfo({Pie::Hoverinfo::Label, Pie::Hoverinfo::Percent, Pie::Hoverinfo::Name})
                      .hole(0.4);
    return Figure()
        .addTraces(std::vector<Trace>{std::move(trace1), std::move(trace2)})
        .setLayout(Layout()
                       .title([](auto& t) { t.text("Global Emissions 1990-2011"); })
                       .annotations({Layout::Annotation()
                                         .font(Layout::Annotation::Font().size(20))
                                         .showarrow(false)
                                         .text("GHG")
                                         .x(0.17)
                                         .y(0.5),
                                     Layout::Annotation()
                                         .font(Layout::Annotation::Font().size(20))
                                         .showarrow(false)
                                         .text("CO2")
                                         .x(0.82)
                                         .y(0.5)})
                       .height(400)
                       .width(600)
                       .showlegend(false)
                       .grid(Layout::Grid().rows(1).columns(2)));
}

// https://plotly.com/javascript/bubble-charts/

Figure bubbleWithMarkerSizeAndColor() {
    auto trace1 = Scatter()
                      .x(std::vector{1, 2, 3, 4})
                      .y(std::vector{10, 11, 12, 13})
                      .mode({Scatter::Mode::Markers})
                      .marker(Scatter::Marker()
                                  .color(std::vector<std::string>{"rgb(93, 164, 214)", "rgb(255, 144, 14)",
                                                                  "rgb(44, 160, 101)", "rgb(255, 65, 54)"})
                                  .opacity(std::vector<double>{1, 0.8, 0.6, 0.4})
                                  .size(std::vector<double>{40, 60, 80, 100}));
    return Figure()
        .addTrace(std::move(trace1))
        .setLayout(
            Layout().title([](auto& t) { t.text("Marker Size and Color"); }).showlegend(false).height(600).width(600));
}

// https://plotly.com/javascript/dot-plots/

Figure categoricalDotPlot() {
    std::vector<std::string> country = {"Switzerland (2011)", "Chile (2013)",   "Japan (2014)",  "United States (2012)",
                                        "Slovenia (2014)",    "Canada (2011)",  "Poland (2010)", "Estonia (2015)",
                                        "Luxembourg (2013)",  "Portugal (2011)"};
    std::vector<double> voting_pop = {40, 45.7, 52, 53.6, 54.1, 54.2, 54.5, 54.7, 55.1, 56.6};
    std::vector<double> reg_voters = {49.1, 42, 52.7, 84.3, 51.7, 61.1, 55.3, 64.2, 91.1, 58.9};

    auto trace1 = Scatter()
                      .x(voting_pop)
                      .y(country)
                      .mode({Scatter::Mode::Markers})
                      .name("Percent of estimated voting age population")
                      .marker(Scatter::Marker()
                                  .color("rgba(156, 165, 196, 0.95)")
                                  .line(Scatter::Marker::Line().color("rgba(156, 165, 19)").width(1))
                                  .symbol(Scatter::Marker::Symbol::Circle)
                                  .size(16));
    auto trace2 = Scatter()
                      .x(reg_voters)
                      .y(country)
                      .mode({Scatter::Mode::Markers})
                      .name("Percent of estimated registered voters")
                      .marker(Scatter::Marker()
                                  .color("rgba(204, 204, 204, 0.95)")
                                  .line(Scatter::Marker::Line().color("rgba(217, 217, 217, 1.0)").width(1))
                                  .symbol(Scatter::Marker::Symbol::Circle)
                                  .size(16));
    return Figure()
        .addTraces(std::vector<Trace>{std::move(trace1), std::move(trace2)})
        .setLayout(Layout()
                       .title([](auto& t) {
                           t.text("Votes cast for ten lowest voting age population in OECD "
                                  "countries");
                           t.font([](auto& f) { f.color("rgb(204, 204, 204)"); });
                       })
                       .xaxis(Layout::Xaxis()
                                  .showgrid(false)
                                  .showline(true)
                                  .linecolor("rgb(102, 102, 102)")
                                  .tickfont(Layout::Xaxis::Tickfont().color("rgb(102, 102, 102)"))
                                  .tickmode(Layout::Xaxis::Tickmode::Linear)
                                  .dtick(10)
                                  .ticks(Layout::Xaxis::Ticks::Outside)
                                  .tickcolor("rgb(102, 102, 102)"))
                       .margin(Layout::Margin().l(140).r(40).b(50).t(80))
                       .legend(Layout::Legend()
                                   .font([](auto& f) { f.size(10); })
                                   .yanchor(Layout::Legend::Yanchor::Middle)
                                   .xanchor(Layout::Legend::Xanchor::Right))
                       .width(600)
                       .height(600)
                       .paper_bgcolor("rgb(254, 247, 234)")
                       .plot_bgcolor("rgb(254, 247, 234)")
                       .hovermode(Layout::Hovermode::Closest));
}

// https://plotly.com/javascript/filled-area-plots/

Figure basicOverlaidArea() {
    auto trace1 = Scatter().x(std::vector{1, 2, 3, 4}).y(std::vector{0, 2, 3, 5}).fill(Scatter::Fill::Tozeroy);
    auto trace2 = Scatter().x(std::vector{1, 2, 3, 4}).y(std::vector{3, 5, 1, 7}).fill(Scatter::Fill::Tonexty);
    return Figure().addTraces(std::vector<Trace>{std::move(trace1), std::move(trace2)});
}

// https://plotly.com/javascript/horizontal-bar-charts/

Figure horizontalBar() {
    auto trace1 = Bar()
                      .x(std::vector{20, 14, 23})
                      .y(std::vector{"giraffes", "orangutans", "monkeys"})

                      .name("SF Zoo")
                      .orientation(Bar::Orientation::H)
                      .marker(Bar::Marker().color("rgba(55,128,191,0.6)"));
    auto trace2 = Bar()
                      .x(std::vector{12, 18, 29})
                      .y(std::vector{"giraffes", "orangutans", "monkeys"})
                      .name("LA Zoo")
                      .orientation(Bar::Orientation::H)
                      .marker(Bar::Marker().color("rgba(255,153,51,0.6)"));
    return Figure()
        .addTraces(std::vector<Trace>{std::move(trace1), std::move(trace2)})
        .setLayout(Layout().title([](auto& t) { t.text("Colored Bar Chart"); }).barmode(Layout::Barmode::Stack));
}

} // namespace plotlypp
