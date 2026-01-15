// Copyright (c) 2025-2026 Jimmy O'Rourke
// Licensed under and subject to the terms of the LICENSE file accompanying this distribution.
// Official repository: https://github.com/jimmyorourke/plotlypp

#pragma once

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "3d_charts.hpp"
#include "basic_charts.hpp"
#include "financial_charts.hpp"
#include "maps.hpp"
#include "scientific_charts.hpp"
#include "statistical_charts.hpp"
#include "subplots.hpp"

#include <plotlypp/figure.hpp>

// Helpers for saving charts to HTML, optionally saving out the JSON representation as well.
// WARNING: These functions output to a relative path, and may write into the source directories!
// These functions are mainly used for generating the live charts for GitHub Pages, and the PNG thumbnails.

inline void saveFigure(const plotlypp::Figure& figure, const std::filesystem::path& file_path, bool json = false) {
    figure.writeHtml(file_path);
    if (json) {
        auto json_dir = file_path.parent_path() / "json";
        auto json_filename = file_path.stem();
        json_filename += ".json";
        std::filesystem::create_directories(json_dir);
        std::ofstream json_file(json_dir / json_filename);
        json_file << figure.json();
    }
}

inline void saveBasicCharts(bool json = false) {
    using namespace plotlypp;
    saveFigure(lineAndScatterWithNamesAxesTitle(), "../examples/output/line_and_scatter_with_names_axes_title.html",
               json);
    saveFigure(dataLabelsOnPlot(), "../examples/output/data_labels_on_plot.html", json);
    saveFigure(scatterWithColorDimension(), "../examples/output/scatter_with_color_dimension.html", json);
    saveFigure(groupedScatter(), "../examples/output/grouped_scatter.html", json);
    saveFigure(lineDashes(), "../examples/output/line_dashes.html", json);
    saveFigure(groupedBar(), "../examples/output/grouped_bar.html", json);
    saveFigure(basicPie(), "../examples/output/basic_pie.html", json);
    saveFigure(donut(), "../examples/output/donut.html", json);
    saveFigure(bubbleWithMarkerSizeAndColor(), "../examples/output/bubble_with_marker_size_and_color.html", json);
    saveFigure(categoricalDotPlot(), "../examples/output/categorical_dot_plot.html", json);
    saveFigure(basicOverlaidArea(), "../examples/output/basic_overlaid_area.html", json);
    saveFigure(horizontalBar(), "../examples/output/horizontal_bar.html", json);
}

inline void saveMaps(bool json = false) {
    using namespace plotlypp;
    saveFigure(linesOnMaps(), "../examples/output/lines_on_maps.html", json);
    saveFigure(lightTile(), "../examples/output/light_tile.html", json);
    saveFigure(outlineMapLocations(), "../examples/output/outline_map_locations.html", json);
    saveFigure(scatterTileMaps(), "../examples/output/scatter_tile_maps.html", json);
}

inline void saveFinancialCharts(bool json = false) {
    using namespace plotlypp;
    saveFigure(basicFunnel(), "../examples/output/basic_funnel.html", json);
    saveFigure(indicator(), "../examples/output/indicator.html", json);
}

inline void save3dCharts(bool json = false) {
    using namespace plotlypp;
    saveFigure(multiple3DSurfacePlots(), "../examples/output/multiple_3d_surface_plots.html", json);
    saveFigure(gen3dSurfaceContours(), "../examples/output/gen3d_surface_contours.html", json);
    saveFigure(gen3dSurfaceTorus(), "../examples/output/gen3d_surface_torus.html", json);
    saveFigure(meshCube(), "../examples/output/mesh_cube.html", json);
    saveFigure(gen3dLineSpiral(), "../examples/output/gen3d_line_spiral.html", json);
    saveFigure(gen3dScatterWithColorscalingAndMarkerStyling(),
               "../examples/output/gen3d_scatter_with_colorscaling_and_marker_"
               "styling.html",
               json);
    saveFigure(simpleVolumePlot(), "../examples/output/simple_volume_plot.html", json);
    saveFigure(multiple3dIsosurfaces(), "../examples/output/multiple_3d_isosurfaces.html", json);
    saveFigure(bubbleChartSizedByVariable(), "../examples/output/bubble_chart_sized_by_variable.html", json);
}

inline void saveScientificCharts(bool json = false) {
    using namespace plotlypp;
    saveFigure(areaPolarChart(), "../examples/output/area_polar_chart.html", json);
    saveFigure(multipleTraceRadarChart(), "../examples/output/multiple_trace_radar_chart.html", json);
    saveFigure(carpetWithScatterTrace(), "../examples/output/carpet_with_scatter_trace.html", json);
    saveFigure(colorscaleForContourPlot(), "../examples/output/colorscale_for_contour_plot.html", json);
    saveFigure(smithChartSubplotsWithStlying(), "../examples/output/smith_chart_subplots_with_stlying.html", json);
}

inline void saveStatisticalCharts(bool json = false) {
    using namespace plotlypp;
    saveFigure(coloredBoxPlot(), "../examples/output/colored_box_plot.html", json);
    saveFigure(coloredAndStyledHistograms(), "../examples/output/colored_and_styled_histograms.html", json);
    saveFigure(continuousFilledErrorBars(), "../examples/output/continuous_filled_error_bars.html", json);
    saveFigure(asymmetricErrorBars(), "../examples/output/asymmetric_error_bars.html", json);
    saveFigure(gen2DHistogramBivariateNormal(), "../examples/output/gen2d_histogram_bivariate_normal.html", json);
    saveFigure(gen2DHistogramContour(), "../examples/output/gen2d_histogram_contour.html", json);
    saveFigure(basicHorizontalViolinPlot(), "../examples/output/basic_horizontal_violin_plot.html", json);
}

inline void saveSubplots(bool json = false) {
    using namespace plotlypp;
    saveFigure(subplotsGridLayout(), "../examples/output/subplots_grid_layout.html", json);
    saveFigure(subplotsDomainLayout(), "../examples/output/subplots_domain_layout.html", json);
    saveFigure(multipleSubplotsWithSharedAxes(), "../examples/output/multiple_subplots_with_shared_axes.html", json);
    saveFigure(gen3dSubplots(), "../examples/output/gen3d_subplots.html", json);
    saveFigure(insetGraph(), "../examples/output/inset_graph.html", json);
    saveFigure(mixedSubplots(), "../examples/output/mixed_subplots.html", json);
}

inline void writeIndexHtml(const std::filesystem::path& outputDir) {
    std::vector<std::string> htmlFiles;
    for (const auto& entry : std::filesystem::directory_iterator(outputDir)) {
        if (entry.is_regular_file() && entry.path().extension() == ".html" && entry.path().filename() != "index.html") {
            htmlFiles.push_back(entry.path().filename().string());
        }
    }
    std::sort(htmlFiles.begin(), htmlFiles.end());

    std::ofstream indexFile(outputDir / "index.html");
    // To render nicely with Github Pages Jekyll, set the required Jekyll frontmatter (layout, title) and don't provide
    // our own HTML boilerplate.
    // clang-format off
    indexFile << R"(---)" << "\n"
            << R"(layout: default)" << "\n"
            << R"(title: Plotly++ Examples)" << "\n"
            << R"(---)" << "\n"
            << R"(<h1>Plotly++ Examples</h1>)" << "\n"
            << R"(Click the links below to view the interactive charts)" << "\n"
            << R"(<ul>)" << "\n";
    for (const auto& filename : htmlFiles) {
        indexFile << R"(    <li><a href=")" << filename << R"(">)" << filename << "</a></li>" << "\n";
    }
    indexFile << R"(</ul>)" << "\n";
    // clang-format on
}
