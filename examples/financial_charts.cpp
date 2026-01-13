#include "financial_charts.hpp"

#include <string>
#include <utility>
#include <vector>

#include <plotlypp/plot.hpp>
#include <plotlypp/trace.hpp>
#include <plotlypp/traces/funnel.hpp>
#include <plotlypp/traces/indicator.hpp>
#include <plotlypp/traces/scatter.hpp>

namespace plotlypp {

// https://plotly.com/javascript/funnel-charts/

Figure basicFunnel() {
    auto trace =
        Funnel()
            .y(std::vector{"Website visit", "Downloads", "Potential customers", "Invoice sent", "Closed deals"})
            .x(std::vector{13873, 10533, 5443, 2703, 908})
            .hoverinfo({Funnel::Hoverinfo::X, Funnel::Hoverinfo::PercentPrevious, Funnel::Hoverinfo::PercentInitial});
    return Figure()
        .addTrace(std::move(trace))
        .setLayout(Layout().margin(Layout::Margin().l(150)).width(600).height(500));
}

// https://plotly.com/javascript/indicator/
Figure indicator() {
    auto trace1 = Indicator()
                      .mode({Indicator::Mode::Number, Indicator::Mode::Delta})
                      .value(492)
                      .delta(Indicator::Delta().reference(512).valueformat(".0f"))
                      .domain(Indicator::Domain().y(std::vector<double>{0, 1}).x(std::vector<double>{0.25, 0.75}))
                      .title([](auto& t) { t.text("Users online"); });
    auto trace2 = Scatter().y(std::vector{
        325, 324, 405, 400, 424, 404, 417, 432, 419, 394, 410, 426, 413, 419, 404, 408, 401, 377, 368, 361, 356, 359,
        375, 397, 394, 418, 437, 450, 430, 442, 424, 443, 420, 418, 423, 423, 426, 440, 437, 436, 447, 460, 478, 472,
        450, 456, 436, 418, 429, 412, 429, 442, 464, 447, 434, 457, 474, 480, 499, 497, 480, 502, 512, 492});
    return Figure()
        .addTraces(std::vector<Trace>{std::move(trace1), std::move(trace2)})
        .setLayout(Layout().width(600).height(450).xaxis([](auto& a) { a.range(std::vector<double>{0, 62}); }));
}

} // namespace plotlypp
