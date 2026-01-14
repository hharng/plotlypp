// Copyright (c) 2025-2026 Jimmy O'Rourke
// Licensed under and subject to the terms of the LICENSE file accompanying this distribution.
// Official repository: https://github.com/jimmyorourke/plotlypp

#include "3d_charts.hpp"
#include "basic_charts.hpp"
#include "financial_charts.hpp"
#include "maps.hpp"
#include "scientific_charts.hpp"
#include "statistical_charts.hpp"
#include "subplots.hpp"

#include <iostream>

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

    multiple3DSurfacePlots().show();
    waitForEnter();

    gen3dSurfaceContours().show();
    waitForEnter();

    gen3dSurfaceTorus().show();
    waitForEnter();

    meshCube().show();
    waitForEnter();

    gen3dLineSpiral().show();
    waitForEnter();

    gen3dScatterWithColorscalingAndMarkerStyling().show();
    waitForEnter();

    simpleVolumePlot().show();
    waitForEnter();

    multiple3dIsosurfaces().show();
    waitForEnter();

    bubbleChartSizedByVariable().show();
    waitForEnter();
}

void showScientificCharts() {
    using namespace plotlypp;

    areaPolarChart().show();
    waitForEnter();

    multipleTraceRadarChart().show();
    waitForEnter();

    carpetWithScatterTrace().show();
    waitForEnter();

    colorscaleForContourPlot().show();
    waitForEnter();

    smithChartSubplotsWithStlying().show();
    waitForEnter();
}

void showStatisticalCharts() {
    using namespace plotlypp;

    coloredBoxPlot().show();
    waitForEnter();

    coloredAndStyledHistograms().show();
    waitForEnter();

    continuousFilledErrorBars().show();
    waitForEnter();

    asymmetricErrorBars().show();
    waitForEnter();

    gen2DHistogramBivariateNormal().show();
    waitForEnter();

    gen2DHistogramContour().show();
    waitForEnter();

    basicHorizontalViolinPlot().show();
    waitForEnter();
}

void showSubplots() {
    using namespace plotlypp;

    subplotsGridLayout().show();
    waitForEnter();

    subplotsDomainLayout().show();
    waitForEnter();

    multipleSubplotsWithSharedAxes().show();
    waitForEnter();

    gen3dSubplots().show();
    waitForEnter();

    insetGraph().show();
    waitForEnter();

    mixedSubplots().show();
    waitForEnter();
}

int main() {
    showBasicCharts();
    show3dCharts();
    showFinancialCharts();
    showMaps();
    showScientificCharts();
    showStatisticalCharts();
    showSubplots();

    std::cout << "Done" << "\n";
}
