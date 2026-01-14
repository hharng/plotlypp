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

void showBasicCharts() {
    using namespace plotlypp;

    lineAndScatterWithNamesAxesTitle().show();
    waitForEnter();

    scatterWithColorDimension().show();
    waitForEnter();

    groupedScatter().show();
    waitForEnter();

    lineDashes().show();
    waitForEnter();

    groupedBar().show();
    waitForEnter();

    basicPie().show();
    waitForEnter();

    donut().show();
    waitForEnter();

    bubbleWithMarkerSizeAndColor().show();
    waitForEnter();

    categoricalDotPlot().show();
    waitForEnter();

    basicOverlaidArea().show();
    waitForEnter();

    horizontalBar().show();
    waitForEnter();
}

void showMaps() {
    using namespace plotlypp;

    linesOnMaps().show();
    waitForEnter();

    lightTile().show();
    waitForEnter();

    outlineMapLocations().show();
    waitForEnter();

    scatterTileMaps().show();
    waitForEnter();
}

void showFinancialCharts() {
    using namespace plotlypp;

    basicFunnel().show();
    waitForEnter();

    indicator().show();
    waitForEnter();
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
    showStatisticalCharts();
    showScientificCharts();
    show3dCharts();
    showFinancialCharts();
    showMaps();
    showBasicCharts();
    showSubplots();

    std::cout << "Done" << "\n";
}
