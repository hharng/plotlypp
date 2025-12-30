#include <vector>

#include <plotlypp/plot.hpp>
#include <plotlypp/traces/scatter.hpp>

namespace plotlypp {

// scatter, line
// https://plotly.com/javascript/line-and-scatter/
// https://plotly.com/javascript/line-charts/

Figure lineAndScatterWithNamesAxesTitle() {
    auto scatter = Scatter()
                       .x(std::vector{1, 2, 3, 4})
                       .y(std::vector{10, 15, 13, 17})
                       .mode("markers")
                       .marker(Scatter::Marker().color("rgb(82, 64, 219)").size(12))
                       .name("Markers");
    auto lines = Scatter().x(std::vector{2, 3, 4, 5}).y(std::vector{16, 5, 11, 9}).mode("lines").name("Lines");
    auto scatter_and_lines = Scatter()
                                 .x(std::vector{1, 2, 3, 4})
                                 .y(std::vector{12, 9, 15, 12})
                                 .mode("lines+markers")
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
                      .mode("markers")
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
                      .mode("markers");
    auto trace2 = Scatter()
                      .x(std::vector{"South Korea", "China", "Canada"})
                      .y(std::vector{13, 15, 12})
                      .name("Silver")
                      .mode("markers");
    auto trace3 = Scatter()
                      .x(std::vector{"South Korea", "China", "Canada"})
                      .y(std::vector{11, 8, 12})
                      .name("Bronze")
                      .mode("markers");

    auto layout = Layout()
                      .title(([](auto& t) { t.text("Grouped by Country"); }))
                      .xaxis(Layout::Xaxis().title([](auto& t) { t.text("Country"); }))
                      .yaxis({"{\"title\": {\"text\": \"Medals\"}}"});

    // TODO: still missing layout attributes!

    return Figure()
        .addTraces(std::vector<Trace>{std::move(trace1), std::move(trace2), std::move(trace3)})
        .setLayout(std::move(layout));
}

Figure lineDashes() {
    auto trace1 = Scatter()
                      .x(std::vector{1, 2, 3, 4, 5})
                      .y(std::vector{1, 3, 2, 3, 1})
                      .mode("lines")
                      .name("Solid")
                      .line(Scatter::Line().dash("solid").width(4));

    auto trace2 = Scatter()
                      .x(std::vector{1, 2, 3, 4, 5})
                      .y(std::vector{6, 8, 7, 8, 6})
                      .mode("lines")
                      .name("DashDot")
                      .line(Scatter::Line().dash("dashdot").width(4));

    auto trace3 = Scatter()
                      .x(std::vector{1, 2, 3, 4, 5})
                      .y(std::vector{11, 13, 12, 13, 11})
                      .mode("lines")
                      .name("Solid")
                      .line(Scatter::Line().dash("solid").width(4));

    auto trace4 = Scatter()
                      .x(std::vector{1, 2, 3, 4, 5})
                      .y(std::vector{16, 18, 17, 18, 16})
                      .mode("lines")
                      .name("Dot")
                      .line(Scatter::Line().dash("dot").width(4));

    auto layout = Layout()
                      .title([](auto& t) { t.text("Line Dash"); })
                      .xaxis(Layout::Xaxis().range({0.75, 5.25}).autorange(Layout::Xaxis::Autorange::False))
                      .yaxis(Layout::Yaxis().range({0., 18.5}).autorange(Layout::Yaxis::Autorange::False))
                      .legend(Layout::Legend().y(0.5).traceorder("reversed").font([](auto& f) { f.size(16); }));

    return Figure()
        .addTraces(std::vector<Trace>{std::move(trace1), std::move(trace2), std::move(trace3), std::move(trace4)})
        .setLayout(std::move(layout));
}

} // namespace plotlypp

/*




//
Grouped Scatter Plot

var trace1 = {


var data = [trace1, trace2, trace3];

var layout = {
  scattermode: 'group',
  title: {
    text: 'Grouped by Country'
  },
  xaxis: {
    title: {
      text: 'Country'
    }
  },
  yaxis: {
    title: {
      text: 'Medals'
    }
  }
};

Plotly.newPlot('myDiv', data, layout);

//
Line Dash

var trace1 = {
  x: [1, 2, 3, 4, 5],
  y: [1, 3, 2, 3, 1],
  mode: 'lines',
  name: 'Solid',
  line: {
    dash: 'solid',
    width: 4
  }
};

var trace2 = {
  x: [1, 2, 3, 4, 5],
  y: [6, 8, 7, 8, 6],
  mode: 'lines',
  name: 'dashdot',
  line: {
    dash: 'dashdot',
    width: 4
  }
};

var trace3 = {
  x: [1, 2, 3, 4, 5],
  y: [11, 13, 12, 13, 11],
  mode: 'lines',
  name: 'Solid',
  line: {
    dash: 'solid',
    width: 4
  }
};

var trace4 = {
  x: [1, 2, 3, 4, 5],
  y: [16, 18, 17, 18, 16],
  mode: 'lines',
  name: 'dot',
  line: {
    dash: 'dot',
    width: 4
  }
};

var data = [trace1, trace2, trace3, trace4];

var layout = {
  title: {
    text: 'Line Dash'
  },
  xaxis: {
    range: [0.75, 5.25],
    autorange: false
  },
  yaxis: {
    range: [0, 18.5],
    autorange: false
  },
  legend: {
    y: 0.5,
    traceorder: 'reversed',
    font: {
      size: 16
    }
  }
};

Plotly.newPlot('myDiv', data, layout);
*/

/*
https://plotly.com/javascript/bar-charts/
//

Grouped Bar chart

var trace1 = {
  x: ['giraffes', 'orangutans', 'monkeys'],
  y: [20, 14, 23],
  name: 'SF Zoo',
  type: 'bar'
};

var trace2 = {
  x: ['giraffes', 'orangutans', 'monkeys'],
  y: [12, 18, 29],
  name: 'LA Zoo',
  type: 'bar'
};

var data = [trace1, trace2];

var layout = {barmode: 'group'};

Plotly.newPlot('myDiv', data, layout);


https://plotly.com/javascript/pie-charts/

Basic pie

var data = [{
  values: [19, 26, 55],
  labels: ['Residential', 'Non-Residential', 'Utility'],
  type: 'pie'
}];

var layout = {
  height: 400,
  width: 500
};

Plotly.newPlot('myDiv', data, layout);


//
Donut

var data = [{
  values: [16, 15, 12, 6, 5, 4, 42],
  labels: ['US', 'China', 'European Union', 'Russian Federation', 'Brazil', 'India', 'Rest of World' ],
  domain: {column: 0},
  name: 'GHG Emissions',
  hoverinfo: 'label+percent+name',
  hole: .4,
  type: 'pie'
},{
  values: [27, 11, 25, 8, 1, 3, 25],
  labels: ['US', 'China', 'European Union', 'Russian Federation', 'Brazil', 'India', 'Rest of World' ],
  text: 'CO2',
  textposition: 'inside',
  domain: {column: 1},
  name: 'CO2 Emissions',
  hoverinfo: 'label+percent+name',
  hole: .4,
  type: 'pie'
}];

var layout = {
  title: {
    text: 'Global Emissions 1990-2011'
  },
  annotations: [
    {
      font: {
        size: 20
      },
      showarrow: false,
      text: 'GHG',
      x: 0.17,
      y: 0.5
    },
    {
      font: {
        size: 20
      },
      showarrow: false,
      text: 'CO2',
      x: 0.82,
      y: 0.5
    }
  ],
  height: 400,
  width: 600,
  showlegend: false,
  grid: {rows: 1, columns: 2}
};

Plotly.newPlot('myDiv', data, layout);


//
https://plotly.com/javascript/bubble-charts/
Bubble with marker size and color

var trace1 = {
  x: [1, 2, 3, 4],
  y: [10, 11, 12, 13],
  mode: 'markers',
  marker: {
    color: ['rgb(93, 164, 214)', 'rgb(255, 144, 14)',  'rgb(44, 160, 101)', 'rgb(255, 65, 54)'],
    opacity: [1, 0.8, 0.6, 0.4],
    size: [40, 60, 80, 100]
  }
};

var data = [trace1];

var layout = {
  title: {
    text: 'Marker Size and Color'
  },
  showlegend: false,
  height: 600,
  width: 600
};

Plotly.newPlot('myDiv', data, layout);


//
https://plotly.com/javascript/dot-plots/

Categorical dot plot
var country = ['Switzerland (2011)', 'Chile (2013)', 'Japan (2014)', 'United States (2012)', 'Slovenia (2014)', 'Canada
(2011)', 'Poland (2010)', 'Estonia (2015)', 'Luxembourg (2013)', 'Portugal (2011)'];

var votingPop = [40, 45.7, 52, 53.6, 54.1, 54.2, 54.5, 54.7, 55.1, 56.6];

var regVoters = [49.1, 42, 52.7, 84.3, 51.7, 61.1, 55.3, 64.2, 91.1, 58.9];

var trace1 = {
  type: 'scatter',
  x: votingPop,
  y: country,
  mode: 'markers',
  name: 'Percent of estimated voting age population',
  marker: {
    color: 'rgba(156, 165, 196, 0.95)',
    line: {
      color: 'rgba(156, 165, 196, 1.0)',
      width: 1,
    },
    symbol: 'circle',
    size: 16
  }
};

var trace2 = {
  x: regVoters,
  y: country,
  mode: 'markers',
  name: 'Percent of estimated registered voters',
  marker: {
    color: 'rgba(204, 204, 204, 0.95)',
    line: {
      color: 'rgba(217, 217, 217, 1.0)',
      width: 1,
    },
    symbol: 'circle',
    size: 16
  }
};

var data = [trace1, trace2];

var layout = {
  title: {
      text: 'Votes cast for ten lowest voting age population in OECD countries',
      font: {
          color: 'rgb(204, 204, 204)'
      }
  },
  xaxis: {
    showgrid: false,
    showline: true,
    linecolor: 'rgb(102, 102, 102)',
    tickfont: {
      font: {
        color: 'rgb(102, 102, 102)'
      }
    },
    tickmode: 'linear',
    dtick: 10,
    ticks: 'outside',
    tickcolor: 'rgb(102, 102, 102)'
  },
  margin: {
    l: 140,
    r: 40,
    b: 50,
    t: 80
  },
  legend: {
    font: {
      size: 10,
    },
    yanchor: 'middle',
    xanchor: 'right'
  },
  width: 600,
  height: 600,
  paper_bgcolor: 'rgb(254, 247, 234)',
  plot_bgcolor: 'rgb(254, 247, 234)',
  hovermode: 'closest'
};

Plotly.newPlot('myDiv', data, layout);

//
https://plotly.com/javascript/filled-area-plots/
basic overlaid area chart
var trace1 = {
  x: [1, 2, 3, 4],
  y: [0, 2, 3, 5],
  fill: 'tozeroy',
  type: 'scatter'
};

var trace2 = {
  x: [1, 2, 3, 4],
  y: [3, 5, 1, 7],
  fill: 'tonexty',
  type: 'scatter'
};

var data = [trace1, trace2];

Plotly.newPlot('myDiv', data);


//
https://plotly.com/javascript/horizontal-bar-charts/
Horizontal colored bar chart
var trace1 = {
  x: [20, 14, 23],
  y: ['giraffes', 'orangutans', 'monkeys'],
  name: 'SF Zoo',
  orientation: 'h',
  marker: {
    color: 'rgba(55,128,191,0.6)',
    width: 1
  },
  type: 'bar'
};

var trace2 = {
  x: [12, 18, 29],
  y: ['giraffes', 'orangutans', 'monkeys'],
  name: 'LA Zoo',
  orientation: 'h',
  type: 'bar',
  marker: {
    color: 'rgba(255,153,51,0.6)',
    width: 1
  }
};

var data = [trace1, trace2];

var layout = {
  title: {
    text: 'Colored Bar Chart'
  },
  barmode: 'stack'
};

Plotly.newPlot('myDiv', data, layout);


https://plotly.com/javascript/table/

//
Styled table

var values = [
      ['Salaries', 'Office', 'Merchandise', 'Legal', '<b>TOTAL</b>'],
      [1200000, 20000, 80000, 2000, 12120000],
      [1300000, 20000, 70000, 2000, 130902000],
      [1300000, 20000, 120000, 2000, 131222000],
      [1400000, 20000, 90000, 2000, 14102000]]

var data = [{
  type: 'table',
  header: {
    values: [["<b>EXPENSES</b>"], ["<b>Q1</b>"],
                 ["<b>Q2</b>"], ["<b>Q3</b>"], ["<b>Q4</b>"]],
    align: ["left", "center"],
    line: {width: 1, color: '#506784'},
    fill: {color: '#119DFF'},
    font: {family: "Arial", size: 12, color: "white"}
  },
  cells: {
    values: values,
    align: ["left", "center"],
    line: {color: "#506784", width: 1},
     fill: {color: ['#25FEFD', 'white']},
    font: {family: "Arial", size: 11, color: ["#506784"]}
  }
}]

Plotly.newPlot('myDiv', data);
*/
