#include "3d_charts.hpp"

#include <cmath>
#include <string>
#include <utility>
#include <vector>

#include <math_utils.hpp>
#include <plotlypp/plot.hpp>
#include <plotlypp/traces/isosurface.hpp>
#include <plotlypp/traces/mesh3d.hpp>
#include <plotlypp/traces/scatter3d.hpp>
#include <plotlypp/traces/surface.hpp>
#include <plotlypp/traces/volume.hpp>

namespace plotlypp {

// https://plotly.com/javascript/3d-surface-plots/
Figure multiple3DSurfacePlots() {
    std::vector<std::vector<double>> z1 = {{8.83, 8.89, 8.81, 8.87, 8.9, 8.87},  {8.89, 8.94, 8.85, 8.94, 8.96, 8.92},
                                           {8.84, 8.9, 8.82, 8.92, 8.93, 8.91},  {8.79, 8.85, 8.79, 8.9, 8.94, 8.92},
                                           {8.79, 8.88, 8.81, 8.9, 8.95, 8.92},  {8.8, 8.82, 8.78, 8.91, 8.94, 8.92},
                                           {8.75, 8.78, 8.77, 8.91, 8.95, 8.92}, {8.8, 8.8, 8.77, 8.91, 8.95, 8.94},
                                           {8.74, 8.81, 8.76, 8.93, 8.98, 8.99}, {8.89, 8.99, 8.92, 9.1, 9.13, 9.11},
                                           {8.97, 8.97, 8.91, 9.09, 9.11, 9.11}, {9.04, 9.08, 9.05, 9.25, 9.28, 9.27},
                                           {9, 9.01, 9, 9.2, 9.23, 9.2},         {8.99, 8.99, 8.98, 9.18, 9.2, 9.19},
                                           {8.93, 8.97, 8.97, 9.18, 9.2, 9.18}};

    std::vector<std::vector<double>> z2;
    for (const auto& row : z1) {
        std::vector<double> z2_row;
        for (double v : row) {
            z2_row.push_back(v + 1);
        }
        z2.push_back(std::move(z2_row));
    }

    std::vector<std::vector<double>> z3;
    for (const auto& row : z1) {
        std::vector<double> z3_row;
        for (double v : row) {
            z3_row.push_back(v - 1);
        }
        z3.push_back(std::move(z3_row));
    }

    auto trace1 = Surface().z(z1);
    auto trace2 = Surface().z(z2).showscale(false).opacity(0.9);
    auto trace3 = Surface().z(z3).showscale(false).opacity(0.9);
    return Figure().addTraces(std::vector<Trace>{std::move(trace1), std::move(trace2), std::move(trace3)});
}

Figure gen3dSurfaceContours() {
    std::vector x = {1, 2, 3, 4, 5};
    std::vector y = {1, 2, 3, 4, 5};
    std::vector<std::vector<int>> z = {
        {0, 1, 0, 1, 0}, {1, 0, 1, 0, 1}, {0, 1, 0, 1, 0}, {1, 0, 1, 0, 1}, {0, 1, 0, 1, 0},
    };
    auto xContours = Surface::Contours::X().show(true).start(1.5).end(2).size(0.04).color("white");
    auto zContours = Surface::Contours::Z().show(true).start(0.5).end(0.8).size(0.05);
    auto surface = Surface().x(x).y(y).z(z).contours(Surface::Contours().x(xContours).z(zContours));
    return Figure().addTrace(std::move(surface));
}

Figure gen3dSurfaceTorus() {
    auto u = math_utils::linspace(0, 2 * M_PI, 50);
    auto v = u;
    auto [ugrid, vgrid] = math_utils::meshgrid(u, v);

    // Eigen or something with vectorized ops would greatly simplify this.

    std::vector<std::vector<double>> x;
    std::vector<std::vector<double>> y;
    std::vector<std::vector<double>> z;
    for (auto r = 0; r < ugrid.size(); ++r) {
        std::vector<double> xr;
        std::vector<double> yr;
        std::vector<double> zr;
        for (auto c = 0; c < ugrid[0].size(); ++c) {
            xr.push_back((5 + 2 * std::cos(vgrid[r][c])) * std::cos(ugrid[r][c]));
            yr.push_back((5 + 2 * std::cos(vgrid[r][c])) * std::sin(ugrid[r][c]));
            zr.push_back(2 * std::sin(vgrid[r][c]));
        }
        x.push_back(std::move(xr));
        y.push_back(std::move(yr));
        z.push_back(std::move(zr));
    }
    return Figure().addTrace(Surface().x(x).y(y).z(z));
}

// https://plotly.com/javascript/3d-mesh/
// https://plotly.com/python/3d-mesh/

Figure meshCube() {
    std::vector<std::pair<double, std::string>> colorscale = {{0, "gold"}, {0.5, "mediumturquoise"}, {1, "magenta"}};
    auto trace = Mesh3D()
                     // 8 vertices of a cube.
                     .x(std::vector{0, 0, 1, 1, 0, 0, 1, 1})
                     .y(std::vector{0, 1, 1, 0, 0, 1, 1, 0})
                     .z(std::vector{0, 0, 0, 0, 1, 1, 1, 1})
                     // i, j and k give the vertices of triangles.
                     .i(std::vector{7, 0, 0, 0, 4, 4, 6, 6, 4, 0, 3, 2})
                     .j(std::vector{3, 4, 1, 2, 5, 6, 5, 2, 0, 1, 6, 3})
                     .k(std::vector{0, 7, 2, 3, 6, 7, 1, 1, 5, 5, 7, 6})
                     // Intensity of each vertex, which will be interpolated and color-coded.
                     .intensity(std::vector<double>{0, 0.14285714285714285, 0.2857142857142857, 0.42857142857142855,
                                                    0.5714285714285714, 0.7142857142857143, 0.8571428571428571, 1})
                     .colorscale(std::move(colorscale));
    return Figure().addTrace(std::move(trace));
}

// https://plotly.com/javascript/3d-line-plots/

Figure gen3dLineSpiral() {
    int point_count = 3142;
    std::vector<double> x;
    std::vector<double> y;
    std::vector<double> z;
    std::vector<std::string> c;
    for (int i = 0; i < point_count; i++) {
        double r = i * (point_count - i);
        x.push_back(r * std::cos(i / 30.0));
        y.push_back(r * std::sin(i / 30.0));
        z.push_back(i);
        c.push_back(std::to_string(i));
    }
    return Figure().addTrace(Scatter3D().x(x).y(y).z(z).mode("lines").opacity(0.7).line(
        Scatter3D::Line().width(10).color(std::move(c)).colorscale("Viridis")));
}

// https://plotly.com/python/3d-scatter-plots/

Figure gen3dScatterWithColorscalingAndMarkerStyling() {
    // Helix equation.
    auto t = math_utils::linspace(0, 20, 100);
    std::vector<double> x;
    std::vector<double> y;
    for (auto t_val : t) {
        x.push_back(std::cos(t_val));
        y.push_back(std::sin(t_val));
    }

    std::vector<std::string> colors(t.size());
    std::transform(t.begin(), t.end(), colors.begin(), [](auto e) { return std::to_string(e); });

    return Figure()
        .addTrace(Scatter3D().x(x).y(y).z(t).mode("markers").marker(
            Scatter3D::Marker().size(12).color(colors).colorscale("Viridis").opacity(0.8)))
        .setLayout(Layout().margin(Layout::Margin().l(0).r(0).b(0).t(0)));
}

// https://plotly.com/python/3d-volume-plots/

Figure simpleVolumePlot() {

    constexpr int kNumPointsPerDim = 40;
    const auto x_coords = math_utils::linspace(-8, 8, kNumPointsPerDim);
    const auto y_coords = math_utils::linspace(-8, 8, kNumPointsPerDim);
    const auto z_coords = math_utils::linspace(-8, 8, kNumPointsPerDim);

    const int total_points = kNumPointsPerDim * kNumPointsPerDim * kNumPointsPerDim;
    std::vector<double> x_flat;
    std::vector<double> y_flat;
    std::vector<double> z_flat;
    std::vector<double> values_flat;
    x_flat.reserve(total_points);
    y_flat.reserve(total_points);
    z_flat.reserve(total_points);
    values_flat.reserve(total_points);

    for (double x : x_coords) {
        for (double y : y_coords) {
            for (double z : z_coords) {
                x_flat.push_back(x);
                y_flat.push_back(y);
                z_flat.push_back(z);
                const double product = x * y * z;
                // sinc(t) = sin(t)/t; for t=0, sinc(0)=1.
                values_flat.push_back(product == 0.0 ? 1.0 : std::sin(product) / product);
            }
        }
    }

    return Figure().addTrace(Volume()
                                 .x(x_flat)
                                 .y(y_flat)
                                 .z(z_flat)
                                 .value(std::move(values_flat))
                                 .isomin(0.1)
                                 .isomax(0.8)
                                 .opacity(0.1)
                                 .colorscale("Jet")
                                 .surface(Volume::Surface().count(17)));
}

// https://plotly.com/python/3d-isosurface-plots/
Figure multiple3dIsosurfaces() {
    constexpr int kNumPointsPerDim = 40;
    const auto x_coords = math_utils::linspace(-5, 5, kNumPointsPerDim);
    const auto y_coords = math_utils::linspace(-5, 5, kNumPointsPerDim);
    const auto z_coords = math_utils::linspace(-5, 5, kNumPointsPerDim);

    const int total_points = kNumPointsPerDim * kNumPointsPerDim * kNumPointsPerDim;
    std::vector<double> x_flat;
    std::vector<double> y_flat;
    std::vector<double> z_flat;
    std::vector<double> values_flat;
    x_flat.reserve(total_points);
    y_flat.reserve(total_points);
    z_flat.reserve(total_points);
    values_flat.reserve(total_points);

    for (double x : x_coords) {
        for (double y : y_coords) {
            for (double z : z_coords) {
                x_flat.push_back(x);
                y_flat.push_back(y);
                z_flat.push_back(z);
                // ellipsoid
                values_flat.push_back(x * x * 0.5 + y * y + z * z * 2);
            }
        }
    }

    return Figure().addTrace(
        Isosurface()
            .x(x_flat)
            .y(y_flat)
            .z(z_flat)
            .value(std::move(values_flat))
            .isomin(10)
            .isomax(50)
            .surface(Isosurface::Surface().count(5))    // number of isosurfaces, 2 by default: only min and max
            .colorbar(Isosurface::Colorbar().nticks(5)) // colorbar ticks correspond to isosurface values
            .caps(Isosurface::Caps().x(Isosurface::Caps::X().show(false)).y([](auto& c) { c.show(false); }))
            .colorscale("Blackbody"));
}

// https://plotly.com/python/3d-bubble-charts/
plotlypp::Figure bubbleChartSizedByVariable() {
    std::vector<std::string> planets = {"Mercury", "Venus",  "Earth",   "Mars", "Jupiter",
                                        "Saturn",  "Uranus", "Neptune", "Pluto"};
    std::vector distanceFromSun = {57.9, 108.2, 149.6, 227.9, 778.6, 1433.5, 2872.5, 4495.1, 5906.4};
    std::vector density = {5427, 5243, 5514, 3933, 1326, 687, 1271, 1638, 2095};
    std::vector gravity = {3.7, 8.9, 9.8, 3.7, 23.1, 9.0, 8.7, 11.0, 0.7};
    std::vector<double> planetDiameter = {4879, 12104, 12756, 6792, 142984, 120536, 51118, 49528, 2370};
    std::vector<std::string> planetColors = {"rgb(135, 135, 125)", "rgb(210, 50, 0)",    "rgb(50, 90, 255)",
                                             "rgb(178, 0, 0)",     "rgb(235, 235, 210)", "rgb(235, 205, 130)",
                                             "rgb(55, 255, 217)",  "rgb(38, 0, 171)",    "rgb(255, 255, 255)"};

    return Figure()
        .addTrace(Scatter3D()
                      .x(distanceFromSun)
                      .y(density)
                      .z(gravity)
                      .text(std::move(planets))
                      .mode("markers")
                      .marker(Scatter3D::Marker()
                                  .sizemode(Scatter3D::Marker::Sizemode::Diameter)
                                  .sizeref(750)
                                  .size(std::move(planetDiameter))
                                  .color(std::move(planetColors))))
        .setLayout(Layout()
                       .width(800)
                       .height(800)
                       .title([](auto& t) { t.text("Planets!"); })
                       .scene(Layout::Scene()
                                  .xaxis(Layout::Scene::Xaxis().title([](auto& t) {
                                      t.text("Distance from Sun");
                                      t.font([](auto& f) { f.color("white"); });
                                  }))
                                  .yaxis(Layout::Scene::Yaxis().title([](auto& t) {
                                      t.text("Density");
                                      t.font([](auto& f) { f.color("white"); });
                                  }))
                                  .zaxis(Layout::Scene::Zaxis().title([](auto& t) {
                                      t.text("Gravity");
                                      t.font([](auto& f) { f.color("white"); });
                                  }))
                                  .bgcolor("rgb(20, 24, 54)")));
}

} // namespace plotlypp

/*

//
https://plotly.com/python/3d-subplots/
# Initialize figure with 4 3D subplots
fig = make_subplots(
    rows=2, cols=2,
    specs=[[{'type': 'surface'}, {'type': 'surface'}],
           [{'type': 'surface'}, {'type': 'surface'}]])

# Generate data
x = np.linspace(-5, 80, 10)
y = np.linspace(-5, 60, 10)
xGrid, yGrid = np.meshgrid(y, x)
z = xGrid ** 3 + yGrid ** 3

# adding surfaces to subplots.
fig.add_trace(
    go.Surface(x=x, y=y, z=z, colorscale='Viridis', showscale=False),
    row=1, col=1)

fig.add_trace(
    go.Surface(x=x, y=y, z=z, colorscale='RdBu', showscale=False),
    row=1, col=2)

fig.add_trace(
    go.Surface(x=x, y=y, z=z, colorscale='YlOrRd', showscale=False),
    row=2, col=1)

fig.add_trace(
    go.Surface(x=x, y=y, z=z, colorscale='YlGnBu', showscale=False),
    row=2, col=2)

fig.update_layout(
    title_text='3D subplots with different colorscales',
    height=800,
    width=800
)

*/
