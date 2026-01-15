// Copyright (c) 2025-2026 Jimmy O'Rourke
// Licensed under and subject to the terms of the LICENSE file accompanying this distribution.
// Official repository: https://github.com/jimmyorourke/plotlypp

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

void waitForEnter() {
    std::cout << "Press Enter to generate next plot...\n";
    std::cin.get();
}

void showAndWait(const plotlypp::Figure& figure) {
    figure.show();
    waitForEnter();
}

void saveFigure(const plotlypp::Figure& figure, const char* file_path) { figure.writeHtml(file_path); }

void showBasicCharts() {
    using namespace plotlypp;

    showAndWait(lineAndScatterWithNamesAxesTitle());
    showAndWait(dataLabelsOnPlot());
    showAndWait(scatterWithColorDimension());
    showAndWait(groupedScatter());
    showAndWait(lineDashes());
    showAndWait(groupedBar());
    showAndWait(basicPie());
    showAndWait(donut());
    showAndWait(bubbleWithMarkerSizeAndColor());
    showAndWait(categoricalDotPlot());
    showAndWait(basicOverlaidArea());
    showAndWait(horizontalBar());
}

void saveBasicCharts() {
    using namespace plotlypp;
    saveFigure(lineAndScatterWithNamesAxesTitle(), "../examples/output/line_and_scatter_with_names_axes_title.html");
    saveFigure(dataLabelsOnPlot(), "../examples/output/data_labels_on_plot.html");
    saveFigure(scatterWithColorDimension(), "../examples/output/scatter_with_color_dimension.html");
    saveFigure(groupedScatter(), "../examples/output/grouped_scatter.html");
    saveFigure(lineDashes(), "../examples/output/line_dashes.html");
    saveFigure(groupedBar(), "../examples/output/grouped_bar.html");
    saveFigure(basicPie(), "../examples/output/basic_pie.html");
    saveFigure(donut(), "../examples/output/donut.html");
    saveFigure(bubbleWithMarkerSizeAndColor(), "../examples/output/bubble_with_marker_size_and_color.html");
    saveFigure(categoricalDotPlot(), "../examples/output/categorical_dot_plot.html");
    saveFigure(basicOverlaidArea(), "../examples/output/basic_overlaid_area.html");
    saveFigure(horizontalBar(), "../examples/output/horizontal_bar.html");
}

void showMaps() {
    using namespace plotlypp;

    showAndWait(linesOnMaps());
    showAndWait(lightTile());
    showAndWait(outlineMapLocations());
    showAndWait(scatterTileMaps());
}

void saveMaps() {
    using namespace plotlypp;
    saveFigure(linesOnMaps(), "../examples/output/lines_on_maps.html");
    saveFigure(lightTile(), "../examples/output/light_tile.html");
    saveFigure(outlineMapLocations(), "../examples/output/outline_map_locations.html");
    saveFigure(scatterTileMaps(), "../examples/output/scatter_tile_maps.html");
}

void showFinancialCharts() {
    using namespace plotlypp;

    showAndWait(basicFunnel());
    showAndWait(indicator());
}

void saveFinancialCharts() {
    using namespace plotlypp;
    saveFigure(basicFunnel(), "../examples/output/basic_funnel.html");
    saveFigure(indicator(), "../examples/output/indicator.html");
}

void show3dCharts() {
    using namespace plotlypp;

    showAndWait(multiple3DSurfacePlots());
    showAndWait(gen3dSurfaceContours());
    showAndWait(gen3dSurfaceTorus());
    showAndWait(meshCube());
    showAndWait(gen3dLineSpiral());
    showAndWait(gen3dScatterWithColorscalingAndMarkerStyling());
    showAndWait(simpleVolumePlot());
    showAndWait(multiple3dIsosurfaces());
    showAndWait(bubbleChartSizedByVariable());
}

void save3dCharts() {
    using namespace plotlypp;
    saveFigure(multiple3DSurfacePlots(), "../examples/output/multiple_3d_surface_plots.html");
    saveFigure(gen3dSurfaceContours(), "../examples/output/gen3d_surface_contours.html");
    saveFigure(gen3dSurfaceTorus(), "../examples/output/gen3d_surface_torus.html");
    saveFigure(meshCube(), "../examples/output/mesh_cube.html");
    saveFigure(gen3dLineSpiral(), "../examples/output/gen3d_line_spiral.html");
    saveFigure(gen3dScatterWithColorscalingAndMarkerStyling(),
               "../examples/output/gen3d_scatter_with_colorscaling_and_marker_"
               "styling.html");
    saveFigure(simpleVolumePlot(), "../examples/output/simple_volume_plot.html");
    saveFigure(multiple3dIsosurfaces(), "../examples/output/multiple_3d_isosurfaces.html");
    saveFigure(bubbleChartSizedByVariable(), "../examples/output/bubble_chart_sized_by_variable.html");
}

void showScientificCharts() {
    using namespace plotlypp;

    showAndWait(areaPolarChart());
    showAndWait(multipleTraceRadarChart());
    showAndWait(carpetWithScatterTrace());
    showAndWait(colorscaleForContourPlot());
    showAndWait(smithChartSubplotsWithStlying());
}

void saveScientificCharts() {
    using namespace plotlypp;
    saveFigure(areaPolarChart(), "../examples/output/area_polar_chart.html");
    saveFigure(multipleTraceRadarChart(), "../examples/output/multiple_trace_radar_chart.html");
    saveFigure(carpetWithScatterTrace(), "../examples/output/carpet_with_scatter_trace.html");
    saveFigure(colorscaleForContourPlot(), "../examples/output/colorscale_for_contour_plot.html");
    saveFigure(smithChartSubplotsWithStlying(), "../examples/output/smith_chart_subplots_with_stlying.html");
}

void showStatisticalCharts() {
    using namespace plotlypp;

    showAndWait(coloredBoxPlot());
    showAndWait(coloredAndStyledHistograms());
    showAndWait(continuousFilledErrorBars());
    showAndWait(asymmetricErrorBars());
    showAndWait(gen2DHistogramBivariateNormal());
    showAndWait(gen2DHistogramContour());
    showAndWait(basicHorizontalViolinPlot());
}

void saveStatisticalCharts() {
    using namespace plotlypp;
    saveFigure(coloredBoxPlot(), "../examples/output/colored_box_plot.html");
    saveFigure(coloredAndStyledHistograms(), "../examples/output/colored_and_styled_histograms.html");
    saveFigure(continuousFilledErrorBars(), "../examples/output/continuous_filled_error_bars.html");
    saveFigure(asymmetricErrorBars(), "../examples/output/asymmetric_error_bars.html");
    saveFigure(gen2DHistogramBivariateNormal(), "../examples/output/gen2d_histogram_bivariate_normal.html");
    saveFigure(gen2DHistogramContour(), "../examples/output/gen2d_histogram_contour.html");
    saveFigure(basicHorizontalViolinPlot(), "../examples/output/basic_horizontal_violin_plot.html");
}

void showSubplots() {
    using namespace plotlypp;

    showAndWait(subplotsGridLayout());
    showAndWait(subplotsDomainLayout());
    showAndWait(multipleSubplotsWithSharedAxes());
    showAndWait(gen3dSubplots());
    showAndWait(insetGraph());
    showAndWait(mixedSubplots());
}

void saveSubplots() {
    using namespace plotlypp;
    saveFigure(subplotsGridLayout(), "../examples/output/subplots_grid_layout.html");
    saveFigure(subplotsDomainLayout(), "../examples/output/subplots_domain_layout.html");
    saveFigure(multipleSubplotsWithSharedAxes(), "../examples/output/multiple_subplots_with_shared_axes.html");
    saveFigure(gen3dSubplots(), "../examples/output/gen3d_subplots.html");
    saveFigure(insetGraph(), "../examples/output/inset_graph.html");
    saveFigure(mixedSubplots(), "../examples/output/mixed_subplots.html");
}

void showAllCharts() {
    showBasicCharts();
    showMaps();
    showFinancialCharts();
    show3dCharts();
    showScientificCharts();
    showStatisticalCharts();
    showSubplots();
}

void writeIndexHtml(const std::filesystem::path& outputDir) {
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
            << R"(<ul>)" << "\n";
    for (const auto& filename : htmlFiles) {
        indexFile << R"(    <li><a href=")" << filename << R"(">)" << filename << "</a></li>" << "\n";
    }
    indexFile << R"(</ul>)" << "\n";
    // clang-format on
}

void saveAllCharts() {
    saveBasicCharts();
    saveMaps();
    saveFinancialCharts();
    save3dCharts();
    saveScientificCharts();
    saveStatisticalCharts();
    saveSubplots();
    writeIndexHtml("../examples/output");
}

int main() {
    showAllCharts();
    //   To update the example outputs:
    // saveAllCharts();

    std::cout << "Done" << "\n";
}
