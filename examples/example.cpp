// Copyright (c) 2025-2026 Jimmy O'Rourke
// Licensed under and subject to the terms of the LICENSE file accompanying this distribution.
// Official repository: https://github.com/jimmyorourke/plotlypp

#include <iostream>

#include "3d_charts.hpp"
#include "basic_charts.hpp"
#include "export.hpp"
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

void showMaps() {
    using namespace plotlypp;

    showAndWait(linesOnMaps());
    showAndWait(lightTile());
    showAndWait(outlineMapLocations());
    showAndWait(scatterTileMaps());
}

void showFinancialCharts() {
    using namespace plotlypp;

    showAndWait(basicFunnel());
    showAndWait(indicator());
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

void showScientificCharts() {
    using namespace plotlypp;

    showAndWait(areaPolarChart());
    showAndWait(multipleTraceRadarChart());
    showAndWait(carpetWithScatterTrace());
    showAndWait(colorscaleForContourPlot());
    showAndWait(smithChartSubplotsWithStlying());
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

void showSubplots() {
    using namespace plotlypp;

    showAndWait(subplotsGridLayout());
    showAndWait(subplotsDomainLayout());
    showAndWait(multipleSubplotsWithSharedAxes());
    showAndWait(gen3dSubplots());
    showAndWait(insetGraph());
    showAndWait(mixedSubplots());
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

void saveAllCharts(bool json = false) {
    saveBasicCharts(json);
    saveMaps(json);
    saveFinancialCharts(json);
    save3dCharts(json);
    saveScientificCharts(json);
    saveStatisticalCharts(json);
    saveSubplots(json);
    writeIndexHtml("../examples/output");
}

int main() {
    // showAllCharts();
    // To update the example outputs. WARNING: may write into the source directories!
    saveAllCharts(true);

    std::cout << "Done" << "\n";
}
